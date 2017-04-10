#include <functional>

unsigned int size, length;

template <class T>
class Heap {
  private:
    unsigned int size, length;
    T *heap;
    void shift(unsigned int child, unsigned int parent) {
      T tmp = heap[child];
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
    Heap(unsigned int initialSize) {
      heap = (T *) malloc(initialSize * sizeof(T));
      size = initialSize;
      length = 0;
    }

    ~Heap() {
      delete &size;
      delete &length;
      delete &heap;
    }
    void insert(T value) {
      if (length == size)
        resize();
      heap[length] = value;
      if (length > 0)
        minHeapify(length);
      length++;
    }

    void clear() {
      free(heap);
      heap = (T *) malloc(size * sizeof(T));
      length = 0;
    }

    bool isEmpty() {
      return length == 0;
    }

    bool isFull() {
      return length == size;
    }

    T peek() {
      return heap[0];
    }

    T pop() {
      if (length <= 0)
        throw std::length_error("Empty heap");
      length--;
      T r = heap[0];
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
};
