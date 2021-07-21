/*

 5. Delete a Node in a Linked List

 This problem is to delete a node in a linked list given the value of the node you want to delete.
 It contains a LinkedListNode class to build the linked list, the class LinkedList is the overall list,
 the method addNode from LinkedList is to build up the linked list to test, and to delete a linked list node is in
 the deleteNode method

 Steps to run it correctly:

 First, call instance of LinkedList
 next, call addNode method as many times as needed
 print list before deleting to check changes
 delete node, and print list again to see changes

 Algorithm works by checking if value of deleted node is at front, then traversing through node until either found or at
 end of the list (no more values ahead) where node will not exist

 Time Complexity: O(N)
 Space Complexity O(1) or O(N)
 */



public class LinkedList {
    // front of linked list - head
    LinkedListNode head;

    // LinkedListNode class to build up list (value of node and next if it has a node ahead of it)
    class LinkedListNode {
        int val;
        LinkedListNode next;

        LinkedListNode(int val) {
            this.val = val;
            this.next = null;
        }
    }

    // method to add node to linked list
    public void addNode(int val) {

        LinkedListNode new_node = new LinkedListNode(val);

        if (head == null) {
            head = new LinkedListNode(val);
            return;
        }

        new_node.next = null;

        LinkedListNode pointer = head;

        while (pointer.next != null) {
            pointer = pointer.next;
        }

        pointer.next = new_node;
    }

    // method to delete node from linked list
    public void deleteNode(int val) {
        LinkedListNode pointer = head;

        if (pointer != null && pointer.val == val) {
            head = pointer.next;
            return;
        }

        LinkedListNode prev = null;

        while (pointer != null && pointer.val != val) {
            prev = pointer;
            pointer = pointer.next;
        }

        if (pointer == null) return;

        prev.next = pointer.next;
    }

    // method to print all values in linked list
    public void printList() {
        LinkedListNode temp = head;

        while (temp != null) {
            System.out.println(temp.val);
            temp = temp.next;
        }
    }

    // main method to run test cases
    public static void main(String[] args){
        // create a new linked list object
        LinkedList linkedList = new LinkedList();

        for (int i = 1; i <= Math.pow(10, 3); i++) {
            linkedList.addNode(i);
        }
        System.out.println("BEFORE DELETION");
        linkedList.printList();
        linkedList.deleteNode(999);

        System.out.println("AFTER DELETION");
        linkedList.printList();
    }
}
