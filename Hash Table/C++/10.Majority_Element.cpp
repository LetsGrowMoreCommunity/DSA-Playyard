/*
-> Problem Statement
- You are given an array/vector. Return an element that appears more than n/2(or actually floor of n/2) from array.
- This element is called Majority element , assume majority element always exists in the array.

-> Approach Explanation:
- We will use HashTable(map) with key as number and value as its frequency. Here majority element will also be element having maximum frequency.
- First start by assuming max frequency is 1 and majority element having that frequency is first element (as size of the array >=1)
- now increase frequency count and map it for each element by traversing array.
- while traversing array if frequency of any element found maximum then say it majority element and after completion of traversal return final majority element.  
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {

        unordered_map<int, int> map;
        int res = 1;
        int majelem = nums[0];
        for (int i=0; i<nums.size(); i++)
           {
                map[nums[i]]++;                // mapping element with its frequency got so far
                if (map[nums[i]]>res)          // if frequency of any element is maximum then it is majority element till this point
                {
                    majelem = nums[i];         
                    res = map[nums[i]];
                }
            }
        return majelem;                       // return final majority element
    }
};

int main() 
{
    cout<<"\nEnter number of test cases: ";
	int t; cin>>t;  //no. of test cases

	/*
	Constraints:
    1 <= array's length <= 5 * 10^4
    -2^31 <= value of any array element <= 2^31 - 1
    */

	while (t--)
	{
	    cout<<"\n\nEnter number of elements in array : ";
	    int n; cin>>n;

	    vector<int> nums(n);

	    cout<<"\nEnter integers in array : ";
	    for (int i=0; i<n; i++)
	        cin>>nums[i];

	    Solution *ob;
        cout<<"Majority element in given array is : ";
	    cout <<  ob-> majorityElement(nums);
	    
	}
	return 0;
}

/*
SAMPLE INPUT
3				               // number of test cases / strings
14                             // no.of integers in array for test case:1
4 2 6 4 2 4 4 6 4 4 6 4 2 4	   // integers for test case:1 	             
9				               // no.of integers in array for test case:1	   
-2 5 -2 4 3 -2 -2 3 -2         // integers for test case:2 
 
SAMPLE OUTPUT (excluding interactive instructions)
4  ( majority element appearing 8 times in 14 elements )
-2  ( majority element appearing 5 times in 9 elements )

COMPLEXITY ANALYSIS : N= no.of integers in array
Time : O(N) to iterate array and map frequencies. 
Space: O(N) for input array and aux space: O(N-N/2) ~ O(N) for map 
       Hence, O(N) overall.
*/