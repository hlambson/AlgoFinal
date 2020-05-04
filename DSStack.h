//
// Created by henry on 5/3/2020.
//

#ifndef STACK_H
#define STACK_H
#include "dsvector.h"
template <typename T>
class DSStack {
private:
    DSVector<T> data;
    int size;
public:
    DSStack();
    DSStack(const DSStack<T>&);
    ~DSStack();
    DSStack<T>& operator=(const DSStack<T>&);
    bool operator==(DSStack<T>&);

    void push(const T&);
    void pop();
    T peek();
    bool isEmpty();
    int getSize();
    DSVector<T> getData();

    bool contains(const T);
};

//default constructor
template <typename T>
DSStack<T>::DSStack() {
    data;
    size = 0;
}

//copy constructor
template <typename T>
DSStack<T>::DSStack(const DSStack<T>& c) {
    this->data = c.data;
    this->size = c.size;
}

template <typename T>
DSStack<T>& DSStack<T>::operator=(const DSStack<T>& c) {
    this->data = c.data;
    this->size = c.size;
    return *this;
}

template <typename T>
bool DSStack<T>::operator==(DSStack<T> & s) {
    if (s.getSize() != data.getSize()) {
        return false;
    }
    else {
        for (int x = 0; x < data.getSize(); x++) {
            if (data[x] != s.getData()[x]) {
                return false;
            }
        }
        return true;
    }
}


//destrutor
template <typename T>
DSStack<T>::~DSStack() {

}

//push a value onto the stack
template <typename T>
void DSStack<T>::push(const T& x) {
    data.push_back(x);
    size ++;
}

//pop the last value added off the stack
template <typename T>
void DSStack<T>::pop() {
    data.pop_back();
    size --;
}

//look at the value at the top of the stack
template <typename T>
T DSStack<T>::peek() {
    return data[size - 1];
}

//check if the stack is empty
template <typename T>
bool DSStack<T>::isEmpty() {
    return data.empty();
}

//return the size of the stack
template <typename T>
int DSStack<T>::getSize() {
    return size;
}

//check if a value is in the stack
template <typename T>
bool DSStack<T>::contains(const T x) {
    return data.contains(x);
}
template <typename T>
DSVector<T> DSStack<T>::getData() {
    return data;
}
#endif // STACK_H
