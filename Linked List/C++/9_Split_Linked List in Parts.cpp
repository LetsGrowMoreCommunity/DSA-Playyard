//time complexity-0(n)
//Space Complexity 0(n)
#include <bits/stdc++.h>
using namespace std;
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        //first calculate the length
        int len=0;
        ListNode* temp=root;
        while(temp)
        {
            len++;
            temp=temp->next;//traversing through the linked list
        }
        
        int numNodes=len/k; //the number of nodes that are to be in each group
        int extra=len%k;  //the extra nodes that are left
        int i=0;
        vector<ListNode*> res;
        temp=root;
        while(temp)
        {
            res.push_back(temp);
            //get the numNodes and make the last node next to NULL
            int currLen=1;
            while(currLen<numNodes)
            {
                temp=temp->next;
                currLen++;
            }
            if(extra>0 && len>k)
            {
                temp=temp->next;
                extra--;
            }
            ListNode* x=temp->next;
            temp->next=NULL;
            temp=x;
        }
        //if the number of nodes are less than k we add NULL
        while(len<k)
        {
            res.push_back(NULL);
            len++;
        }
        return res;
        
    }
int main()
{ 
vector<int>head(n);
cin>>head;
int k;
cin>>k;
cout<<splitListToParts(ListNode* root,  k)<<endl;


return 0;


}
/*Input: head = [1,2,3], k = 5
Output: [[1],[2],[3],[],[]]

Example 2:


Input: head = [1,2,3,4,5,6,7,8,9,10], k = 3
Output: [[1,2,3,4],[5,6,7],[8,9,10]]
s/*
