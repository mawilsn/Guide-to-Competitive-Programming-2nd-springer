#include <bits/stdc++.h>

using namespace std;


int main(){

    cout <<"---set---\n";

    set<int> s;
    s.insert(3); // [3]
    s.insert(2); // [3,2]
    s.insert(5); // [3,2,5]
    cout << s.count(3) << "\n"; // there is one three
    cout << s.count(4) << "\n"; // there are no fours
    s.erase(3);
    s.insert(4);
    cout << s.count(3) << "\n"; // there is one three
    cout << s.count(4) << "\n"; // there are no fours
    cout << "--- ---";
    

}

