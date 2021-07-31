// Question  https://leetcode.com/problems/partition-list/

/**
 * Initialize num1 and num2 nodes of below two linked lists as 0. 
 * ListNode of values smaller than x.
 * ListNode of values greater than or equal to x.
 * 
 * Now iterate through the original linked list.
 * If a node’s value is less than x then append it at the end of the num1 list.
 * If the value is greater than or equal to x, then at the end of the num2 list.
 * 
 * Now concatenate both two lists.
 */

import java.util.Scanner;

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

    public static ListNode partition(ListNode head, int x) {
        ListNode res1 = new ListNode(0), num1 = res1, res2 = new ListNode(0), num2 = res2;
        while(head != null)
        {
            if(head.val < x){
                num1.next = head;
                num1 = head;
            }else{
                num2.next = head;
                num2 = head;
            }
            head = head.next;
        }
        num2.next = null;
        num1.next = res2.next;
        return res1.next;
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
            llist.head = new ListNode(e);
        }

        for(int i = 1;i < n;i ++)
        {
            int e = sc.nextInt();
            llist.push(e);
        }

        System.out.println("\nCreated Linked list is:");
        llist.printList();

        System.out.println("\nEnter the partition number:");
       int x = sc.nextInt();

        ListNode res = partition(llist.head, x);

        while(res!=null){
            System.out.println(res.val);
            res=res.next;
        }
    }
}

// Examples
/**
 * Example 1:
 * Input: head = [1,4,3,2,5,2], x = 3
 * Output: [1,2,2,4,3,5]
 *
 * Example 2:
 * Input: head = [2,1], x = 2
 * Output: [1,2]
 */
