class Solution {
public:
    int countConsistentStrings(string s, vector<string>& v) {
        int ans=0;
        unordered_map<char,int>mp;//stores the character and its freq
        
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