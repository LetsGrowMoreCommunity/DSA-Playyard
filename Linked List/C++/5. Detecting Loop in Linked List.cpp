/* 
Ques. Given a linked list, check if the linked list has loop or not. 
A loop in linked list is said to exist if while traversing the linked list we're not getting a terminated output 
or getting repeated element that we had traversed in the beginning
*/

#include<iostream>
using namespace std;

//creating structure Node which is used to store data and a pointer pointing to next node so as to create a linked list
struct Node{           
    int data;
    struct Node *next;
}*first=NULL;      //declaring first node of linked list as NULL


void insert(struct Node *p, int x,int pos){      //inserting the given element at given index
    
    struct Node *t;       //declaring a pointer t of type Node

    /* while inserting an element, we've to keep in mind the two cases: if element is 
       inserted at first position or element is added at any other position except first
        as both have slightly different logic */

    if(pos==0){          //if we're inserting element at first position in linked list

        t=new Node;     
        t->data=x;      
        t->next=first;   
        first=t;     
    }

    else        //if we're inserting element at any other place except first         
    { 
      // move pointer p till we reach the position previous to where element has to be inserted
      for(int i=0; i<pos-1 && p!=0 ;i++)  p=p->next;  

      if(p!=0){             

          t=new Node;    
          t->data=x;     
          t->next=p->next;  
          p->next=t;  

      }   
    }
}


/* Explaination: If there is a loop in the linked list p and q will never point at last node(NULL), so in case
                 of loop we made pointer q to go 2 step forward and pointer p to move 1 step forward so that 
                 they'll point at the same location at some point of time  */
                 
                 
int isLoop(Node *f){      //function to detect loop in a Linked list
    Node *p, *q;         //Creating pointers of type Node making them point to the first node of linked list
    p=q=f;
    
    
    /* we use a do while loop as it'll run the statement without checking the condition, whereas in other loops
       the code will not be executed as in the beginning, both p and q are pointing at the same place */
    do{
        //moving p and q
        p=p->next;
        q=q->next;
        
        q= (q!=NULL)? q->next : NULL;  //if q is not equal to NULL then move q to next otherwise store NULL in q
    }
    //the while statement is checking whether the given pointers are becoming NULL or p is becoming equal to q or not
    while( p&&q && p!=q);
    
    if(p==q) 
      return 0;       //returns true
    else 
      return 1;      //returns false
}


int main(){
    insert(first,6,0);
    insert(first,20,1);
    insert(first,12,2);
    insert(first,38,3);
    insert(first,26,4);
    insert(first,32,5);
    
    
    //created a loop for test case, comment it out to check for no loop case
    struct Node *t1, *t2;
    t1= first->next->next;
    t2= first->next->next->next->next;
    t2->next = t1;
    
    int ans = isLoop(first);
    if(ans==0) cout<<"\nLoop is detected in Linked List";
    else if(ans==1) cout<<"\nNo loop is there in Linked List";
}   


/*  -------------------------------------------------------------------------------  */
