/*ques_link:https://leetcode.com/problems/merge-two-sorted-lists/

Merge two sorted linked lists and return it as a sorted list.

Explanation:
the given two sorted linked list are merged to a single linked list
by comparing the data of given  linked lists and choosing the one with smaller data and adding it to merged list which we make.

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
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        /*r1 points to first linked list
        r2 points to second linked list
        r3 points to the linked list which we create by merging*/
        ListNode*r1=l1;
        ListNode*r2=l2;
        ListNode*m=new ListNode(-1);
        ListNode*r3=m;
        
        while(r1!=NULL && r2!=NULL)
        {
            if(r1->val<r2->val)//comparing the values of nodes from the given two non empty linked list
            {
                r3->next=r1;
                r1=r1->next;
            }
            else
            {
                r3->next=r2;
                r2=r2->next;
            }
            r3=r3->next;
        }
        while(r1!=NULL)//loop to merge values of first non empty linked list if the second list is empty
        {
            r3->next=r1;
            r1=r1->next;
            r3=r3->next;
        }
        while(r2!=NULL)//loop to merge values of second non empty linked list if the first list is empty
        {
            r3->next=r2;
            r2=r2->next;
            r3=r3->next;
        }
        return m->next;
    }
};

/*
TEST CASES
Input: 
l1 = [1,2,4] 
l2 = [1,3,4]
Output:
[1,1,2,3,4,4]

Input:
l1 =[1,7,8]
l2 =[1,2,5]
output:
[1,1,2,5,7,8]
*/
