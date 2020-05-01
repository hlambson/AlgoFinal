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

void salesman::trivial(string start) {

}

void salesman::nearestNeighbor(string start) {
    auto itr = map.find(start);
    int num = map.getSize();

    vector<string> path;
    path.push_back(start);
    double total = 0;
    while(path.size() < num) {
        double min = itr->second.getConnections()[0].getWeight();
        int index = 0;
        for(int x = 0; x < itr->second.getConnections().size(); x++) {
            if (itr->second.getConnections()[x].getWeight() < min) {
                min = itr->second.getConnections()[x].getWeight();
                index = x;
            }
        }
        path.push_back(itr->second.getConnections()[index].getName());
        total += itr->second.getConnections()[index].getWeight();
        itr = map.find(itr->second.getConnections()[index].getName());
    }

    for (int x = 0; x < itr->second.getConnections().size(); x++) {
        if (itr->second.getConnections()[x].getName() == start) {
            total += itr->second.getConnections()[x].getWeight();
        }
    }
    path.push_back(start);
}
