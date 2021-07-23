package Contribution;

/*

6. Pascal's Triangle (DP)

 This problem is to create a Pascal's Triangle given a number of rows the triangle needs to have. The pattern is that
 after creating the first two rows, the middle number(s) are the sum of the two above numbers, which is the one with the 
 same index of the previous row and the one with the index subtracted by one of the previous row

 Time Complexity: O(N^2)
 Space Complexity O(N)
 */

import java.util.*;

public class PascalTriangle {
    // runs test cases
    public static void main(String[] args) {
        PascalTriangle pt = new PascalTriangle();
        pt.printList();
    }
    
    // method to input test cases
    private void printList() {
        System.out.println(pascalTriangle(5));
        System.out.println(pascalTriangle(2));
    }
    
    // method that creates the Pascal Triangle
    private List<List<Integer>> pascalTriangle(int rows) {
        List<List<Integer>> result = new ArrayList<List<Integer>>();
        result.add(new ArrayList<>(Arrays.asList(1)));
        
        if (rows == 1) return result;
        
        result.add(new ArrayList<>(Arrays.asList(1, 1)));

        if (rows == 2) return result;

        for (int i = 2; i < rows; i++) {
            List<Integer> sublist = new ArrayList<>();
            sublist.add(1);

            for (int j = 1; j < i; j++) {
                int next_num = result.get(i-1).get(j) + result.get(i-1).get(j-1);
                sublist.add(next_num);
            }

            sublist.add(1);
            result.add(sublist);
        }

        return result;
    }
    
    /*
    
    Test Cases:
    
    pascalTriangle(5) -> [1], [1. 1], [1, 2, 1], [1, 3, 3, 1], [1, 4, 6, 4, 1]
    pascalTriangle(2) -> [1], [1,1]
    
     */
}
