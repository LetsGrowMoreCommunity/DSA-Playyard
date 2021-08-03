/*
Problem: Binary to Linked list Integer.

Description: Given head which is a reference node to a singly-linked list. 
The value of each node in the linked list is either 0 or 1. 
The linked list holds the binary representation of a number.
Return the decimal value of the number in the linked list.
*/

#include <iostream>
using namespace std;

class ListNode
{
	public:
	bool val;
	ListNode* next;
};

int getDecimalValue(ListNode* head) //Returns decimal value of binary linked list
    {
        int ans = 0;
        while(head != NULL)
        {
            ans = (ans*2) + head->val;
            head = head->next;
        }
        return ans;
    }
ListNode *newNode(bool val) //function to create a new node
{
	ListNode *temp = new ListNode;
	temp->val = val;
	temp->next = NULL;
	return temp;
}

int main()
{
	ListNode* head = newNode(1); //empty list
	head->next = newNode(0);
	head->next->next = newNode(1);
	cout << "Decimal value is "
		<< getDecimalValue(head);

	return 0;
}

/*
Input: head = 1->0->1
Output: 5

Example:
If below examples are needed to be printed in drivers code we have to keep on adding ->next.
Input: head = 1->0->0->1->0->0->1->1->1->0->0->0->0->0->0
Output: 18880

Input  : 0->0->0->1->1->0->0->1->0
Output : 50

Head: Head is the top most element. If the binary input is 101100 then 1 at left side will be considered as head.

Explanation:
(1011) base 2 = (1*2^3) + (0*2^2) + (1*2^1) + (1*2^0)
let result be the last element:
step 1: result = 1 = 1*2^0
step 2: (result*2) + 0 = ((1*2^2 + 0) * 2 + 1)
step 3:                = ((1*2^2 + 0*2^1 + 1*2^0) * 2)
step 4:                = (1*2^3 + 0*2^2 + 1*2^1 + 1)
*/
