#include <bits/stdc++.h>
using namespace std;
 
// Utility function for solving the minimum coins problem
int minCoinsUtil(int coins[], int m, int V, int* dp)
{
    // Base case: If target value V is 0, no coins are
    // needed
    if (V == 0)
        return 0;
 
    // If subproblem is already solved, return the result
    // from DP table
    if (dp[V] != -1)
       { cout << "dp[V]: " << dp[V] << "\n";
        return dp[V];}
 
    int res = INT_MAX;
 
    // Iterate over all coins and recursively solve for
    // subproblems
    for (int i = 0; i < m; i++) {
        if (coins[i] <= V) {
            // Recursive call to solve for remaining value V
            // - coins[i]
            cout << "V: " << V << ", coins[i]: " << coins[i] 
                 << ", i: " << i << "\n"
                 << " V - coins[i]: " <<  V - coins[i]<<"\n";
            int sub_res
                = minCoinsUtil(coins, m, V - coins[i], dp); //11-2, 9-2, 7-2, 5-2,3-2, 1-2
            
            cout << "sub_res: "<< sub_res 
                 << ", res: " << res
                 << "\n---------------\n";
            // If the subproblem has a valid solution and
            // the total number of coins is smaller than the
            // current result, update the result
            if (sub_res != INT_MAX && sub_res + 1 < res)
                {res = sub_res + 1;
                cout << "true \n";
                 cout << "V: " << V << ", coins[i]: " << coins[i] 
                 << ", i: " << i << "\n"
                 << " V - coins[i]: " <<  V - coins[i]<<"\n";
                 cout << "sub_res: "<< sub_res << "\n";
                cout << "res : "<< res <<"\n"
                << "---------------\n";
                }
        }
    }
 
    // Save the result in the DP table
    dp[V] = res;
 
    return res;
}
 
// Function to find the minimum number of coins needed to
// make a target value
int minCoins(int coins[], int m, int V)
{
    // Create a DP table to store results of subproblems
    int* dp = new int[V + 1];
    memset(dp, -1,
           sizeof(int)
               * (V + 1)); // Initialize DP table with -1
 
    // Call the utility function to solve the problem
    return minCoinsUtil(coins, m, V, dp);
}
 
// Driver code
int main()
{
    int coins[] = { 2,4,1};
    int m = sizeof(coins) / sizeof(coins[0]);
    int V = 11;
 
    int res = minCoins(coins, m, V);
    if (res == INT_MAX)
        res = -1;
 
    // Find the minimum number of coins required
    cout << "Minimum coins required is "<< res << "\n";
 
    return 0;
}