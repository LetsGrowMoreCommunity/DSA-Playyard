/* Given an integer columnNumber, return its corresponding column title as it appears in an Excel sheet.
Problem Statement: https://leetcode.com/problems/excel-sheet-column-title/
*/

/* A simple iterative solution to continously divide base-10 number and generate a 
pseudo-base-26 character corresponding to the column title */

import java.util.Scanner;

public class ExcelSheetColumnTitle {
    public static String convertToTitle(int columnNumber) {
        StringBuilder ColumnName = new StringBuilder();  // store the result
        while (columnNumber > 0) {            
            columnNumber--;
            ColumnName.append((char)('A' + columnNumber % 26)); // treated 'A' to 'Z' with remainder 
            columnNumber /= 26;  // spilt the number by diving 26
        }
        return ColumnName.reverse().toString();  // reverse the name and return string 
    }
    public static void main(String[] args) {
    
        Scanner sc = new Scanner(System.in);
        System.out.print("ColumnNumber = ");    
        int n = sc.nextInt();   // taking input from user
        System.out.println("\""+convertToTitle(n)+"\"");   // calling to method and print
    }
}

/*
Example 1:
Input: columnNumber = 1
Output: "A"

Example 2:
Input: columnNumber = 28
Output: "AB"

Example 3:
Input: columnNumber = 80
Output: "CB"

Example 4:
Input: columnNumber = 701
Output: "ZY"

Example 5:
Input: columnNumber = 2147483647
Output: "FXSHRXW"
*/