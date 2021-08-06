/*
-> Problem Statement
- Find First no-repeating characher in given string and return its index. If does not exist return -1.

-> Approach Explanation:
- First traverse the string, save frequency of each character in array and push indexes of elements in queue when frequency of character becomes one.
- Now pop indexes from queue having character frequency > 1 
- If non-repeating character will be there then queue's first element would be that character, return it or -1 if queue is empty
*/

#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        
        int freq[26];
        queue<int>q;
        memset(freq,0,sizeof(freq));               
        
        for(int i=0;i<s.size();i++)
        {                                                          
            if(++freq[s[i]-'a'] == 1)                      // saving frequency of lowercase letters 
                q.push(i);                                  // pushing indexes when frequency becomes one to maintain order of characters
                                   
        }                               
        while(!q.empty() && freq[s[q.front()]-'a'] > 1)    // poping front indexes till frequency of its element is > 1 and queue is not empty 
            q.pop();
        
        return !q.empty() ? q.front() : -1;                // returning first index from q's front if queue is not empty else -1
    }
};

int main() 
{
    cout<<"\nEnter number of test cases/strings you have to check: ";
	int t; cin>>t;  //no. of test cases

	/*
	Constraints:
    1 <= string's length <= 10^5
    string consists of only lowercase English letters.
    */

	while (t--)
	{
	    cout<<"\n\nEnter String ( Input ): ";
	    string s; cin >> s;

	    Solution *ob;
        cout<<"First non-repeating index in string is  :";
	    cout <<  ob-> firstUniqChar(s);
	    
	}
	return 0;
}

/*
SAMPLE INPUT
3				         // number of test cases / strings
leetcode				 // string for test case:1 	             
codeforces				 // string for test case:2 	   
lgmsocletsgrowmore         // integers array / vector for test case:2
 
SAMPLE OUTPUT (excluding interactive instructions)
0  ( index 0 for non-repeating 'l' )
2  ( index 2 for non-repeating 'd' )
5  ( index 5 for non-repeating 'c' )

COMPLEXITY ANALYSIS : N= no.of characters in string
Time : O(N) to iterate string and maximum O(N) to traverse and pop from queue. 
       Hence, O(N) overall.
Space: O(1) for stringinput and aux space: O(1) for fixed max size 26 of array or queue.
       Hence, O(1) overall.
*/