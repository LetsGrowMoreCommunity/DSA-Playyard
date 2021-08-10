
// Find all numbers disappeared in an array (HASHTABLE)

/*

Question : In this we will be given an array with [1,n] numbers, we need to find all the numbers that are not in that array between [1,n]

Algorithm :
	In this first we will insert all the array elements inside a hashtable.
	Then we iterate from 1 to n, and check which is not present in hashtable, and keep inserting that element in the ans array
	And finally return that ans array
*/


#include<bits/stdc++.h>
using namespace std;

// main function defined to get the array with disappeared numbers
vector<int > all_disappeared_numbers(vector<int > v)
{
	// created a hash table
	map<int, int > mp;
	// created a temp 
	vector<int > temp;
	// inserting the array element in the hashtable
	for(int i=0;i<v.size();i++)
	{
		mp[v[i]] = 1;
	}
	// checking the numbers which are not in hashtable
	for(int i=1;i<=v.size();i++)
	{
		if(mp[i]==0)
		temp.push_back(i);
	}
	//returning the temp array with all disappeared array
	return temp;
}

int main()
{
	// declared variable
	int n;
	vector<int > input_array;
	
	// talking input of n and array
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		input_array.push_back(x);
	}
	
	// function called for finding the maximum lenght of repeated subarray
	vector<int > ans = all_disappeared_numbers(input_array);
	// case when some disapppeared numbers present in array
	if(ans.size()>0)
	{
		cout<<"The numbers in the array which are disappeared are  :  ";
		for(int i=0;i<ans.size();i++)
		{
			cout<<ans[i]<<" ";
		}
	}
	// case when no array element is disappeared
	else
	{
		cout<<"No array element is disappeared"<<endl;
	}
	
	return 0;
}

/*

Time Complexity : O(n)
Space Complexity : O(n)

Sample testcase :
Input 1 :
	10
	2 3 2 3 2 3 2 3 2 3
Output 1:
	The numbers in the array which are disappeared are  :  1 4 5 6 7 8 9 10
Explaination:
	We can see that the element from 1 to 10, which is not present in array are, 1,4,5,6,7,8,9,10
	as in input array only 2 and 3 are present
	
Input 2 :
	10
	1 2 3 4 5 6 7 8 9 10
Output 1:
	No array element is disappeared
Explaination:
	As we can see in the input array,there are all numbers present from 1 to 10, so there will be no disappeared numbers present.

*/

