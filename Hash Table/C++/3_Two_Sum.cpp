/*

Problem: Two Sum

Description:
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
It is assumed that each input would have exactly one solution, and the same element is not used twice.

This solution returns the indices of the array nums that sum up to obtain target in random order.

Note:
2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
Only one valid answer exists.

*/

#include<iostream>
#include<bits/stdc++.h>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        int l;
        l=nums.size(); // l->size of the input array.
        
        
        for(int i=0;i<(l-1);i++) {  // This loop i goes from 0 to l-1.
            for(int j=(i+1);j<l;j++) { // This loop goes from i+1 to l.
            	
                int sum = nums[i]+nums[j];
                // If sum = target, add indices to answer array, also breaks the loop.
                if(sum==target) {
                    ans.push_back(i);
                    ans.push_back(j);
                    break;
                }
            }
        }
        return ans;
    }
};

int main() {
	
	int t;
	cout<<"Enter number of testcases: ";
	cin>>t; // Number of testcases.
	
	for(int tc=0;tc<t;tc++) {
		
		Solution* s = new Solution;
		
		cout<<"Enter the size of array: ";
		int sz;
		cin>>sz; //Size of the input array
		
		vector<int> ar(sz);
		
		cout<<"Enter array values: "; 
		// Array values
		for(int a=0;a<sz;a++) {
			cin>>ar[a];
		}
		
		// Target
		cout<<"Enter target: ";
		int tar;
		cin>>tar;
		
		vector<int> answer;
		
		answer=s->twoSum(ar,tar);
		
		// Outputs the answer
		cout<<"Output: ";
		for(int o=0;o<(answer.size());o++) {
			cout<<answer[o]<<" ";
		}
		cout<<endl;
	}
	return 0;
}

/*
//Accepted

First line represents the number of testcases.
First input of every line represents the size of array. let's say n.
Next n elements of the same line represent the array elements.
Last element of every line represnts the corresponding target.

SAMPLE INPUT:
3                       -> Number of testcases
4 2 7 11 15 9           -> First testcase.  
3 3 2 4 6
2 3 3 6

SAMPLE OUTPUT: (Exclusive of interactive statements)
0 1                     
1 2
0 1

Explanation:
Testcase 1:
Input array(say nums): [2 7 11 15]. Target=9
Output array: [0 1] which represent the indices of the input array that sum up to the target i.e., nums[0]+nums[1]=9 (Because 2+7=9).

Same for all the testcases.

Time Complexity: O(n^2)  
n = Size of the input array

*/
