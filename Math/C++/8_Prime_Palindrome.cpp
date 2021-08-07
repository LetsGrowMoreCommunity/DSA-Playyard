/*
-> Problem Statement
- Given an integer n, return the smallest prime palindrome greater than or equal to n.

-> Approach Explanation:
- We will go through each number >=n 
- for each n we will check first if its a palindrome by comparing it with its reverse integer if not then will move to next n
- If any integer is palindrome then we willl check is it a prime, if yes then will return it else will move to next n
- Math is there when we are checking it isprime and isplandrome, also it is found that every 8 length integer wiil be multiple of 11
  So we will check for integer having length 9 which is only 100030001 possible for possible testcases
*/

#include <iostream>
#include <math.h>
using namespace std;

class Solution {
public:
    
     int isprime(int n) {
        if (n <= 1)
            return 0; 
        for (int i = 2; i <= sqrt(n); i++)       // to check prime checking if n is divisible by any possible divisor
            if (n % i == 0)
                return 0;
        return 1;
    }

    int ispalindrome(int n){               
        return n == reverse(n);                 // checking palindrom by comparing n and its reverse
    }
    
    int reverse(int n){
        int rev = 0;
        while (n) {
            rev = rev*10 + n % 10;              // reverse of n can be found by removing digits from back and 
            n /= 10;                            // adding it to front as multiple of 10 of previous reverse
        }
        return rev;
    }
    
    int primePalindrome(int n) {
        if (1e7 <= n and n <= 1e8)             // if length is 8 or 9 we will have only one possible prime palindrom
            n = 100030001;
        while(1){
            while(ispalindrome(n) == 0)
                n++;                           // increase n while not palindrom
            if (isprime(n))
                return n;                      // return if prime else increase n
            n++;
        }
    }
       
};

int main() 
{
    cout<<"\nEnter number of test cases: ";
	int t; cin>>t;  //no. of test cases

	/*
	Constraints:
    1 <= n <= 10^8
    */

	while (t--)
	{
	    cout<<"\n\nEnter integer n : ";
	    int n; cin>>n;

	    Solution *ob;
        cout<<"\nsmallest prime palindrome greater than or equal to "<< n <<" is  :";
	    cout <<  ob-> primePalindrome(n);
	    
	}
	return 0;
}

/*
SAMPLE INPUT
2				    // number of test cases 
930				    // integer n for test case:1 	         
42	                // integer n for test case:2
98292618 			// integer n for test case:3

SAMPLE OUTPUT (excluding interactive instructions)
10301               
101
100030001  

COMPLEXITY ANALYSIS : 
Time : O(N) everytime to check ispalingrom or reverse number or going through each N
       Hence, O(N) overall.
Space: O(1) since checking condition for every n without storing it.
       Hence, O(1) overall.
*/