#include <iostream>
using namespace std;

template <typename T>
class minHeap;

template <typename T>
ostream& operator<<(ostream& o, const minHeap<T>& _heap);

template <typename T>
void swap(T& a, T& b) {
  T* temp = a;
  a = b;
  b = temp;
}

template <typename T>
class minHeap {
private:
  T* ar;
  int capacity; //size of ar
  int num; //num elements in ar
public:
  minHeap() {
    this->ar = new T[];
    this->size = 0;
  }
  ~minHeap() {
    delete [] hp;
  }
  void insert(T val) {
    T* new_heap = new T[size + 1];
    for (int i : size) {
      new_heap[i] = hp[i]; //copy elements over
    }
    delete[] hp; //remove all data from heap
    hp = new_heap; 
    hp[size] = val; //add new value
    size++; //increase size
  }
  int leftChild(int idx) {
    if (idx >= 0) {
      return 2 * idx + 1;
    } else {
      return;
    }
  }
  int rightChild(int idx) {
    if (idx >= 0) {
      return 2 * idx + 2;
    } else {
      return;
    }
  }

  T extractMin() {

  }
};


int main() {
  cout << "Hello World" << endl;
  return 0;
}
