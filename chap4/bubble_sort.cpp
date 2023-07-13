#include <bits/stdc++.h>

using namespace std;

// print an array
void printArray(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    cout << "  " << array[i];
  }
  cout << "\n";
}

int main(){

    int arr[] = {10, 1, 3, 8,12, 2, 9, 2, 5, 6,3};
    int n = *(&arr + 1) - arr;
    cout << "Printing Array: ";
    printArray(arr, n);
    cout << n  << "\n";
    for (int i = 0; i < n; i++){
        for(int j = 0; j < n-1; j++){
            cout <<"comparing "<< arr[j] <<" > " << arr[j+1] << "\n";
            if(arr[j] > arr[j+1]){
                cout << "True "<< arr[j] << " is greater\n ";
                cout << "Printing new Array: ";
                swap(arr[j], arr[j+1]);
                    printArray(arr, n);

            } else{
                cout << "False "<< arr[j] << " is less \n";


            }
        }
    }
    cout << " Printing Final Array: ";

     printArray(arr, n);

    return 0;
}

