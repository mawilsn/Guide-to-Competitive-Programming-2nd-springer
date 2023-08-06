#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;


int main(){

    indexed_set s;
    s.insert(2);
    s.insert(3);
    s.insert(7);
    s.insert(9);

    auto x = s.find_by_order(2);
    cout << *x << "\n";
    
    auto k = s.order_of_key(7);
    cout << k << "\n";

}