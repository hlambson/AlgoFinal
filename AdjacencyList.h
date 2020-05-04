//
// Created by henry on 2/25/2020.
//

#ifndef PROGRAM2_ADJACENCYLIST_H
#define PROGRAM2_ADJACENCYLIST_H
#include <unordered_map>
#include <iostream>
#include "storage.h"
using namespace std;
template<typename T, typename U>
class AdjacencyList {
private:
    unordered_map<T,storage<U>> map;
    int size;
public:
    AdjacencyList();
    ~AdjacencyList();
    AdjacencyList(const AdjacencyList<T,U>&);
    AdjacencyList<T,U>& operator=(const AdjacencyList<T,U>&);
    unordered_map<T,U>& getMap();
    void insert(T, storage<U>&);
    typename unordered_map<T,storage<U>>::iterator find(T);
    int getSize();
};

//default constructor
template<typename T, typename U>
AdjacencyList<T,U>::AdjacencyList() {
    size = 0;
}

//destructor
template<typename T, typename U>
AdjacencyList<T,U>::~AdjacencyList() {
    map.clear();
}

//copy constructor
template<typename T, typename U>
AdjacencyList<T,U>::AdjacencyList(const AdjacencyList<T, U>& a) {
    this->map = a.getMap();
}

//overloaded assignment operator
template<typename T, typename U>
AdjacencyList<T, U> & AdjacencyList<T,U>::operator=(const AdjacencyList<T, U> & a) {
    this->map = a.getMap();
}

//gets the hash table
template<typename T, typename U>
unordered_map<T,U>& AdjacencyList<T,U>::getMap() {
    return map;
}

//inserts a pair into the hash table
template<typename T, typename U>
void AdjacencyList<T,U>::insert(T key, storage<U>& val) {
    bool check = false;
    for (pair<T,storage<U>> element : map) {
        if (key == element.first) {
            check = true;
            typename unordered_map<T,storage<U>>::iterator tempItr = map.find(key);

            tempItr->second.addConnection(val.getConnections()[0]);
        }
    }
    if (check == false) {
        if (val.getConnections().empty()) {
            storage<U> tempObj(key);
            pair<T, storage<U>> temp(key, tempObj);
            map.insert(temp);
        }
        else {
            storage<U> tempObj(key, val.getConnections()[0]);
            tempObj.setWeight(val.getWeight());
            pair<T, storage<U>> temp(key, tempObj);
            map.insert(temp);
    }
        size++;
    }
}

//returns an iterator to the node asked for
template<typename T, typename U>
typename unordered_map<T,storage<U>>::iterator AdjacencyList<T,U>::find(T key) {
    typename unordered_map<T,storage<U>>::iterator tempItr = map.find(key);
    storage<U> test = tempItr->second;
    if (tempItr == map.end()) {
        cout << "error, could not find that key" << endl;
        exit(-1);
    }
    return tempItr;
}

template<typename T, typename U>
int AdjacencyList<T,U>::getSize() {
    return size;
}


#endif //PROGRAM2_ADJACENCYLIST_H
