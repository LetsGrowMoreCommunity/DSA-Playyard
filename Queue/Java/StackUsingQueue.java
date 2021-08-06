/**
 Implement Stack using Queue.
 ref. https://leetcode.com/problems/implement-stack-using-queues/
 
 The java.util package's Queue interface is used to hold the components that will be processed in
 FIFO (First In First Out) order. Each Stack operation makes use of functions from the interface's
 LinkedList class.
 
 Time Complexity of Push Operation: O(n) and Pop Operation: O(1)
 Space Complexity: O(n)
 Where n is the size of the Stack. Here, n = q.size();
 */

package suvrashaw;
import java.util.*; //Importing the package
public class StackUsingQueue{
    Queue<Integer> q1 = new LinkedList<>(); //Uses the Queue Interface
        
    void push(int val){ //Adding into the Stack.
        q1.add(val); //Adding a new entry into the Stack.
        for (int i = 0; i < q1.size(); i++) //Putting previous entries after the new one. (Enqueue)
            q1.add(q1.remove()); //'front' elements added to the 'rear'. (Dequeue)
    }
	
    int pop(){ //Deleting from the Stack.
	if (q1.isEmpty()){ //Checking if the Stack is empty.
            System.out.println("Stack Underflow"); //Stack Empty Message.
            return -1; //Terminating the method if the Stack is empty.
	}
	return q1.remove(); //Deleting an entry from the Stack.
    }
	
    int top(){ //Denotes the position of the top of the Stack.
	if (q1.isEmpty()) //Checking if the Stack is empty.
            return -1; //top = -1 when a stack is empty.
        return q1.peek(); //If the Stack isn't empty,
                          //returns the position of the top of the Stack.
    }
	
    boolean empty(){ //Method to check if the Stack is empty.
        return q1.isEmpty(); //Returns true is the interface object is empty.
    }
    
    int getSize(){ //Method to check the Stack size.
        return q1.size(); //Returns size of the interface object q1, our virtual stack.
    }

    public static void main(String[] args){  //Main Method
        StackUsingQueue obj = new StackUsingQueue();
        Scanner sc = new Scanner(System.in); 
        while(true){ //Menu Driven
            System.out.println("1. push");
            System.out.println("2. pop");
            System.out.println("3. check top");
            System.out.println("4. if Empty");
            System.out.println("5. size");
            System.out.println("6. exit");
            System.out.println("Give Choice"); //Menu
            int choice = sc.nextInt(); //User Choice
            switch (choice){
                case 1 -> { //push function.
                    System.out.println("Input Number: "); //User Input
                    obj.push(sc.nextInt());
                    }
                case 2 -> System.out.println("Deleted Element: " + obj.pop()); //pop function.
                case 3 -> System.out.println("top: " + obj.top()); //function to check top's position.  
                case 4 -> System.out.println("Empty: " + obj.empty()); //function to check if the Stack is empty.
                case 5 -> System.out.println("Size: " + obj.getSize()); //function to check Stack's size.
                case 6 -> System.exit(0); //function to quit the program.
                default -> System.out.println("Wrong Entry"); //Error Choice Check
            }}}}

/**
Test Case

compile-single:
run-single:
1. push
2. pop
3. check top
4. if Empty
5. size
6. exit
Give Choice
1
Input Number: 
10
1. push
2. pop
3. check top
4. if Empty
5. size
6. exit
Give Choice
1
Input Number: 
20
1. push
2. pop
3. check top
4. if Empty
5. size
6. exit
Give Choice
3
top: 10
1. push
2. pop
3. check top
4. if Empty
5. size
6. exit
Give Choice
2
Deleted Element: 10
1. push
2. pop
3. check top
4. if Empty
5. size
6. exit
Give Choice
33
Wrong Entry
1. push
2. pop
3. check top
4. if Empty
5. size
6. exit
Give Choice
3
top: 20
1. push
2. pop
3. check top
4. if Empty
5. size
6. exit
Give Choice
5
Size: 1
1. push
2. pop
3. check top
4. if Empty
5. size
6. exit
Give Choice
4
Empty: false
1. push
2. pop
3. check top
4. if Empty
5. size
6. exit
Give Choice
2
Deleted Element: 20
1. push
2. pop
3. check top
4. if Empty
5. size
6. exit
Give Choice
4
Empty: true
1. push
2. pop
3. check top
4. if Empty
5. size
6. exit
Give Choice
6
BUILD SUCCESSFUL (total time: 1 minute 19 seconds)*/