#include <iostream>
#include <vector>

using namespace std;

vector<int> permutation;
int n; // global because it was declared outside. Bad!
bool chosen[];

void search(){

    if (permutation.size() == n){
        //process
    } else{
        for(int i = 1; i <= n; i++){
            if (chosen[i]) continue;
            chosen[i] = true;
            permutation.push_back(i);
            search();
            chosen[i] = false;
            permutation.pop_back();
        }
    }
}

