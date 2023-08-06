#include <bits/stdc++.h>

using namespace std;


int main(){

    cout << "--- maps ---\n";

    map<string, int> m;
    m["monkey"] = 4;
    m["banana"] = 3;
    m["harpsichord"] = 9;

    cout << m["banana"] << "\n";  // prints out 3

    for (auto x: m){
        cout << x.first << " "<< x.second << "\n";
    }


    
}