//
// Created by henry on 3/2/2020.
//

#ifndef PROGRAM2_NODE_H
#define PROGRAM2_NODE_H

#include <string>

using namespace std;

class node {
private:
    string name;
    int val;
    int distance;
    string previous;
    int num;
    int children;
    double weight;
    int visited;
public:
    node();
    node(string);
    string& getName();
    string& getPrevious();
    void setPrevious(string);
    int& getVal();
    void setVal(int);
    int& getDistance();
    void setDistance(int);
    double& getWeight();
    void setWeight(double);
    int& getNum();
    void setNum(int);
    int& getChildren();
    void setChildren(int);
    int& getVisited();
    void setVisited(int);
    node& operator= (const node&);
    bool operator> (const node&);
    bool operator< (const node&);

};


#endif //PROGRAM2_NODE_H
