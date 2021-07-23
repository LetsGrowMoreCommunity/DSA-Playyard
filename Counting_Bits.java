/* Question Counting Bits
In order to solve this problem 
Step 1 : Taking the input from the user and passing it to countingBits Function
Step 2 : Create a res array. Iterate for loop from 0 to n and then pass each 
value to bitsofNumber Function to find the bits of each number which is done 
using while loop till n is not equal to 0. If this is the case them we check if 
n % 2 = 1 then we increase ans otherwise we divide n by 2.
Step 3 : Display the array of result.
*/

import java.util.*;
public class Counting_Bits
{
    
    //Calculate bits of each number
    public static int bitsofNumber(int n){
        int ans = 0;
 
        while(n != 0){
            if(n % 2 == 1){ // Check if remainder of value is 1 
                ans++; // Increase answer
            }
            n = n/2; // Divide value by 2
        }
 
        return ans;
    }
    // Counting Bits till num
    public static int[] countingBits(int num) {
        int[] res = new int[num+1]; //Create array 
 
        for(int x=0; x<=num; x++){ // Iterate from 0 to n
            res[x] = bitsofNumber(x); // Calling bitsofNumber function
        }
 
        return res;
    }
    
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