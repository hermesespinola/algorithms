#include <iostream>
#include "minheap.cpp"

using namespace std;

template <class T>
class PriorityQueue {
  private:
    Heap<T> *heap;

  public:
    PriorityQueue(unsigned int size){
      heap = new Heap<T>(size);
    }

    void insert(T value) {
      heap->insert(value);
    }

    T extractMin() {
      return heap->pop();
    }

    T minimum() {
      return heap->peek();
    }

    bool isFull() {
      return heap->isFull();
    }

    bool isEmpty() {
      return heap->isEmpty();
    }
};

