/*Algorithm: 
We will use map to store the Long and short Url. For each shorten Url "http://tinyurl.com/" will be commom 
plus some unique id is given to the Long url. So we will take any global number and increment it and concatenate it with common 
url for encoding. For decoding simply use the map and return the Long Url

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    unordered_map<string,string>m;
    int s=0; //unique id number

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        
        s++; //incrementing

        string ans="http://tinyurl.com/"; //common url
        ans+= to_string(s); //concatenating

        m[ans]=longUrl; //storing it in map
    
        return ans;
        
        
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {

        return m[shortUrl]; //returning decoded url using map
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
        string shortUrl=ob.encode(s);
        string longUrl=ob.decode(shortUrl);

        cout<<longUrl<<" "<<shortUrl<<endl;
    }
    return 0;
}

/*
Input: url = "https://leetcode.com/problems/design-tinyurl"
Output: "https://leetcode.com/problems/design-tinyurl"

Explanation:
Solution obj = new Solution();
string tiny = obj.encode(url); // returns the encoded tiny url.
string ans = obj.decode(tiny); // returns the original url after deconding it.

*/