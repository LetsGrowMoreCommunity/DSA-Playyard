/*

1. Coin Change (DP)

This problem is to take a list of coins and a value to return
the minimum amount of coins needed to equal to a given value, or -1 if
any selection of coins will never return the given value

 Algorithm is memoization, a DP algorithm in which there is a hashmap (dictionary)
 to store computed values (from subtracting value from either coin value from list of coins)
 to reference later if repeated calculation to reduce computational time. Uses recursion (calling a method inside
 the same method, but with a changed value(s)) to break down value until -1 or value to be stored for later

 */

import java.util.*;

public class CoinChange {
    public static void main(String[] args) {
        CoinChange cc = new CoinChange();
        cc.printCases();

        /*

        5 -> helper([1,2,5], 5, map (for storing computed values)) -> returns 1 because the minimum amount of coins
        needed is you taking one 5 coin from the list of coins to equal 5, which only needs one coin

        64 -> helper([10, 25, 33], 64, map) -> -1, because no matter what combination of coins you use you will never
        get a combination of coins that equals to the value 64

         */
    }

    // method to implement test cases
    public void printCases() {
        System.out.println(helper(new int[]{1,2,5}, 5, new HashMap<Integer, Integer>()));
        System.out.println(helper(new int[]{10, 25, 33}, 64, new HashMap<Integer, Integer>()));
    }

    // method where memoization happens
    private int helper(int[] coins, int value, Map<Integer, Integer> map) {
        // edge case, if value is 0, return 0
        if (value == 0) return 0;

        // if value already exists in map, there has been a calculation for it, just return computed value
        if (map.containsKey(value)) return map.get(value);

        int max = Integer.MAX_VALUE;

        // loop through all coins in list coins
        for (int coin: coins) {
            int remainder = value - coin;

            if (remainder >= 0) {
                // recursion to cut down value for getting minimum number of coins
                int temp = helper(coins, remainder, map);

                if (temp != -1) max = Math.min(max, temp);
            }
        }

        if (max == Integer.MAX_VALUE) map.put(value, -1);

        else map.put(value, max + 1);

        return map.get(value);
    }
    
    /*
    
    helper([1,2,5], 5, map) (from first test case above)
    
                5
              / | \
              4 3  0
             / \ / \
             3 2 2 1
            / \
            2 1
      
      minimum from this tree is 0, but since we selected one coin, we return 1
     */
}
