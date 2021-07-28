/*Algorithm: 
First store all the stones in max heap as priority queue then keep poping first two heaviest stones from priority queue.
If both are of same value then continue else push the difference of stones. If size of queue become 1 or 0 the stop and return 
value of stone left(pq.size()==1) or return 0 (pq.size()==0)
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
            m[s.substr(i,10)]++;
        }
        
        for(auto x:m)
        {
            if(x.second>1)
                ans.push_back(x.first);
                
        }
        
        return ans;
        
    }
};


int main() 
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        string s;

        cin>>s;

        Solution obj;
        vector<string>ans=obj.findRepeatedDnaSequences(s);

        for(int i=0;i<ans.size();i++)
            cout<<ans[i]<<" ";
       
    }
    return 0;
}