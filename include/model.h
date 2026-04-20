#pragma once
#include <vector>
using namespace std;

class model {
    public :
        vector<double> weights;
        double bias;

        void train(const vector<vector<double>>& X);
        double compute_loss(const vector<vector<double>>& X);
        int predict(const vector<double>& x);
};
