// Question https://leetcode.com/problems/trapping-rain-water/

/**
 *leave first and last building as no water will be collected
 * for rest building find left most heighest building and right most heighest building.
 * difference between them to fid the collected water.
 */

// Solution

import java.lang.*;
import java.util.Scanner;

class Solution {
    public static int trap(int[] height) {
        int tot=0;
        for(int i=1;i<height.length-1;i++){
            int m1=0;
            for(int j=0;j<=i;j++){
                m1=Math.max(m1,height[j]);
            }
            int m2=0;
            for(int k=i;k<height.length;k++){
                m2=Math.max(m2,height[k]);
            }
            tot+=Math.min(m1,m2)-height[i];
        }
        return tot;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int[] height = new int[n];

        for(int i = 0;i < n;i++)
            height[i] = sc.nextInt();

        System.out.println( trap(height) );
    }
}

// Examples
/**
 * Example 1:
 * Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
 * Output: 6
 * Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
 *
 * Example 2:
 * Input: height = [4,2,0,3,2,5]
 * Output: 9
 */
