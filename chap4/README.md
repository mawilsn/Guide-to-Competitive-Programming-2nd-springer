# Sorting and Searching chap 4

- Sorting the input can help improve the efficeny. 
- This chapter will discuss the theory and practice of sorting

---
## 4.1 Sorting Algorithms
- The basic problem being solved: Given an array of *n* elements, sort the elements increasing order.

### 4.1.1 Bubble Sort
- Basics of the algorithm, going through an array and compare two elements at a time. When two consecutive elements are found, the greater of the two proceeds to be in the next comparison. The greater is of the two is always moving forward. At the end of the first round the largest values will be at the last place in the array.
  - Example: The parenthese highlight which elements, I'm focusing on
    1. 10,1,2,3,4
    2. (10,1),2,3,4 Compare 10 and 1. 10 is greater and the two swap
    3. 1,(10,2) 3,4 Compare 10 and 2. 10 is greatest in the set, the two swap
    4. 1,2,(10, 3),4 Compare 10 and 3. 10 is greatest in the set, the two swap.
    5. 1,2,3,(10,4) Compare 10 and 4. 10 is greatest in the set, the two swap
    6.  1,2,3,4,10 Nothing to compare, will proceed two do this again until we have gone through the list. Even though the list is in order, we would proceed to do this process again.
    7.  (1,2),3,4,10 Compare 1 and 2. 2 is greatest in the set, the two stay the same
    8.  1,(2,3),4,10 Compare 2 and 3. 3 is greatest in the set, the two stay the same
    9.  and so on.

The algo is implemented as such in code:
```c++
for (int i=0;i<n;i++){
    for (int j = 0; j < n-1; j++){
        if(array[j] > array[j+1]){
            swap(array[j],array[j+1])
        }
    } 
}
```

- This is an $O(n^2)$ time complexity