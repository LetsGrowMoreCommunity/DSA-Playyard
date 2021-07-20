// Question  https://leetcode.com/problems/number-complement/

/**
 * First concert the given number into Binary string.
 * Then make the complement of that String using for loop.
 * lastly return that converting Binary string to decimal number.
 */

import java.util.Scanner;

class Solution {
    public static int findComplement(int num) {
        String s = Integer.toBinaryString(num);                       // number to binary

        String ch = "";

        for(int i =0 ; i < s.length(); i++){                         // take complement of it
            if(s.charAt(i) == '0'){
                ch += '1';
            }else{
                ch += '0';
            }
        }

        return Integer.parseInt(ch, 2);                              // return binary to decimal
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        System.out.println( findComplement(n) );                     // Pass the number
    }
}

/**
 * Example 1:
 * Input: num = 5
 * Output: 2
 * Explanation: The binary representation of 5 is 101 (no leading zero bits), and its complement is 010. So you need to output 2.
 *
 * Example 2:
 * Input: num = 1
 * Output: 0
 * Explanation: The binary representation of 1 is 1 (no leading zero bits), and its complement is 0. So you need to output 0.
 */
