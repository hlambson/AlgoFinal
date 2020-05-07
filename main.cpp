//
// Created by henry on 4/29/2020.
//
#include "salseman.h"
using namespace std;

int main() {
    salesman test;
    test.readIn("g1.txt");
  test.nearestNeighbor("A");
  //test.trivial("A");
    return 0;
}
