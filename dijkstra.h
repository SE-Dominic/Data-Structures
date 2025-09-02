/*****************************************************
Kazumi Slott
CS311
Homework on Dijkstra's algorithm

4-19-2024

This file contains code used for Dijkstra's algorithm.
This implementation is least invasive to the graph and min heap classes.

Min heap has a struct. In min heap class, maintain the property
using distance by operator overloaded func.
******************************************************/
#include <iostream>
#include "minHeap.h"
#include "graph.h"
#include <stack>
using namespace std;
//???????? include your min heap class. It will be used in Dijkstra's algorithm
//???????? include  your graph class. You will pass a graph to Dijkstra's algorithm

//Each vertex has a vertex number, current shortest distance and predecessor
struct vertex
{
  int vertexNum; //the vertex number
  int curDist; //the current shortest distance from start to the vertex 
  int predecessor; //the predecessor along the shortest path to the vertex
};

int* locator; ///tells where each vertex exists within the heap. The dynamic array pointed to by this pointer will be created inside dijkstraSHortestPath() down below
//e.g. vertex numbers in heap[3, 1, 2, 4, 0] vertex 3 is at the root because its curDist is the smallest
//     locator should look like this [4, 1, 2, 0, 3] vertex 3 can be found at 0. vertex 0 can be found at 4 in heap
//This is a global variable (sounds terrible), but that is ok for this application. The reason why it is declared global is that it is accessed from mySwap() down below. mySwap() is called from the min heap class. We are not passing locator to the min heap class.


//this will be called from the min heap class. Each element in the heap is a vertex which consists of vertexNum, curDist and predecessor.
//The heap is maintained by curDist. 
bool operator<(const vertex& v1, const vertex& v2)
{
  //compare the curDistances of v1 and v2
  if (v1.curDist < v2.curDist) {
    return true;
  }
  return false;
}

//this will be called from the min heap class
bool operator>(const vertex& v1, const vertex& v2)
{
  //compare the curDistances of v1 and v2
  if (v1.curDist > v2.curDist) {
    return true;
  }
  return false;
}

bool operator<=(const vertex& v1, const vertex& v2) {
  if (v1.curDist <= v2.curDist) {
    return true;
  }
  return false;
}

bool operator>=(const vertex& v1, const vertex& v2) {
  if (v1.curDist >= v2.curDist) {
    return true;
  }
  return false;
}
//If you are comparing 2 elements using >= or <= in your min heap class, you will need to make those operator overloaded functions as well.

//this will be called from your min heap class.
void mySwap(vertex& v1, vertex& v2)
{
  //swap 2 vertices
  vertex v_temp;
  v_temp = v1;
  v1 = v2;
  v2 = v_temp;
  
  
  //Throughout this template, one line of ?s doesn't mean you can only have 1 statement. You can have multiple statmenets.
  //the locations of the 2 vertices need to be swapped as well.  locator is a global pointer declared above
  //????????
}

//This will be called from printHeapArrays() down below. printHeapArrays() should be used for debugging your code. 
ostream& operator<<(ostream& o, const vertex& v)
{
  //output the 3 values of the vertex, v.  You could Output them in this format [vertexNum, curDist, predecessor]
  o << "Vertex Number: " << v.vertexNum << endl;
  o << "Current Distance: " << v.curDist << endl;
  o << "Predecessor: " << v.predecessor << endl;
  return o;
}

//print the min heap and locator array for debugging
//num_ver is the total number of vertces.
void printHeapArrays(const minHeap<vertex>& h, const int* locator, int num_ver)
{
  //This functions is complete. 
  cout << "----- heap ------" << endl;
  cout << h << endl; //operator<<() in min heap class is called here, which calls operator<<(ostream, vertex) above

  cout << "----- locator ------" << endl;
  for(int i = 0; i < num_ver; i++)                                                                                          
    cout << locator[i] << " ";                                                                                               
  cout << endl;
}

//This function will show the path from stat to destination
//MH is the min heap which contains the vertexNum, curDist and precessor of all the vertices created by Dijkstra's algorithm
//start is the start vertex. Dijkstra's algorithm calculated the shortest distance from start to every other vertex
//This function shows the shortest path from start to destination in the following format.
//  The shortest path from 3 to 5 is 3 0 4 5
//  The distance is 8
void showShortestDistance(const minHeap<vertex>& MH, int start)
{
  //******  COMPLETE this function  ******
  int dest; //destination			
  locator = new int[MH.getNum()];
  cout << "Enter the destination: ";
  cin >> dest;

  stack<int> path;
  int curr = dest;
  while (curr != start) {
    path.push(curr);
    int idx = locator[curr];
    curr = MH.getHeap()[idx].predecessor;
  }
  path.push(start);
  //trace the shortest path from dest back to start
  //I suggest you use either library's stack or queue. Which one will work?
  
  cout << "The shortest path from " << start << " to " << dest << " is ";
  while (!path.empty()) {
    cout << path.top();
    path.pop();
    if (!path.empty()) {
      cout << "->";
    }
  }

  int dest_index = locator[dest];


  cout << "\nThe distance is " << MH.getHeap()[dest_index].curDist << endl;
}

//Dijkstra's shortest path algorithm - generating a table that contains the shortest distance from start to every other vertex and the predecessor of each vertex.
//g is a graph. We will pass the graph created in our client file.
//start is the start vertex.
void DijkstraShortestPath(const graph& g, int start)
{
  /*
  minHeap<??????> ????????; //Create a min heap of the data type, vertex.
  */

  
  /*
  //The following for loop populates the min heap with all the vertices. Set curDist to 999 and predecessor to -1.
  //e.g. vertex for vertext number 0 should like this [0, 999, -1]
  //     vertex for vertext number 1 should like this [1, 999, -1]
  vertex ver; //temp vertext struct used for multiple purposes 
  for (int i = 0; i < ?????; i++)
    {
      //fill ver (declared above) with 3 values
      //call minHeap::insert() to insert each vertex
    }
  */

  
  /*
  ????????? //Create a dynamic array pointed to by locator, which is declared globally above.
  //locator is an array containing the location of each vertex in the heap
  //locator[0] always tells the location/index of vertex 0 in the heap. If the locator looks like [3, 0, 1, 2], vertex 0 is located at index 3 in the heap, veertex 1 is located at index 0 (meaning vertex 1 has the minimum distance).
  */
  
  /*
  ????????? //You need to initialize the locator array. To start with, locator array should look like this [0, 1, 2, 3, 4, ...] telling us vertex 0 is at index 0 in the heap, vertex 1 is at index 1
  */
  
 
  /*
  //fill ver (declared above) with start, 0 and -1. start vertex should have 0 for curDist and -1 for predecessor
  //If start is 3, ver should look like [3, 0, -1] 
  ver.vertexNum = ?????
  ver.curDist = ????
  ver.predecessor = ????
  //call minHeap::updateElem() to update the start vertex's info
  ??????????
  //the updateElem() will update the info at index i (first parameter). 
  //updateElem() will fix the min heap based on curDist starting at i.
  //Since this start vertex has 0 for curDist and the other vertices have 999 for curDist,
  //this start vertex should come up to the top
  */

  /*
  //******** Follow Dijkstra's algorithm in the lecture notes and complete the following ***********
  
  //Use printHeapArrays() for debugging
  
  //After Dijkstra's algorithm is finished, call showShortestDistance() above to show the path and distance from start and destination
  
  //Don't forget to destroy the dynamic array you made for locator
  */  
}


