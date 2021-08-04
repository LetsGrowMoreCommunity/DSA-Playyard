/*
Given two strings str1 and str2, return the largest string x such that x divides both str1 and str2.

In strings ‘str1’ and ‘str2’, we say “str2 divides str1” if and only if str1 = concatenation of str2 more than 1 times. Here we have to find the largest string which divides both str1 and str2. 

Input: str1 = "ABCABC", str2 = "ABC"
Output: "ABC"

Input: str1 = "ABABAB", str2 = "ABAB"
Output: "AB"
*/

//The code below implements this approach

import java.util.Scanner;

public class GreatestCommonDivisor {

    static Scanner sc = null;

    public String gcdOfStrings(String str1, String str2) {

        // Checking if the two strings are already equal
        while (!str2.isEmpty()) {
            if (str1.equals(str2)) {
                return str1;
            }

            // swap to make str1 longer than str2
            if (str1.length() < str2.length()) {
                String tmp = str1;
                str1 = str2;
                str2 = tmp;
            }

            // checking whether the substring of str1 (length of which is equal to the
            // length of str2) is equal to str2
            if (str1.substring(0, str2.length()).equals(str2)) {
                String r = str1.substring(str2.length());

                str1 = str2;
                str2 = r;

            } else {
                return "false";
            }
        }

        return str1;

    }

    public static void main(String[] args) {
        sc = new Scanner(System.in);
        System.out.println("Enter the first string : ");
        String str1 = sc.nextLine();
        System.out.println("Enter the second string : ");
        String str2 = sc.nextLine();
        GreatestCommonDivisor obj = new GreatestCommonDivisor();
        String res = obj.gcdOfStrings(str1, str2);
        if (res.equals("false")) {
            System.out.println("No Greatest Common Divisor possible!");
        } else
            System.out.println("The Greatest Common Divisor is : " + obj.gcdOfStrings(str1, str2));
    }

}

/*
Sample Input:
Enter the first string : 
XYZXYZ
Enter the second string : 
XYZ
Sample Output:
The Greatest Common Divisor is : XYZ

Sample Input:
Enter the first string : 
ABCABS
Enter the second string : 
ABC
Sample Output:
No Greatest Common Divisor possible!
*/
