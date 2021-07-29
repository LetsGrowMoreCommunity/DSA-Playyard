
// Longest Happy Prefix (HASHING)

/*

Question : We will be given a string s, and we need to compute the longest prefix which is also a suffix.

Algorithm :
	In the we use to precompute the an array, which tells us about the longest prefix which is also suffix.
	so we will find the that array and form a string of length equals to last element in vector, and will return that string
*/


#include<bits/stdc++.h>
using namespace std;

// main function defined to get the length of longest happy prefix
string longest_happy_prefix(string &input_string)
{
	// vector created to store the length of longest happy prefix from from each index 
    vector<int> temp;
	for(int i=0;i<input_string.length();i++)
	{
		temp.push_back(0);
	}
    
    // temporary variable taken to keep track od index
    int idx = 0;
    for(int i = 1; i < input_string.length();i+=0)// we loop through length of input string 
    {
    	// if character at index i matches with character at index idx
        if(input_string[i] == input_string[idx])
        {
            idx++;// we increase the value of idx 
            temp[i] = idx;// insert that idx value in temp vector, since this is the length of prefix which is suffix also
            i++;
        }
        // else is characters don't matches, then we need to update the idx value to the new value
        else
        {
        	if(idx==0)
        	{
        		i++;//incremented i
			}
			else
            {
            	idx = temp[idx-1];// idx updated
			}
        }
    }
    
    // now the length of the longest happy prefix is the last element in temp vector,
    // so we form a string pf that length
    string ans = "";
    for(int i=0;i<temp.back();i++)
    {
    	ans += input_string[i];
	}
	
	// return the longest happy prefix
    return ans;
}

int main()
{
	// declared two variable n and m, for size of both array
	string input_string;
	// taking input of both array size
	cin>>input_string;
	
	// function called for finding the maximum lenght of repeated subarray
	cout<<"The Longest Happy Prefix is  :  "<<longest_happy_prefix(input_string)<<endl;
	
	return 0;
}

/*

Time Complexity : O(n)
Space Complexity : O(n)

Sample testcase :
Input 1 :
	anyonecananyone
Output 1:
	The Maximum length of repeated subarray is  :  anyone
Explaination :
	In the input string "anyonecananyone", the length of longest happy prefix is "anyone", because we can see that in the inputstring substring "anyone" 
	is present from index 0 to 5 and other is from 9 to 14.
	Thus we can say the substring "anyone" may be one of the happy prefix.
	Now if we add one more character in "anyone", like we take "anyonec", we can clearly see that this substing is not suffix also.
	So "anyone" substring should be the longest happy prefix.

Input 2 :
	luckyfool
Output 1:
	The Maximum length of repeated subarray is  :  l
Explaination :
	In the input string "luckyfool", the length of longest happy prefix is "l", because we can see that in the inputstring substring "l" 
	is present as the first letter and the last letter.
	Thus we can say the substring "l" may be one of the happy prefix.
	Now if we add one more character in "l", like we take "lu", we can clearly see that this substing is not present as suffix also.
	So "l" substring should be the longest happy prefix.

*/

