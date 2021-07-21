// Factorial Trailing Zeroes 
// In this question, we have to find the number of trailing zeroes in n!
// Factorial means the product of all positive integers less than or equal to a given positive integer and denoted as n!.


// Code:

#include <iostream>
using namespace std;

// function to find number of trailing zeroes
int trailingZeroes (int n)
{
  int zeroes = 0;
  int divisor5 = 5;
  while (n >= divisor5)
    {
      zeroes += n / divisor5;
      divisor5 *= 5;
    }

  return zeroes;
}

// main function
int main ()
{
  int n;
  cout << "Enter a Number : ";
  cin >> n;
  int res = trailingZeroes (n);
  cout << "No of trailing zeroes in " << n << "! = " << res << endl;

  return 0;
}

// Input 1:
// 5
// Output 1:
// There is only 1 trailing zero in 5!, as 5! = 120 

// Input 2:
// 10
// Output 2:
// There are 2 trailing zero in 10!, as 10! = 3628800


// Time Complexity : O(logn)
// Space Complexity : O(1)
