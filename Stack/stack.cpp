#ifndef HEADFILE_H
#define HEADFILE_H
#include <iostream>
using namespace std;

template <typename T>
class Node {
public:
  T data;
  Node<T>* next;
  Node<T>(): next(nullptr){}
};

template <typename T>
class Stack {
private:
  Node<T>* top;
  unsigned size;
public:
  Stack(): top(nullptr), size(0){}
  ~Stack();

  void push(T newData);
  void pop();
  T peek();
  unsigned getSize();
  void display();
};

template <typename T>
void Stack<T>::push(T newData) {
  Node<T>* ptr = new Node<T>;
  ptr->data = newData;
  ptr->next = this->top;
  top = ptr;
  this->size++;
}

template <typename T>
T Stack<T>::peek() {
  return this->top->data;
}

template <typename T>
void Stack<T>::pop() {
  Node<T>* tmp = this->top->next;
  delete this->top;
  top = tmp;
  this->size--;
}

template <typename T>
unsigned Stack<T>::getSize() {
  return this->size;
}

template <typename T>
void Stack<T>::display() {
  Node<T>* view = this->top;
  cout << "--top of stack--" << endl;
  while (view) {
    cout << view->data << endl;
    view = view->next;
  }
  cout << "--end of stack--" << endl;
}

template <typename T>
Stack<T>::~Stack() {
  Node<T>* temp = this->top;
  while (temp) {
    Node<T>* next_ = temp->next;
    delete temp;
    temp = next_;
  }
}
#endif
