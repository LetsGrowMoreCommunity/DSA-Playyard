/*Algorithm: 
We will store each unique DNA sequence and its frequency in map by traversing from index 0. At last we will return all the
unique DNA sequence which are repeated by traversing map .
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        
        unordered_map<string,int>m;
        vector<string>ans;
        
        int n=s.length();
        
        for(int i=0;i<=(n-10);i++)
        {
            m[s.substr(i,10)]++; //storing string and its frequency of length 10
        }
        
        for(auto x:m) //traversing map
        {
            if(x.second>1) //DNA is repeated
                ans.push_back(x.first); 
                
        }
        
        return ans;
        
    }
};


int main() 
{
   
    string s;
    cin>>s;

    Solution obj;
    vector<string>ans=obj.findRepeatedDnaSequences(s);

    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
       
    return 0;
}

// Time Complexity : O(N)
// Space Complexity : O(1)

/*
TestCase 1:
Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
Output: ["AAAAACCCCC","CCCCCAAAAA"]
Explaination: DNA sequence AAAAACCCCC and CCCCCAAAAA both of length 10 are repeating 2 times ,
rest all sequences are present only once.
 

TestCase 2:
Input: s = "AAAAAAAAAAAAA"
Output: ["AAAAAAAAAA"]
Explaination: DNA sequence AAAAAAAAAA of length is repeating 4 times, rest all sequences are present only once.

*/