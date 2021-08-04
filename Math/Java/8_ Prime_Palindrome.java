// Question  https://leetcode.com/problems/prime-palindrome/

/**
 * first check the given number is even or odd, if it is even then convert it to odd by adding 1.
 * then check if the number is palindrome as well as prime or not.
 * if the number lies between 10^5 to 10^6 then, number = 100_000_001.
 * finally return next possible primePalindrome number.
 */

// Solution

import java.util.Scanner;

class Solution {
    public static boolean palindrome(int n){
        if(n%10 == 0 && n!=0)
            return false;

        int reverse = 0;
        int num = n;
        while(n>0){
            reverse = reverse*10 + n%10;
            n /= 10;
        }

        return num == reverse;
    }

    public static boolean prime(int n){
        if(n%2 == 0 || n == 1)
            return false;

        for(int i = 3; i < n/2; i++){
            if(n%i == 0)
                return false;
        }

        return true;
    }

    public static int primePalindrome(int n) {
        if(n == 1 || n == 2)
            return 2;

        if(n%2 == 0)
            n += 1;

        while(true){
            if(palindrome(n) && prime(n))
                return n;

            n += 2;

            if (10_000_000 < n && n < 100_000_000)
                n = 100_000_001;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        System. out.println( primePalindrome(n) );
    }
}

// Examples
/**
 * Example 1:
 * Input: n = 6
 * Output: 7
 *
 * Example 2:
 * Input: n = 8
 * Output: 11
 *
 * Example 3:
 * Input: n = 13
 * Output: 101
 */
