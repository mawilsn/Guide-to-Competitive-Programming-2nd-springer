
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


</table>

### Summary
This section was just about rbasics of input and output
---



templ:
<tr></tr><td style="text-align: left" width="20%">
cue
</td><td width="80%">
note
</td>