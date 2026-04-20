#include "encoder.h"
#include <cmath>

vector<double>Features(const string& s){
 vector<double> fet;
  double feature_val = 0.0;
    
   
    int len = min(5, (int)s.size()); 
    for(int i = 0; i < len; i++) {
        double char_val = (tolower(s[i]) - 'a');
        feature_val += char_val / pow(26.0, i + 1); 
    }

    
    fet.push_back(feature_val);                 
    fet.push_back(pow(feature_val, 2)*2);         
    fet.push_back(pow(feature_val, 3)*5);         
    fet.push_back(pow(feature_val, 4)*10);         
    
    return fet;
}
    