#include <iostream>
#include "priorityqueue.h"

using namespace std;

PriorityQueue::PriorityQueue(unsigned int size){
  heap = new Heap(size);
}

void PriorityQueue::insert(int value) {
  heap->insert(value);
}

int PriorityQueue::extractMax() {
  return heap->pop();
}

bool PriorityQueue::increaseKey(int index, int amount) {
  heap->increase(index, amount);
}

int PriorityQueue::maximum() {
  return heap->peek();
}

bool PriorityQueue::isFull() {
  return heap->isFull();
}
