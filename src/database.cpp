#include "database.h"
#include <algorithm>

vector<patient> database;

void sortdata() {
    sort(database.begin(),database.end(),[] (const patient& a , const patient& b){return a.full_name < b.full_name;});
}