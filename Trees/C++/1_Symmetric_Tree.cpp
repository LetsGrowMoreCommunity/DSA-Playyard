/*
Problem: Symmetric Tree on LeetCode 
Solution: Recursive solution by AtrikGit6174
The <bool isSymmetric()> function calls the recursive function <bool symmeTreec()> 
on both the children of the root, after solving the trivial base cases of 0 nodes and 1 node, 
which default to a symmetric tree.

<bool symmeTreec(TreeNode *node1, TreeNode *node2)> returns true IF
1. both nodes are null.
2. both nodes have the same value and their subtress are symmetric.

ELSE, it returns false.
Further comments about the alogorithm are in the function itself.
The function is written in a bit shorter syntax, so needs slightly more careful observation.

Constraints:

|| The number of nodes in the tree is in the range [1, 1000].
|| -100 <= Node.val <= 100

The main() supports both interactive input and block inputs.
Also, for some unexplainable reason, multiple test cases do not run well in the J-Doodle online iDE and compiler,
while CodeChef IDE supports it perfectly. Both are in C++17 (GCC 9.1)
*/

#include <iostream>
#include <queue>
using namespace std;

//Definition for a binary tree node.
struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int n) : val(n), left(nullptr), right(nullptr) {}
    
};

class Solution 
{
public:
    //testing only. Not for functionality
    void inorder (TreeNode *root)
    {
        if (root) 
        {
            if (root->left or root->right) inorder (root->left);
            cout<<root->val<<" ";
            if (root->left or root->right) inorder (root->right);
        }
        
        else
        {
            cout<<999<<" ";
            return;
        }
    }
    
    bool isSymmetric(TreeNode* root) 
    {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        
        //the (!root->left and !root->right) condition is checked here only as it is found 
        //to reduce the run-time slightly. Not essential for functionality.
        
        return (!root or (!root->left and !root->right) or symmeTreec(root->left, root->right));
    }
    
    bool symmeTreec (TreeNode *node1, TreeNode *node2)
    {
        if (!node1 and !node2)      //trivial base case of both nodes being simultaneously null.
            return true;
        
        //returns false if either nodes are null but not both, or node values are not equal, 
        //or if sub-trees are not symmetric. Else true.
        return (
            !(
            (!node1 and node2) 
            or (!node2 and node1) 
            or node1->val!=node2->val
            )
            
            and symmeTreec (node1->left, node2->right) and symmeTreec (node1->right, node2->left)
        );
        
    }
};

int main() 
{
	/* 
	The input format asks for nodes in level order traversal. 
    Check at the end of the program for I/O Format.
	Since the original problem requires a -100<=node.val<=100, values outside the range are for null. 
	For other requirements, the sentinel will have to be changed accordingly.
	*/
	
	//as per question
	const int UPPER= 100;
	const int LOWER= -100;
	    
	int t;      //t test cases
	cout<<"Enter the number of test cases: ";
	cin>>t;
	
	for (int test=1; test<=t; test++)
	{
	    cout<<"\nTEST CASE "<<test;
	    cout<<"\nEnter the number of nodes in [0-1000] (assume nulls inside the tree to be nodes): ";
	    int n; cin>>n;      //number of nodes
	    
	    if (n==0)       //trivial base case
	    {
	        cout<<"\ntrue\n";
	        continue;
	    }
	    
	    //creating the tree
	    std::vector<TreeNode *> vec(n);
	    cout<<"\nEnter level order traversal of tree. Node values in ["<<UPPER<<", "<<LOWER<<"] for non-null nodes and values outside the range for null: ";
	    
	    int val;
	    for (int i=0; i<n; i++)
	    {
	        cin>>val;
	        vec[i]= (val<=UPPER and val>=LOWER) ? new TreeNode (val) : nullptr;
	    }
	    
	    TreeNode *root= vec[0];
	    
	    if (root)
	    {
	        auto parent= root;
	        for (int i=0; i<(n-1)/2;)   //condition for presence of children nodes to be added
	        {
	            //left child
	            int left= 2*i+1;
    	        if (vec[left])
    	        {
	                parent->left= vec[left];
    	        }
    	        
    	        //right child
    	        int right= 2*i+2;
    	        if (vec[right])
    	        {
	                parent->right= vec[right];
    	        }
    	        
    	        i++;
    	        while (!vec[i])     //skipping over nullptr
    	            i++;
    	        parent= vec[i];
    	   }
	    }

	    Solution *ob;
        //cout<<"\nInorder: "; ob->inorder (root); //testing only.
	    cout<<"\n"<<(ob->isSymmetric(root) ? "true" : "false")<<"\n";
	    
	    for (int i=0; i<n; i++)
	        delete vec[i];
	   
	}
    
	return 0;
}

/*
SAMPLE INPUT

5                           <--NO OF TEST CASES
7 1 2 2 3 4 4 3             <-- NO.OF NODES... LEVEL ORDER TRAVERSAL OF NODES
7 1 2 2 999 3 999 3         <-- 999 REPRESENT NULL VALUES. NEED TO BE ENTERED TO MIMIC A COMPLETE BINARY TREE
0                           <-- EMPTY TREE
1 1                         <-- SINGLE NODE
3 1 2 999

SAMPLE OUTPUT FOR THE ABOVE INPUT (excluding the interactive instructions)
true
false
true
true
false

COMPLEXITY ANALYSIS. For n= no. of nodes
Time: O(n)
Space: O(n) in total, aux space: O(1). 
Since we are dealing with the nodes themselves from the beginning, 
only constant extra space for handling counters in loops and pointers to nodes are required.
*/
