#include <iostream>
#include "loader.h"
#include "encoder.h"
#include "database.h"
#include "model.h"

int learned_search(const string& target_name, int max_error,model& trained_mod) {
    

    vector<double> fet = Features(target_name);
    int pred = trained_mod.predict(fet);
    
    
    int left = max(0, pred - max_error);
    int right = min((int)database.size() - 1, pred + max_error);
    
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (database[mid].full_name == target_name) {
            return mid; 
        }
        if (database[mid].full_name < target_name) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1; 
}

int main() {
    loadata("dataset.txt");
    cout<<"Loaded data"<<database.size()<<endl;

    sortdata();

    vector<vector<double>> X;

    for(auto &p: database){
        X.push_back(p.features);
    }

    model mod;
    mod.train(X);
    mod.compute_loss(X);
    
    for(int i = 0; i < 10; i++){
    int pred = mod.predict(database[i].features);

    cout << "Actual: " << i
         << " Pred: " << pred << endl;
}

// ... (Your training loop finishes here) ...

   
    cout << "\n--- CALCULATING TRUE ERROR BOUNDS ---\n";
int max_error = 0;

for (int i = 0; i < (int)database.size(); i++) {
    vector<double> fet = Features(database[i].full_name);
    int pred = mod.predict(fet);
    
    
    int current_error = abs(pred - i); 
    
    if (current_error > max_error) {
        max_error = current_error;
    }
}

max_error += 10; // Safety buffer
cout << "Model's TRUE maximum error bound is: +-" << max_error << endl;
    

    max_error += 10; 
    cout << "Model's maximum error bound is: +-" << max_error << endl;

    cout << "\n--- TESTING 10 RANDOM INDEXES ---\n";
    srand(time(0)); 
    
    for(int i = 0; i < 10; i++) {
        
        int actual_idx = rand() % database.size(); 
        string target_word = database[actual_idx].full_name;
        
        
        int found_idx = learned_search(target_word, max_error,mod);
        
        cout << "Test " << i+1 << ": Target ['" << target_word << "']\n";
        cout << "  -> Actual Position: " << actual_idx << "\n";
        cout << "  -> Found Position:  " << found_idx;
        
       
        if (found_idx != -1 && database[found_idx].full_name == target_word) {
            cout << " [SUCCESS!]\n";
            
            if (actual_idx != found_idx) {
                cout << "     (Note: Found duplicate entry at index " << found_idx << " instead of " << actual_idx << ")\n";
            }
        } else {
            cout << " [FAILED!]\n";
        }
    }

    return 0;
}