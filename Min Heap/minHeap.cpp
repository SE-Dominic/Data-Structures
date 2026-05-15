#include <iostream>
using namespace std;

//prototypes
template <typename T>
class minHeap;

template <typename T>
ostream& operator<<(ostream& o, const minHeap<T>& _heap) {
  for (int i = 0; i < _heap.num; i++) {
    o << _heap.ar[i] << " ";
  }
  o << endl;
  return o;
}

template <typename T>
void swap(T& a, T& b) {
  T temp = a;
  a = b;
  b = temp;
}

//class implementation
template <typename T>
class minHeap {
  friend ostream& operator<<(ostream& o, const minHeap<T>& _heap);
private:
  T* ar;
  int capacity;
  int num; //current number of elements in array
public:
  minHeap() { //empty constructor
    this->capacity = 1;
    this->num = 0;
    this->ar = new T[capacity];
  }
  minHeap(int c) { //set capacity constructor
    this->capacity = c;
    this->num = 0;
    this->ar = new T[c];
  }
  ~minHeap() { //destructor
    if (ar != NULL) {
      delete [] ar;
    }
  } 
  void min_heapify(int i);
  void bubbleUp(int i);
  void insert(const T& el);
  int find(const T& key) const; //O(log(n))
  void remove(int i);
  T getMin();
  T& getElem(int i);
  const T& getElem(int i) const;
  int getCap() const;
  int getNum() const;
  void updateElem(int i, const T& newValue); //update the elemnt at index i                                      
  void print() const {
    for (int i = 0; i < num; i++) {
      cout << ar[i] << " ";
    }
  }
  class Underflow{};
  class Overflow{};
  class BadIndex{};
  class NotFound{};
};

template<typename T>
T& minHeap<T>::getElem(int i) {
  if (i < 0 || i >= num) {
    throw BadIndex {};
  }
  return ar[i];
}

template <typename T>
const T& minHeap<T>::getElem(int i) const {
  if (i < 0 || i >= num) {
    throw BadIndex {};
  }
  return ar[i];
}

template<typename T>
int minHeap<T>::getCap() const {
  return this->capacity;
}

template<typename T>
int minHeap<T>::getNum() const {
  return this->num;
}

template <typename T>
void minHeap<T>::updateElem(int i, const T& newValue) {
  if (i < 0 || i >= num) {
    throw BadIndex {};
  }
  ar[i] = newValue;
  if (i > 0 && ar[i] < ar[(i - 1) / 2]) { //checks if updated value is less than parent value
    bubbleUp(i);
  } else {
    min_heapify(i); //heapify down if larger than children
  }
}

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
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int smallest = i;

    if (l < num && ar[l] < ar[smallest]) {
      smallest = l;
    }
    if (r < num && ar[r] < ar[smallest]) {
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
  ar[num] = val;
  num++;
  bubbleUp(num - 1);
}

template <typename T>
int minHeap<T>::find(const T& el) const {
  for (int i = 0; i < num; i++) {
    if (ar[i] == el) {
      cout << "Key found at: (" << i << ") " << endl;
      return i;
    }
  }
  throw NotFound{}; //not found
}

template <typename T>
void minHeap<T>::remove(int i) {
  if (i < 0 || i >= num) {
    throw BadIndex{};
  }
  ar[i] = ar[num - 1]; //value gets replaced by last
  num--;
  
  if (num == 0) {
    return;
  }
  if (i > 0 && ar[i] < ar[(i - 1) / 2]) { //value < parent
    bubbleUp(i);
  } else if (i < num) {
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
