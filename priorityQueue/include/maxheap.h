class Heap {
  private:
    unsigned int size, length;
    int *heap;

    void shift(unsigned int child, unsigned int parent);
    void resize();
    void maxHeapify(unsigned int i);
    void heapifyDown(unsigned int i);

  public:
    Heap (unsigned int initialSize);
    Heap() : Heap(100) {};
    virtual ~Heap();
    void insert(int value);
    void clear();
    void increase(int index, int amount);
    bool isEmpty();
    bool isFull();
    int peek();
    int pop();
    int getSize();
    int* heapSort();
};
