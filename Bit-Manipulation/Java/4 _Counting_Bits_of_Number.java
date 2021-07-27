/* Question Counting Bits of a Number
In order to solve this problem 
Step 1 : Taking the input from the user and passing it to countingBits Function
Step 2 : Calculating bits of each number from 1 to n
Step 3 : Display the array elements of result.
Time Complexity : O(n^2)
Space Complexity : O(1)
*/

import java.util.*;
public class Counting_Bits_of_Number {
    //Counting Bits of a Number
    public static int[] countingBits(int n) {
        int A[]=new int[n+1]; // Create array 
        A[0]=0; 
        for(int i=1;i<=n;i++)
        {
            A[i]=(i&1)+A[i/2]; //Calculating Bits     
        }      
        return A; //Return values
    }
    
    //Main method
	public static void main(String[] args) {
	    
	    Scanner sc=new Scanner(System.in);
	    int num = sc.nextInt(); //Take input
	    int result[] = new int[num+1]; // create array
	    result = countingBits(num); // Call function
	    for(int i=0; i<result.length;i++)
	    {
	        System.out.print(result[i]+" "); //Print values
	    }
	}
}
//Input 1 : 4   Output 1 : 0 1 1 2 1
//Input 2 : 3   Output 2 : 0 1 1 2
