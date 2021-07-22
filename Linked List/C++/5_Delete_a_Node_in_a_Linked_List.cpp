// C++ program to delete a given node in a Linked List

// Code:
#include <bits/stdc++.h>
using namespace std;
/* structured a class of a linked list node */
class Node
{
public:
    int data;
    Node *next;
};

//function to delete the node
void deleteNode(Node *head, Node *n)
{
    // if head node is to be deleted 
    if (head == n)
    {
        if (head->next == NULL)
        {
            cout << "There is only one node."<< " The list can't be made empty ";
            return;
        }
        // Copy the data of next node to head 
        head->data = head->next->data;
        // store address of next node
        n = head->next;
        // Remove the link of next node and connecting to the next element
        head->next = head->next->next;        
        free(n);
        return;
    }    
    
    Node *prev = head;  // to find the previous node
    while (prev->next != NULL && prev->next != n)
        prev = prev->next;    
    if (prev->next == NULL) // Check if node exist
    {
        cout << "\nGiven node is not present in Linked List";
        return;
    }    
    prev->next = prev->next->next; // Remove node from Linked List    
    free(n);
    return;
}
void pushele(Node **head_ref, int new_data) //function to insert a node at the beginning
{
    Node *new_node = new Node();
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}
void printList(Node *head) //function to print a linked list 
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
int main()
{
    Node *head = NULL;
    pushele(&head, 1);
    pushele(&head, 8);
    pushele(&head, 23);
    pushele(&head, 7);
    pushele(&head, 9);
    pushele(&head, 4);
    pushele(&head, 5);
    pushele(&head, 0);

    cout << "Given Linked List: ";
    printList(head);    
    cout << "Deleting node " << head->next->next->data << " "; //delete the node 
    deleteNode(head, head->next->next);
    cout << "\nNew Linked List: ";
    printList(head);

    return 0;
}

// Test Case 1:
// Given Linked List: 0 5 4 9 7 23 8 1 
// Deleting node 4 
// New Linked List: 0 5 9 7 23 8 1

// Test Case 2:
// Given Linked List: 0 5 4 9 7 23 8 1 
// Deleting node 9 
// New Linked List: 0 5 4 7 23 8 1 
