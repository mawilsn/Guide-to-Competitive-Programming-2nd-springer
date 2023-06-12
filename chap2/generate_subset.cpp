#include <iostream>
#include <vector>

using namespace std;

vector<int> subset;
int n; // global because it was declared outside. Bad!

void processSubset() {
    cout << "{ ";
    for (int i : subset) {
        cout << i << " ";
    }
    cout << "}\n";
}

void search(int k) {
    if (k == n + 1) {
        processSubset();
    } else {
        // Include k in the subset
        subset.push_back(k);
        search(k + 1);
        subset.pop_back();
        
        // Don't include k in the subset
        search(k + 1);
    }
}

int main() {

    n = 3; // this appears to be global/ shrug
    
    search(1);
    
    return 0;
}