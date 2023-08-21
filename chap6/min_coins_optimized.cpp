#include <bits/stdc++.h>  
using namespace std;  
  
int coins[] = { 9, 25, 5 }; // coins array  
int dp[1000] = { 0 }; // array for memoisation  

int minCoins(int N, int M) // N is the sum , M is total_coins  
{  
  cout << "\n init \n";
    for (int i = 0; i <= N; i++) 
        {
        dp[i] = INT_MAX; // Initialise all dp[] value to INT_MAX  
        cout << i << "\n";
        } 
    cout << "---------------\n";
    dp[0] = 0; // Base case if sum becomes zero min rupees = 0  
  
    //Iterating in the outer loop for possible values of sum between 1 to N  
    //Since our final solution for sum = N might depend upon any of these values  
    for (int i = 1; i <= N; i++) {  
        //Inner loop denotes the index of coin array.  
        //For each value of sum, to obtain the optimal solution.  
        for (int j = 0; j < M; j++) {  
            cout << "j: " << j << ", i: " << i;
            cout << " coin: " << coins[j] << "\n";
            //i ?> sum  
            //j ?> next coin index  
            //If we can include this coin in our solution  
            if (coins[j] <= i) {  
                //Solution might include the newly included coin  

                // cout << "coins[j]: " << coins[j] << ", j: " << j << "\n";

                // cout << "dp[coins[j]]: " << dp[coins[j]] << "\n";
                // cout << "dp[i]: " << dp[i] << "\n";


                // cout << "dp[i - coins[j]] "<< dp[i - coins[j]] << "\n";

                // cout << 1+dp[i - coins[j]] << "\n";
                // cout << "i: " << i << "\n";
                // cout << "min: " << min(dp[i], 1 + dp[i - coins[j]]) << "\n"; 
                dp[i] = min(dp[i], 1 + dp[i - coins[j]]);  
                
            }  
        }  
    }  
    return dp[N];  
}  
  
int main()  
{  
    for (auto x: coins){ cout << x << "\n";}
  
    int sum = 10; // the money to convert  
    int total_coins = 3; // total availability of coins  
    cout << "Minimum coins needed are " << minCoins(sum, total_coins) << "\n";  
}  