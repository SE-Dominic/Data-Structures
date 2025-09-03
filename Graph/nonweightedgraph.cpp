#ifndef HEADER_FILE_H
#define HEADER_FILE_H
#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Node {
  public:
    T data;
    Node<T>* next;
    Node<T>(): next(nullptr){};
};

template <typename T>
class LinkedList {
  private:
    Node<T>* head;
    unsigned size;
  public:
    LinkedList<T>(): head(nullptr), size(0){}
    ~LinkedList();
    void insert_front(T new_data);
    void insert_at(unsigned idx, T new_data);
    void remove_data(T ex_data);
    void remove_front();
    void remove_end();
    void display();
    unsigned get_size();
    T find(T key);

};

  template <typename T>
  LinkedList<T>::~LinkedList() {
    Node<T>* tmp;
    while (this->head) {
      tmp = this->head->next;
      delete this->head;
      this->head = tmp;
    }
  }
  template <typename T>
  void LinkedList<T>::insert_front(T new_data) {
    Node<T>* ptr = new Node<T>;
    ptr->data = new_data;
    ptr->next = this->head;
    this->head = ptr;
    this->size++;
  }

  template <typename T>
  void LinkedList<T>::display() {
    Node<T>* tmp = this->head;
    while (tmp) {
      cout << tmp->data << " ";
      tmp = tmp->next;
    }
  }

  template <typename T>
  void LinkedList<T>::insert_at(unsigned idx, T new_data) {
    if (idx < 0 || idx > this->size) {
      cout << "Index is out of range." << endl;
      return;
    }
    Node<T>* newNode = new Node<T>;
    newNode->data = new_data;
    newNode->next = nullptr;
    //insert at head
    if (idx == 0) {
      this->head = newNode;
    }
    //traverse index
    Node<T>* tmp = this->head;
    for(unsigned counter = 0; counter < idx - 1; counter++) {
      //increment and push pointer
      tmp = tmp->next;
    }
    newNode->next = tmp->next;
    tmp->next = newNode;
    size++;
  }

template <typename T>
class Graph {
  int numV;
  LinkedList<T>* V;
public:
  Graph(int vertices) {
    numV = vertices;
    V = new LinkedList<T>[numV]; /*->array of linked list objects*/
/*int arr = new int[numV]; <-- this is how a regular dynamic array looks */
  }

~Graph() {
    delete[] V;
}
//index of array (to know what is adjacent, value to be inputted)
  void addEdge(int idx, T new_data) {
    if (idx < 0 || idx > numV) {
      cout << "Cannot input " << new_data << " at " << idx << " because it is out of range." << endl;
      return;
    }
    V[idx].insert_front(new_data); //insert to list to show what is next to it
  }
  void printGraph() {
    for (int i = 0; i < numV; i++) {
      V[i].display();
      cout << endl;
    }
  }
};

#endif
