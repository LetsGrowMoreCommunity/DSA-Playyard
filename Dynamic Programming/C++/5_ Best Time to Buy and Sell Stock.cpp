

//time comlexity 0(N)

#include <bits/stdc++.h>
using namespace std;

int maxProfit(int prices[], int N)
{

    int cost = 0;//declaration and initialization
    int maxCost = 0;
    
    
    int min_price = prices[0];//initialising

    for(int i = 0; i < N; i++)
    {
       
        min_price = min(min_price, prices[i]);//the min price

        

        maxCost = max(maxCost, (prices[i] - min_price));//find thea max because profit would be the max when u sell for max and buy for min
    }
    return maxCost;
}

// main func 
int main()
{
    int N;
    cin>>N;
    int prices[N];
    
    for (int i = 0; i < N; i++) {

     cin >> prices[i]; 
    }
   
    
   
    cout << maxProfit(prices, N);

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


        
