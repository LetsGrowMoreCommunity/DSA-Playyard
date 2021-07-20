/*
Problem: Excel Sheet Column Title on LeetCode
Solution by AtrikGit6174
A simple iterative solution to continously divide base-10 number and generate a 
pseudo-base-26 character corresponding to the column title
*/

#include <iostream>
#include <string>
using namespace std;

class Solution 
{
public:
    string convertToTitle(int n) 
    {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        
        string str= "";
        
        while (n)
        {
			/* n%26==0 is a special case and hence, has to be treated separately. 
			This is because counting starts from A==1 and Z is 25th wrt A.
			*/
            str= ((n%26) ? char(n%26 + 64) : 'Z') + str;
            n= (n/26) - ((n%26) ? 0 : 1 );
        }
        
        return str;        
    }
};

int main() 
{
	int t; cin>>t;  //no. of test cases
	
	while (t--)
	{
	    cout<<"Enter number in [1, 2147483647]: ";
	    int n; cin>>n;
	    
	    Solution *ob;
	    cout<<"\n"<<ob->convertToTitle(n)<<"\n";
	}
	return 0;
}

/*
SAMPLE INPUT
4           	<-- NO. OF TEST CASES
1				<-- FIRST ALLOWED COLUMN NUMBER
28
701
2147483647		<-- LAST ALLOWED COLUMN NUMBER

SAMPLE OUTPUT (excluding interative instructions)
A           
AB          
ZY          
FXSHRXW
*/
