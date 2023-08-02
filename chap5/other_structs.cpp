#include <bits/stdc++.h>

using namespace std;

int main(){

    cout <<"----- deque ---- \n"; 
    deque<int> d;
    d.push_back(5); // [5]
    d.push_back(2); // [5, 2]
    d.push_front(3); // [3, 5, 2]
    d.pop_back(); // [3, 5]
    d.pop_front(); // [5]


    for (auto x : d){
        cout << x << "\n";
    }

    cout <<"--------- \n"; 

    cout <<"----- stack ---- \n"; 

    stack<int> s; 
    s.push(2); // [2]
    s.push(5); // [2, 5]
    cout << s.top() << "\n"; // 5
    s.pop(); // [2]
    cout << s.top() << "\n"; // 2

    cout <<"--------- \n"; 

    cout <<"----- queue ---- \n"; 
    queue<int> q;
    q.push(2); // [2]
    q.push(5); // [2, 5]
    cout << q.front() << "\n"; // 2
    cout << q.back() << "\n"; // 5
    cout <<"--------- \n"; 


}