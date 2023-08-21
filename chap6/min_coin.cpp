// A Naive recursive C++ program to find minimum of coins
// to make a given change V
#include<bits/stdc++.h>
using namespace std;

// m is size of coins array (number of different coins)
int minCoins(int coins[], int m, int V)
{
	int table[V+1];
	table[0]=0;
	for (int i = 1; i <= V; i++){
		table[i] = INT_MAX;
	}

	 for (int i = 1; i <= V; i++) {
		// Go through all coins smaller than i
		for (int j = 0; j < m; j++){
			if (coins[j] <= i) {
				int sub_res = table[i - coins[j]];
				if (sub_res != INT_MAX
                    && sub_res + 1 < table[i]){
                    table[i] = sub_res + 1;
				}		
			}
		}
	}

	if (table[V] == INT_MAX)
        return -1;



return table[V];
}

// Driver program to test above function
int main()
{
	int coins[] = {2,5 }; ;
	int m = sizeof(coins)/sizeof(coins[0]);
	int V = ;
	cout << "Minimum coins required is "
		<< minCoins(coins, m, V) << "\n";
	return 0;
}
