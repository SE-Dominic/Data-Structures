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
  friend ostream& operator<<(ostream& o, const minHeap<T>& _heap);
private:
  T* ar;
  int capacity; //size of ar
  int num; //num elements in ar
public:
  minHeap() {
    this->capacity = 1;
    this->num = 0;
    this->ar = new T[capacity];
  }
  minHeap(int c) {
    this->capacity = c;
    this->num = 0;
    this->ar = new T[c];
  }
  ~minHeap() {
    if (ar != NULL) {
      delete [] ar;
    }
  } 
  void min_heapify(int i);
  void bubbleUp(int i);
  void insert(const T& el);
  int find(const T& key) const;
  void remove(int i);
  T getMin();
  T& getElem(int i);
  const T& getElem(int i) const;
  int getCap() const;
  int getNum() const;
  void updateElem(int i, const T& newValue); //update the elemnt at index i                                      
  
  class Underflow{};
  class Overflow{};
  class BadIndex{};
  class NotFound{};
};

template <typename T>
void minHeap<T>::bubbleUp(int idx) {
  while (idx > 0) {
    int parent = (idx - 1) / 2;
    if (ar[idx] < ar[parent]) {
      swap(ar[parent], ar[idx]);
      idx = parent;
    } else {
      break;
    }
  }
}
template <typename T>
void minHeap<T>::min_heapify(int i) {
  if (ar != NULL) {
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int smallest = i;
    if (ar[l] < ar[r] && ar[l] < ar[smallest]) {
      smallest = l;
    }
    if (ar[r] < ar[l] && ar[r] < ar[smallest])
    smallest = r;
  }
  if (smallest != i) {
    swap(ar[smallest], ar[i]);
    min_heapify(smallest); //recursively call function to fix heap
  }
}

template<typename T>
void minHeap<T>::insert(const T& val) {
  if (num == capacity) {
    throw Overflow{};
  }
  if (capacity == 0) {
    capacity = 1;
    ar = new T[capacity];
  }
  ar[num] = val;
  num++;
  bubbleUp(num - 1);
}

template <typename T>
int minHeap<T>::find(const T& el) const {
  int l, r;
  l = 0;
  r = num;
  

  while (l < r) {
    int m = (r - l) / 2;
    if (ar[m] == el) {
      return m;
    } else if (ar[m] < target) {
      l = m + 1;
    } else {
      r = m - 1;
    }
  }
  throw NotFound{}; //not found
}

template <typename T>
void minHeap<T>::remove(int i) {
  if (i < 0 || i > num) {
    throw BadIndex{};
  }
  ar[i] = ar[num - 1]; //value gets replaced by last
  num--;
  if (i > 0 && ar[i] < ar[(i - 1) / 2]) { //value < parent
    bubbleUp(i);
  } else {
    min_heapify(i); //fix structure
  }
}

template <typename T>
T minHeap<T>::getMin() {
  if(num == 0) {
    throw Underflow{};
  }
  T min = ar[0];
  remove(0);
  return min;
}

int main() {
  cout << "Hello World" << endl;
  return 0;
}
