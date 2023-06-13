#include <iostream>
#include <vector>

using namespace std;


void search( vector<int>& permutation, vector<bool>& chosen){
    int n = chosen.size();

    if (permutation.size() == n){
        for(int i = 0; i < n; i++){
            cout << permutation[i];
        }
       
    } else{
        for(int i = 1; i <= n; i++){
            if (chosen[i]) continue;
            chosen[i] = true;
            permutation.push_back(i);
            search(permutation, chosen);
            chosen[i] = false;
            permutation.pop_back();
        }
    }
}

int main(){
    int n = 3;
    vector<int> permutation;
    vector<bool> chosen(n+1, false);
    search(permutation, chosen);
}
