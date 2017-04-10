#include <iostream>
#include "minheap.cpp"

using namespace std;

class PriorityQueue {
  private:
    Heap *heap;

  public:
    PriorityQueue(unsigned int size){
      heap = new Heap(size);
    }

    void printValues() {
      heap->printValues();
    }

    void insert(int value) {
      heap->insert(value);
    }

    int extractMin() {
      return heap->pop();
    }

    bool increaseKey(int index, int amount) {
      heap->increase(index, amount);
    }

    int minimum() {
      return heap->peek();
    }

    bool isFull() {
      return heap->isFull();
    }
};
