#include <iostream>
#include "bst.h"
using namespace std;

int main() {
    BST<int> tree;
    tree.insert(5);
    tree.insert(1);
    tree.insert(3);
    tree.insert(7);
    tree.insert(4);
    Node<int>* ptr = tree.find(1);
    cout << endl;
    tree.inOrderTraversal();
    return 0;
}

/*

5 root
1 l
3 lr
7 r
4 lrr


*/