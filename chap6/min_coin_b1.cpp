#include <bits/stdc++.h>

using namespace std;

 int coins[] = {1 ,3 ,4 };

int solve(int x){

    if (x < 0) return 0;
    if (x == 0) return 0;

    int best = INT_MAX;

    for(auto c : coins){
        best = min(best, solve(x-c)+1);
    }

    return best;
}


int main(){
    int x = 11;

    cout << solve(x) << "\n";
}