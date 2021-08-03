/*Algorithm: 
Considering smaller string as str1, we will consider all substrings of str1 which can be GCD ,starting from maximum length.
If the length of any substring of str1 is multiple of length of str1 and str2 and divide both str1 and str2, then that substring
is GCD of two given strings.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string gcdOfStrings(string str1, string str2) 
    {
        if(str1.length()>str2.length()) //considering str1 as smaller string
            swap(str1,str2);
        
        for(int n=str1.length();n>=1;n--)//considering all possible substring
        {
            if(str1.length()%n!=0) //size of substring is not multiple of str1
                continue;
            
            if(str2.length()%n!=0)//size of substring is not multiple of str1
                continue;
            
            string s=str1.substr(0,n); //possible substring
            
            int f=0;
            
            for(int i=0;i<str1.length();i+=n)
            {
                if(s!=str1.substr(i,n)) // substring s is not diving str1
                {
                    f=1;
                    break;
                }
            }
            
            if(f==1)
                continue;
            
            f=0;
                
            for(int i=0;i<str2.length();i+=n)
            {
                if(s!=str2.substr(i,n)) // substring s is not diving str2
                {
                    f=1;
                    break;
                }
            }
            
            if(f==0)
                return s; //substring found
            
            
            
        }
        return "";
        
    }
};

int main()
{
    string s,t;
    cin>>s>>t;

    Solution obj;
    string ans=obj.gcdOfStrings(s,t);
    
    cout<<ans<<endl;


}

//Time Complexity: O(n*n)
//Space Complexity: O(1)

/*
Input: str1 = "ABABAB", str2 = "ABAB"
Output: "AB"
Explanation : AB is the longest positive string which can divide str1 and str2.

Input: str1 = "LEET", str2 = "CODE"
Output: ""
Explanation : There is no such string which can divide both str1 and str2

*/