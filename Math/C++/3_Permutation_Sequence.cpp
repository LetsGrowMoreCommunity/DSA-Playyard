/*
-> Problem Statement
- Given integers n and k, take a set having numbers [1,2,3,...,n]
- Return kth permutation (lexicographically) for string having characters as 1 to n.

-> Approach Explanation:
- We will find every character of required answer string one by one.
- First we can have n! string permutations which can be grouped in n groups by fixing first character as one of n characters.
- find which group( or which first character group) can contain answer string by taking total permutaions / strings in each groyp.
- so first character will be found from that group this way , include it in answer string and remove from nums array.
- here nums array is array having numbers 1 to 9, also we will maintain fact which will tell us size of each group in every  recursion.
- problem is now redused to n-1 numbers now we need to find which group having strings of size n-1 will have first character as answer's next character.
- for this new reduced problem now fact is smaller fact number that can be found by deviding old fact by new nums size and k will be last k % newfact. 
- now keep recursing similarly take characters from matching groups and add in string untill you get all characters in answer and nums array empty.

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public: 
    string getPermutation(int n, int k) {
        
        vector<int>nums;
        string ans = "";
        int fact = 1;
        for(int i=1;i<n;i++)
        {
            fact = fact * i;                        // fact for n-1
            nums.push_back(i); 
        }
        nums.push_back(n);                          // pushing all numbers 1 to n to nums array
        k = k-1;                                    // k for index starting from 0
        while(true)
        {
            int indchose = k / fact;                // this index will be used to find next character for answer
            ans = ans + to_string(nums[indchose]);  // nums array element at this index is the next haracter
            nums.erase(nums.begin() + indchose);    // remove character which is selected in anser string
            if(nums.size()==0)
               break;
            k = k % fact;                           // new k which will be applied for that selected index group now
            fact = fact / nums.size();              // group sizes will be decreasing to fact less then current fact
        }                                           // that we can get from size of new nums array
        
        return ans;
    }
};

int main() 
{
    cout<<"\nEnter number of test cases: ";
	int t; cin>>t;  //no. of test cases

	/*
	Constraints:
    1 <= n <= 9
    1 <= k <= n!
    */

	while (t--)
	{
	    cout<<"\n\nEnter integer n : ";
	    int n; cin>>n;

        cout<<"\nEnter integer k : ";
	    int k; cin>>k;

	    Solution *ob;
        cout<<"\nkth permutation sequence for integers 1 to "<< n <<" is  :";
	    cout <<  ob-> getPermutation(n,k);
	    
	}
	return 0;
}

/*
SAMPLE INPUT
2				// number of test cases 
5               // n for test case : 1 
94				// k for test case : 1   	         	               
8               // n for test case : 2 
10456			// k for test case : 2 

SAMPLE OUTPUT (excluding interactive instructions)
45231           // 94th permutaion of "12345"  
31627584        // 10456th permutation of "12345678"

COMPLEXITY ANALYSIS : N = number n used for numbers in array (1 to n)
Time : O(N*N) since O(N) for selecting one element and O(N) to erase that element from nums every time
Space: O(N) for inputs and aux space: O(N) for nums array and to store answer string
*/