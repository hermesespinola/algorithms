#include <functional>
#include "maxheap.h"

unsigned int size, length;
int *heap;

void Heap::shift(unsigned int child, unsigned int parent) {
    int tmp = heap[child];
    heap[child] = heap[parent];
    heap[parent] = tmp;
}

void Heap::resize() {
  throw std::length_error("Heap is full");
}

void Heap::maxHeapify(unsigned int i) {
    if(i > 0)
      do {
        int parent = (i + 1) / 2 - 1;
        if (heap[i] > heap[parent]) {
          shift(i, parent);
        } else break;
        i = parent;
      } while(i > 0);
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

Heap::Heap (unsigned int initialSize) {
  heap = (int *) malloc(initialSize * sizeof(int));
  size = initialSize;
  length = 0;
}

Heap::~Heap() {
  delete &size;
  delete &length;
  delete &heap;
}
void Heap::insert(int value) {
    if (length == size)
      resize();
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

void Heap::increase(int i, int key) {
  heap[i] = heap[i] + key;
  maxHeapify(i);
}

bool Heap::isEmpty() {
  return length == 0;
}

bool Heap::isFull() {
  return length == size;
}

int Heap::peek() {
  return heap[0];
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

int Heap::getSize() {
  return size;
}
