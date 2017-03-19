#ifndef MINHEAP_H_
#define MINHEAP_H_

#include <iostream>
#include <stdexcept>
#include <functional>
#include <stdlib.h>
#include <cstddef>

using namespace std;

template<class T>
class Heap {
private:
  unsigned int size, length;
  T dummy;
  T *heap;
public:
  Heap (unsigned int initialSize, T dum) {
    heap = (T *) malloc(initialSize * sizeof(T*));
    size = initialSize;
    length = 0;
    dummy = dum;
  }
  ~Heap() {
    delete &size;
    delete &length;
    delete &heap;
  }
  void shift(unsigned int child, unsigned int parent){
    T tmp = heap[child];
    heap[child] = heap[parent];
    heap[parent] = tmp;
  }
  void minHeapify(unsigned int i){
    if(i > 0){
      do {
        int parent = (i + 1) / 2 - 1;
        if (*heap[i] < *heap[parent]) {
          shift(i, parent);
        } else break;
        i = parent;
      } while(i > 0);
    }
  }
  void heapifyDown(unsigned int i) {
      while (i < length / 2) {
        int left = (i + 1) * 2 - 1;
        int right = left + 1;
        int path = left;

        if (*heap[right] < *heap[left]) {
          path = right;
        }
        if (*heap[path] < *heap[i]) {
          shift(i, path);
        } else break;
        i = path;
      }
  }
  void insert(T value) {
      //if (length == size)
        //resize();
      heap[length] = value;
      if (length > 0)
        minHeapify(length);
      length++;
  }
  void clear() {
    free(heap);
    heap = (int *) malloc(size * sizeof(int));
    length = 0;
  }
  void increase(int i, int key) {
    heap[i] = heap[i] + key;
    minHeapify(i);
  }
  bool isEmpty() {
    return length == 0;
  }
  bool isFull() {
    return length == size;
  }

  int peek() {
    return heap[0];
  }

  T pop() {
      if (length <= 0)
        throw std::length_error("Empty heap");
      length--;
      T r = heap[0];
      heap[0] = heap[length];
      heap[length] = dummy;
      if (length > 1) {
        heapifyDown(0);
      }
      return r;
  }

  int getSize() {
    return size;
  }
};

#endif
