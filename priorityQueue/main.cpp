#include <iostream>
#include "maxheap.h"

int main(int argc, char const *argv[]) {
  Heap* heap = new Heap();
  for (int i = 1; i <= 10; i++) {
    heap->insert(i);
  }

  std::cout << "Insertion done" << '\n';

  for (size_t i = 0; i < 10; i++) {
    std::cout << heap->pop() << '\n';
  }

  return 0;
}
