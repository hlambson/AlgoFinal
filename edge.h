//
// Created by henry on 3/4/2020.
//

#ifndef PROGRAM2_EDGE_H
#define PROGRAM2_EDGE_H
#include <string>
using namespace std;

class edge {
private:
    string name1;
    string name2;
    int distance;
    double weight;
    double betweenness;
public:
    edge();
    edge(string,string);
    string getName1();
    string getName2();
    int getDistance();
    double getWeight();
    double getBetweenness();
    void setWeight(double);
    void setBetweenness(double);
    void setN1(string);
    void setN2(string);
    bool operator!=(edge&);
    bool operator==(edge&);
    bool operator<(edge&);
};


#endif //PROGRAM2_EDGE_H
