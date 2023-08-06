# Chapter 5 Data Structures

- introduces important data structures in c++

## 5.1 Dynamic Arrays

in c++ ordinary arrays are fixed-size sturcutres. 

```c++
int array[n]
```
Code above creates an array of size n integers.

*dynamic array* can be changed during the executuion of the program. C++ has severaly builtin dynamic arrays. Most useful of them is the **Vectory Structure**.

### 5.1.1 Vecotrs

Vector is a dynmaic array and can effeciently add and remove elements at the end of the structure

```c++
vector<int> v;
v.push_back(3); // [3]
v.push_back(2); // [3, 2]
v.push_back(5); // [3, 2, 5]

```

Can be accesed like a normal array

```c++
cout << v[0] <<"\n"; // 3
cout << v[1] <<"\n"; // 2
cout << v[2] <<"\n"; // 5
```

A vectory can be give a list

```c++
vector<int> v = {2, 4, 2, 5, 1};
```

We can also give number of elements and initial values.

```c++
vector<int> a(8); // size 8 initial value is 0
vector<int> b(8,2); // size 8 initial value is 2

```

*size* can be used

```c++
for (int i = 0; i < v.size(); i++){
    cout << v[i] << "\n";
}
```

a shorter way to iterate through the vector is as follows:

```c++
for (auto x : v){
    cout << x << "\n";
}
```

*back* returns the last element

*push_back* removes the last element

```c++
vector<int> v = {2, 4, 2, 5, 1};
cout << v.back() << "\n"; \\ 1
v.pop_back()
cout << v.back() << "\n"; \\ 5
```

Using a vector is almost as fast as using an ordinary array.

### 5.1.2 Iterators and Ranges
*iterator* - points to the element of a data structure. The iterator begin points to the first element and the iterator end points to the posision after the last element.

```c++
vector<int> v = {1,2,3,4,5};
```
v.begin would point to 1 and v.end would point **after** 5. end points outside of the array

Many  functions will use a range.

```c++
sort(v.begin(), v.end());
reverse(v.begin(), v.end());
random_shuffle(v.begin(), v.end());
```

The element to which an iterator poitns can be access using the * syntax

```c++
cout << *v.begin() << "\n"; 
```
*lower_bound* givers an iterator to the first element in a sorted range whiose value uis at least x, and *upper_bound* gives an iterator to the first element whose value is larger than x

### 5.1.3 Other Structures
*deque* dynamic array that can effciently manipulated at bot end  of the strucuture. This ahs push_back and pop_back like a vector, but it has an additional push_front and pop_front

```c++
deque<int> v;
v.push_back(5); // [5]
v.push_back(2); // [5, 2]
v.push_front(3); // [3, 5, 2]
v.pop_back(); // [3, 5]
v.pop_front(); // [5]
```
deques have larger constant factores than vecotrs so deques should be used only if there is a need to manipulate both ends of the array.


C++ offers two specialized data structures based off of *deque*.

*stack* has push and pop for inserting and removing elements at the end of the stucuture and top to retrieve the last element

```c++
    stack<int> s; 
    s.push(2); // [2]
    s.push(5); // [2, 5]
    cout << s.top() << "\n"; // 5
    s.pop(); // [2]
    cout << s.top() << "\n"; // 2
```

*queue* elements are inserted at the end of the strucutre and removed from the front of the structure. *front* and *back* are provided for accessing the first and last elements respectively.

```c++
    queue<int> q;
    q.push(2); // [2]
    q.push(5); // [2, 5]
    cout << q.front() << "\n"; // 2
    q.pop(); // [5]
    cout << q.back() << "\n"; // 5
```

## 5.2 Set Structures

*set* - data structure that maintains a colklections ofelements. Basic operations are insertions, search and removal.

C++ has 2 set structures

- `set` is based on a balanced binary search treee and its operations work in O(logn) time
- `unordered_set`  is based on a has table and its operations work on averate O(1)

---
- `insert` adds an element to the set
- `count` returns the number of occurreneces of an element in the set
- `erase` removes an element from the set
  

  ```c++
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
  ```

WARNING - A gotcha is the count: Sets only have distinct values and that means the .count will return only a 0 or 1 for a set

- `set` can be used like a vecotr but it is not possible to access elementes using the [] notation. You can use a for loop to go through it by iterating through it.

```c++
for (auto x : s){
        cout << x << "\n";
    }
```



**Ordered Sets** is the biggest difference between sets and unordered_sets. It would be more efficient to find the largest and smallest ints in 
a ordered set as opposesed to an unordered set.

```c++
auto first = s.begin();
    auto last = s.end(); last--;
    cout << "smallest and largest ";
    cout << *first << " " << *last <<"\n";
```
s.end() points to the element after the last one


**multisets** - can have several copies of the same value.  C++ will have `multiset` and `unordered_multiset`. This resemebles set and unordered_set

```c++
 multiset<int> ms;
    ms.insert(5);
    ms.insert(5);
    ms.insert(5);
    cout << "how may 5s? "<< ms.count(5)<<"\n";
```

### 5.2.2 Maps

`maps` consists of a key-value pairs. map can also be seen as a generalized array.

```c++
map<string, int> m;
m["monkey"] = 4;
m["banana"] = 3;
m["harpsichord"] = 9;

cout << m["banana"] << "/n";  // prints out 3
```

.first will print out the key and the .second will print out the value in the for loop below

```c++
for (auto x: m){
        cout << x.first << " "<< x.second << "\n";
    }
```

### 5.2.3 Priority Queues

`priority_queue`- multiset that supports element inserttion. This is a sorted data struct. Good idea to use this instead of set or multiset.

```c++
 priority_queue<int> q;
q.push(3);
q.push(5);
q.push(7);
q.push(2);

cout << q.top() << "\n"; // 7
q.pop();
cout << q.top() << "\n"; // 5
// q.pop();
q.push(6);
cout << q.top() << "\n"; //6
```

### 5.2.4 Policy Based Sets

g++ compiler also privoides some data strucutcures that are not part of the C++ standard library. These are called *policy-based structures*.

To use these  data structures the line below must be added:
```c++
#include <bits/stdc++.h>
using namespace __gnu_pbds;
```

W can then define the data structure indexed_set that is like set but can be indexed like an array.

```c++ 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

int main(){

    indexed_set s;
    s.insert(2);
    s.insert(3);
    s.insert(7);
    s.insert(9);
    auto x = s.find_by_order(2);
    cout << *x << "\n"; // 7
    
    auto k = s.order_of_key(7);
    cout << k << "\n"; // 2

}
```




