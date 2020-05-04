#ifndef DSVECTOR_H
#define DSVECTOR_H
#include <iostream>
template <typename t>
class DSVector {

private:
    t* arr;
    int capacity;
    int size;
    
public:
    DSVector();
    DSVector(const int);
    DSVector(const DSVector<t>&);
    ~DSVector();
    
    t& operator[](const int) const;
    DSVector<t>& operator=(const DSVector<t>&);
    
    int getSize() const;
    int getCapacity() const;
    void resize();
    void push_back(const t);
    void pop_back();
    bool empty();

    bool contains(t);
    
};

//default constructor
template <typename t>
DSVector<t>::DSVector() {
    capacity = 10;
    size = 0;
    arr = new t[capacity];
}

//constructor that takes a capacity as a parameter
template <typename t>
DSVector<t>::DSVector(const int c) {
    capacity = c;
    size = 0;
    arr = new t[capacity];
}

//copy constructor
template <typename t> 
DSVector<t>::DSVector(const DSVector<t>& vect)  {
    capacity = vect.getCapacity();
    size = vect.getSize();
    arr = new t[capacity];
    for (int x = 0; x < size; x++) {
        this->arr[x] = vect[x];
    }
    
}

//overloaded [] operator
template <typename t>
t& DSVector<t>::operator[](const int index) const {
    return arr[index];
}

//overloaded = operator
template <typename t>
DSVector<t>& DSVector<t>::operator=(const DSVector<t>& vect)  {

    this->capacity = vect.getCapacity();
    this->size = vect.getSize();
    delete[] arr;
    this->arr = new t[capacity];
    for (int x = 0; x < size; x++) {
        this->arr[x] = vect[x];
    }
    return *this;
}

//return the size of the vector
template <typename t>
int DSVector<t>::getSize() const{
   return this->size;
}

//return the capacity of the vector
template<typename t>
int DSVector<t>::getCapacity() const {
    return this->capacity;
}

//double the capacity and allocate new memory for it
template <typename t> 
void DSVector<t>::resize() {
    capacity *= 2;
    t* tempArr = new t[capacity];
    for (int x = 0; x < size; x++) {
        tempArr[x] = arr[x];
    }
    delete[] arr;
    arr = tempArr;
}

//push values back into the array
template <typename t>
void DSVector<t>::push_back(const t value) {
    if (this->size == this-> capacity) {
        resize();
    }
    this->arr[size] = value;
    size++;
}

//reduce the size by one
template <typename t>
void DSVector<t>::pop_back() {
    size = size - 1;
}

//check if the array is empty
template <typename t>
bool DSVector<t>::empty() {
    if (size == 0) {
        return true;
    }
    else {
        return false;
    }
}

//deconstructor
template <typename t>
DSVector<t>::~DSVector() {
    delete[] arr;
}

template <typename t>
bool DSVector<t>::contains(t x) {
    bool D4C = false;
    for (int i = 0; i < size; i++) {
        if (arr[i] == x) {
            return true;
        }
    }
    return D4C;
}

#endif // DSVECTOR_H
