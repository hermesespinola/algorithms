#include <iostream>
#include <vector>
#include <algorithm>

void insertion_sort(std::vector<float> &v) {
  unsigned int max;

  for (unsigned int i = 0; i < v.size()-1; i++) {
    max = i;
    for (unsigned int j = i + 1; j < v.size(); j++)
      if (v[j] > v[max])
        max = j;

    if (max != i) {
      float tmp = v[i];
      v[i] = v[max];
      v[max] = tmp;
    }
  }
}

//Bucket Sort assume an each element in the array is in [0, 1]
void bucket_sort (float arr[], int n)
{
  //Create m empty buckets
  std::vector<float> buckets[n];

  // Put array elements in different buckets
  for (int i = 0; i < n; i++) {
    unsigned int bucketIndex = n * arr[i];   // index in bucket
    buckets[bucketIndex].push_back(arr[i]);
  }

  // Sort each bucket
  for (int i = 0; i < n; i++) {
    std::sort(buckets[i].begin(), buckets[i].end());
  }

  // merge buckets into arr
  int index = 0;
  for (int i = 0; i < n; i++)
    for (unsigned int j = 0; j < buckets[i].size(); j++)
      arr[index++] = buckets[i][j];
}
