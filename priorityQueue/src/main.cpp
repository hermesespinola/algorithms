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
  ofstream randOut("./bigData/outRand.txt");

  random_device rd;   // Used to initialize seed engine
  mt19937 rng(rd());  // random number engine
  uniform_int_distribution<int> uni(0, 9999999); // unbiased

  for (int i = 1; i < 10000; i+=10) {
    q = new PriorityQueue(i);
    randOut << i << ",";

    clock_t start = clock();

    // insert
    for (int j = 0; j < i; j++) {
      auto r = uni(rng);
      q->insert(r);
    }
    randOut << (clock() - start) << ",";

    // maximum
    start = clock();
    for (int j = 0; j < i; j++) {
      q->maximum();
    }
    randOut << (clock() - start) << ",";

    // increase key
    start = clock();
    for (int j = 0; j < i; j++) {
      auto r = uni(rng);
      q->increaseKey(j, r);
    }
    randOut << (clock() - start) << ",";

    // extract max
    start = clock();
    for (int j = 0; j < i; j++) {
      q->extractMax();
    }
    randOut << (clock() - start) << endl;

    delete q;
  }
  randOut.close();

  // =========================== Best case =================================
  // file writer
  ofstream BestOut("./bigData/outBest.txt");
  for (int i = 1; i < 10000; i+=10) {
    q = new PriorityQueue(i);
    BestOut << i << ",";

    clock_t start = clock();

    // insert
    for (int j = i; j > 0; j--) {
      q->insert(j);
    }
    BestOut << (clock() - start) << ",";

    // maximum
    start = clock();
    for (int j = 0; j < i; j++) {
      q->maximum();
    }
    BestOut << (clock() - start) << ",";

    // increase key
    start = clock();
    for (int j = 0; j < i; j++) {
      q->increaseKey(j, 1);
    }
    BestOut << (clock() - start) << ",";

    // extract max
    start = clock();
    for (int j = 0; j < i; j++) {
      q->extractMax();
    }
    BestOut << (clock() - start) << endl;

    delete q;
  }
  BestOut.close();

    // =========================== Worst input =================================
    // file writer
    ofstream worstOut("./bigData/outWorst.txt");
    for (int i = 1; i < 10000; i+=10) {
      q = new PriorityQueue(i);
      worstOut << i << ",";

      clock_t start = clock();

      // insert
      for (int j = 0; j < i; j++) {
        q->insert(j);
      }
      worstOut << (clock() - start) << ",";

      // maximum
      start = clock();
      for (int j = 0; j < i; j++) {
        q->maximum();
      }
      worstOut << (clock() - start) << ",";

      // increase key
      start = clock();
      for (int j = i - 1; j >= 0; j--) {
        q->increaseKey(j, i + 1);
      }
      worstOut << (clock() - start) << ",";

      // extract max
      start = clock();
      for (int j = 0; j < i; j++) {
        q->extractMax();
      }
      worstOut << (clock() - start) << endl;

      delete q;
    }
    worstOut.close();

  return 0;
}
