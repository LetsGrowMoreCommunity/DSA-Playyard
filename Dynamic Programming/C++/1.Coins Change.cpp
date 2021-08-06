/*
-> Problem Statement
- You are given an array having coins of different denominations and an integer representing total amount of money.
- Return the fewest number of coins you need to make up that amount if possible to make otherwise return -1

-> Approach Explanation:
- One approach could be a brute force approach where we try to reach each collection of coins and return the collection having minimum number of coins for making sum 
  but in this approach we keep checking same subproblem multiple times ,to make it better we will use dynamic programming to save the state each time and reuse it  
- We first start with finding minimum coins required to make amount 0,1,2...amount , for finding each we take each coin which can contribute to make amount ,
  for taking each coin we find minimum coins required by considering previous minimum and 1 + dp[curramount-coinval], so here we are using coins required for one of previous amount.
- Going this way we find miminum coins required for making required amount.
- This is called Top-Down approach in DP, where we solve subproblems first and then try to find final result using those results .
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    
    int coinChange(vector<int>& coins, int amount) {
        
        vector<int>dp(amount+1,INT_MAX);                    // vector having INT_MAX intialization denotes not possible to make that amount
        dp[0] = 0;                                          // 0 coins for making amount 0
        for(int i=0;i<=amount;i++)
        {
            for(int j=0;j<coins.size();j++)                 // for each amount traversing each coin value
            {
                if(coins[j]<=i && dp[i-coins[j]]!=INT_MAX)  
                  dp[i] = min(dp[i],1 + dp[i-coins[j]]);    // if coin can make that amount then update mimum by previous minimum and 1 + minimum coins required for remaining sum
            }
        }
        if(dp[amount]==INT_MAX) return -1;                  // If array element for amount is INT_MAX it means no combination posiible to make that amount
           
        return dp[amount];                                  // Returning minimum number of coins for making that amount
    }
};

int main() 
{
    cout<<"\nEnter number of test cases: ";
	int t; cin>>t;  

	/*
	Constraints:
    1 <= coins array length <= 12
    1 <= coin value <= 2^31 - 1
    0 <= amount <= 10^4
    */

	while (t--)
	{
	    cout<<"\n\nEnter number of elements in coins array: ";
	    int n; cin>>n;

	    vector<int> coins (n);

	    cout<<"\nEnter coin values in array : ";
	    for (int i=0; i<n; i++)
	        cin>>coins[i];

        cout<<"\nEnter amount you want to make : ";
        int amount; cin >> amount;

	    Solution *ob;
        cout<<"\nMinimum number of coins required to make amount "<< amount<< " are : ";
	    cout <<  ob-> coinChange(coins,amount);
	    
	}
	return 0;
}

/*
SAMPLE INPUT
2			   // number of test cases 
5              // size of coins array for test case:1
1 2 7 9 11	   // array of coins values for test case:1
93	           // amount to make for test case:1
3              // size of coins array for test case:2
3 7 6 9		   // array of coins values for test case:2
23             // amount to make for test case:2
 
SAMPLE OUTPUT (excluding interactive instructions)
9   ( using 6 coins of '11' and 3 coins of '9' )
3   ( using 2 coins of '7' and 1 coin of '9' )

COMPLEXITY ANALYSIS : M = amount N= no.of coins
Time : O(M*N) to iterate for each smaller amount and for each coin required to make that amount
Space: O(M) for dp array having size of required amount.
*/