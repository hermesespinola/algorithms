#include "maxheap.h"

class PriorityQueue {
  private:
    Heap *heap;

  public:
    PriorityQueue (unsigned int initialSize);
    PriorityQueue() : PriorityQueue(100) {};
    void insert(int value);
    bool increaseKey(int index, int amount);
    bool isFull();
    int extractMax();
    int maximum();
    int getSize();
};
