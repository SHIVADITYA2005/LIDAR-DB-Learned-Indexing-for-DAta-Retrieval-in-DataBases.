#ifndef DATABASE_H
#define DATABASE_H

#include <vector>
#include <string>
using namespace std;

struct patient {
    string full_name;
    int id;
    vector<double> features;
};



void sortdata();

#endif

extern vector <patient> database;