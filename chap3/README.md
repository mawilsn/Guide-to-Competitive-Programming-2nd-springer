## 3.1 Time Complexity

What is time complexity?

- It is an algorithm that estimates how time it will take given a certain output

What is the benefit?

- We can find out if the algorithm is fast enough

There is a basic understanding of what we mean by time complexity. What is the notation used?

- "O" is th symbol for the time complexity
- "n" denotes the size of the input
  - if n is an array, the length of the array is the size.
  - if n is a string, it's the lenght of the string

### 3.1.1

What is the time complexitgy of a single comand?

- This is a time complexisty of O(1)
- examples of `O(1)`
  - `a++`
  - `c=a+b`

What would th etime complexity for a single loop?

```
#include <bits/stdc++.h>

using namespace std;

int main(){

  for(int i = 0; i>n;i++){
    // return something
  }
}
```

- The loop would have a `O(n)` time complexity becasue it goes through the loop n amount of times

What would a nested loop be?

```

using namespace std;

int main(){

  for(int i = 0; i<;i++){
    for (int j = 0; j<n; j++){
      // return
    }
  }
}
```

- This will be `O(n^2)` since it goes through twice?

We can think of every loop as adding more time complexity.

- a simple formula would be $ O(n^k) $ where n is the input; k is the number of loop

What is the time complexity for a multi loop funciton where one loop is O(n^2) and the other loop is O(n)?

To figure this out we would just take the largest loop and say it's O(n^2) for time complexity

```

using namespace std;

int main(){

  for(int i = 0; i<;i++){
    for (int j = 0; j<n; j++){
      // some action
    }
  }

  for(int k = 0; k < n; k++){
    // do something
  }
  // return something
}
```

### 3.1.2

<table><tbody><tr><td>Time complexity</td><td>Def</td></tr><tr><td>o(1)</td><td>Constant time algorithm. A</td></tr><tr><td>o(logn)</td><td>Logarithm algorithm often halve the input</td></tr><tr><td>o(sqrt(n))</td><td>Square root algorith. O(log(n)) is faster; O(n) is slower</td></tr><tr><td>o(n)</td><td>In linear algo. The input is processed at constant time. This may releastically will be the fastest alg. for many situations</td></tr><tr><td>o(nlog(n))</td><td>This complexity is usually meant for sorting algos.</td></tr><tr><td>O(n^2)</td><td>quadratic alog. Often two nested loops</td></tr><tr><td>o(n^3)</td><td>Cubic 3 nestedloops</td></tr><tr><td>O(2^n)</td><td>Often iterates through all subsets</td></tr><tr><td>&nbsp;</td><td>&nbsp;</td></tr></tbody></table>

### 3.1.3 Estimating Efficency

Lets assume we have a problem that requires 1 sec. The input is size is 10^5 and complexity is O(n^2). Will the algorithm work?

- No. The total algorithm will take O(10^10)=10^5 * O(n^2). The example given in the book was a little hard to understand, but the assumptions it would take 10^10 operations or 10 seconds to complete. It wasn't clear but it seems like each loop takes a millisecond.

### 3.1.4 Formula Definition

I'm going to briefly go over this. It seems like the book could've gone more in depth and so I'm lacking in understanding.
----

what does $ O(f(n)) $ time meand?
- it means that there are constancent c & $ n_0 $ such that the algorithm performs the most at $ c(f(n)) $ where $ n >= n_0 $ for all inputs. This would be the upperbound.

The book then gives a confusing example of stating: 
    For example, it is technically correct to say that the time complexity of the following algorithm is $ O(n^2) $ 
    """ c++
    for (int i = 1; i <= n; i++) {
      ...
    }
    """
  page 32

The book proceeds to say a better bound (also the definition they have given for most of the book) is $ O(n) $ and it's "misleading to give bound $ O(n^2) $ ...."
My opinion is the book is expecting us to know some more information and this section is only mildy important. It's to quell the disapproval of math or the studious computer scientists of the world. 

Other definitions:

Two other common notations: the $\Omega$ gives the lower bound.  the other is $\Theta$ gives the upper bound


## 3.2 Algorithm Design Examples

Presents two algos. design examples where a problem can be solved in different ways: Brute force and then more effiecient.

### 3.2.1 Maximum Subarray Sum

array `[-1,2,4,-3,5,2,-5,2]`

Probem: find the largets sum of numbers in the array.


$O(n^3)$ solution: go through all possible combinations and calculate the sum.
1. create set all
2. sum

```c++
int best = 0;
int array[8] = {-1,2,4,-3,5,2,-5,2};

for (int a = 0; a < array.size(); a++){
  for (int b = a; b < array.size(); b++){
    int sum = 0;
    for (int k = a; k <= array.size(); k++){
      sum += array[k]
    }
    best = max(best, sum);
  }
}
cout << best << "\n";

```
Let do $O(n^2)$ solution

```c++
int best = 0;
int array[8] = {-1,2,4,-3,5,2,-5,2};

for (int a = 0; a < array.size(); a++){
  int sum = 0;
  for (int b = a; b < array.size(); b++){
    sum += array[b];
    best = max(best, sum);
  }
}
cout << best << "\n";

```

$O(n)$ solution is even faster 

```c++
int best = 0, sum=0;
int array[8] = {-1,2,4,-3,5,2,-5,2};
for(int k = 0; k<n; k++){
  sum = max(array[k], sum+array[k]);
  best = max(best, sum);
}
cout << best << "\n";

```

### 3.2.2 Two Queens Problem

Number of ways to put two queens on a chessboard of n x n size without attacking eacher other.

There is no code for this section. It only goes on to describe potential algos.

$O(n^4)$ 

<table><tbody>
<tr><td>Time complexity</td><td>solution</td></tr>
<tr><td> $O(n^4)$  </td>><td> Go through all possible ways to place two queens on the board and count the combinations where the queens don't attack each other. This is $O(n^4)$ because there are $n^2$ ways to choose the posistion for the first queen and $n^2-1$ ways to put the second queen. </td></tr> 
<tr><td> $O(n^2)$  </td>><td> We can calculate the number of squares a single queen can attack (n-1 diagnolly, d-1 vertically and d-1 horizontally). Knowing this we can calculate thin O(1) time where the second queen can be placed </td></tr> 
<tr><td> $O(1)$  </td>><td> Recursive solution. If we know the value of q(n), how can we use it to calculate the value of q(n+1)? The book goes more in depth on it. It's a little to general for me.</td></tr>

</tbody></table>



## 3.3 Code Optimization

I'm going to skip the rest of this. I think this is important, but I want to keep moving on and I don't think this in my notes is what I'm trying to achieve.