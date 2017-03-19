#include <iostream>
#include "heap.h"
#include <limits.h>

using namespace std;

template<class T>
class Node;

template<class T>
ostream& operator<<(ostream& os, const Node<T>& dt);

template<class T>
class Node {
public:
  T element;
  float freq;
  Node<T>* left;
  Node<T>* right;

  Node(Node<T> left, Node<T> right, float freq){
    this->freq = freq;
    this->left = left;
    this->right = right;
  }

  Node(T element, double freq) {
    this->freq = freq;
    this->element = element;
  }

  ~Node() {
    delete &element;
    delete &freq;
    delete &left;
    delete &right;
  }

  bool operator<(const Node<T>& a) {
    return this->freq < a.freq;
  }
  bool operator>(const Node<T>& a) {
    return this->freq > a.freq;
  }
  void operator = (const Node& a) {
    this->freq = a.freq;
    this->element = a.element;
  }
  friend ostream& operator<< <>(ostream& os, const Node& dt);
};
template<class T>
ostream& operator<<(std::ostream& os, const Node<T>& dt){
    os << dt.freq << " " << dt.element;
    return os;
}

Node<char>* huffman(const char abc[], const float freq[]) {
  Heap<Node<char>*>* h = new Heap<Node<char>*>(27, new Node<char>('-', 1000));

  for (size_t i = 0; i < 27; i++) {
    h->insert(new Node<char>(abc[i], freq[i]));
  }

  for (int i = 1; i < h->getSize(); i++) {
    Node<char>* p = new Node<char>('*', 0);
    Node<char>* l = h->pop();
    Node<char>* r = h->pop();
    p->left = l;
    p->right = r;
    p->freq = l->freq + r->freq;
    h->insert(p);
  }

  return h->pop();
}

static void printCodingHelper(Node<char>* tree, string code) {
  // add 0 when going to the left
  if (tree->left != 0) {
    printCodingHelper(tree->left, code + '0');
  }

  // print
  if (tree->element != '*') {
    cout << tree->element << '\t' << code << endl;
  }

  // add 1 when going to the left
  if (tree->right != 0) {
    printCodingHelper(tree->right, code + '1');
  }
}

void printCoding(Node<char>* tree) {
  printCodingHelper(tree, "");
}
