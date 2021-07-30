/*
-> Problem Statement
From given integer Array Choose a set of integers and remove all the occurrences of these integers in the array.
You need to find the minimum size of that set such that at least half of the integers of the array are removed.

-> Approach Explanation:
- First save each integer present in array and its no of occurrences in array using map 
- As we need to find minimum size of the set we will keep removing elements having maximum occurrences to make its size less than or equal to half
- For finding elements having maximum occurrences we will use heap (priority_queue or maxheap) which will be take occurrences from map
  and will return in descending order , so that we can remove at least half elements from array using minimum set of imtegers
*/

#include <iostream>
#include <map>
#include <queue>
using namespace std;

class Solution {
public:
    
    int minSetSize(vector<int>& arr) {
        
    map<int,int>mp;
    for(int i=0;i<arr.size();i++)
    {
        mp[arr[i]]++;
    }
    
    priority_queue<int>pq;
    
    for(auto i : mp)
    {
        pq.push(i.second);
    }
        
    int remove_count = 0;
    int currsize = arr.size();
    
    while(currsize >  arr.size()/2)
    {
        int top = pq.top();
        currsize -= top;
        pq.pop();
        remove_count ++; 
        
    }

  return remove_count;
        
  }
};

int main() 
{
    cout<<"\nEnter number of test cases: ";
	int t; cin>>t;  //no. of test cases

	/*
	Constraints:
    1 <= arr.length <= 105
    arr's length is even.
    1 <= arr[i] <= 105
    */

	while (t--)
	{
	    cout<<"\n\nEnter number of elements in array: ";
	    int n; cin>>n;

	    vector<int> arr (n);

	    cout<<"\nEnter integers in array ( Input ): ";
	    for (int i=0; i<n; i++)
	        cin>>arr[i];

	    Solution *ob;
        cout<<"\nMinimum elements in set required to remove atleast half of the elements are :";
	    cout <<  ob-> minSetSize(arr);
	    
	}
	return 0;
}

/*
SAMPLE INPUT
2				         // number of test cases 
6				         // size of the array for test case:1
7 3 4 3 3 4  	         // integers array / vector for test case:1
10				         // size of the array for test case:2
5 5 5 4 4 5 1 2 2 4      // integers array / vector for test case:2
 
SAMPLE OUTPUT (excluding interactive instructions)
1   ( for test case-1 only by removing occurrences of 1 element(i.e 3) array will be of half in size )
2   ( for test case-2 we need to remove occurrences of atleast 2 elements (i.e. {5,4} or {5,2}) to make array of size <= half )

COMPLEXITY ANALYSIS : N= no.of cards in desk 
Time : O(N) to iterate array/vector and save frequencies or . 
       O(NLogN) for creating maxheap or inserting elements in priority_que
       Hence, O(NlogN) overall.
Space: O(N) for inputs and aux space: O(N) to re-create a queue.
       Hence, O(N) overall.
*/