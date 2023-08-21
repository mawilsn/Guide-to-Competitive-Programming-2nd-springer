// A Dynamic Programming based C++ program to find minimum
// of coins to make a given change V
#include <bits/stdc++.h>
using namespace std;
 
// m is size of coins array (number of different coins)
int minCoins(int coins[], int m, int V)
{
    // table[i] will be storing the minimum number of coins
    // required for i value.  So table[V] will have result
    int table[V + 1];
 
    // Base case (If given value V is 0)
    table[0] = 0;
 
    // Initialize all table values as Infinite
    for (int i = 1; i <= V; i++)
        table[i] = INT_MAX;
 
    // Compute minimum coins required for all
    // values from 1 to V
    for (int i = 1; i <= V; i++) {
        cout << "---------------------\n";
        cout << "i: " << i << "\n";
        // Go through all coins smaller than i
        for (int j = 0; j < m; j++)
            if (coins[j] <= i) {
                cout << "j: " << j << ", " << "coins[j]: " << coins[j]<< "\n";
                cout << "i - coins[j]: " << i - coins[j] << "\n";
                int sub_res = table[i - coins[j]];
                cout << "Subresult: "<<sub_res <<", table[i]: "<< table[i]<< "\n";
                if (sub_res != INT_MAX
                    && sub_res + 1 < table[i]){
                    table[i] = sub_res + 1;
                    cout << "table[i]: " << table[i] << "\n";
                    cout << "true \n";}
            }
    }
 
    if (table[V] == INT_MAX)
        return -1;

    for (auto x: table)
        cout << x <<", ";
    cout << "\n";
 
    return table[V];
}
 
// Driver program to test above function
int main()
{
    int coins[] = { 1,2,4 };
    int m = sizeof(coins) / sizeof(coins[0]);
    int V = 11;
    cout << "\nMinimum coins required is "
         << minCoins(coins, m, V)
         << "\n";
    return 0;
}