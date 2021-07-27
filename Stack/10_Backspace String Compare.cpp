//time complexity 0(N)

class Solution {
public:
    bool backspaceCompare(string S, string T) {
            
         stack <int> s1,s2;//taking input for stacks
         string str1,str2; 
            
         for(int i = 0; i < S.size(); i++){
                 
                 if(S[i] == '#' && !s1.empty())
                         s1.pop();//pop if # present
                 
                 else if(S[i] != '#')//others are pushed except #
                         s1.push(S[i]);
                 
         }
         
         for(int i = 0; i < T.size(); i++){
                 
                 if(T[i] == '#' && !s2.empty())
                         s2.pop();
                 
                 else if(T[i] != '#')//others are pushed except #
                         s2.push(T[i]);
                 
         }
            
         while(!s1.empty()){
                 
                 str1.push_back(s1.top());//printing the elements in the stack s1
                 s1.pop();
                 
         }
            
         while(!s2.empty()){
                 
                 str2.push_back(s2.top());
                 s2.pop();///printing the elements in the stack s2
                 
         }      
            
         return str1 == str2;   //check if they are equal or not
    }
};
int main()
{

    string S,string T;
    cin>>S>>T;
    backspaceCompare(string S, string T);
    return 0;

}
/*Example 1:

Input: s = "ab#c", t = "ad#c"
Output: true
Explanation: Both s and t become "ac".
Example 2:

Input: s = "ab##", t = "c#d#"
Output: true
Explanation: Both s and t become "".
Example 3:

Input: s = "a##c", t = "#a#c"
Output: true
Explanation: Both s and t become "c"/*