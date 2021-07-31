// Question  https://leetcode.com/problems/reorder-list/

/**
 * Initialize current node as head.
 * While next of current node is not null, do following
 *     a) Find the last node, remove it from the end and insert it as next
 *        of the current node.
 *     b) Move current to next to next of current
 */

import java.util.Scanner;
import java.util.Stack;

class LinkedList {
    ListNode head; // head of list

    /* Linked list Node*/
    static class ListNode {
        int data;
        ListNode next;
        ListNode(int data)
        {
            this.data = data;
            next = null;
        }
    }

    public static void reorderList(ListNode head) {
        if (head==null||head.next==null)
            return;

        Stack<ListNode> sk= new Stack<>();

        int count=0;
        ListNode temp=head;
        while(temp!=null) {
            sk.push(temp);
            temp=temp.next;
            count++;
        }

        temp=head;
        while (count>0) {
            ListNode node = sk.pop();
            node.next = temp.next;
            temp.next = node;
            temp = temp.next.next;
            count=count-2;
        }
        temp.next=null;
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
            System.out.print(tnode.data + " ");
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

        System.out.println("\nReorderOrder of Linked list is:");

        reorderList(llist.head);
        }
    }

// Examples
/**
 * Example 1:
 * Input: head = [1,2,3,4]
 * Output: [1,4,2,3]
 *
 * Example 2:
 * Input: head = [1,2,3,4,5]
 * Output: [1,5,2,4,3]
 */
