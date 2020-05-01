//
// Created by henry on 4/29/2020.
//

#include "salseman.h"
#include "fstream"
salesman::salesman() {

}

void salesman::readIn(string f) {
    ifstream file;
    file.open(f);
    if (!file.is_open()) {
        cout << "graph file didnt open" << endl;
    }
    char* buffer = new char[10];
    file.getline(buffer,10);
    int num = atoi(buffer);
    int x = 0;
    string line;
    string line2;
    while(x < num) {
       file >> line;
       file >> line2;
       file >> line2;
       node obj(line2);
       node obj2(line);

       file.getline(buffer, 10);
       double weight;
       weight = atoi(buffer);
       obj.setWeight(weight);
       storage<node> temp(line,obj);
       map.insert(line,temp);
       obj2.setWeight(weight);
       storage<node> temp2(line2,obj2);
       map.insert(line2,temp2);
       x ++;
    }
}
