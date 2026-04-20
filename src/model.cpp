#include "model.h"
#include<iostream>
#include <cmath>

using namespace std;
int data_size;

void model::train(const vector<vector<double>>& X){
 int n = X.size();
 data_size = n;
 int d = X[0].size();

 weights.assign(d, 0.0);
 bias = 0.0;
double best_loss = 1e9;
int patience = 500;
int wait = 0;
vector<double> best_w;
double best_b;
 
 int epochs = 50000;
  double learning_rate = 0.42;
 for(int epoch = 0;epoch<epochs;epoch++){
   
    
    vector<double> dw(d,0.0);
    double db = 0.0;
    
    


    for(int i=0;i<n;i++){
        double y_pred = bias;

        for(int j = 0;j<d;j++){
            y_pred += weights[j]*X[i][j];
        }

        double y_true = (double)i/n;
        double error = y_pred - y_true;

        for(int j = 0;j<d;j++){
            dw[j] += error*X[i][j];
        }

        db += error;
    }

    for (int j = 0; j < d; j++) {
        dw[j] /= n;
        }
        db /= n;

    


    for(int j = 0;j<d;j++){
        weights[j] -= learning_rate*dw[j];
    }
    bias -= learning_rate*db;

     

    if(epoch%100==0){
        double loss = compute_loss(X);
        cout<<"Epoch"<<epoch<<"Loss:"<<loss<<endl;
    }
    double current_loss = compute_loss(X);

     if (current_loss < best_loss) {
        best_loss = current_loss;
         best_w = weights;
        best_b = bias;
        wait = 0;
    } else {
        wait++;
    }

    if (wait > patience) {
        cout << "Stopping at epoch " << epoch << endl;
        weights = best_w;
        bias = best_b;
        break;
    }
 }
 
}

double model::compute_loss(const vector<vector<double>>& X){
    int n = X.size();
    double loss = 0.0;

    for(int i = 0;i<n;i++){
        double y_pred = bias;

        for(int j = 0;j<weights.size();j++){
            y_pred += weights[j]*X[i][j];
        }

        double error = y_pred - ((double)i/n);
        loss += error*error;


    }
    return loss/n;
}

int model::predict(const vector<double>& x){
    double y_pred = bias;

    for(int j = 0;j<weights.size();j++){
        y_pred += weights[j]*x[j];
    }
    return (int)(y_pred*data_size);
}