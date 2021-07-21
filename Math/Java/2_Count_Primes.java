/*
 Question - Count Prime
 In order to solve the problem first let us understand what are prime numbers
 Prime numbers are the numbers which are divisible by 1 and by itself
 Step 1 : Taken value of N from user
 Step 2 : Called countPrimeNumbers Function to find no. of prime numbers
 Step 3 : Iterate from 2 to N and check which number is prime by calling isPrime Function which 
 returns false if any value is divisible from 2 to num/2 otherwise return true. If the value is 
 return by isPrime Function is true then we increase count 
 Step 4 : Return count from countPrimeNumbers Function and print it in the main function.
 Time Complexity : O(n^2)
 Space Complexity : O(1)
*/
import java.util.*;
public class Count_Primes
{
    //Function to check whether a number is prime or not
    public static boolean isPrime(int num) {
        
        for(int x = 2; x <= num/2; x++) 
        {
            if(num % x == 0) // Checking whether number is divisible by values in x
            {
                return false; // Returning false if remainder is 0
            }
        }
        return true; 
    }
    
    //Function to check number of Prime Numbers
    public static int countPrimeNumbers(int n) {
        
        int count = 0;//count number of prime numbers
        // Since 1 is neither prime nor composite , we will start counting from 2
        for(int i = 2; i <= n; i++) // Find number of prime numbers from 2 to n
        {
            if(isPrime(i)) //Check if a number is prime or not by calling is Prime Function
            {
                count++; // Increase count if number is prime
            }
        }
        
        return count; //Return value of count
    }
    
    public static void main(String args[]) {
        
        Scanner sc=new Scanner (System.in);
        int N = sc.nextInt(); // Taking User Input
         
        int result = countPrimeNumbers(N); // Calling countPrimeNumbers Function to find no. of prime numbers
        System.out.println(result);// Printing Result
    }
}

//Input 1 : 11     Output 1 : 5
//Input 2 : 1      Output 2 : 0