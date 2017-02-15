#include <iostream>
#include "maxheap.h"

int main(int argc, char const *argv[]) {
  Heap* heap = new Heap();
  for (int i = 1; i <= 5; i++) {
    std::cout << i << '\n';
    heap->insert(i);
    std::cout << '\n';
  }

  std::cout << "Insertion done" << '\n';

  for (size_t i = 0; i < 5; i++) {
    std::cout << "Next element: " << heap->pop() << '\n';
  }

  return 0;
}
