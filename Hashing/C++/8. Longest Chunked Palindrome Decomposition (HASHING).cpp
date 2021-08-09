
// Longest Chunked Palindrome Decomposition (Hashing)

/*

Question : We will be given a string s, and we need to split the string into small small k chunks, such that the two chunked string in positii=on opposite to one other must be same.

Algorithm :
	We will aplly rolling hash algorithm, where we will form two hash value, one for suffix substring and other for prefix substring,
	and for each index we keep on checking comparing the hash values, and if they come to be same, then we unsergo further recursion with new range.
	And this way we get the count of maximum no. of chunks.
*/


#include<bits/stdc++.h>
using namespace std;
# define mod 1000000007 // this is the prime number we take to generate the hash values in limited range of numbers


// main function defined to get the largest value of k chunks
int longest_chunked_palindrome_decomposition(string input_string, int min_index, int max_index) 
{
	// condition defined to terminate the recursion at this point
    if (min_index >= max_index)
    {
    	return 0;
	}
	
	// defined temporary variable
	int x = 1;
	
    // now as we are using rolling hashing algorithm, we need two hash value, one for prefix substring and other for suffix substring
    int substring_pre_hash = 0;
    int substring_su_hash = 0;
    
    int i=0;
    // looping through half of the loop
    while(i<(max_index - min_index)/2)
    {
    	// tempoaray variable defined to get the additinal part that we need to add to the hash value of both prefix and suffix
    	int temp1 = input_string[min_index + i] - 'a';
    	int temp2 = input_string[max_index - i - 1] - 'a';
    	
    	temp1 = temp1 * x;
    	substring_su_hash = substring_su_hash * 26;
    	x = (x%mod * 26)%mod;
    	
    	// now we need to generate the prefix substring hash value and the suffix substring hash value with the help of prime number defined
        substring_pre_hash = (substring_pre_hash%mod + temp1%mod) % mod;
        substring_su_hash = (substring_su_hash%mod + temp2%mod) % mod;
        
        
        // after we have found the hash value for suffix and prefix, we compare both and if they came to be equal, then we go for further checkin using recursion
        if (substring_pre_hash == substring_su_hash) 
		{
			// defined the new upper and lower index for going through recursion
			int min1 = min_index + i + 1;
			int max1 = max_index - i - 1;
			
			//undergone recursion for the new value of min and max index
            return longest_chunked_palindrome_decomposition(input_string, min1, max1) + 2;  
        }
        i++;
	}
	
	// at final if we fail to find any such chunk in the string, we return 1, as the input string cannot be divided into small chunks
    return 1;
}

int main()
{
	// declared string as input_string
	string input_string;
	// taking input of string
	cin>>input_string;
	
	// decalred two variables and assigned accordingly
	int min_index = 0;
	int max_index = input_string.length();
	
	// function called for finding the largest k chunks value after splitting 
	cout<<"The Maximum value of k is  :  "<<longest_chunked_palindrome_decomposition(input_string, min_index, max_index)<<endl;
	
	return 0;
}

/*

Time Complexity : O(n)
Space Complexity : O(1)

Sample testcase :
Input 1 :
	lgmsociswhatislgmsoc
Output 1:
	The Maximum value of k is  :  5
Explaination :
	Here we can see that in string, prefix "lgmsoc" is same as suffix "lgmsoc", and second prefix "is" is same as last 2nd suffix "is", and  substring "what" is left as it is,
	as it cannot be chunked further as palindromes.
	thus the maximum value of chunks is 5 and that are ["lgmsoc","is", "what", "is", "lgmsoc"]
	
Input 2 :
	nowyouseeme
Output 1:
	The Maximum value of k is  :  1
Explaination :
	Here we can see that there us no prefix whiich is also equal to suffix, therefore here will not be able to chunks this string to further samller substrings,
	this answer of maximum chunk is 1 ,and that is the input string itself.

*/

