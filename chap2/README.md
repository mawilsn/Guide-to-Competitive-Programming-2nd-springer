
2.1 Language Features
<table width="100%"><tr><td style="text-align: left" width="20%">

### Cues

</td><td width="80%">

### Notes

</td></tr><td style="text-align: left" width="20%">

<li>typical example of atemplate</li>



</td><td width="80%">

```c
#include

using namespace std;

int main(){

    // solution
}
```

</td>

<tr></tr><td style="text-align: left" width="20%">


* `#include`


</td><td width="80%">
brings in the standard library

</td>
<tr></tr><td style="text-align: left" width="20%">

`using namespace std;`
</td><td width="80%">

you don;'t have to write `std::cout`

</td>
<tr></tr><td style="text-align: left" width="20%">
compile
</td><td width="80%">

```bash
g++ -std=c+11 -O2 -Wall test.cpp -o test
```
commad will produce a binarree file test from the source code test.cpp


it will fllo the c++ 11 standard

-O2 optimizes the code

- -Wall shows warnings about possible errors

</td>
</table>

### Summary
This section was just about running code.

---


# 2.1.1 input and output
<table width="100%"><tr><td style="text-align: left" width="20%">

### Cues

</td><td width="80%">

### Notes

</td></tr><td style="text-align: left" width="20%">
basic input example:
</td><td width="80%">

```c++
#include <bits/stdc++.h>

using namespace std;


int main(){
    cout << "enter 2 ints and a string. \n example: 1 2 hello\n";
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b;
    string x;
    
    cin  >> a >> b >> x;
    cout << "printing values: " << a << " " << b << " " << x << "\n";


}
```
I'm taking in 2 ints and a string.
This will print out the values
I added a hint to help out

   `ios::sync_with_stdio(0); cin.tie(0);` can speed up the code.


</td>


<tr></tr><td style="text-align: left" width="20%">
entering input on the command line with while loop
</td><td width="80%">

```c++

#include <bits/stdc++.h>

using namespace std;


int main(){
    cout << "enter stuff ";
    cout << "ctrl+c to end: ";
    string x;

    while (cin >> x){
        cout << x << " ";
    }

};
```

The code will work like the code above but it will take *n* number of argurments and out put them in a line.

I could put a `\n` to break everything in a single line

</td>



<tr></tr><td style="text-align: left" width="20%">
by line
</td><td width="80%">

```c++
#include <bits/stdc++.h>

using namespace std;


int main(){
    cout << "enter a sentence ";



    string x;
    getline(cin, x);

    cout << x ;


};

```

reads entire line and outputs it.

</td>
<tr></tr><td style="text-align: left" width="20%">
freopen input
</td><td width="80%">

```c++
#include <bits/stdc++.h>

using namespace std;

int main(){
 // Redirecting input.txt to standard input
    FILE* inputFile = freopen("input.txt", "r", stdin);
    if (inputFile == nullptr) {
        std::cerr << "Failed to open input.txt" << std::endl;
        return 1;
    }

    // Redirecting output.txt to standard output
    FILE* outputFile = freopen("output.txt", "w", stdout);
    if (outputFile == nullptr) {
        std::cerr << "Failed to open output.txt" << std::endl;
        return 1;
    }

    // Your program logic goes here
    // Read from standard input using std::cin
    // Write to standard output using std::cout

    int num1, num2;
    std::cin >> num1 >> num2;
    std::cout << "Sum: " << num1 + num2 << std::endl;

    // Closing the file streams
    fclose(stdin);
    fclose(stdout);

    return 0;

}
```

</td>

</table>

### Summary
This section was just about rbasics of input and output

---


<table>

## 2.1.2 Working with numbers


<tr></tr><td style="text-align: left" width="20%">
int
</td><td width="80%">

* Most used integer type
* 32 bit

$$

    -2^{31} \to\ 2^{31}-1
$$ 

</td>
<tr></tr><td style="text-align: left" width="20%">
long long
</td><td width="80%">

* if int is to small, use long long
* 64 bit
$$

    -2^{63} \to\ 2^{63}-1
