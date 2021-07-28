/*

Problem: Next greater node in linked list

Description:
A linked list is given with head as the first node. Let's number the nodes in the list: node_1, node_2, node_3, ... etc.
Each node may have a next larger value: for node_i, next_larger(node_i) is the node_j.val such that j > i, node_j.val > node_i.val, and j is the smallest possible choice.  If such a j does not exist, the next larger value is 0.

This solution returns an array of integers answer, where answer[i] = next_larger(node_{i+1}).  (Ex: answer[0] = next_larger(node_1))

Note:
1 <= node.val <= 10^9 for each node in the linked list.
The given list has length in the range [0, 10000].

*/

#include<iostream>
#include<vector>
#include<bits/stdc++.h>

using namespace std;

//Definition for Singly-linked list
struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ans; // Answer array
        
        // returns an empty set if input is null (0 nodes) i.e., head is null
        if(head==NULL){
        	return ans;
		}
		
        while(head->next!=NULL) {
            ListNode* temp=head; //temporary node pointing to node_i 
            head=head->next;
            
            // initially lets assume there is no node with greater value than the initial node value. x represents the the next larger node value. 
            int x=0;
            while(head!=NULL) {
            	//Checks if greater value exists:
                if(head->val>temp->val) {
                    x=head->val;
                    break; 
                }
                head=head->next;
            }
            ans.push_back(x); //Adds x to the answer array
            head=temp;
            head=head->next;
        }
        ans.push_back(0); // Last node has no next node (as j does not esixt). Hence, has no next greater node. 
        
        return ans;
    }
};

int main() {
	
	int t;
	cout<<"Enter the number of test cases: ";
	cin>>t;
	
	for(int i=1;i<=t;i++) {
		
		Solution* s = new Solution;
		
		cout<<"Enter the number of nodes: ";
		int n; // Number of nodes
		cin>>n;
				
		if(n>=1) {
			int head;
			cout<<"Enter node values: \n";
			cin>>head; // Head node	value
			ListNode* h;
			ListNode* t1 = new ListNode(head);  // Node pointing to the head node
			h=t1;
			for(int j=1;j<n;j++) {
				int v;
				cin>>v;
				h->next = new ListNode(v);
				h=h->next;	
			}
			h=t1; // Node h points back to the head of the linked-list
			
			vector<int> answer(n); //Creating an array with size of number of nodes.
			answer = s->nextLargerNodes(h); // Answer array consists of next larger node value for every node in order.
				
			cout<<"Answer: [";
			for(int k=0;k<answer.size();k++) {
				cout<<answer[k]<<" ";
			}
			cout<<"]"<<endl;
		}
		
		// If the head node is null
		else {
			cout<<"Answer: []\n";
		}	
	}
	
	return 0;
	
}

/*
// Accepted

SAMPLE INPUT:
5                                     -> Number of testcases
3 2 1 5                               -> First testcase. First input represents the number of nodes, rest are the node values. 
5 2 7 4 3 5                           -> Second testcase
8 1 7 5 1 9 2 5 1                     -> Third testcase
1 5                                   -> Testcase with a single node
0                                     -> Testcase with zero nodes     

SAMPLE OUTPUT: (excusive of interactive instructions)
[5 5 0]                                 
[7 0 5 5 0]
[7 9 9 9 0 5 0 0]
[0]
[]

Explanation:
First input of every testcase represents number of nodes.

Testcase 1:
Inputs following the first input i.e., 3(number of nodes) represent the serialization of a linked list with a head node value of 2, second node value of 1, and third node value of 5.
The next node value greater than 2 is 5. The next node value greater than 1 is 5. last node value 5 has no next node.

Testcase 2:
Head node val = 2. Next greater node val is 7. 
Second node val = 7. Next greater node does not exist. Hence outputs 0.
Third node val = 4. Next greater node val is 5.
Fourth node val = 3. Next greater node val is 5. 
Fifth node val = 5. Next node does not exist. Hnece outputs 0.

(Same for testcase 3)

Testcase 4: 
Head node = 5. Next node does not exist. Hence outputs 0.

Testcase 5:
Head node does not exist. Hence outputs an empty array.


Time complexity: O(n^2)  
n= number of nodes.

*/
