#include <bits/stdc++.h>

using namespace std;


int main(){
    int x = 0; // 0000000000000000000000...
    x |= (1<<1); // 000....0010 or 2
    x |= (1<<3); // 0000...1010 or 3
    x |= (1<<4); //000...11010 or 26
    x |= (1<<8); //000...100011010 or 280


    cout << x <<"\n";
    cout << __builtin_popcount(x) << "\n";

}