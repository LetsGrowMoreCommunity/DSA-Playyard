/* 
Problem: Palindrom Linked List on LeetCode
Solution by AtrikGit6174

The solution revereses the later half of the singly linked list 
to check for its palindrome nature. It destroys the linked list property.
*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Definition for singly-linked list.
 struct ListNode 
 {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution 
{
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
                ptr- ptr->next;
            }
        }
        
        return head;
    }
    
    bool isPalindrome(ListNode* head) 
    {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        
        if (!head || !head->next)       //trivial cases of empty LL or single node
            return true;
        
        auto start= head, end= head;
        int count=0;
        
        while (end)
        {
            count++;
            end= end->next;
        }
        
        if (count==2)
            return (head->val==head->next->val) ? true : false;     //case of two nodes
        
        int mid= count/2;
        auto midptr= head;
        
        while (--mid)
            midptr= midptr->next;
        
        if (!(count%2))
        {
            //add a middle node if total even nodes
            midptr->next= new ListNode (INT_MAX, midptr->next);
        }
        
        //rotating half the LL
        midptr= midptr->next;
        
        auto back= midptr;
        auto cur= back->next;
        auto front= cur->next;
        
        midptr->next= nullptr;
        
        while (cur)
        {
            cur->next= back;
            back= cur;
            cur= front;

            if (front)
                front= front->next;
        }
        
        while (start && back)
        {
            if (start->val != back->val)
                return false;
            
            start= start->next;
            back= back->next;
        }
        
        return true;
        
    }
};

int main() 
{
	int t; cin>>t;      //no of test cases
	
	while (t--)
	{
	    cout<<"\nEnter the number of nodes: ";
	    int n; cin>>n;
	    
	    vector<int> vec (n);
	    cout<<"\nEnter nodes (if not zero): "
	    for (int i=0; i<n; i++)
	    {
	        cin>>vec[i];
	    }
	    
	    Solution *ob;
	    cout<<"\n"<<( (ob->isPalindrome(ob->creation (vec))) ? "true" : "false")<<"\n";
	    
	}
	return 0;
}

/*
SAMPLE INPUT
7               <-- NO. OF TEST CASES
4 1 2 2 1       <-- STARTS WITH NO. OF NODES, THEN VECTOR OF VALUES
2 1 2           
1 1             <-- SINGLE NODE
0               <-- NO NODE
3 1 2 1         
3 1 2 3         
4 1 2 3 4       

SAMPLE OUTPUT (excluding interactive instructions)
true
false
true
true
true
false
false

COMPLEXITY ANALYSIS n= no. of nodes 
Time: O(n) for creation, O(n) to traverse all nodes for counting, 
      O(ceil(n/2)) to reverse, O(ceil(n/2)) to compare.
      Hence overall, O(n).
Space: O(n) for the nodes, 
       Aux space: O(1) done w/o copying the LL by destroying the original LL.
*/
       



