// Question  https://leetcode.com/problems/split-linked-list-in-parts/

/**
 *First find the length of the linked list.
 * If the total ratio sum exceeds the actual length then dividing the list is not possible so print -1.
 * If it is possible to divide the list then simply traverse the list up to length p and break it into the ratio p:q.
 * Next node will be the head of the second list then print both the lists.
 * Below is the implementation of the above approach: 
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

    public static ListNode[] splitListToParts(ListNode root, int k) {

        ListNode cnt = root;
        int len = 0;
        while (cnt != null) {
            len++;
            cnt = cnt.next;
        }
        ListNode[] res = new ListNode[k];
        cnt = root;
        int carry = len % k;

        for (int i = 0; i < k && cnt != null; i++) {
            ListNode r = new ListNode(0);
            ListNode rr = r;
            int m = 0, j = 0;

            if (carry > 0) {
                j = 1;
                carry--;
            }
            while ((m++ < (len / k) + j) && cnt != null) {
                r.next = new ListNode(cnt.val);
                r = r.next;
                cnt = cnt.next;
            }
            res[i] = rr.next;
        }

        return res;
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
        int k = sc.nextInt();

        ListNode[] res = splitListToParts(llist.head, k);

        for (ListNode re : res) {
            System.out.println(re);
        }
    }
}

// Examples
/**
 * Example 1:
 * Input: head = [1,2,3], k = 5
 * Output: [[1],[2],[3],[],[]]
 * Explanation:
 * The first element output[0] has output[0].val = 1, output[0].next = null.
 * The last element output[4] is null, but its string representation as a ListNode is [].
 *
 * Example 2:
 * Input: head = [1,2,3,4,5,6,7,8,9,10], k = 3
 * Output: [[1,2,3,4],[5,6,7],[8,9,10]]
 * Explanation:
 * The input has been split into consecutive parts with size difference at most 1, and earlier parts are a larger size than the later parts.
 */

// Time Complexity O(N)
// Space Complexity O(1)
