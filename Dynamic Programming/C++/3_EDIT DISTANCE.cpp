////Time: O(m*n), Space: O(m*n);
//Bottom up Approach

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.length();
        int n2 = word2.length();
         
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));   // store the dp ans
        
        for(int i=0; i<= n1; i++){
            for(int j=0; j<= n2; j++){//Iterating over the word1 and word 2
                
                if(i==0) 
                    dp[i][j] = j;//Base conditions
                
                else if(j==0) 
                    dp[i][j] = i;//Base conditions

                else if(word1[i-1] == word2[j-1])
                    dp[i][j] = dp[i-1][j-1];

                else//taking the min of the three operations and then adding  to it
                    dp[i][j] = 1 + min({
                                   dp[i][j - 1], // Insert 
                                   dp[i - 1][j], // Remove 
                                   dp[i - 1][j - 1]}); // Replace
            }
        }
        
          cout<<dp[n1][n2]<<endl;//dp stores the final state and returns
    }
};
int main()//the main function
{
    string word1, word2;
    cin>>word1>>word2;
    Solution ob;
    ob.minDistance(word1, word2);
    return 0;
}

//Example 1:

//Input: word1 = "horse", word2 = "ros"
//Output: 3
//Example 2:

//Input: word1 = "intention", word2 = "execution"
//Output: 5
