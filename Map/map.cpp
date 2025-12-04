#include <iostream>
#include "map.h"
using namespace std;


int main() {
  Map<string, int> mp(10);
  mp.put("Dominic", 21);
  mp.put("Angela", 42);
  mp.put("Alan", 12);
  mp.put("Jenna", 19);
  cout << "Display map #1:\n";
  mp.displayMap();
  //mp.remove("Jenna");
  cout << "Display map #2:\n";
  mp.displayMap();
  cout << "Size: " << mp.getNumElements() << endl;
  cout << "Capacity: " << mp.getCapacity() << endl;
  return 0;
}
