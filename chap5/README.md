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

