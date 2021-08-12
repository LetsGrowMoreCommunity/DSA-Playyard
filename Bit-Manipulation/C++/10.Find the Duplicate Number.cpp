/*
-> Problem Statement
- You are given an array nums having length n+1 and numbers in range [1,n]
- You need to return one and only repeating element from array without modifying array and using constant extra space

-> Approach Explanation:
- We can use bit-manipulation here for given numbers in array. 
- We can have maximum 32 bits representing any desimal number, for each bit we will traverse numbers and maintain two sums 
- for every bit if that bit in array element is 1 then we will increase elesum and also if index's that bit is 1 then we wil increase numsum 
- doing this step for every bit we will have two sumofbits for numbers 1 to n and given elements 1 to n + 1 bit for repeating number
- if numsum > elesum then that says that bit is one in repeating number , so we will set that bit as 1 for answer element 
- after traversing all bits and all numbers for those bits we will have final answer having required 1 bits set that we will return

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    
    int findDuplicate(vector<int>& nums) {
        
        int n = nums.size();                   
        int ans = 0;
        for(int b=0;b<32;b++)
        {
            int numsum = 0;int elesum = 0;     
            for(int i=0;i<n;i++)
            {
                if(i & (1<<b)) numsum ++;        // checking and increasing numsum if number between [1,n] has that bit 1
                if(nums[i] & (1<<b)) elesum++;   // checking and increasing elesum if element of array has that bit 1
            }
            
            if(elesum > numsum)                 // this condition says that bit is 1 in answer, so set it using '|'
              ans = ans | (1<<b);        
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
    1 <= n <= 10^5
    array length = n+1
    1 <= any number in array <= n
    All the integers in nums appear only once except for precisely one integer which appears two or more times.
    */

	while (t--)
	{
	    cout<<"\n\nEnter value of n : ";
	    int n; cin>>n;

	    vector<int> nums (n+1);

	    cout<<"\nEnter integers in range [1,n] for nums array : ";
	    for (int i=0; i<n+1; i++)
	        cin>>nums[i];

	    Solution *ob;
        cout<<"\nOne and only repeating element in array is :";
	    cout <<  ob-> findDuplicate(nums);
	    
	}
	return 0;
}

/*
SAMPLE INPUT
2				       // number of test cases 
6				       // value of n for test case:1
4 1 3 5 6 5 2  	       // integers array / vector for test case:1
8				       // value of n for test case:2
2 1 8 5 6 7 4 7 3      // integers array / vector for test case:2
 
SAMPLE OUTPUT (excluding interactive instructions)
5   
7   

COMPLEXITY ANALYSIS : N= no.of elements in array
Time : O(1) to iterate 32 bits and O(N) to iterate array/vector for that bit 
       Hence, O(N) overall.
Space: O(1) since only constant space required for some variables 
       
*/