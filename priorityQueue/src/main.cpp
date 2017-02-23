#include <stdio.h>
#include <random>
#include <iostream>
#include <fstream>

#include "priorityqueue.h"

using namespace std;

int main(int argc, char const *argv[]) {
  PriorityQueue * q;

  // =========================== Random input =================================
  // file writer
  ofstream output("./bigData/outRand.txt");

  random_device rd;   // Used to initialize seed engine
  mt19937 rng(rd());  // random number engine
  uniform_int_distribution<int> uni(0, 9999999); // unbiased

  for (int i = 1; i < 10000; i+=10) {
    q = new PriorityQueue(i);
    output << i << ",";

    clock_t start = clock();

    // insert
    for (int j = 0; j < i; j++) {
      auto r = uni(rng);
      q->insert(r);
    }
    output << (clock() - start) << ",";

    // maximum
    start = clock();
    for (int j = 0; j < i; j++) {
      q->maximum();
    }
    output << (clock() - start) << ",";

    // increase key
    start = clock();
    for (int j = 0; j < i; j++) {
      auto r = uni(rng);
      q->increaseKey(j, r);
    }
    output << (clock() - start) << ",";

    // extract max
    start = clock();
    for (int j = 0; j < i; j++) {
      q->extractMax();
    }
    output << (clock() - start) << endl;

    delete q;
  }

  // =========================== Best case =================================


  // =========================== Worst input =================================


  return 0;
}
