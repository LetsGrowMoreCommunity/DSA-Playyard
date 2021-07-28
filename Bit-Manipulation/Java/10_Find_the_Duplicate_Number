// Question  https://leetcode.com/problems/find-the-duplicate-number/

/**
 * first of all find the max number in num[],
 * then create an array of size (max_nums + 1).
 * finally find out the first repetition number using frequency method,
 * if frequency of any number == 2 then return false else true.
 */

// Solution

import java.util.Scanner;

class Solution {
    public static int findDuplicate(int[] nums) {
        int n = -1;

        for(int i = 0; i < nums.length; i++)
            n = Math.max(n,nums[i]);

        int[] arr = new int[n+1];

        for(int i = 0; i < nums.length; i++){
            arr[nums[i]]++;
            if(arr[nums[i]] == 2)
                return nums[i];
        }
        return -1;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int[] nums = new int[n];

        for(int i = 0; i < n; i++)
            nums[i] = sc.nextInt();

        System. out.println( findDuplicate(nums) );
    }
}

// Examples
/**
 * Example 1:
 * Input: nums = [1,3,4,2,2]
 * Output: 2
 *
 * Example 2:
 * Input: nums = [3,1,3,4,2]
 * Output: 3
 */
