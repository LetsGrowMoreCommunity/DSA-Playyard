Time Complexity: O(2^N)
Space Complexity: O(2^N)

#include <bits/stdc++.h>
using namespace std;
class TreeNode{
public:
    vector<TreeNode*> allPossibleFBT(int n) {
	
        if(n&1 == 0)return {}; //FBT can have only odd number of nodes
        if(n == 1)return {new TreeNode()};
		
        vector<TreeNode*>res;
		
        for(int i = 1; i < n-1;i+=2){  //incrementation by 2 to avoid redundant recursive call for even number of nodes
		
            vector<TreeNode*>left = allPossibleFBT(i);
            vector<TreeNode*>right = allPossibleFBT(n-i-1);  //1 is reserved for root node, hence n-i-1
			
            for(auto l : left)
                for(auto r : right)
                    TreeNode* root = new TreeNode(), root->left = l, root->right = r, res.push_back(root);
        }
		
        return res;
        
    } 
};
int main(){
   vector<TreeNode*> v;//declaring a vector
   Solution ob;
   v = (ob.allPossibleFBT(7)) ;// accessing member functions
   for(TreeNode *t : v){
      tree_level_trav(t);//calling the function
   }
}
/*Input: n = 7
Output: [[0,0,0,null,null,0,0,null,null,0,0],[0,0,0,null,null,0,0,0,0],[0,0,0,0,0,0,0],[0,0,0,0,0,null,null,null,null,0,0],[0,0,0,0,0,null,null,0,0]]
Example 2:

Input: n = 3
Output: [[0,0,0]]/*
