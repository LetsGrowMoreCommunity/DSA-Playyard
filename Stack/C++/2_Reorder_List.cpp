/*
Problem: Reorder List on LeetCode
Solution by AtrikGit6174

Used a stack to store half of the LL and popping to re-order
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

//Definition for singly-linked list.
struct ListNode 
{
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* creation (vector<int> vec)
    {
         if (vec.size()==0)
              return nullptr;
    
         auto head= new ListNode (vec[0]);
    
         if (vec.size()!=1)
         {
            auto ptr= head;   
            for (int i=1; i<vec.size(); i++)
            {
                ptr->next= new ListNode (vec[i]);
                ptr= ptr->next;
            }
         }
    
         return head;
    }
    
    void reorderList(ListNode* head) 
    {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        
        if (head->next and head->next->next)       
            //trivial base cases of single or two nodes return directly
        {
            auto slow= head;
            auto fast= head;
            
            stack<ListNode *> stk;

            while (fast and fast->next)
                //ends at fast==nullptr for even no. of nodes
                //and fast->next==nullptr for odd no. of nodes
            {
                slow= slow->next;
                fast= fast->next->next;
            }
            
            //now slow is the middle element
            while (slow)
            {
                stk.push (slow);
                slow= slow->next;
            }
            
            auto ptr= head;
            
            while (ptr->next!=ptr)
            {
                stk.top()->next= ptr->next;
                ptr->next= stk.top();
                ptr= stk.top()->next;
                stk.pop();
            }
            
            ptr->next= nullptr;
        }
    }
    
    void deletion (ListNode *temp)
    {
         while (temp)
         {
            cout<<temp->val<<" ";
            auto ptr= temp->next;
            delete temp;
            temp= ptr;
         }
    }
    
};

int main() 
{
	cout<<"Enter the number of test cases: ";
	int t; cin>>t;
	
	for (int count=1; count<=t; count++)
	{
	    cout<<"\nTEST CASE "<<count<<"\nEnter the number of nodes: ";
        int n; cin>>n;
        
        std::vector<int> vec (n);
        cout<<"\nEnter the nodes values: ";
        for (int i = 0; i < n; i++)   
          cin>>vec[i];
        
        Solution *ob;
        auto head= ob->creation(vec);
        ob->reorderList(head);
        cout<<"\nReordered list: ";
        ob->deletion(head);     //prints and deletes
        cout<<"\n";
        
	    
	}
	
	return 0;
}

/*
SAMPLE INPUT
5               <-- NUMBER OF TEST CASES
1 1             <-- TRIVIAL CASE OF SINGLE NODE
2 1 2           <-- TRIVIAL CASE OF TWO NODES ONLY
3 1 2 3         <-- STARTS WITH NUMBER OF NODES, FOLLOWED BY THE VECTOR OF NODE VALUES
4 1 2 3 4
5 1 2 3 4 5

SAMPLE OUTPUT (excluding interactive instructions)
1
1 2
1 3 2
1 4 2 3
1 5 2 4 3

COMPLEXITY ANALYSIS n= no. of nodes
Time: O(ceil(n/2)) to recreate the stack
      O(floor(n/2)) to traverse and re-order.
      Overall O(n).
Space: O(n) for input, O(n) to create the list.
       Aux space: O(ceil(n/2)) for the stack.
*/
