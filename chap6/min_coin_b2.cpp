#include <bits/stdc++.h>

using namespace std;

 int coins[] = {1 ,3 ,4 };
 const int x = 11;
 bool ready[x];
 int value[x];

int solve(int x){

    if (x < 0) return 0;
    if (x == 0) return 0;
    if (ready[x]) return value[x];


    int best = INT_MAX;

    for(auto c : coins){
        best = min(best, solve(x-c)+1);
    }
    ready[x] = true;
    value[x] = best;

    return best;
}


int main(){
    
    cout << solve(x) << "\n";
}