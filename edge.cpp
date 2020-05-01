//
// Created by henry on 3/4/2020.
//

#include "edge.h"

edge::edge() {

}


edge::edge(string n, string n2) {
    name1 = n;
    name2 = n2;
    distance = 0;
    betweenness = 0;
}

string edge::getName1() {
    return name1;
}

int edge::getDistance() {
    return distance;
}

double edge::getBetweenness() {
    return betweenness;
}

double edge::getWeight() {
    return weight;
}

void edge::setBetweenness(double b) {
    if (b == 0) {
        betweenness = 0;
    }
    else {
        betweenness += b;
    }
}

void edge::setWeight(double w) {
    weight = w;
}

string edge::getName2() {
    return name2;
}

void edge::setN2(string n) {
    name2 = n;
}

void edge::setN1(string n) {
    name1 = n;
}

bool edge::operator!=(edge& e) {
    if (this->name1 == e.getName1() && this->name2 == e.getName2()) {
        return false;
    }
    else {
        return true;
    }
}

bool edge::operator==(edge& e) {
    if (this->name1 == e.getName1() && this->name2 == e.getName2()) {
        return true;
    }
    else {
        return false;
    }
}

bool edge::operator<(edge & e) {
    if (this->weight < e.getWeight()) {
        return true;
    }
    else {
        return false;
    }
}
