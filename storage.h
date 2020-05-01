//
// Created by henry on 2/26/2020.
//

#ifndef PROGRAM2_STORAGE_H
#define PROGRAM2_STORAGE_H
#include <vector>
#include <string>
#include "node.h"

using namespace std;
template<typename T>
class storage {
private:
    string name;
    vector<T> connections;
    double weight;
public:
    storage();
    storage(string, T);
    storage(string);
    string& getName();
    vector<T>& getConnections();
    double& getWeight();
    void setWeight(double);
    void addConnection(T);

};
template<typename T>
storage<T>::storage() {
    weight = 0;
}

template<typename T>
storage<T>::storage(string n, T val) {
    name = n;
    connections.push_back(val);
    weight = 0;
}

template <typename T>
storage<T>::storage(string n) {
    name = n;
}

template<typename T>
string& storage<T>::getName() {
    return name;
}

template<typename T>
vector<T>& storage<T>::getConnections()  {
    return connections;
}

template<typename T>
void storage<T>::addConnection(T val)  {
    connections.push_back(val);
}

template<typename T>
double& storage<T>::getWeight() {
    return weight;
}

template<typename T>
void storage<T>::setWeight(double w) {
    weight = w;
}


#endif //PROGRAM2_STORAGE_H
