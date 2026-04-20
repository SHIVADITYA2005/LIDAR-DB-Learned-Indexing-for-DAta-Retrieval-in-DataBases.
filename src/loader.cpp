#include "loader.h"
#include "database.h"
#include "encoder.h"

#include <fstream>
#include <sstream>
#include <iostream>

void loadata (const string& filename) {
    ifstream file(filename);

    if(!file.is_open()){
        return;
    }

    string line ;

    while(getline(file,line)){
        stringstream ss(line);
        string first,last;
        int id;

        if(!(ss >> first >> last >> id)){
            continue;
        }

        string full_name = first + " " + last;
        vector<double>features = Features(full_name);

        database.push_back({full_name,id,features});
    }
    file.close();

}