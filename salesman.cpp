//
// Created by henry on 4/29/2020.
//

#include "salseman.h"
#include "fstream"
#include "DSStack.h"
#include <stack>
#include <cstring>

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
       node obj(line);
       node obj2(line2);

       file.getline(buffer, 10);
       double weight;
       weight = atoi(buffer);
       obj.setWeight(weight);
       obj2.setWeight(weight);
       storage<node> temp(line,obj2);
       map.insert(line,temp);

       storage<node> temp2(line2,obj);
       map.insert(line2,temp2);
       bool check1 = false;
       bool check2 = false;
       for (int y = 0; y < nodes.size(); y++) {
           if (nodes[y].getName() == line) {
               check1 = true;
           }
           if (nodes[y].getName() == line2) {
               check2 = true;
           }
       }
       if (check1 == false) {
           nodes.push_back(obj);
       }
       if (check2 == false) {
           nodes.push_back(obj2);
       }
       x ++;
    }
}

void salesman::trivial(string start) {
    DSStack<string> path;
    DSVector<DSStack<string>> allPaths; //im using these because they have contains functions lol
    stack<string> another;
    vector<int> allWeights;
    int weight = 0;
    int tempWeight;
    path.push(start);
    another.push(start);
    auto itr = map.find(start);
    int num = map.getSize();
    while(!path.isEmpty()) {
        bool check = true;
        for (int x = 0; x < itr->second.getConnections().size(); x++) {
            if (!path.contains(itr->second.getConnections()[x].getName()) && check == true) {
                path.push(itr->second.getConnections()[x].getName());
                another.push(itr->second.getConnections()[x].getName());
                weight += itr->second.getConnections()[x].getWeight();
                tempWeight = itr->second.getConnections()[x].getWeight();
                check = false;
            }
        }
        if (check == true) {
            path.pop();
            another.pop();
            weight -= tempWeight;
            itr = map.find(path.peek());
        }
        else {
            if (path.getSize() == num) {
                if (!allPaths.contains(path)) {
                    int index = 0;
                    for (int i = 0; i < itr->second.getConnections().size(); i++) {
                        if(strcmp(itr->second.getConnections()[i].getName().c_str(), start.c_str()) == 0) {
                            path.push(start);
                            another.push(start);
                            index = i;
                            weight += itr->second.getConnections()[i].getWeight();
                        }
                    }
                    allPaths.push_back(path);
                    allWeights.push_back(weight);
                    path.pop();
                    another.pop();
                    weight -= itr->second.getConnections()[index].getWeight();
                }
                path.pop();
                another.pop();
                weight -= tempWeight;

            }
            itr = map.find(path.peek());
        }

    }
    cout << "done" << endl;
}

void salesman::nearestNeighbor(string start) {
    auto itr = map.find(start);
    storage<node> test;
    test = itr->second;
    int num = map.getSize();
    for (int x = 0; x < nodes.size(); x++) {
        if (nodes[x].getName() == start) {
            nodes[x].setVisited(1);
        }
        else {
            nodes[x].setVisited(0);
        }
    }
    vector<string> path;
    path.push_back(start);
    double total = 0;
    while(path.size() < num) {
        test = itr->second;
        double min = itr->second.getConnections()[0].getWeight();
        int index = 0;
        int index2;
        int counter = 0;
        for (int x = 0; x < nodes.size(); x++) {
            if (strcmp(nodes[x].getName().c_str(), test.getConnections()[counter].getName().c_str()) == 0) {
                if (nodes[x].getVisited() != 0) {
                    counter ++;
                    min = itr->second.getConnections()[counter].getWeight();
                    x = 0;
                }
                else {
                    index2 = x;
                }
            }
        }

        for(int x = 0; x < itr->second.getConnections().size(); x++) {
            if (itr->second.getConnections()[x].getWeight() < min) {
                bool check = false;
                for (int y = 0; y < nodes.size(); y++) {
                    if (strcmp(nodes[y].getName().c_str(),itr->second.getConnections()[x].getName().c_str()) == 0 && nodes[y].getVisited() == 0) {
                        check = true;
                        index2 = y;
                    }
                }
                if (check == true) {
                    min = itr->second.getConnections()[x].getWeight();
                    index = x;
                }
            }
        }
        if (path.size() == num -1) {
            path.push_back(itr->second.getConnections()[counter].getName().c_str());
            total += itr->second.getConnections()[counter].getWeight();
            itr = map.find(itr->second.getConnections()[counter].getName());
        }
        else {
            path.push_back(itr->second.getConnections()[index].getName().c_str());

            nodes[index2].setVisited(1);
            total += itr->second.getConnections()[index].getWeight();
            itr = map.find(itr->second.getConnections()[index].getName());
        }
    }

    test = itr->second;
    for (int x = 0; x < itr->second.getConnections().size(); x++) {
        if (strcmp(itr->second.getConnections()[x].getName().c_str(),start.c_str()) == 0) {
            total += itr->second.getConnections()[x].getWeight();
        }
    }
    path.push_back(start.c_str());
    for (int x = 0; x < path.size(); x++) {
        cout << path[x] << endl;
    }
    cout << total << endl;
}
