// Question  https://leetcode.com/problems/reverse-linked-list/

import java.util.Scanner;

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

    public static ListNode reverseList(ListNode head) {
        if(head == null){
            return null;
        }
        ListNode temp = head, after = null, prev = null;
        while(temp != null){
            after = temp.next;
            temp.next = prev;
            prev = temp;
            temp = after;
        }
        head = prev;
        return head;
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

        System.out.println("\nReverse of Linked list is:");

        ListNode res = reverseList(llist.head);

        while(res!=null){
            System.out.print( res.data + " ");
            res = res.next;
        }
    }
}

// Examples
/**
 * Example 1:
 * Input: head = [1,2,3,4,5]
 * Output: [5,4,3,2,1]
 *
 * Example 2:
 * Input: head = [1,2]
 * Output: [2,1]
 */
