/*
-> Problem Statement
Sort given string based on frequency of characters and return sorted string.

-> Approach Explanation:
- First save each character present in string and its frequency in string using map 
- To get characters having maximum frequencies we will use heap (priority_queue or maxheap) having pairs of frequency and character
- Start removing pairs from top of the priority_queue ,concatinate string of top character having length same as frequency 
  so final string will have characters in decreasing order of their frequencies.
*/

#include <iostream>
#include <map>
#include <queue>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        
        map<char,int>mp;
        for(int i=0;i<s.size();i++)
         {
            mp[s[i]]++;                                     // mapping character and frequencies of character
         }
        
        priority_queue<pair<int,char>>freqchar;             // priority_queue of pairs having frequency and character
        for(auto i : mp)
        {
            freqchar.push(make_pair(i.second,i.first));     // frequencies and chracters are pushed in priority_queue respectively as a pair 
        }
        
        string ans;
        while(!freqchar.empty())
        {
            pair<int,char>top = freqchar.top();              // removing pair having maximum frequency with its character in current priority_queue
            ans += string(top.first, top.second);           // concatenating string of character having length same as maximum frequency
            freqchar.pop();                                 // poping top element to get next required pair on top
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
    1 <= input string length <= 5 * 105
    string consists of English letters and digits.
    */

	while (t--)
	{
	    cout<<"\n\nEnter Input String: ";

	    string st;
	    cin>>st;

	    Solution *ob;
        cout<<"\nOutput string sorted in decreasing order of frequency is :";
        cout << ob-> frequencySort(st);
         
	}
	return 0;
}

/*
SAMPLE INPUT
3				         ( number of test cases )
kbbkuiwww				 ( input string for test case:1 )
abcbaadeeef 	         ( input string for test case:2 )
lmrrltmlrluttuu		     ( input string for test case:3 )

SAMPLE OUTPUT ( excluding interactive instructions )
wwwkkbbui     ( characters should be in decreasing order of frequencies i.e w->3, k->2, b->2, u->1, i->1 )
eeeaaabbfdc   ( order of characters can be different if characters have same frequency ,every string having characters in decreasing order of frequencies will be a valid answer)
lllluuutttrrrmm

COMPLEXITY ANALYSIS : N= no.of characters in string 
Time : O(N) to iterate string and save frequencies . 
       O(NlogN) for creating maxheap or inserting elements in priority_que
       Hence, O(NlogN) overall.
Space: O(N) for inputs and aux space: O(N) to create priority_queue.
       Hence, O(N) overall.
*/