/* Algorithm:
We will traverse the string and if sign will be '+' or '-', we will push the number with sign in the stack as the priority of
+ and - is less than / or *. If the sign will be / or * ,we will pop the number from stack and do the arthimetic operation
and then again push the obtained ans. At last we will add all the numbers of stack and then return it as answer.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int calculate(string s) 
    {
        
        stack<int>st;
        int n=s.length();
        int i=0,num=0,ans=0;
        char sign='+'; //initialising sign
        
        while(i<n)
        {
             if(isdigit(s[i])) //If digit
            {
                 num=0;
                while(i<n && isdigit(s[i])) 
                {
                     num=num*10+int(s[i]-'0'); // Calculating number
                    i++;
                    
                }
                i--;
                if(sign=='+')
                    st.push(num); //pushing to stack
                else
                {
                    if(sign=='-')
                    {
                        num=-num;
                        st.push(num); //pushing negative number into stack
                    }
                    else
                    {
                        if(sign=='/')
                        {
                            int a=st.top();
                            st.pop(); //poping top number
                            int ans=a/num; //dividing
                            st.push(ans); //pushing back again after dividing
                            
                        }
                        else
                        {
                             int a=st.top();
                            st.pop(); //poping top number
                             ans=a*num;
                            st.push(ans); //pushing back again after multiply
                            
                        }
                    }
                }
                  
            }
            else
            {
                if(s[i]!=' ') //if not space 
                {
                    sign=s[i]; //if any operator
                    
                    
                }
            }
            i++;
            
        }
        ans=0;
        
        while(st.size()>0)
        {
            ans=ans+st.top(); //calculating answer
            st.pop();
            
        }
        
        return ans;
        
        
    }
};

int main() 
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.calculate(s)<<endl;
    }
    return 0;
}

/*

Input: s = " 3+5 / 2 "
Output: 

*/