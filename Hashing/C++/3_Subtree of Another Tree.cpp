//TC-O(mn) where m and n are number of nodes in given two trees. 
//SC-0(M) the one having largest nodes
#include<bits/stdc++.h>
using namespace std;

class node
{
	public:
	int data;
	node* left;
	node* right;
};

//function to checkwhether trees with roots as root1 and root2 are identical or not//
bool areIdentical(node * root1, node *root2)
{
	// base cases //
	if (root1 == NULL && root2 == NULL)
		return true;

	if (root1 == NULL || root2 == NULL)
		return false;

	//Checks if the data of both roots issame and data of left and right subtrees are also same //
	return (root1->data == root2->data &&
			areIdentical(root1->left, root2->left) &&
			areIdentical(root1->right, root2->right) );
}


//This function returns true if as a subtree of T, otherwise false //
bool isSubtree(node *T, node *S)
{
	/* base cases */
	if (S == NULL)
		return true;

	if (T == NULL)
		return false;

	// Check the tree with root as current node//
	if (areIdentical(T, S))
		return true;

	//If the tree with root as current
	node doesn't match then try left
	and right subtrees one by one //
	return isSubtree(T->left, S) ||
		isSubtree(T->right, S);
}


node* newNode(int data)
{
	node* Node = new node();
	Node->data = data;
	Node->left = NULL;
	Node->right = NULL;
	return(Node);
}
int main()
{
	//taking the user input
    int root1,root2,data1,data2,data3,data4,data5,data6,data7,data8,data9;
    cin>>root1>>data1>>data2>>data3>>data4>>data5>>data6>>data7>>data8>>data9;
	node *T = newNode(root1);
	T->right		 = newNode(data1);
	T->right->right = newNode(data2);
	T->left		 = newNode(data3);
	T->left->left	 = newNode(data4);
	T->left->left->right = newNode(data5);
	T->left->right	 = newNode(data6);
	node *S = newNode(root2);
	S->right	 = newNode(data7);
	S->left	 = newNode(data8);
	S->left->right = newNode(data9);


	if (isSubtree(T, S))//calling the function
		cout << "true";
	else{
		cout << "false";
    }

	return 0;
}

/*Input: root = [3,4,5,1,2,null,null,null,null,0], subRoot = [4,1,2]
Output: false//its false since if we write the nodes in a form of  a tree we would find that its not forming a subtree
Input: root = [3,4,5,1,2], subRoot = [4,1,2]
Output: true/*
//if we write the nodes in form  of a tree we will notice that they are satisfying the conditions and forming a subtree
