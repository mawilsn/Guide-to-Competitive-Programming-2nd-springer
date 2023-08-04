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
    cout << s.count(3) << "\n"; // there are no threes
    cout << s.count(4) << "\n"; // there is a fours
    cout << "--- ---";

    cout << "size of the set: " << s.size() << "\n";

    for (auto x : s){
        cout << x << "\n";
    }
    
    auto first = s.begin();
    auto last = s.end(); last--;
    cout << "smallest and largest ";
    cout << *first << " " << *last <<"\n";


    cout << "--- multiset ---\n";
    
    multiset<int> ms;
    ms.insert(5);
    ms.insert(5);
    ms.insert(5);
    cout << "how may 5s? "<< ms.count(5)<<"\n";

}

