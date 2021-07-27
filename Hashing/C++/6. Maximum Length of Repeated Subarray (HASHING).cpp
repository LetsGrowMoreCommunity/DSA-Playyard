
// Maximum Length of Repeated Subarray

/*

Question : We will be given two array A and B of any size, and we need to compute the Maximum length of subarray which is present in both.

Algorithm :
	We will use hashing algorithm to solve this problem.
	First will make a hash table for array A, to store the index of each element of A.
	Then for each element of array B, will loop through the size of the hash value of that array B element and update the ans accordingly

*/


#include<bits/stdc++.h>
using namespace std;

int max_length_of_repeated_subarray(int a[ ], int b[ ], int n, int m) 
{
	// ans variable defined to store the answer of max length and initialized to 0
    int ans = 0;
    // unordered map taken for storing hash value of array a
    unordered_map<int, vector<int>> hash_a;
    for (int i=0;i<n;i++) 
	{
        hash_a[a[i]].push_back(i); // stored indices of each array element in hashtable
    }
    
    // Now we loop through all the element of array b
    for (int i=0;i<m;i++) 
	{
		// and for each element of B, we loop through the value of size of hash value for that value 
        for (int j = 0; j < hash_a[b[i]].size(); j++) 
		{
            int k = 0;
            // for each of i and j we check the condition for maximum subarray length
            while (i+k<m && hash_a[b[i]][j] + k<n && b[i+k]==a[hash_a[b[i]][j]+k]) 
			{
				k++;// and if satisfies will keep on updating the values of k
			}
			// updating the ans if k we got is greater than previous ans
            if(k>ans)
            ans = k;
        }
    }
    return ans;//returning the final answer
}

int main()
{
	// declared two variable n and m, for size of both array
	int n,m;
	// taking input of both array size
	cin>>n>>m;
	// declared two array a and b of size n and m respectively.
	int a[n], b[m];
	// taking input of the element in array a
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	// taking input of the element in array b
	for(int i=0;i<m;i++)
	{
		cin>>b[i];
	}
	
	// function called for finding the maximum lenght of repeated subarray
	cout<<"The Maximum length of repeated subarray is  :  "<<max_length_of_repeated_subarray(a,b,n,m)<<endl;
	
	return 0;
}

/*

Time Complexity : O(n*m*k)
Space Complexity : O(n)

Sample testcase :
Input 1 :
	5
	5
	10 23 17 2 3
	23 17 4 5 19
Output 1:
	The Maximum length of repeated subarray is  :  2
	
Input 2 :
	5
	4
	7 3 5 6 1
	3 2 4 5
Output 1:
	The Maximum length of repeated subarray is  :  1

*/

