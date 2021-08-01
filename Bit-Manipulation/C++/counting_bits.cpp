/*                                      LEETCODE PROBLEM #338
                                            COUNTING BITS

    Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), ans[i] is the number of 1's 
    in the binary representation of i.

    Example 1:
    Input: n = 2
    Output: [0,1,1]
    Explanation:
    0 --> 0
    1 --> 1
    2 --> 10

    Example 2:
    Input: n = 5
    Output: [0,1,1,2,1,2]
    Explanation:
    0 --> 0
    1 --> 1
    2 --> 10
    3 --> 11
    4 --> 100
    5 --> 101

    Constraints:

    0 <= n <= 105

    **********APPROACH**********
        USING BIT MANIPULATION 
*/

#include <iostream>
#include <vector>

using namespace std;

//Adding a class of name Solution
class Solution {
public:
    vector<int> countBits(int num) {
        //Defining a vector of type int to store the solution of the problem of size num+1
        vector<int> ans(num + 1);
        for (int i = 0; i <= num; i++) {
            int sum = 0, n = i;
            while (n) {
                sum++;
                n &= (n - 1); 
		// Equivalent to n = n & (n - 1)
		// & means bitwise AND operator, if we do (1 & 0) we get 0, we get 1 only if both n and (n-1) has 1 on same position
		// Example: 
		// Suppose: n =  1100101
		// Then n & (n-1) will be 1100101 & 1100100 => 1100100
            }
            ans[i] = sum;
	    // Now here sum calculated will be assigned to ans of index i
        }
        return ans;
	// We return the ans which stores the solution of our code to the main function
    }
};

int main() {
	
	int n; 
	cin >> n;
	Solution s1;
	// Define an object for the class Solution
	
	vector<int> sol;
	// Calling the function containing our solution using the object: s1
	// Storinig the returned value in vector sol of type int 
	sol = s1.countBits(n);
	
	// We start printing the solution from here
	cout << "[";
	for (int i = 0; i < sol.size(); i++) {
	    cout << sol[i] << ",";
	}
	cout << "]";
	
	return 0;
}

//TEST CASE: 
//INPUT: 2
//OUTPUT: [0,1,1]
