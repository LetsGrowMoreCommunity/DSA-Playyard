/* Problem Link:
   https://leetcode.com/problems/reverse-linked-list/

   Ques. 
   Given the head of a singly linked list, reverse the list, and return the reversed list.

  Explaination:
  Reversing a linked list means reversing the elements present in linked list, i.e. the 
  linked list after reversing should display the elements in reverse order as they were 
  entered. 
  Now, reversing the elements in linked list can have two approaches- either reversing all 
  the elements or to reverse the links and the latter is more logical.
*/



/*
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

#include<iostream>
using namespace std;

class Solution {
    
    public: 
    ListNode* reverseList(ListNode* head) {         //code to reverse the linked list by reversing nodes
      
       ListNode *p =head, *q = NULL, *r = NULL;

        while(p!=NULL){              //continue the loop until p reaches NULL 

            r=q;              //make pointer r points to the place where pointer q is pointing 
            q=p;              //make pointer q points to the place where pointer p is pointing 
            p=p->next;         //move pointer p to point to next element

            q->next=r;        //changing the linking of nodes to reverse the linked list
        }
        head=q;             //making head points on the last node of given linked list as in revsere it becomes the first node
       
        return head;       // return the reverse linked list
    }
};

/********************* Time and Space complexity *************************************/


/* Time Complexity of above method: O(n)
   Space Complexity of above method: O(1)  */


/****************************** Testcases:  ******************************************/

/*
   Testcase 1-
   Input: head = [1,2,3,4,5]
   Output: [5,4,3,2,1]

   Testcase 2-
   Input: head = [1,2]
   Output: [2,1]

   Testcase 3-
   Input: head = []
   Output: []
*/
