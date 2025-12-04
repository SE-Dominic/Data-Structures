#ifndef BST_H
#define BST_H

#include <iostream>
using namespace std;

template <typename T>
struct Node {
    T val;
    Node<T>* left;
    Node<T>* right;
    Node(T nVal) {
        this->val = nVal;
        this->left = this->right = nullptr;
    }
};

template <typename T>
class BST {
    private:
        Node<T>* root;
    public:
    BST(): root(nullptr) {}
    ~BST() {} //come back to this

    //helper function for insertion
    Node<T>* insert(Node<T>* curr, T val) {
        if (curr == nullptr) {
           return new Node<T>(val);
        }
        if (val < curr->val) { //take left path if value less than current node
            curr->left = insert(curr->left, val);
        } else {
            curr->right = insert(curr->right, val); //take right path if value less than current node
        }
        return curr;
    }
    //insert function
    void insert(T val) {
        this->root = insert(this->root, val);
    }

    Node<T>* find(Node<T>* rt, T key) {
        if (rt == nullptr || rt->val == key) {
            return rt;
        }
        if (key < rt->val) {
            return find(rt->left, key);
        } else {
            return find(rt->right, key);
        }
    }
    Node<T>* find(T key) {
        return find(this->root, key);
    }
    void displayData(Node<T>* point) {
        if (point != nullptr) {
            displayData(point->left);
            cout << point->val << " ";
            displayData(point->right);
        }
    }
    void inOrderTraversal() {
        displayData(root);
    }

};

//create req. doc: what should be included (why), what should be considered as reqs. , how are they related
//assumptions, environment components
//system as is, system to be, system requirements (assignment 1)
//why (objectives), what (functions needed), how (environment components, software to be)
//process, collection (doc, stackholder, rpl), evaluation, specification
/*
Goal:
    -Fundamentals (concept of goal) 
        - behavior (maintain, achieve)/soft goals (hard to say if it is satisfied, 'minimize', 'maximise')
        - agents (at the bottom)
    -Modeling
        - choose correct architectual patter/style
*/
#endif