// Question https://leetcode.com/problems/palindrome-linked-list/

/**
 * First implement a stack
 * then push all the elements
 * so according to stack = LIFO,
 * the last item comes first and compare with first element through node
 * if comparision remain same then print yes else no.
 */

import java.util.Scanner;
import java.util.Stack;

class LinkedList {
    ListNode head; // head of list

    /* Linked list Node*/
    static class ListNode {
        int val;
        ListNode next;
        ListNode(int val)
        {
            this.val = val;
            next = null;
        }
    }

    public static boolean isPalindrome(ListNode head) {
        ListNode temp = head;
        Stack<Integer> stack = new Stack<Integer>();
        while(temp!=null){
            stack.push(temp.val);
            temp = temp.next;
        }
        while(!stack.isEmpty()){
            if(stack.pop()!=head.val){
                return false;
            }
            head=head.next;
        }
        return true;
    }

    public void push(int new_data)
    {
        ListNode new_node = new ListNode(new_data);
        ListNode temp = head;

        while(temp.next != null)
        {
            temp = temp.next;
        }

        temp.next = new_node;
    }

    public void printList()
    {
        ListNode tnode = head;
        while (tnode != null) {
            System.out.print(tnode.val + " ");
            tnode = tnode.next;
        }
    }

    public static void main(String[] args)
    {
        Scanner sc =new Scanner(System.in);

        LinkedList llist = new LinkedList();

        System.out.println("\nEnter Linked list size:");
        int n = sc.nextInt();

        if(llist.head == null)
        {
            int e = sc.nextInt();
            ListNode new_node =new ListNode(e);
            llist.head = new_node;
        }

        for(int i = 1;i < n;i ++)
        {
            int e = sc.nextInt();
            llist.push(e);
        }

        System.out.println("\nCreated Linked list is:");
        llist.printList();

        System.out.println( "Palindrome: " + isPalindrome(llist.head) );
    }
}

// Examples
/**
 * Example 1:
 * Input: head = [1,2,2,1]
 * Output: true
 *
 * Example 2:
 * Input: head = [1,2]
 * Output: false
 */
