#include <functional>

unsigned int size, length;
int *heap;

class Heap {
  private:
    unsigned int size, length;
    void shift(unsigned int child, unsigned int parent) {
      int tmp = heap[child];
      heap[child] = heap[parent];
      heap[parent] = tmp;
    }

    void resize() {
      throw std::length_error("Heap is full");
    }

    void minHeapify(unsigned int i) {
      while(i > 0) {
        int parent = (i + 1) / 2 - 1;
        if (heap[i] < heap[parent]) {
          shift(i, parent);
        } else break;
        i = parent;
      }
    }

    void heapifyDown(unsigned int i) {
      while (i < length / 2) {
        int left = (i + 1) * 2 - 1;
        int right = left + 1;
        int path = left;

        if (right < length && heap[right] < heap[left]) {
          path = right;
        }
        if (heap[path] < heap[i]) {
          shift(i, path);
        } else break;
        i = path;
      }
    }

  public:
    Heap (unsigned int initialSize) {
      heap = (int *) malloc(initialSize * sizeof(int));
      size = initialSize;
      length = 0;
    }

    ~Heap() {
      delete &size;
      delete &length;
      delete &heap;
    }
    void insert(int value) {
      if (length == size)
        resize();
      heap[length] = value;
      if (length > 0)
        minHeapify(length);
      length++;
    }

    void clear() {
      free(heap);
      heap = (int *) malloc(size * sizeof(int));
      length = 0;
    }

    void increase(int i, int key) {
      heap[i] = heap[i] + key;
      minHeapify(i);
    }

    bool isEmpty() {
      return length == 0;
    }

    bool isFull() {
      return length == size;
    }

    int peek() {
      return heap[0];
    }

    int pop() {
      if (length <= 0)
        throw std::length_error("Empty heap");
      length--;
      int r = heap[0];
      heap[0] = heap[length];
      heap[length] = 0;
      if (length > 1) {
        heapifyDown(0);
      }
      return r;
    }

    int getSize() {
      return size;
    }

    void printValues() {
      for (int i = 0; i < length; i++)
        std::cout << heap[i] << ", ";
      std::cout << std::endl;
    }
};
