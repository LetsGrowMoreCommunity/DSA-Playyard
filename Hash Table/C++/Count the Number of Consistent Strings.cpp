//time complexity of the code is 0(N)

///this problem is done using concept of hashing(distributing key and value pairs)
#include <iostream>
using namespace std;
    int countConsistentStrings(string s, vector<string>& v) {
        int ans=0;
        unordered_map<char,int>mp;//stores the character and its freq and we dont want any duplicate ones

        for(auto x:s)mp[x]++;//checks if present 

        for(auto x:v){
            int i=0;
            for(;i<x.size();i++)
                if(mp.find(x[i])==mp.end()) break;//if allowed is not present in words then break

            if(i==x.size())ans++;//if found then increment the ans
        }
        return ans;
    }
};
int main()
{
	string s;
	cin>>s;
	int v[v.size()];
	for (i = 0; i < v.size(); i++) {

     cin >> v[i]; 
    }
	cout <<countConsistentStrings(s) << endl;

    return 0;
}
/*Input: allowed = "ab", words = ["ad","bd","aaab","baa","badab"]
Output: 2
Explanation: Strings "aaab" and "baa" are consistent since they only contain characters 'a' and 'b'.
Input: allowed = "abc", words = ["a","b","c","ab","ac","bc","abc"]
Output: 7
Explanation: All strings are consistent./*
