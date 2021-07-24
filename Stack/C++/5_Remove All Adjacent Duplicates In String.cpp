
//0(n) time complexity
class Solution {
public:
    string removeDuplicates(string s) {
	stack<char> st;//taking the string as a stack
	string ans="";
	for(auto curr:s) {
		if(st.empty()) st.push(curr);//empty then we should push
		else if(st.top() == curr) st.pop();//checks for duplicacy
		else st.push(curr);//if differnt char is there then we should push it
	}

	while(!st.empty()) {
		ans += st.top();
		st.pop();//for printing the elements in the stack
	}

	reverse(ans.begin(), ans.end());//since we store it as a stack hence we need to reverse it

	return ans;
        
    }
};
/*
Input: s = "abbaca"
Output: "ca"
Explanation: 
.

Example 2:

Input: s = "azxxzy"
Output: "ay"/*