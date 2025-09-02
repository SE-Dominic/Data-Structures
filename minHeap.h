/*****************************************************
Template prepared by Kazumi Slott
CS311
min heap class

Your name: Dominic Allen
Your programmer number: 1
Hours spent making and testing your min heap class: ????
Any difficulties?: ????
*******************************************************/
#ifndef MINHEAP_H
#define MINHEAP_H
#include <iostream> //for operator<<()
using namespace std;
//#include "swap.h" //for mySwap().  If you didn't create it, you can use the library's swap()

template <class T>
class minHeap;

template <class T>
ostream& operator<<(ostream& o, const minHeap<T>& h);

template <class T>
class minHeap
{
  friend ostream& operator<< <T>(ostream& o, const minHeap<T>& h);
private:
  T* ar; //dynamic array
  int capacity; //the size of ar
  int num; //the number of elements I have in ar
public:
  minHeap(){ar = NULL; capacity = 0; num = 0;}
  minHeap(int c);
  ~minHeap(){if(ar!=NULL)delete [] ar;}
  void min_heapify(int i);
  //void build_min_heap(); //no need to implement this. We won't use it for our application.
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

template<typename T>
minHeap<T>::minHeap(int c) {
  capacity = c;
  num = 0;
  ar = new T[capacity];
}

//You need to implement all the memeber functions above.  Don't forget operator<<().
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
    mySwap(ar[i], ar[smallest]);
    min_heapify(smallest);
  }
}

template <typename T>
T& minHeap<T>::getElem(int i) {
  if (i < 0 || i >= capacity) {
    throw BadIndex{}; 
  }
  return ar[i];
}

template <typename T>
const T& minHeap<T>::getElem(int i) const {
  if (i < 0 || i >= capacity) {
    throw BadIndex{};
  }
  return this->ar[i];
}

template <typename T>
int minHeap<T>::getCap() const {
  return this->capacity;
}

template <typename T>
int minHeap<T>::getNum() const {
  return this->num;
}

template <typename T>
void minHeap<T>::updateElem(int i, const T& newValue) {
  this->ar[i] = newValue;
}
template <typename T>
ostream& operator<<(ostream& o, const minHeap<T>& h) {
  for (int i = 0; i < h.num; i++) {
    o << h.ar[i] << endl;
  }
  return o;
}

template <typename T>
void minHeap<T>::insert(const T& el)
{
  if(capacity == 0) {
    capacity = 1;
    ar = new T[capacity];
  }
  else if(num == capacity)
    {
      throw Overflow{}; //"The array is full"; 
    }
  ar[num] = el;
  num++;
  bubbleUp(num - 1);
}

template <typename T>
void minHeap<T>::bubbleUp(int i) {
  while (i > 0) {
    int par = (i - 1) / 2;
    if (ar[par] > ar[i]) {
      mySwap(ar[par], ar[i]);
      i = par;
    } else {
      break;
    }
  }
}
template <class T>
int minHeap<T>::find(const T& key) const
{
  for(int i = 0; i < num; i++) 
    if(ar[i] == key)
      return i;

  //The element doesn't exist 
  throw NotFound();// "The element doesn't exist";                                                                                             
}

template <typename T>
void minHeap<T>::remove(int i)
{
  if(i < 0 || i >= this->num)
    {
      throw BadIndex(); //"The element doesn't exist";                                                                       
    }
  ar[i] = ar[num - 1];
  num--;
  if (i > 0 && ar[i] < ar[(i - 1) / 2]) {
    bubbleUp(i); //bubble up value toward the top
  } else {
    min_heapify(i); //fix structure
  }
}

template <typename T>
T minHeap<T>::getMin()
{
  if(num == 0)
    {
       throw Underflow();
    }
  T min = ar[0];
  remove(0);
  return min;
  //This function removes the top element and returns it.
  //You should be calling remove()
  
}


#endif
