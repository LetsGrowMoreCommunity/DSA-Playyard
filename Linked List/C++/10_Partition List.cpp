
#include <iostream>
#include <vector>
#include <climits>
using namespace std;
//definition of a single linked list
  struct ListNode {
      int val;
      ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 



class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *n = new ListNode();//input 
        ListNode *tail = n;//dummy
        ListNode *q = new ListNode();
        ListNode *t = q;//dummy variable
        while(head!=NULL){//for iteraing
            if(head->val>=x){
                t->next=head;
                t=t->next;//the t dummy or storing the nodes which has values greater than or equal to given value
            }
            else if(head->val<x){//for storing the nodes which has value less than the given and,
                tail->next=head;
                tail=tail->next;
            }
            head=head->next;
        }
        tail->next=q->next;
        t->next=NULL;
        return n->next;//printing the final one
    }
};
int main()
{
    
    int x,n;//the 
    cin>>x;
    cin>>n;
    int head[n];
    for(int i=0;i<n;i++)
    {
        cin>>head[i];
    }
     partition(head, x);//calling the func
     return 0; 

}
/*Input: head = [1,4,3,2,5,2], x = 3
Output: [1,2,2,4,3,5]
Example 2:

Input: head = [2,1], x = 2
Output: [1,2]