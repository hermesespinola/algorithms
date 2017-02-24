#include <stdio.h>
#include <stdlib.h>

typedef struct queue *queue_ptr;
  struct queue {
    int data;
    queue_ptr next;
  };

queue_ptr front[10], rear[10];  /* For base 10, The 11th queue is not needed */

void add_queue(int i, int data) {
  queue_ptr tmp;

  tmp = (queue_ptr) malloc(sizeof(*tmp));
  tmp->next = NULL;
  tmp->data = data;
  if (front[i]) {
    rear[i]->next = tmp;
  } else {
    front[i] = tmp;
  }
  rear[i] = tmp;
}

int delete_queue(int i) {
  int data;
  queue_ptr tmp;

  tmp = front[i];
  if (!tmp) {
    return -1;  /* So that we can check if queue is empty */
  }
  data = tmp->data;
  front[i] = tmp->next;
  free(tmp);
  return data;
}

void radix_sort(int *arr, const int size) {
  int i, j, k, radix, digits, tmp;

  if (size < 1) {
    return;  /* don't do anything if invalid size */
  }

  /* get the number of digits */
  for (digits = 0, radix = 1; arr[0] >= radix; digits++, radix *=10);

  /* perform sort (digits) times from LSB to MSB */
  for (i = 0, radix = 1; i < digits; i++, radix *= 10) {
    /* distribute to queues */
    for (j = 0; j < size; j++) {
      add_queue((arr[j] / radix) % 10, arr[j]);
    }
    /* take them out from each queue to the original test array */
    for (j = 0, k = 0; j < 10; j++) {
      for (tmp = delete_queue(j); tmp != -1;\
       tmp = delete_queue(j), k++) {
        arr[k] = tmp;
      }
    }
  }
}
