/* 
Problem: Design a stack with increment operation

This solution supports following operations:
1. CustomStack(int maxSize) : Initializes the object with maxSize which is the maximum number of elements in the stack or do nothing if the stack reached the maxSize.
2. void push(int x) : Adds x to the top of the stack if the stack hasn't reached the maxSize.
3. int pop() : Pops and returns the top of stack or -1 if the stack is empty.
4. void inc(int k, int val) : Increments the bottom k elements of the stack by val. If there are less than k elements in the stack, just increment all the elements in the stack. 

*/

#include<iostream>
#include<bits/stdc++.h>
#include<string>
#include<vector>

using namespace std;

class CustomStack {
	public:
	    int top=-1; // Stack empty initially.
	    int ans[1000]; //Given the maximum of maxSize is 1000.
	    int max=0;
	    CustomStack(int maxSize) {
	       max=maxSize;
	    }
	    
	    void push(int x) {
	    	//Adds element to the stack only if stack hasn't reached the maxSize.
	       if(top<(max-1)) { 
	            top++;
	            ans[top]=x;
	       }
	    }
	    
	    int pop() {
	    	// Pops and returns the top element of stack.
	        if(top>-1) {
	            top--;
	            return ans[top+1];
	        }
	        //Returns -1 if the stack is empty.
	        return -1;
	    }
	    
	    void increment(int k, int val) {
	    	//Increments the bottom k elements of the stack by val.
	        for(int i=0;i<k;i++) {
	            ans[i]+=val;
	        }
	    }
	        
};

int main() {
	
	int t;
	cout<<"Enter the number of test cases: ";
	cin>>t;
	
	int key, value;
		
	for(int j=1;j<=t;j++) {
		
		
		CustomStack* s;
		
		vector<string> i1; // Input array of operations
		
		string str;
		str = "";
		
		cout<<"Enter input operation array with string elements. Enter 0 to end the input of operations\n";
		//Enter 0 to end the input of operations.
		while(str!="0") {
			cin>>str;
			if(str=="0") {
				break;
			}
			i1.push_back(str);
		}
		
		vector<int> ansarr(i1.size()); //Output array
		
		for(int sz=0;sz<i1.size();sz++) {
			
			ansarr[sz]=NULL;
			if(i1[sz]=="CustomStack") {
				cout<<"\nEnter the maximum size for this testcase: ";
				int m;
				cin>>m;
				cout<<endl;
				s= new CustomStack(m);
			}
			else if(i1[sz]=="push") {
				cout<<"Enter an item to push in the stack\n";
				cin>>value;
				s->push(value);
			}
			else if(i1[sz]=="pop") {
				value=s->pop();
				ansarr[sz]=value;
			}
			else if(i1[sz]=="increment") {
				cout<<"Enter the number of bottom elements of stack which you want to increment: ";
				cin>>key;
				cout<<"\nIncrement by?: ";
				cin>>value;
				cout<<endl;
				s->increment(key,value);
			}
			else {
				cout<<"invalid input\n";
				break;
			}
			
		}
		
		cout<<"Output: ";
		for(int Sz=0;Sz<ansarr.size();Sz++) {
			cout<<ansarr[Sz]<<" ";
		}
		cout<<endl;
		
	}
	return 0;
}


/*
//Accepted

SAMPLE INPUT:
2                                                                                     -> Number of testcases
CustomStack push push pop push push push increment increment pop pop pop pop 0        -> Input array of operations (First testcase) (Last element 0 is to terminate the input of operations)
3 1 2 2 3 4 5 100 2 100                                                               -> Input according to the input of operations. 
CustomStack push pop push push push increment increment pop pop pop pop 0             -> Second testcase
5 4 3 7 11 4 50 2 100

SAMPLE OUTPUT (exclusive of interactive instructions):
0 0 0 2 0 0 0 0 0 103 202 201 -1                                                      -> First testcase output
0 0 4 0 0 0 0 0 61 157 153 -1                                                         -> Second testcase ouput

Explanation: 

Testcase 1:
CustomStack customStack = new CustomStack(3); // Stack is Empty []
customStack.push(1);                          // stack becomes [1]
customStack.push(2);                          // stack becomes [1, 2]
customStack.pop();                            // return 2 --> Return top of the stack 2, stack becomes [1]
customStack.push(2);                          // stack becomes [1, 2]
customStack.push(3);                          // stack becomes [1, 2, 3]
customStack.push(4);                          // stack still [1, 2, 3], Don't add another elements as size is 4
customStack.increment(5, 100);                // stack becomes [101, 102, 103]
customStack.increment(2, 100);                // stack becomes [201, 202, 103]
customStack.pop();                            // return 103 --> Return top of the stack 103, stack becomes [201, 202]
customStack.pop();                            // return 202 --> Return top of the stack 102, stack becomes [201]
customStack.pop();                            // return 201 --> Return top of the stack 101, stack becomes []
customStack.pop();                            // return -1 --> Stack is empty return -1.

Testcase 2:
CustomStack customStack = new CustomStack(5); // Stack is Empty []
customStack.push(4);                          // stack becomes [4]
customStack.pop();                            // return 4 --> Return top of the stack 4, stack becomes []
customStack.push(3);                          // stack becomes [3]
customStack.push(7);                          // stack becomes [3, 7]
customStack.push(11);                         // stack becomes [3, 7, 11]
customStack.increment(4, 50);                 // stack becomes [53, 57, 61]
customStack.increment(2, 100);                // stack becomes [153, 157, 61]
customStack.pop();                            // return 61 --> Return top of the stack 61, stack becomes [153, 157]
customStack.pop();                            // return 157 --> Return top of the stack 157, stack becomes [153]
customStack.pop();                            // return 153 --> Return top of the stack 153, stack becomes []
customStack.pop();                            // return -1 --> Stack is empty return -1.

Time complexity: O(n) 
n = number of elements to be incremented

*/ 
