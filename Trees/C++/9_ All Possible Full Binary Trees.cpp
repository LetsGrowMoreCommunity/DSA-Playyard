//Given an integer n, return a list of all possible full binary trees with n nodes. Each node of each tree in the answer must have Node.val == 0.

//Each element of the answer is the root node of one possible tree. You may return the final list of trees in any order.

//A full binary tree is a binary tree where each node has exactly 0 or 2 children.///


Time Complexity: O(2^N)
Space Complexity: O(2^N)

#include <bits/stdc++.h>
#include<iostream>
using namespace std;

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
   for(TreeNode *t : v){
      tree_level_trav(t);//calling the function
   }
}
/*Input: n = 7
Output: [[0,0,0,null,null,0,0,null,null,0,0],[0,0,0,null,null,0,0,0,0],[0,0,0,0,0,0,0],[0,0,0,0,0,null,null,null,null,0,0],[0,0,0,0,0,null,null,0,0]]
Example 2:

Input: n = 3
Output: [[0,0,0]]/*
