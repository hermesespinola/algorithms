#include "maxheap.h"
#include <algorithm>
#include <iostream>

Heap::Heap (unsigned int initialSize){
  *heap = heap[initialSize];
  size = initialSize;
  length = 0;
}

Heap::Heap() {
  *heap = heap[100];
  size = 100;
  length = 0;
}

Heap::~Heap() {
  delete &size;
  delete &length;
  delete &heap;
}

void Heap::resize() {
  return;
}

void Heap::shift(unsigned int child, unsigned int parent) {
  int tmp = heap[child];
  std::cout << "temp: " << tmp << '\n';
  std::cout << "parent: " << heap[parent] << '\n';
  heap[child] = heap[parent];
  std::cout << "new child: " << heap[child] << '\n';
  heap[parent] = tmp;
  std::cout << "new parent: " << heap[parent] << '\n';
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
  std::cout << "last element: " << heap[i] << '\n';
  // do {
  //   int parent = (i + 1) / 2 - 1;
  //   std::cout << "parent: " << parent << " value: " << heap[i] << '\n';
  //   if (heap[i] > heap[parent]) {
  //     shift(i, parent);
  //   } else break;
  //   i = parent;
  // } while(i > 0);
}

void Heap::insert(int value) {
  // if (length >= size)
  //   resize();
  heap[length] = value;
  std::cout << "last element: " << heap[length] << '\n';
  // if (length > 0)
  //   maxHeapify(length);
  std::cout << "last element: " << heap[length] << '\n';
  length++;
  std::cout << "The heap so far: " << ' ';
  for (unsigned int i = 0; i < length; i++) {
    std::cout << heap[i] << ' ';
  }
  std::cout << '\n';
}

void Heap::clear() {
  std::fill_n(heap, length, 0);
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
