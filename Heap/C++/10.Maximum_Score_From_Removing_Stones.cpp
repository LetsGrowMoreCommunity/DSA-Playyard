/*
-> Problem Statement
- You are given three piles a,b and c of stones, Each turn you choose two different nonempty piles, take one stone from each and add 1 point to your score.
- You need to return maximum score you can get.

-> Approach Explanation:
- We need to find maximum moves we can perform where each move is taking two stones from two nonempty piles.
- Two maximize these moves we need to keep removing stones from piles having maximum and second maximum stones at each move. 
- To find max and second max values out of a,b and c everytime we will use maxheap(priority_queue).
- We can keep poping maximum elements from priority_queue and push elements having 1 less value > 0 which will again priortize elements at that stage. 
- We follow above step till priority_queue contains >=2 elements and increse count for moves everytime.
*/

#include <iostream>
#include <map>
#include <queue>
using namespace std;

class Solution {
public:
    int maximumScore(int a, int b, int c) {
        
        priority_queue<int> maxheap;         // pushing initial values of a,b and c to maxheap
        maxheap.push(a);
        maxheap.push(b);
        maxheap.push(c);
        
        int score = 0;
        while (maxheap.size() >= 2) {        // performing required step untill there are two nonempty piles of stones
            
            int max = maxheap.top();         // poping maximum and second maximum elements from maxheap
            maxheap.pop();
            
            int secmax = maxheap.top();
            maxheap.pop();
            
            if (max>0 && secmax>0) {
                maxheap.push(max-1);
                maxheap.push(secmax-1);      // pushing element having 1 less value to priortize again 
                score++;                     // increasing score by 1 only if we can push again having value > 0 which indicates stone can be removed from teo piles
            }
        }
        return score;
        
    }
    
};

int main() 
{
    cout<<"\nEnter number of test cases: ";
	int t; cin>>t;  //no. of test cases

	// Constraint: 1 <= a, b, c <= 10^5

	while (t--)
	{


	    cout<<"\n\nEnter number of stones present in piles a,b and c  : ";
	    int a; cin>>a;
        int b; cin>>b;
        int c; cin>>c;

	    Solution *ob;
        cout<<"\nK Maximum score you can get is :";
	    cout <<  ob-> maximumScore(a,b,c);
	    
	}
	return 0;
}

/*
SAMPLE INPUT
3				    // number of test cases 
5 7 2				// values of a,b and c for test case:1
1 9 3 	            // values of a,b and c for test case:2
1000 96 345         // values of a,b and c for test case:1

SAMPLE OUTPUT (excluding interactive instructions)
7                   // first 3 moves will make (a,b,c) => (2,4,2) and next 4 moves will make them all 0
4                   // first 2 moves will make (a,b,c) => (1,7,1) and next two will make (0,5,0) then stopped as nonempty piles <2
441                 
 
COMPLEXITY ANALYSIS : 
Time : O(max(a,b,c)) since forming max heap is independent of values of a, b and c. 
Space: O(1), since max heap only stores 3 elements at a time.
*/