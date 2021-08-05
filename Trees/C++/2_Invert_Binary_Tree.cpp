
/*
Alogorithm: Here, start from left and right child of root, swap both the nodes then recursively swap the children of left and right subtree.
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


//Function to print tree in level order
void printLevelOrder(TreeNode* root)
{
    int h = height(root);
    int i;
    for (i = 1; i <= h; i++)
        printCurrentLevel(root, i);
}

//Helper function that swaps the left child with the right child recursively
void replace(TreeNode* &left, TreeNode* &right){
        if(left==NULL && right==NULL){
            return;
        }
        TreeNode* temp=left;
        left=right;
        right=temp;
        if(left!=NULL){
            replace(left->left,left->right);
        }
        if(right!=NULL)
        replace(right->left,right->right);
    }

//Function to invert Tree
    TreeNode* invertTree(TreeNode* root) {
        if(!root){
            return root;
        }
       replace(root->left, root->right);
       return root;
    }
 

// Driver program to test above function
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
     invertTree(root);
     printLevelOrder(root);
    }
  
}


/*
Example 1
Input: 7 8 9 3 1 2
Output: 7 9 8 2 1 3

So, here the tree goes from    7
                             /    \
                            8      9
                           / \    /
                           3  1  2
                           
                        to     7
                             /    \
                            9      8
                             \    / \
                              2  1   3
                              
Example 2
Input: 4 2 7 1 3 6 9
Output: 4 7 2 9 6 3 1
*/

//Time Complexity: O(n), where n is the number of nodes in the tree
//Space Complexity: O(h), where h is the height of the tree
