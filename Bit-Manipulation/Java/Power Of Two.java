// Question  https://leetcode.com/problems/power-of-two/

/**
 * first check number is less than equal to zero or not
 * if yes return false;
 * Count no of bits in a given number
 * if no_of_bits == 1 then return true;
 * else return false;
 */

import java.util.Scanner;

class Solution{
    public static boolean isPowerOfTwo(int n) {

        if(n<=0)                                         // Check less than equal zero or not
            return false;

        int count=0;
        while(n>0){                                      // count no_of_bits
            count+=n&1;
            if(count>1)
                return false;
            n=n>>>1;
        }

        return true;
    }

    public static void main(String[] args) {            // main()
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        System.out.println( isPowerOfTwo(n) );          // Pass the number
    }
}

// Examples
/**
 * Example 1:
 * Input: n = 1
 * Output: true
 * Explanation: 20 = 1
 *
 * Example 2:
 * Input: n = 16
 * Output: true
 * Explanation: 24 = 16
 */
