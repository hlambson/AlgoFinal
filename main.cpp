//
// Created by henry on 4/29/2020.
//
#include "salseman.h"
#include "chrono"
using namespace std;

int main() {
    salesman test;
    std::chrono::time_point<std::chrono::system_clock> start;
    std::chrono::time_point<std::chrono::system_clock> end;

    test.readIn("g1.txt");

    start = std::chrono::system_clock::now();
    test.nearestNeighbor("A");
    end = chrono::system_clock::now();

    cout << chrono::duration_cast<chrono::microseconds>(end - start).count() << endl;

    start = std::chrono::system_clock::now();
    test.trivial("A");
    end = chrono::system_clock::now();
    cout << chrono::duration_cast<chrono::microseconds>(end - start).count() << endl;
    return 0;
}
