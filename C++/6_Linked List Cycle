// C++ program to detect loop in a linked list
//Floyd’s Cycle-Finding Algorithm 

#include<iostream>
#include <bits/stdc++.h>
using namespace std;

/* Link list node */
typedef struct Node {
	int data;
	struct Node* next;
}ListNode;

void push(ListNode** head_ref, int new_data)
{
	/* allocate node */
	ListNode* new_node = new Node;

	/* put in the data */
	new_node->data = new_data;

	/* link the old list off the new node */
	new_node->next = (*head_ref);

	/* move the head to point to the new node */
	(*head_ref) = new_node;
}

class Solution {
public:
    bool hasCycle(ListNode *head) {
        
        //Take two pointers slow and fast
        
        ListNode *current_pointer=head;
        
        ListNode *ahead_pointer=head;
        
    //Our slow pointer moves with us and fast pointer moves fast to check for loop or null address
    
    //Our loop runs untill current,ahead and ahead->head which may mark the loop, are not null
    
        while(current_pointer && ahead_pointer && ahead_pointer->next){
            
            current_pointer=current_pointer->next; // we move current pointer in 1 step
            
            ahead_pointer=ahead_pointer->next->next; // we move ahead pointer in two steps
            
            if(current_pointer==ahead_pointer) return true; // loop is detected when both point to the same address
            
        }
        // in this algorithm ahead pointer moves over the same addresses for few times to detect the loop since current pointer is just at 1 step movement
        
        return false;// when loop ends and reaches till here it means there might be null address encountered and no loop
    }
};
// Returns true if there is a loop in linked list
// else returns false.

/* Main program to test our function*/
int main()
{
	/* Start with the empty linked list */
	ListNode* head = NULL;
	int data;
	//"Enter some data to continue and 0 to stop";
	cin>>data;
	while(data!=0){
	    push(&head, data);
	    cin>>data;
	}

	/* Create a loop for testing  so try to give input atleast with 4 nodes else loop can't be created*/
	head->next->next->next->next = head;
	Solution *ob;

	if (ob->hasCycle(head))
		cout << "Loop found";
	else
		cout << "No Loop";

	return 0;
}

/*
Ex-1: 

3->2->0->4->2

here loop is from 4 to 2 back

current and ahead mark to head i.e;3
Now,
in loop 
current(not null) and ahead(not null) and ahead->next(2)(not null)
current=2
ahead=0

current(not null) and ahead(not null) and ahead->next(4)(not null)
current=0
ahead=2

current(not null) and ahead(not null) and ahead->next(0)(not null)
current=4
ahead=4

here,
current==ahead =>loop is detected.Return true

Ex-2: 

1->2->3->4->5->2

here loop is from 5 to 2 back

current and ahead mark to head i.e;1
Now,
in loop 
current(not null) and ahead(not null) and ahead->next(2)(not null)
current=2
ahead=3

current(not null) and ahead(not null) and ahead->next(4)(not null)
current=3
ahead=5

current(not null) and ahead(not null) and ahead->next(2)(not null)
current=4
ahead=3

current(not null) and ahead(not null) and ahead->next(4)(not null)
current=5
ahead=5

here,
current==ahead =>loop is detected.Return true

**Assume above input as addresses with data as the given numbers
*/
//Time Complexity : O(n) where n can be the length of the loop made from the head pointer
//Space Complexity : O(1)
