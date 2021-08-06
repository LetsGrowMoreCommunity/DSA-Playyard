/* 
Algorithm: 

1. The idea is to utilize the property of binary search tree that every left node's value is smaller than the parent node's value and right node's value is greater
than the parent node's value.
2. A boolean functon (named check here) is made to check recursively that left node is smaller than its parent node and right node is greater than its parent node.
3. In the function check, at each recursive call, the min and max is updated because:
  3.a For every left node, the max value it has is less than the parent's value.
  3.b For every right node, the min value it can have is greater than its parent value
4. In this way, we are checking for every node.

*/

#include <bits/stdc++.h>
using namespace std;
 
/* 
Definition for a binary tree node.
A binary tree node has data,
pointer to left child and a
pointer to right child.
Constructor that initialises a new node in three different cases:
1. Empty Node is created with left and right pointer poiting to nullptr
2. When only value of node is given as parameter then node with left as NULL and right as NULL is created
3. When all the three values: the node value, the left pointer and right pointer is given */

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

// Function to insert nodes in level order
TreeNode* insertLevelOrder(int arr[], TreeNode* root, int i, int n)
{
    // Base case for recursion
    if (i < n)
    {
        TreeNode* temp = new TreeNode(arr[i]);
        root = temp;
 
        // insert left child
        root->left = insertLevelOrder(arr,
                   root->left, 2 * i + 1, n);
 
        // insert right child
        root->right = insertLevelOrder(arr,
                  root->right, 2 * i + 2, n);
    }
    return root;
}
 
//Function to calculate height of tree
int height(TreeNode* TreeNode)
{
    if (TreeNode == NULL)
        return 0;
    else
    {
        /* compute the height of each subtree */
        int lheight = height(TreeNode->left);
        int rheight = height(TreeNode->right);
 
        /* use the larger one */
        if (lheight > rheight)
        {
            return(lheight + 1);
        }
        else {
          return(rheight + 1);
        }
    }
}

//Function to print nodes of current level in level order traversal
void printCurrentLevel(TreeNode* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        cout << root->val << " ";
    else if (level > 1)
    {
        printCurrentLevel(root->left, level-1);
        printCurrentLevel(root->right, level-1);
    }
}


//Function to print tree in level order.makes a recursive call on printCurrentLevel Function
void printLevelOrder(TreeNode* root)
{
    int h = height(root);
    int i;
    for (i = 1; i <= h; i++)
        printCurrentLevel(root, i);
}

//A class with member function isValidBST that checks whether tree is BST or not by calling check member function which traverses and verifies the BST recursively 
class Solution {
public:
    bool check(TreeNode* root,TreeNode* min, TreeNode* max){
        if(root==NULL){
            return true;
        }
        if(min!=NULL && root->val<=min->val){
            return false;
        }
        if(max!=NULL && root->val>=max->val){
            return false;
        }
        
        bool left=check(root->left,min,root);
        bool right=check(root->right,root,max);
        return (left&&right);
    }
    bool isValidBST(TreeNode* root) {
        return check(root,NULL,NULL);
    }
};


//Driver function which accesses the class members and checks for Valid BST
int main()
{
    int t;
    cin>>t;
    while(t--){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    TreeNode* root = insertLevelOrder(arr, root, 0, n);
    Solution ob;
      if(ob.isValidBST(root)) 
        cout<<"True";
     else
        cout<<"False";
    }
}

/*

Example 1
Input: 7 5 9 4 6 8

       7
    /    \
   5      9
  / \    /
 4   6  8
                          
Output: True

Example 2
Input: 5 1 4 3 6

       5
     /   \
    1     4
        /   \
       3     6
       
Output: False

*/

//Time Complexity: O(n)
//Space Complexity: O(n)
