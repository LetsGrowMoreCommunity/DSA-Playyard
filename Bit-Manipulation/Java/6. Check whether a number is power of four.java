/*

6. Check whether a number is power of four(BIT-MANIPULATION)

 This problem is to check if a number is a power of four. It will loop through until (4 ^ i), depending on i,
 is greater than the given number (return false), or if it equals to the given number (return true)

 Works with numbers up to (2^31 - 1)

 Time Complexity: O(N)
 Space Complexity O(1)
 */

public class IfNumberIsPowerOfFour {

    // where method checks if value is power of four
    public boolean check(int value) {
        int i = 0;

        // loops until 4 to the power of i is equal to (return true) or greater than value (return false)

        int bits = value & (value - 1);

        if (value > 0 && bits == 0) {
            while (value > 1) {
                value >>= 1;
                i++;
            }

            return i % 2 == 0;
        }

        return false;
    }

    // To use for test cases
    public void print() {

        /*

        5 -> check(5) -> false
        64 -> check(64) -> true
        1073741824 -> check(1073741824) -> true

         */

        System.out.println(check(5));
        System.out.println(check(16));
        System.out.println(check(1073741824));
    }

    // To use for test cases
    public static void main(String[] args) {

        IfNumberIsPowerOfFour tester = new IfNumberIsPowerOfFour();

        tester.print();
    }
}
