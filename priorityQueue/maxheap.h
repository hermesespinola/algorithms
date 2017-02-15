class Heap {
private:
  unsigned int size, length;
  int *heap;
  void shift(unsigned int child, unsigned int parent);
  void resize();

public:
  Heap (unsigned int initialSize);
  Heap();
  virtual ~Heap();
  void insert(int value);
  void clear();
  bool isEmpty();
  bool isFull();
  int peek();
  int pop();
  int getSize();

  protected:
    void maxHeapify(unsigned int i);
    void heapifyDown(unsigned int i);
};