$$ 

* `long long x = 123456789123456789LL;`
* `LL` means the number is Long Long. Why do that if I'm already declaring.

</td>
<tr></tr><td style="text-align: left" width="20%">
common int and long long error
</td><td width="80%">
an error can occur when the ints and long long are mixxed

```c++
int a = 123456789;
long long b = a*a;
cout << b << "\n" ; // -175789751

```
</td>

<tr></tr><td style="text-align: left" width="20%">
floating point number types

</td><td width="80%">

```c++
double = 1.234

```
`long double` is just a longer double
</td>

<tr></tr><td style="text-align: left" width="20%">
modular
</td><td width="80%">

`x%b`
</td>
</table>

### Summary

---
## 2.1.3 Shortening code
<table>
<tr></tr><td style="text-align: left" width="20%">
shortening code
</td><td width="80%">
code can be shorten 

`typedef long long ll;` can help rewrite code

```c++
ll a = 123456789;
```

`a` is now a long long
</td>

<tr></tr><td style="text-align: left" width="20%">
macros can also shorten code
</td><td width="80%">

```c++
#define F first
#define S second
#define PB push_back
#define MP make_pair
```
can change from this
```c++
v.push_back(make_pair(y1,x1));

```
to this
```c++
v.PB(MP(y1,x1))

```
</td>
</table>

---
# 2.2 Recursive Algorithms

## 2.2.1
<table>
<tr></tr><td style="text-align: left" width="20%">
Generate all subsets of a set with n elements.

```
n=3 //n has 3 elements
```
this will need to look like

$

null, {1},{2},{3},{1,2},{1,3},{2,3}, {1,2,3}
// the output would be more base off the indexes rather than the set.
$

</td><td width="80%">

```c++


void search(int k){
    if (k == n+1){
        // process subset
    }else{
        // include k in the subset
        subset.push_back(k);
        search(k+1);
        subset.pop_back();
        // don't include k in the subset
        search(k+1)


    }
}

```
A key concept of this code is it's generate the placement. The numbers don't really matter, but the index does.

{7,3,4} would have an index of {1,2,3}. The code was a little confusing until I understood that part.

I wrote some ccode showing this. I had to consult some help and it's not the best.

</td>

</table>

---

##2.2.1 Generating permutions
<table>

<tr></tr><td style="text-align: left" width="20%">
generating permutations:

1,2,3 permutations will be 1,2,3; 1,3,2; 2,1,3; 2,3,1; 3,1,2; 3,2,1
</td><td width="80%">
void search( vector<int>& permutation, vector<bool>& chosen){
    int n = chosen.size();

    if (permutation.size() == n){
        for(int i = 0; i < n; i++){
            cout << permutation[i];
        }
       
    } else{
        for(int i = 1; i <= n; i++){
            if (chosen[i]) continue;
            chosen[i] = true;
            permutation.push_back(i);
            search(permutation, chosen);
            chosen[i] = false;
            permutation.pop_back();
        }
    }
}
</td>

</table>

---

## 2.2.3 Backtracking
<table>
<tr></tr><td style="text-align: left" width="20%">
backtracking
</td><td width="80%">
begins with an empty solution and extends the solution step by step. Recursivly finds all the different ways how a solution can be constructed
</td>


<tr></tr><td style="text-align: left" width="20%">
calculating the queens
</td><td width="80%">
Problem: imagine how many queens can be put on a chessboard where no two queens attack each other.

There are only 4 queens on a 4X4 chess board

|||||
|---|---|--|--|
| |q|||
||||q|


</td>
</table>

---
## 2.3 bit manipulation
<table>
<tr></tr><td style="text-align: left" width="20%">
bit representation
</td><td width="80%">
is read left to right
</td>

<tr></tr><td style="text-align: left" width="20%">
how to convert bit representation to a formula?
</td><td width="80%">

$b_{k}2^k + \cdots + b_{2}2^2  + b_{1}2^1 +  b_{0}2^0$

or

$\Sigma b_{k}2^k$

