// Question https://leetcode.com/problems/valid-sudoku/

/**
 * Check if each row of the board[][] array stores only unique values from the range [1, 9] or not.
 * Check if each column of the board[][] array stores unique values from the range [1, 9] or not.
 * Check if all possible 3 × 3 submatrices of the board[][] array stores unique values from the range [1, 9] or not.
 */

// Solution

import java.util.Scanner;

class Solution {

    public static boolean isValidSudoku(char[][] board) {

        boolean[][] rows = new boolean[9][9];
        boolean[][] columns = new boolean[9][9];
        boolean[][] boxes = new boolean[9][9];

        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.'){
                    int n = Character.getNumericValue(board[i][j]);
                    int boxindex = (i / 3) * 3 + j / 3;
                    if(rows[i][n-1] ||
                            columns[j][n-1] ||
                            boxes[boxindex][n-1])
                        return false;
                    else{
                        rows[i][n-1] = true;
                        columns[j][n-1] = true;
                        boxes[boxindex][n-1] = true;
                    }
                }
            }
        }
        return true;
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        char[][] board = new char[9][9];

        for(int i = 0; i < 9; i++) {
            String s = sc.next();
            for (int j = 0; j < 9; j++) {
                board[i][j] = s.charAt(j);
            }
        }

        System.out.println( isValidSudoku(board) );
    }
}

// Examples
/**
 * Example 1:
 * Input: board =
 * [["5","3",".",".","7",".",".",".","."]
 * ,["6",".",".","1","9","5",".",".","."]
 * ,[".","9","8",".",".",".",".","6","."]
 * ,["8",".",".",".","6",".",".",".","3"]
 * ,["4",".",".","8",".","3",".",".","1"]
 * ,["7",".",".",".","2",".",".",".","6"]
 * ,[".","6",".",".",".",".","2","8","."]
 * ,[".",".",".","4","1","9",".",".","5"]
 * ,[".",".",".",".","8",".",".","7","9"]]
 * Output: true
 *
 * Example 2:
 * Input: board =
 * [["8","3",".",".","7",".",".",".","."]
 * ,["6",".",".","1","9","5",".",".","."]
 * ,[".","9","8",".",".",".",".","6","."]
 * ,["8",".",".",".","6",".",".",".","3"]
 * ,["4",".",".","8",".","3",".",".","1"]
 * ,["7",".",".",".","2",".",".",".","6"]
 * ,[".","6",".",".",".",".","2","8","."]
 * ,[".",".",".","4","1","9",".",".","5"]
 * ,[".",".",".",".","8",".",".","7","9"]]
 * Output: false
 *
 * Explanation: Same as Example 1, except with the 5 in the top left corner being modified to 8.
 * Since there are two 8's in the top left 3x3 sub-box, it is invalid.
 */

// Time Complexity O(n2)
// Space Complexity O(1)
