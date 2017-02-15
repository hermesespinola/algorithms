#include "maxheap.h"
#include <iostream>
#include <algorithm>

Heap::Heap (unsigned int initialSize){
  heap = (int *) malloc(initialSize * sizeof(int));
  size = initialSize;
  length = 0;
}

Heap::~Heap() {
  delete &size;
  delete &length;
  free(heap);
  delete &heap;
}

void Heap::resize() {
  return;
}

void Heap::shift(unsigned int child, unsigned int parent) {
  int tmp = heap[child];
  heap[child] = heap[parent];
  heap[parent] = tmp;
}

int Heap::pop() {
  if (length <= 0)
    throw std::length_error("Empty heap");
  length--;
  int r = heap[0];
  heap[0] = heap[length];
  heap[length] = 0;
  if (length > 1) {
    heapifyDown(0);
  }
  return r;
}

void Heap::heapifyDown(unsigned int i) {
  while (i < length / 2) {
    int left = (i + 1) * 2 - 1;
    int right = left + 1;
    int path = left;

    if (heap[right] > heap[left]) {
      path = right;
    }
    if (heap[path] > heap[i]) {
      shift(i, path);
    } else break;
    i = path;
  }
}

void Heap::maxHeapify(unsigned int i) {
  do {
    int parent = (i + 1) / 2 - 1;
    if (heap[i] > heap[parent]) {
      shift(i, parent);
    } else break;
    i = parent;
  } while(i > 0);
}

void Heap::insert(int value) {
  // if (length >= size)
  //   resize();
  heap[length] = value;
  if (length > 0)
    maxHeapify(length);
  length++;
}

void Heap::clear() {
  free(heap);
  heap = (int *) malloc(size * sizeof(int));
  length = 0;
}

bool Heap::isEmpty() {
  return length == 0;
}

bool Heap::isFull() {
  return length == size - 1;
}

int Heap::peek() {
  return heap[0];
}
