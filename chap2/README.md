
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
note
</td>

</table>

---

templ:
<tr></tr><td style="text-align: left" width="20%">
cue
</td><td width="80%">
note
</td>