/*
problem statement
- You are given a deck of unrevealed cards having unique integers on it.
- You are expected to keep doing these two steps untill all cards are revealed:
   1] Take top card, Reveal it and remove it from deck
   2] Take top card and put it at the back of the deck without revealing it.
- You need to return an order of the deck that would reveal the cards in increasing order.

Explanation:
- we will be using a queue having indices from given vector of integers (present on cards) and a vector having all integer on cards in sorted order.
- as final ans vector is going to be checked by performing two steps , while iterating queue we will also be performing those two steps as given in problem.
and at every position(or index) to be revealed we will be putting next increasing integer from sorted vector.
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        
        int n = deck.size();
        vector<int>ans(n);
        sort(deck.begin(),deck.end());
        queue<int>q;
        
        //putting indices present in given vector to queue
        for(int i=0;i<n;i++)
        {
            q.push(i);
        }
        
        int sortarrind = 0;
        int reveal = 1;
        while(q.size()>0)
        {
            if(reveal)                                // integer on this index is going to be revealed and removed from deck
            {
               ans[q.front()] = deck[sortarrind++];   // index which is going to be revealed is at q's front, where we want to put next increasing number
               q.pop();                               
            }
            else{                                     // integer on this position is going to be put at the end the deck
                q.push(q.front());
                q.pop();
            }
            reveal^=1;                                // to track on which position integer is going to be revealed
        }
        
        return ans;
           
    }
};

int main() 
{
  cout<<"\nEnter number of test cases: ";
	int t; cin>>t;  //no. of test cases
	
	/*
	Constraints:
    1 <= deck's length <= 1000
    1 <= deck[i] <= 10^6
    deck[i] != deck[j] for all i != j
    */
	
	while (t--)
	{
	    cout<<"\nEnter number of cards in deck: ";
	    int n; cin>>n;
	    
	    vector<int> deck (n);
	    
	    cout<<"\nEnter integers present in deck ( Input vector): ";
	    for (int i=0; i<n; i++)
	        cin>>deck[i];
	        
	    Solution *ob;
	    vector<int>ans = ob->deckRevealedIncreasing(deck);
	    cout<<"\nOrdering of integers in the deck we should provide is ( Output vector ) :";
	    for(int i=0;i<n;i++)
	       cout<< ans[i] << " ";
	    
	}
	return 0;
}

/*
SAMPLE INPUT
2				                // number of test cases 
7				                // size of the given desk for test case:1
15 12 5 1 4 10 8	      // desk integers vector for test case:1
9				                // size of the given desk for test case:2
1 21 7 19 8 99 8 23 55  // desk integers vector for test case:2
 

SAMPLE OUTPUT (excluding interactive instructions)
1 12 4 10 5 15 8
1 99 7 21 8 55 8 23 19 

COMPLEXITY ANALYSIS : N= no.of cards in desk 
Time : O(NlogN) could be best time to srt and O(N) to iterate. 
       Even if the queue is rolling over, it cannot 
       exceed n more iterations after the required count is reached.
       Hence, total O(NlogN).
Space :O(N) for inputs and aux space: O(N) to re-create a queue.
       Hence, O(N) overall.
*/

