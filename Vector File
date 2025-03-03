#ifndef HEADFILE_H
#define HEADFILE_H
#include <iostream>
#include <iomanip>
using namespace std;

template <typename A>
class Vector {
private:
  int capacity = 1;
  int size = 0;
  A* dyn_arr = new A[capacity];
public:
  //constructors
  Vector<A>(){}
  ~Vector<A>() {
    delete [] dyn_arr;
  }
  //insert function
  void insert(A val) {
    if (size == capacity) {
      growVectorSize();
    }
    dyn_arr[size] = val;
    size++;
  }
  //insert at index function
  void insert_at(A val, int idx) {
    if (idx < 0 || idx > size) {
      cerr << "Could not access the element at the index specified." << endl;
      return;
    }
    if (size == capacity) {
      growVectorSize();
    }
    for (int i = size - 1; i >= idx; i--) {
      dyn_arr[i + 1] = dyn_arr[i];
    }
      dyn_arr[idx] = val;
      size++;
  }
  //pop element
  void pop_back() {
    dyn_arr[size - 1] = 0;
    size--;

    if (size == (capacity / 2)) {
      shrinkVectorSize();
    }
  }
  //remove at certain index
  void remove_at(int idx) {
    if (idx < 0 || idx > size) {
      cerr << "Could not access the element at the index specified." << endl;
      return;
    }
    for (int i = idx; i < size; i++) {
      dyn_arr[i] = dyn_arr[i + 1];
    }
    dyn_arr[size - 1] = 0;
    size--;
    if (size == (capacity / 2)) {
      shrinkVectorSize();
    }
  }
  //double dynamic array size
  void growVectorSize() {
    capacity *= 2;
    A* temp = new A[capacity]; //create new array twice the size of old array
    for (int i = 0; i < size; i++) {
      temp[i] = dyn_arr[i];
    }
    dyn_arr = temp; //array equals new array thats double for size
  }
  //divide dynamic array size by 2
  void shrinkVectorSize() {
    capacity /= 2;
    A* temp = new A[capacity];
    for (int i = 0; i < size; i++) {
      temp[i] = dyn_arr[i];
    }
    dyn_arr = temp;
  }
  //display contents of vector
  void displayVector() {
    cout << left << "Size: " << setw(4) << size << "Capacity: " << setw(4) << capacity << endl;
    for (int i = 0; i < size; i++) {
      cout << dyn_arr[i] << " ";
    }
  }
  //return value at specified index
  A at(int idx) {
    return dyn_arr[idx];
  } 
};

#endif
