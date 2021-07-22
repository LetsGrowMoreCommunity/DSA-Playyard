/*
The set [1, 2, 3, ..., n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

 

Example 1:

Input: n = 3, k = 3
Output: "213"
Explanation: 
The ordered list of permutation sequence from integer 1 to 3 is : 123, 132, 213, 231, 312, 321. So, the 3rd permutation sequence is “213”.

Input: n = 2, k = 1 
Output: 12 
Explanation: 
For n = 2, only 2 permutations are possible 12 21. So, the 1st permutation sequence is “12”. 
*/
//The code for the given problem is given below:

// Java program to Find the kth Permutation Sequence of first n natural numbers
import java.util.*;

class PermutationSequence {
    static Scanner sc = null;

    // Function to find the kth permutation of n numbers
    public String getPermutation(int n, int k) {
        // Creation of an ArrayList
        ArrayList<Integer> arr = new ArrayList<>();
        int fact = 1;
        // Calculating and storing the factorials of the first n numbers in the
        // ArrayList
        for (int i = 1; i < n; i++) {
            fact = fact * i;
            arr.add(i);
        }
        arr.add(n);
        k = k - 1;
        // Store final answer
        String ans = "";
        while (true) {
            // First position of the kth sequence will be occupied by the number present at
            // index = k / fact
            int i1 = k / fact;
            int i2 = k % fact;
            ans += arr.get(i1);
            arr.remove(i1);
            k = i2;
            if (arr.size() == 0) {
                break;
            }
            fact = fact / arr.size();
        }
        return ans;
    }

    // Main function
    public static void main(String[] args) {
        sc = new Scanner(System.in);
        // Input for n
        System.out.println("Enter the value of n : ");
        int n = sc.nextInt();
        // Input for k
        System.out.println("Enter the value of k : ");
        int k = sc.nextInt();
        // Creating object of the class PermutationSequence
        PermutationSequence obj = new PermutationSequence();
        String kth_perm_seq = obj.getPermutation(n, k);
        System.out.println("The kth permutation sequence of n is : " + kth_perm_seq);

    }
}

/*
Sample Input:
Enter the value of n : 
4
Enter the value of k : 
17

Sample Output:
The kth permutation sequence of n is : 3412
