//time comlexity 0(n)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int profit=0;
        int minvalue=INT_MAX;//since min hence we are storing INT_MAX
        int N=prices.size();
        for(int i=0;i<N;i++)//Iterating 
        {
            minvalue=min(minvalue,prices[i]);//find out the min of the prices
            profit=max(profit,prices[i]-minvalue);//find thea max because profit would be the max when u sell for max and buy for min
        }
        
        return profit;
        
    }
};
int main()
{
  
    int prices[N];
    for (i = 0; i < N; i++) {
 
     cin >> prices[i]; 
    }
    Solution obj;//declaration of object of the class

    
    obj.maxProfit();//accessing the member func
     
    cout << maxProfit(prices);
 
    return 0;
}
 
/*Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.

Input: prices = [100, 180, 260, 310,40, 535, 695]
Output: 655
Buy on day 5 (price = 40) and sell on day 7 (price = 695), profit =  655.

/*


        
