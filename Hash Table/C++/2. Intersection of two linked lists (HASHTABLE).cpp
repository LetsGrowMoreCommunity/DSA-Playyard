
// 2. Intersection of two linked lists (HASHTABLE)

/*

Question : We will be given two linked list and head of both will be given, and we need to find the intersection node of both linked list, if not intersecting return -1

Algorithm :
	first we traverse linked list1 and insert all the elements of linked list 1 into hashtable
	then we iterate through linkedlist 2 and check for each element if it is present in hashtable, if present then we return that element
	else return null
	
*/


#include<bits/stdc++.h>
using namespace std;

// created a strucure that contains the node structure
struct Node 
{
    int data;
    Node* next;
};
bool no = false;

// funciton defined to find the length of linked list
int lenLinkedList (Node *head)
{
    int len = 0;
    while(head!= NULL)
	{
        len++;
        head = head-> next;
    }
    return len;
}
// this is the main function to find the intersecting node.
Node *getIntersectionNode(Node *headA, Node *headB) 
{
	map<Node *, int> hash_table;
	// inserting all the elements of linked list 1 into hashtable
    while (headA) 
	{
        hash_table[headA] = 1;
        headA = headA->next;
    }
    // then we iterate through linkedlist 2 and check for each element if it is present in hashtable
    while (headB) 
	{
        if (hash_table.count(headB))// if present then we return that element
            return headB;
        headB = headB->next;
    }
    return headB;// of no element found in hashtable return null
    
}
// this function is defind to inser the node in the linked list
void insert(Node** root, int item)
{
    Node* temp = new Node;
    Node* ptr;
    temp->data = item;
    temp->next = NULL;
 
    if (*root == NULL)
        *root = temp;
    else {
        ptr = *root;
        while (ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = temp;
    }
}

// this function is used to convert the vector to list
Node *vecToList(vector<int > arr, int n)
{
    Node *root = NULL;
    for (int i = 0; i < n; i++)
        insert(&root, arr[i]);
   return root;
}

int main()
{
	// created list with value in linked list
	vector<int > linked_list1{10,15,30};
	vector<int > linked_list2{3,6,9,15,30};
	
	// forming the linked list
	Node* newNode;
 
    Node* head1 = new Node();
    head1->data = linked_list1[0];
 
    Node* head2 = new Node();
    head2->data = linked_list2[0];
 
    newNode = new Node();
    newNode->data = linked_list2[1];
    head2->next = newNode;
 
    newNode = new Node();
    newNode->data = linked_list2[3];
    head2->next->next = newNode;
 
    newNode = new Node();
    newNode->data = linked_list1[1];
    head1->next = newNode;
    head2->next->next->next = newNode;
 
    newNode = new Node();
    newNode->data = linked_list1[2];
    head1->next->next = newNode;
 
    head1->next->next->next = NULL;
	
//	Node* head1 = vecToList(linked_list1, linked_list1.size()); 
//	Node* head2 = vecToList(linked_list2, linked_list2.size()); 
	
	// function called for finding the intersection of both linked list
	if(no)
	cout<<"The intersecting node of both linked list is  :  -1"<<endl;
	else
	cout<<"The intersecting node of both linked list is  :  "<<getIntersectionNode(head1, head2)->data<<endl;
	
	return 0;
}

/*

Time Complexity : O(n)
Space Complexity : O(n)

Sample testcase :
Input 1 :
	linked_list1 = [10,15,30]
	linked_list2 = [3,6,9,15,30]
Output 1:
	The intersecting node of both linked list is  :  15
Explaination:
	we can clearly see that the two linked list is intersecting at node 15. 
	
Input 2 :
	linked_list1 = [10,15,30]
	linked_list2 = [3,6,9,12,18]
Output 1:
	The intersecting node of both linked list is  :  -1
Explaination:
	we can clearly see that the both the linked list are not imtersecting at any node therefore ans is -1. 
	
*/

