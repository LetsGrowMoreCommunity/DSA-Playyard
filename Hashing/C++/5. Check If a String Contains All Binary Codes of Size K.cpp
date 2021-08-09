/*
-> Problem Statement
Given a binary string s and an integer k. 
Return true if every binary code of length k is a substring of s, Otherwise, return false.

-> Approach Explanation:
- We can have 2^k codes of length k, so we need to find if we get all codes as string's substrings.
- As we can perform bitwise operators directly on desimal we will use desimal number as hash for substrings.
- we can get hash for each substring for previous hash , which we call 'Rolling Hash'.
- In Rolling hash to get new hash we shift left old hash first, then to make it of length k if do bitwise & with 1's of length k.
  then bitwise | with last digit of new/current string given new hash.
- Using above steps we consider hashes converted from substrings and if its new hash / code then we consider it under count.
  If final count is 2^k then we return true else return false
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        
        int reqcodes = 1 << k;                                  // required count of codes we need from substrings
        vector<bool>codes(reqcodes,false);
        int allone = reqcodes - 1;                              // all one's code : 111...k times or 2^k-1
        int hash = 0;                                           // initially code = 000...k times or zero
        
        for(int i=0;i<s.size();i++)
            {
                hash = ((hash << 1) & allone) | (s[i] - '0');   // new hash = ((old hash << 1) & allone) | last digit of new hash
                    
                if(i>=k-1 &&  !codes[hash])                     // consider hash if converted from string's substring and not got before
                {
                    codes[hash] = true;
                    reqcodes--;                                 // if new code is found then reduse required count
                    if(reqcodes == 0) 
                        return true;
                }
            }
        return false;                                           // codes present in string are < 2^k
        
    }
};

int main() 
{
    cout<<"\nEnter number of test cases: ";
	int t; cin>>t;  //no. of test cases

	/*
	Constraints:
    1 <= string length <= 5 * 10^5
    string characters are either '0' or '1'
    1 <= k <= 20
    */

	while (t--)
	{
	    cout<<"\n\nEnter Binary String : ";
	    string s; cin >> s;

	    cout<<"\nEnter integer K : ";
        int k; cin >> k;

	    Solution *ob;
        cout<<"\nIs every binary code of length l is substring of s ? : ";
	    ob-> hasAllCodes(s,k) ? cout<< "Yes" : cout<< "No";
	    
	}
	return 0;
}

/*
SAMPLE INPUT
2				         // number of test cases 
0000000001011100		 // binary string  for test case:1
3  	                     // value of k for test case:1
0010011111011100         // binary string for test case:2
5			             // value of k for test case:2
      
SAMPLE OUTPUT (excluding interactive instructions)
Yes  ( all codes of length 3 are present inside string )
No   ( some codes of length 5 are not present inside string )

COMPLEXITY ANALYSIS : N= no.of elements in array
Time : O(N) to iterate string and O(1) to calculate the hash of each substring. 
       Hence, O(N) overall.
Space: O(2^k) aux. space for vector of size 2^k.
*/