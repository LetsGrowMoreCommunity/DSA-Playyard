/*Algorithm: 
First store all the stones in max heap as priority queue then keep poping first two heaviest stones from priority queue.
If both are of same value then continue else push the difference of stones. If size of queue become 1 or 0 the stop and return 
value of stone left(pq.size()==1) or return 0 (pq.size()==0)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {

        priority_queue<int>pq;

        int n=stones.size();

        for(int i=0;i<n;i++)
            pq.push(stones[i]); //storing value of stones in max heap

        while(pq.size()!=1 && pq.size()!=0) // Till size become 1 or 0
        {
            int a=pq.top(); //First heaviest stone
            pq.pop();

            int b=pq.top(); //Second heaviest stone
            pq.pop();


            if(a!=b) // Both stones are not equal
                pq.push(a-b);


        }

        if(pq.size()==1) //If only 1 stone exist
            return pq.top();
        else
            return 0; // No stone left


    }
};


int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
        vector<int>v;
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            int a;
            cin>>a;
            v.push_back(a);

        }

        Solution ob;
        int ans= ob.lastStoneWeight(v);

        cout<<ans<<endl;

    }
    return 0;
}

// Time Complexity : O(N)
// Space Complexity : O(N)

/*
Test Case 1 :
Input: 
t=1
n=6
arr=[2,7,4,1,8,1]
Output: 1
Explanation: 
We combine 7 and 8 to get 1 so the array converts to [2,4,1,1,1] then,
we combine 2 and 4 to get 2 so the array converts to [2,1,1,1] then,
we combine 2 and 1 to get 1 so the array converts to [1,1,1] then,
we combine 1 and 1 to get 0 so the array converts to [1] then that's the value of last stone.


Test Case 2:
Input: 
t=1
n=4
arr=[4,6,8,2]
Output: 0
Explaination: 
We combine 8 and 6 to get 2 so the array converts to [4,2,2] then,
we combine 4 and 2 to get 2 so the array converts to [2,2] then,
we combine 2 and 2 ,since both are equal so both get destroyed and there is no stone left.
*/