/*
Problem: Climbing Stairs on LeetCode, solution by AtrikGit6174
Both recursive and iterative solns are there. Please read the comments in the functions.
Both methods effectively use memoisation: storing values for subproblems for optimising 
against re-calculation of previously encouuntered subproblems to finally solve the problem.

The idea lies in the fact that we can reach the nth stair in two ways considering subproblems
1. climb 2 stairs after reaching (n-2)th step.
2. climb 1 stairs after reaching (n-1)th step.

This makes the no. of ways for nth step= no. of ways for (n-1)th step + no. of ways for (n-2)th step 
*/

#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution 
{
    
    vector <int> vec;   //for iterative approach
    map <int,int> mp;   //for recursive approach. stairs:no. of ways pairs.
    
public:
    int climbStairs_ite(int n) 
    {
        if (n==1 or n==2)
            return n;
        
        //storing base cases.
        vec.push_back (1);
        vec.push_back (2);
        
        //iterative approach
        for (int i=2; i<n; i++)
            vec.push_back (vec[i-2]+vec[i-1]);
        
        return vec[n-1];
        
    }
    
    int climbStairs_rec(int n) 
    {
        if (n==1 or n==2)
            return n;
        
        //storing base cases.
        mp.insert(make_pair(1,1));
        mp.insert(make_pair(2,2));
        
        //recursive approach
        if (mp.find(n)==mp.end())
            //notice that climbStairs_rec (n-2) is called before climbStairs (n-1)
            //as value for n-1 relies on value for n-2
            mp.insert(make_pair(n,climbStairs_rec(n-2)+climbStairs_rec(n-1)));  
        
        return mp[n];
        
    }
};

int main() 
{
   cout<<"Enter the number of stairs [1-45]: ";
   int n; cin>>n;
   
   Solution ob;
   cout<<"\nNo. of ways\n1. Iterative: "<<ob.climbStairs_ite(n)<<"\n2. Recursive: "<<ob.climbStairs_rec(n);
   return 0;
   
}

/*
SAMPLE INPUT-OUTPUT 
Input 1: n = 2
Output 1: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps

Input 2: n = 3
Output 2: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step

COMPLEXITY ANALYSIS n= no. of steps
Time: Iteratively storing in a vector is O(n)
      Recursively storing in a map is O(n)
Space: input is O(1) as n is just an integer
       Aux space of O(n) for memoisation.
       */
