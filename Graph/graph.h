/****************************
Templated created by Kazumi Slott
CS311

Your name: Dominic Allen
Your programmer number: 1
*****************************/
#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <queue>
#include <list>
using namespace std;

class edge
{
  friend class graph;  //What do you need here if you want to access the private members of edge class from graph class
  int neighbor; //adjacent vertex
  int wt; //weight of the edge
 public:
  edge() { neighbor = -999, wt = -999;};
  edge(int u, int w) {
    neighbor = u; //u = adjacent vertex
    wt = w;
  };
  int getNeighbor() const {
    return this->neighbor;
  }
  int getWt() const {
    return this->wt;
  }
};

class graph
{
  int num_ver; //the total number of vertices in the graph
  list<edge*>* ver_ar; //pointer to the dynamic array that holds linked lists. The element of a node in a linked list is a pointer to an edge object 
                       //Let's use the library's list class. It is actually a doubly linked list. 
  int nextUnvisitedNodes(int* num, int start, int s);
  void DFT_helper(int v, int& i, int* num, queue<string>& q);
 public:
  graph(int V);
  ~graph();
  void addEdge(int v, int u, int w=1);  //If the weight is not given, 1 is used for wt.
  void BFT(int start);
  void DFT(int start);
  int getNumVer() const {
    return this->num_ver;
  }
  list<edge*>* getVerAr() const {
    return this->ver_ar;
  }
};

//constructor: num is the number of vertices
graph::graph(int num)
{
  //The element of a node in the linked list is a pointer to an edge object 
  num_ver = num; //num of vertices put into constructor variable
  ver_ar = new list<edge*>[num]; //dynamc array of linked lists which hold edge pointers 
}

graph::~graph()
{
  //destroy all the edge objects created in heap
  for(int i = 0; i < num_ver; i++) {
    for (edge* e : ver_ar[i]) {
      delete e;
    }
  }
  delete [] ver_ar;
  //For each vertex in ver_ar
  //    go through each node in the linked list. The element field of each node points to an edge object created with "new". You need to delete these.  

  //The library's list class has a destructor. All nodes belonging to the list will be destroyed by the destructor.
  //https://www.cplusplus.com/reference/list/list/~list/
  //destroy the ver_ar dynamic array
}


//add an edge from v to u with weight w into the graph
void graph::addEdge(int v, int u, int w)
{
  //We are using the list class from the library. Which member function do you need to use to add a node at the end of the list?
  this->ver_ar[v].push_back(new edge(u, w));
  //https://www.cplusplus.com/reference/list/list/
  //Don't create an edge object statically, then it would get destroyed as soon as you leave this function. You need to create an edge object dymamically in heap, which will remain in heap even after you leave this function.. Remember "new" operator returns the memory address of the newly created object.
  //I have one line of code in this function.
}

//I decided to make this function a stand alone function. It doesn't have anything to do with the graph class.                                
template<class T>
void displayQueue(queue<T>& q)
{
  while(!q.empty())
    {
      cout << q.front() << ",";
      q.pop();
    }
}

//start Traversal at start
void graph::DFT(int start)
{ 
  int* n = new int[num_ver]();
  int i = 1;
  queue<string> q;
  int s = start;
  do {
    if (n[s] == 0) {
      DFT_helper(s, i, n, q);
    }
    s = nextUnvisitedNodes(n, start, s + 1);
  } while (s != -1);
  displayQueue(q);
  //Don't forget to destroy the dynamic array
  delete[] n;
}
                                                                      
int graph::nextUnvisitedNodes(int* num, int start, int s)
{
  //go through the num array from s to see if you find a vertext with num=0. If so, return the index. If all visited, return -1.
  //don't start from index 0!
  //Althought this function may be called multiple times because there may be multiple disconnected graphs, we are checking each vertex only once.
  for(int i = s; i < num_ver; i++) {
    if (num[i] == 0) {
      return i; //found unvisited vertex
    }
  }
  return -1; //all vertices have been visited
}

void graph::DFT_helper(int v, int& i, int* num, queue<string>& q)
{
  //The algorithm is in my lecture notes

  //The following shows how to iterate the library's linked list. You use an iterator.
  //https://www.cplusplus.com/reference/list/list/end/ 
  //iterator class is nested inside list class
  num[v] = i++;
  for (list<edge*>::iterator u = ver_ar[v].begin(); u != ver_ar[v].end(); u++)
    {
      //From the example on https://www.cplusplus.com/reference/list/list/end/
      //Notice *u gives you the element of the node pointed to by u. The element is a pointer to an edge object.
      //Between * and -> operator, -> has higher precedence. You need to use () around *u to get the element first.  
      int n = (*u)->neighbor;
      //push each path e.g. 0->1 into q. to_string(int) converts int to string. 
      //to_string() is in c++11, so compile with the option. g++ -std=c++11 graphClient.cpp 
      q.push(to_string(v) + "->" + to_string((*u)->neighbor));
      if (num[n] == 0) {
	DFT_helper(n, i, num, q);
      }
    }

  /***********************************************************************************************
   **********************************************************************************************
    Compile with a c++11 option if you are using to_string()
        g++ -std=c++11 graphClient.cpp 
   **********************************************************************************************
   ***********************************************************************************************/
}

//start is the index for the start vertex
void graph::BFT(int start)
{
  //The algorithm is in my lecture notes
  int* num = new int[num_ver]();  // num[i] = 0 means unvisited
    int i = 1;

    queue<int> q;

    // Handle disconnected graphs
    for (int v = start; v < num_ver; ++v) {
        if (num[v] == 0) {
            num[v] = i++;
            q.push(v);

            while (!q.empty()) {
                int current = q.front();
                q.pop();
                cout << "Visited vertex: " << current << endl;

                for (edge* e : ver_ar[current]) {
                    int u = e->neighbor;
                    if (num[u] == 0) {
                        num[u] = i++;
                        q.push(u);
                        cout << "Tree edge: (" << current << ", " << u << ")" << endl;
                    }
                }
            }
        }
    }

    delete[] num;
}

#endif
