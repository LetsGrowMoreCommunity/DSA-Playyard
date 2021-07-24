// Question https://leetcode.com/problems/factorial-trailing-zeroes/

/**
 * We can count trailing 0s by repeatedly dividing the factorial by 10 till the remainder is 0
 * The idea is to consider prime factors of a factorial n.
 * A trailing zero is always produced by prime factors 2 and 5.
 * If we can count the number of 5s and 2s, our task is done.
 */

// Solution

import java.util.Scanner;

class Solution {
    // Function to return trailing
    public static int trailingZeroes(int n)
    {
        int count = 0;

        while (n > 1) {
            count += n / 5;
            n /= 5;
        }

        return count;
    }

    // Driver Code
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        System.out.println( trailingZeroes(n) );
    }
}

// Examples
/**
 *Example 1:
 * Input: n = 3
 * Output: 0
 * Explanation: 3! = 6, no trailing zero.
 *
 * Example 2:
 * Input: n = 5
 * Output: 1
 * Explanation: 5! = 120, one trailing zero.
 */
