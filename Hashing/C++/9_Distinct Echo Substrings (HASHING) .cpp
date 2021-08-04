//brute force approach
//time complexity=0(n2)
//space complexity 0(n)

#include <iostream>
using namespace std;
    int distinctEchoSubstrings(string text) {
        int n=text.length();
        if(n==1) return 0;
        if(n==2){
            if(text[0]==text[1]) return true;//considering the base cases one string can be formed in such case
            return false;
        }
        set<string_view>s;//stored in a set to be in order
        string_view str=text;
        for(int i=0;i<n;i++){//iterating throgufh the string 
           for(int len=2;i+len-1<n;len+=2){//trying to find the substrings
               string_view a1=str.substr(i,len/2);
               string_view a2=str.substr(i+len/2,len/2);//string view is used for some string type interface is used 
               if(a1==a2){//sice its a part of the string concatenated to form one 
                   
                   s.insert(a1);.//inserting all such strings that can be formed
               }
                   
           }
        }
        return s.size();//returning
    }
};
int main(){
string text;
cin>>text;
cout<<distinctEchoSubstrings(text)<<endl;
return 0;   
}
    /*Example 1:

Input: text = "abcabcabc"
Output: 3
Explanation: The 3 substrings are "abcabc", "bcabca" and "cabcab".
Example 2:

Input: text = "leetcodeleetcode"
Output: 2
Explanation: The 2 substrings are "ee" and "leetcodeleetcode"./*
    

