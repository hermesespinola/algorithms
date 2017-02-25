
#include <stdio.h>
#include <random>
#include <iostream>
#include <fstream>
#include "BucketSort.cpp"
#include "RadixSort.cpp"

using namespace std;

template <typename T>
void print_array(T arr[], int n) {
  for (int i = 0; i < n; i++) {
    std::cout << arr[i] << ", ";
  }
  std::cout << endl;
}

int main(int argc, char const *argv[]) {
  // ========================= BucketSort ======================================
  random_device rd;   // Used to initialize seed engine
  mt19937 rng(rd());  // random number engine
  uniform_real_distribution<float> uni(0.0, 0.999999999999999); // unbiased

  ofstream bucketRand("../bigData/bucketRand.txt");

  for (int n = 1; n < 10000; n+=10) {
    float *arr = (float *) malloc(n * sizeof(float));
    bucketRand << n << ',';

    clock_t start = clock();

    // init array with random real numbers
    for (int i = 0; i < n; i+=1) {
      arr[i] = uni(rng);
    }

    bucket_sort(arr, n);

    bucketRand << (clock() - start) << endl;

    delete arr;
  }


  uniform_real_distribution<float> uniWorst(0.0, 0.0001); // unbiased

  for (int n = 1; n < 10000; n+=10) {
    float *arr = (float *) malloc(n * sizeof(float));
    bucketRand << n << ',';

    clock_t start = clock();

    // init array with random real numbers
    for (int i = 0; i < n; i+=1) {
      arr[i] = uniWorst(rng);
    }

    bucket_sort(arr, n);

    bucketRand << (clock() - start) << endl;

    delete arr;
  }

  for (int n = 1; n < 10000; n+=10) {
    float *arr = (float *) malloc(n * sizeof(float));
    bucketRand << n << ',';

    clock_t start = clock();

    // init array with random real numbers
    for (int i = 0; i < n; i+=1) {
      arr[i] = i / n;
    }

    bucket_sort(arr, n);

    bucketRand << (clock() - start) << endl;

    delete arr;
  }

  // ========================= RadixSort ======================================
  ofstream radixOut("../bigData/radixOut.txt");

  uniform_int_distribution<int> unir(0, 999999); // unbiased

  for (int n = 1; n < 10000; n+=10) {
    int *arr = (int *) malloc(n * sizeof(int));
    radixOut << n << ',';

    clock_t start = clock();

    // init array with random numbers
    for (int i = 0; i < n; i+=1) {
      arr[i] = unir(rng);
    }

    radix_sort(arr, n);

    radixOut << (clock() - start) << endl;

    delete arr;
  }

  for (int n = 1; n < 10000; n+=10) {
    int *arr = (int *) malloc(n * sizeof(int));
    radixOut << n << ',';

    clock_t start = clock();

    // init array with random real numbers
    for (int i = 0; i < n; i+=1) {
      arr[i] = uniWorst(rng);
    }

    radix_sort(arr, n);

    radixOut << (clock() - start) << endl;

    delete arr;
  }

  for (int n = 1; n < 10000; n+=10) {
    int *arr = (int *) malloc(n * sizeof(int));
    radixOut << n << ',';

    clock_t start = clock();

    // init array with random real numbers
    for (int i = 0; i < n; i+=1) {
      arr[i] = i / n;
    }

    radix_sort(arr, n);

    radixOut << (clock() - start) << endl;

    delete arr;
  }

  return 0;
}
