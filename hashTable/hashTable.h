#ifndef HASHTABLE_H_
#define HASHTABLE_H_

#include <iostream>
#include <stdexcept>
#define INIT_CAP = 101

using namespace std;

template<class K, class V>
class Node {
public:
  Node<K, V>* next;
  K key;
  V value;

  Node(Node<K, V> _next, K _key, V _value){
    next = _next;
    key = _key;
    value = _value;
  }
};

template<class K, class V>
class hashTable{

private:
  int n;
  int m;
  Node<K, V>* table;

public:
  hashTable(int size){
    n = size;
    m = 0;
    table = new Node<K, V> [size];
  }

  int hash(K key){
    return 0;
  }

  int hashDivision(K key){
    return 0;
  }

  int hashMultiplication(K key){
    return 0;
  }

  int product(int row, int vector){
    int i = row & vector;
    i = i - ((i >> 1) & 0x55555555);
    i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
    i = (((i + (i >> 4)) & 0x0F0F0F0F) * 0x01010101) >> 24;
    return i & 0x00000001;
  }

  int getSize(){
    return this->n;
  }

  bool isEmpty(){
    return this->m == 0;
  }

  V get(K key){
    if (key == NULL){
      throw invalid_argument("Invalid key");
    }
    int pos = hash(key);
    for (Node<K, V> x = table[pos]; x != NULL; x = x->next){
      if (x->key = key){
        return x->value;
      }
    }
    return NULL;
  }

  bool contains(K key){
    return get(key) == NULL;
  }

  void add(K key, V value){
    if (key == NULL || value == NULL){
      throw invalid_argument("Invalid key");
    }
    int pos = hash(key);
    for (Node<K, V> x = table[pos]; x != NULL; x = x->next){
      if (x->key = key){
        x->value = value;
        return;
      }
    }
    m++;
    table[pos] = new Node<K, V>(this->table[pos], key, value);
  }

  V remove(K key){
    if(key == NULL){
      throw invalid_argument("Invalid key");
    }
    int pos = hash(key);
    V toReturn = NULL;
    for (Node<K, V> x = this->table[pos]; x != NULL; x = x->next){
      if (x->key = key){
        toReturn = x->value;
      }
    }
    return toReturn;
  }
};

#endif
