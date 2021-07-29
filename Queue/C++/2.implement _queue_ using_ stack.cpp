/*
problem statement
Implement a first in first out (FIFO) queue using only two stacks. The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).

Explanation:
here we use two stacks st1 and st2.
1.to perform enqueue we directly insert the elements using push function.
2.dequeue operation is performed by first checking whether the given stacks are empty and then if st2 is empty and st1 is nonempty push the elements of st1 to st2.
Then pop the elements from stack st2 .
*/



class MyQueue {
    stack<int>st1;
    stack<int>st2;
public:
    //ENQUEUE OPERATION
    void push(int x) {
        
        st1.push(x);
    }
    //DEQUEUE OPERATION
    int pop() {
        //CHECKING WHETHER STACKS ARE EMPTY
        if(st1.empty() and st2.empty())
        {
            return -1;
        }
        if(st2.empty())
        {//PUSHING ELEMENTS TO STACK 2 FROM STACK 1
            while(!st1.empty())
            {
                st2.push(st1.top());
                st1.pop();
            }
        }
        
        int top1=st2.top();
        st2.pop();
        return top1;
        
        
    }
     bool empty() {//FUNCTION TO CHECK WHETHER STACKS ARE EMPTY
        if(st1.empty() and st2.empty())
        
            return true;
        return false;
        
    }
    int peek() {
        //CHECKING FOR THE TOPMOST ELEMENT STACK 2
        if(st2.empty())
        {
            while(!st1.empty())
            {
                st2.push(st1.top());
                st1.pop();
                
            }
        }
        
        int x=st2.top();
        return x;
        
    }
    
};

/*
Test Cases:
Input
["MyQueue", "push", "push", "peek", "pop", "empty"]
[[], [1], [2], [], [], []]
Output
[null, null, null, 1, 1, false]


Input
["MyQueue", "push", "push", "push", "pop", "peek","empty"]
[[], [1], [2], [3], [], [],[]]
Output
[null, null, null, null,1, 2, false]
*/

