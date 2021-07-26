/*Algorithm: 
We will use stack for flattening. 
NestedIterator : Put all the list and integers from nestedList to stack .
next() : Pop top of stack and check for interger. If integer then return its value.
hasNext() : Keep poping from stack. If the element is integer then return true else keep flattening nestedList by
pushing each element of of list in stack individually.
*/

#include <bits/stdc++.h>
using namespace std;

class NestedIterator 
{
   
public:
    stack<NestedInteger *>s;
  
    
    NestedIterator(vector<NestedInteger> &nestedList) 
    {
        for(int i=nestedList.size()-1;i>=0;i--)
        {
            s.push(&nestedList[i]); //putting nestedlist in stack
        }
        
        
    }
    
    int next() {
        int val= s.top()->getInteger(); // Poping from stack
        s.pop();
        return val; //returning integer value
        
        
        
    }
    
    bool hasNext() 
    {
        while(!s.empty())
        {
            NestedInteger *top=s.top(); //poping from stack
            
            if(top->isInteger()) //if integer
                return true;
            else
            {
                vector<NestedInteger>&curr=top->getList();
                
                s.pop();
                for(int i=curr.size()-1;i>=0;i--)
                    s.push(&curr[i]); //pushing elements of list in stack (flattening the nestedList)
            }
                
                
            
        }
        return false;
        
    }
};

// Time Complexity : O(N)
// Space Complexity : O(N)
/*
Input: nestedList = [1,[4,[6]]]
Output: [1,4,6]
Explanation: By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,4,6].

*/