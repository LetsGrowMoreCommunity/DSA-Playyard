/*
Algorithm: Basically the idea is to perform preorder traversal but instead of going from left to right, going from right to left,since right side of the tree is required first.
Taking level as call by reference and checking the current level of the node, check whether currlevel is greater than previous level, if yes then add value to the resultant 
array and set level as currlevel otherwise we will continue with our traversal from first right and then left,increasing currlevel by 1 for every next node recursively.
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

//A class with member function rightSideView that prints values of the nodes one can see ordered from top to bottom.
class Solution {
public:
    vector<int> res;
    void helper(TreeNode* root, int &level, int curlevel){
        if(!root){
            return;
        }
        if(curlevel>level){
            res.push_back(root->val);
            level=curlevel;
            
        } 
          helper(root->right,level,curlevel+1);
          helper(root->left,level,curlevel+1);

    }
 
    vector<int> rightSideView(TreeNode* root) {
        if(!root){
            return res;
        }        
        int level=-1;
        helper(root,level,0);
        return res;
       
    }
};

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
        vector<int> vec = ob.rightSideView(root);
        for(int x : vec){
            cout<<x<<" ";
        }
        cout << endl;
    }
}


/*
Example 1
Input: 1 2 3 5 4 
              1
            /   \
           2     3
            \     \
             5     4
             
Output: 1 3 4


Example 2
Input: 5 4 7 3 9
              5
             / \
            4   7
           / \
          3   9
Output: 5 7 9

*/

//Time Complexity: O(n), where n is the no. of nodes 
//Space Complexity: O(h), where h is the height of the tree
