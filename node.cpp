//
// Created by henry on 3/2/2020.
//

#include "node.h"
node::node() {
    val = 0;
    num = 0;
    weight = 0;
}

node::node(string n) {
    name = n;
    val = 0;
    num = 0;
    weight = 0;
}

string& node::getName() {
    return name;
}

string& node::getPrevious() {
    return previous;
}

void node::setPrevious(string p) {
    previous = p;
}


int& node::getVal() {
    return val;
}

void node::setVal(int v) {
    val = v;
}

int& node::getDistance() {
    return distance;
}

void node::setDistance(int d) {
    distance = d;
}

int& node::getNum() {
    return num;
}

void node::setNum(int n) {
    if (n == 0) {
        num = n;
    }
    else {
        num += n;
    }
}

int& node::getChildren() {
    return children;
}

void node::setChildren(int c) {
    children = c;
}

double& node::getWeight() {
    return weight;
}

void node::setWeight(double w) {
    weight = w;
}

int& node::getVisited() {
    return visited;
}

void node::setVisited(int v) {
    visited = v;
}

node& node::operator=(const node& n) {
    this->name = n.name;
    this->val = n.val;
    this->distance = n.distance;
    this->num = n.num;
    return *this;
}

bool node::operator<(const node & n) {
    if (this->distance < n.distance) {
        return true;
    }
    else {
        return false;
    }
}

bool node::operator>(const node& n) {
    if (this->distance > n.distance) {
        return true;
    }
    else {
        return false;
    }

}


