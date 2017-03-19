#include <iostream>
#include "heap.h"
#include "huffman.cpp"

using namespace std;

int main(int argc, char const *argv[]) {
  char abc[] = {' ','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
  float freq[] = {18.3, 6.8, 1.3, 2.6, 3.5, 10.2, 1.8, 1.7, 4.9, 5.8, 0.2, 0.6, 3.4, 2.1, 5.5, 5.9, 1.6, 0.1, 4.8, 5.1, 7.7, 2.4, 0.9, 1.9, 0.2, 1.6, 0.1};

  Node<char>* huffmanTree = huffman(abc, freq);

  printCoding(huffmanTree);
  return 0;
}
