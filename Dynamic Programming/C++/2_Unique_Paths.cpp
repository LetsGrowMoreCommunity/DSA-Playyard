/*
Problem: Unique Paths on LeetCode
Solution by AtrikGit6174

A top-down DP solution with memoisation
*/

#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution 
{
    map<pair<int, int>, int> mp;   //set(m,n):ways, m>n. This is because ways(m,n)==ways(n,m)
public:
    int uniquePaths(int m, int n) 
    {
        if (m*n==0)
            return 0;   
            //so that the functions can be called without adding a validity check
        
        //no need to store the next two cases as they return directly. 
        //In fact, storing increases time taken.
        
        if ((m==1 or n==1))
            return 1;   //a mono-directional way upto the finish

        if ((m==2 or n==2))
            return max(m,n);    //found by observation
        
        auto p= make_pair(max(m,n), min(m,n));
        
        if (mp.find(p)==mp.end())
        {
            if ((m-1)*n<=m*(n-1))
                mp.insert (make_pair (p, uniquePaths (m-1,n) + uniquePaths (m,n-1)));
            else
                mp.insert (make_pair (p, uniquePaths (m,n-1) + uniquePaths (m-1,n)));
            
            //in both the cases, the expected smaller value is called first.
        }
        
        return mp[p];    
    }
};

int main() 
{
	cout<<"Enter the number of test cases: ";
	int t; cin>>t;
	
	for (int count=1; count<=t; count++)
	{
	    cout<<"\nTEST CASE "<<count<<"\nEnter m and n (both in range [1,100]): ";
	    int m, n; cin>>m>>n;
	    
	    Solution ob;
	    cout<<"\nPaths: "<<ob.uniquePaths (m,n)<<"\n";
	}
	return 0;
}

/*
SAMPLE INPUT
4       <-- NUMBER OF TEST CASES
3 7     <-- 3*7 GRID
3 2
7 3
3 3

SAMPLE OUTPUT (excludin interactive instructions)
28
3
28
6

*/
