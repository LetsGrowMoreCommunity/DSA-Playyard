class Solution {
public:
    bool isValid(string s) {//taking an input string
        stack<char>x;//taking the stack
        for(int i = 0; i < s.size(); i++)//iterating over s
        {
            if(s[i] == ')' || s[i] == '}' || s[i] == ']')//Checking if the closing brackets are present or not
            {
                if(x.empty() || s[i] == ')' && x.top() != '(' || s[i] == '}' && x.top() != '{' || s[i] == ']' && x.top() !='[')
                    return false;//if the opening and the closing brackets are not present simultaneously or not thenit will return false
                x.pop();       
            }
            else
                x.push(s[i]);
        }
       return x.empty();//if x is empty then it will return true else false
    }
};
//Accepted
//Runtime: 0 ms
//Your input
//"()"
//Output
//true

Expected
true