101011 = 43


$1*2^5+0*2^4+1*2^3+1*2^2+1*2^1+1*2^0=43$
</td>

## 2.3.1 Bit Operations
<tr></tr><td style="text-align: left" width="20%">
AND (&)
</td><td width="80%">

`x&y` produce a number that has on in the bits where x and y have bits.

```
10110 \n
11010&
-----
10010
```
Notice how the 1 is only where one was for both data sets.
</td>

<tr></tr><td style="text-align: left" width="20%">
OR |
</td><td width="80%">
creates a bit as long as there is at least one bit

22|26=30
```
10110| 
11010
-----
11110
```

</td>

<tr></tr><td style="text-align: left" width="20%">
XOR ^
</td><td width="80%">
Produces a bit where there is exatly one buit

22^26=12
```
10110| 
11010
-----
01100
```
</td>

<tr></tr><td style="text-align: left" width="20%">
NOT operation ~
</td><td width="80%">
~x all bits are in verted

~x=-x-1

~29=-30

~00000000000000000000000000011101=11111111111111111111111111100010
</td>

<tr></tr><td style="text-align: left" width="20%">
Left Bit shift
</td><td width="80%">

`x<<k` appends `k` 0 bits  on `x`

```c++
1110 << 2 = 111000 // 14 << 2 = 56

```


</td>

<tr></tr><td style="text-align: left" width="20%">
Right Bit Shift
</td><td width="80%">

`x >> k` removes `k` bits on `x`   

```c++
110001 >> 3 = 110 // 49 >> 3 = 6

```

</td>

<tr></tr><td style="text-align: left" width="20%">
common functions
</td><td width="80%">

```
int x = 5328; // 00000000 00000000 00010100 11010000
cout << __builtin_clz(x) << "\n"; // 19  counts 0s at the begining
cout << __builtin_ctz(x) << "\n"; // 4 number 0s at the end
cout << __builtin_popcount(x) << "\n"; // 5 number of 1s in the bit representation
cout << __builtin_parity(x) << "\n"; // 1 the parity of the number of ones in the bit representation
```
</td>

## 2.3.2 Representing sets
<tr></tr><td style="text-align: left" width="20%">
Representing a set in a bit representation
</td><td width="80%">

{0,1,2,3,...,n-1} can represent a bit integer

example: 32 bit integer can be represented in a set of 0-31

{0,1,2,3, ... (32-1)}

</td>

<tr></tr><td style="text-align: left" width="20%">
Represent {1,3,4,8}
</td><td width="80%">

Remember the formula for bit representation: $\Sigma b_{k}2^k$

$1*2^8+1*2^4+1*2^3+1*2^1=282$ // 00...10001101

```c++
#include <bits/stdc++.h>

using namespace std;


int main(){
    int x = 0; // 0000000000000000000000...
    x |= (1<<1); // 000....0010 or 2
    x |= (1<<3); // 0000...1010 or 10
    x |= (1<<4); //000...11010 or 26
    x |= (1<<8); //000...100011010 or 282


    cout << x <<"\n";
    cout << __builtin_popcount(x) << "\n";

}
```
The progran above uses or and then assigns

Lets walk through it.

1. assign x = 0, we have a 32 bit number that is 0 or 00000000 00000000 000000000 00000000
2. bitshift to the left 1 once or 000...10 which equals 2
   1.  do an or for 0 | 2 = 2 or 000...10
3.  bit shift 1 left 3 or 00...1000 and or that with previous 2 
    1.  2|8 = 10 or 00000...00010|00000...01000 = 000...01010
4.  bit shift 1 left 4 or 00...10000 and or that with previous 10
    1.  10|16 = 36 or 00000...1010|00000...010000 = 000...011010
5.  bit shift 1 left 8 or 00...100000000 and or that with previous 26
    1.  256|36 = 282 or 00000...011010|00000...0100000000 = 000...0100011010

</td>

</table>

---

templ:
<tr></tr><td style="text-align: left" width="20%">
cue
</td><td width="80%">
note
</td>