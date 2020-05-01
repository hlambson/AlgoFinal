//
// Created by henry on 4/29/2020.
//

#ifndef FINAL_SALSEMAN_H
#define FINAL_SALSEMAN_H
#include "AdjacencyList.h"
#include "edge.h"
using namespace std;

class salesman {
private:
    AdjacencyList<string, node> map;
public:
    salesman();
    void readIn(string);
    void trivial(string);
    void nearestNeighbor(string);
};


#endif //FINAL_SALSEMAN_H
