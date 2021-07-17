/* 
Reversing a linked list means reversing the elements present in linked list, i.e. the 
linked list after reversing should display the elements in reverse order as they were 
entered. 
Now, reversing the elements in linked list can have two approaches- either reversing all 
the elements or to reverse the links and the latter is much easier and logical.

Here is a function for reversing the elements of linked list by reversing nodes:
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

void display(struct Node *p){      //displaying the linked list

    while(p!=NULL){                //continue till p points on NULL
        cout<<p->data<<"\t";
        p=p->next;                
    }
 }


void rev(struct Node *p){         //code to reverse the linked list by reversing nodes

    struct Node *q=NULL, *r=NULL;    

    while(p!=0){     //continue the loop until p reaches NULL 

        r=q;           //make pointer r points to the place where pointer q is pointing          
        q=p;           //make pointer q points to the place where pointer p is pointing
        p=p->next;     //move pointer p to point to next element

        q->next=r;     //changing the linking of nodes to reverse the linked list
    } 
    
    /*When p is equal to NULL,pointer q will point to last element present in original 
    linked list  */

    first=q;             //the last element will not be the first node (reversed)
    
    cout<<"\n\nLinked list after reversing: \n";
    display(q);
}

/* Time Complexity of above method: O(n)
   Space Complexity of above method: O(1)  */


int main(){

    insert(first,6,0);
    insert(first,20,1);
    insert(first,12,2);
    insert(first,38,3);
    insert(first,26,4);
    insert(first,32,5);
    display(first);
    rev(first);
    
    return 0;
}


/*  -------------------------------------------------------------------------------  */
