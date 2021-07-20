/*
Problem: Excel Sheet Column Number on LeetCode
Solution by AtrikGit6174
A simple iterative solution to treat each alphabet in the input string as a base-26 number.
*/

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Solution 
{
public:
    int titleToNumber(string col) 
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        
        int ret= 0;
        int n= col.size()-1;
        for (int i=n; i>=0; i--)
        {
            ret+= pow(26, n-i) * (col[i]-64);   //'A'= 65
        }
        
        return ret;
    }
};

int main() 
{
	int t; cin>>t;  //no. of test cases
	
	while (t--)
	{
	    string str;
	    cout<<"Enter str in [\"A\", \"FXSHRXW\"]: ";
	    cin>>str;
	    
	    Solution *ob;
	    cout<<"\n"<<ob->titleToNumber(str)<<"\n";
	}
	return 0;
}

/*
SAMPLE INPUT
4           <-- NO. OF TEST CASES
A           <-- FIRST ALLOWED COLUMN NAME
AB          
ZY          
FXSHRXW     <-- LAST ALLOWED COLUMN NAME

SAMPLE OUTPUT (excluding interative instructions)
1
28
701
2147483647

COMPLEXITY ANALYSIS n= string length
Time: O(n) to traverse the full string and treat the string as a base-26 number
Space: O(n) for input, aux space: O(1)
*/
