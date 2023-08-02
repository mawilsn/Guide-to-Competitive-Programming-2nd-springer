#include <bits/stdc++.h>

using namespace std;


int main(){
    vector<int> v = {9,2,3,3,5,7,8,8,8};
    sort(v.begin(), v.end());


    cout << *v.begin()<<"\n";
    // cout << v.begin()<<"\n"; // errors
    auto a = lower_bound(v.begin(), v.end(),5);
    auto b = upper_bound(v.begin(), v.end(),5);
    cout << *a<<" " << *b <<"\n";
    // vector<int> c =  
    v.erase(unique(v.begin(), v.end()), v.end());
    for (auto x : v){
        cout << x << "\n";
    }







}