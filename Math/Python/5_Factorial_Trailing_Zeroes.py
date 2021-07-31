# Given an integer n, return the number of trailing zeroes in n!.
# Question https://leetcode.com/problems/factorial-trailing-zeroes

"""We can count trailing 0s by repeatedly dividing the factorial by 10 till the remainder is 0
    The idea is to consider prime factors of a factorial n.
    A trailing zero is always produced by prime factors 2 and 5.
    If we can count the number of 5s and 2s, our task is done. """

class Solution:
    # function that return trailing zeroes
    def trailingZeroes(self, n: int) -> int:
        count = 0;
        while(n > 1):   # count trailing zeroes
            count += n // 5
            n //= 5
        return count
n = input("n = ")    # take number from user to count trailing zeroes of factorial of user inputed number
print(Solution.trailingZeroes(Solution,int(n)))   # function calling and print trailing zeroes

#Example 1:
#Input: n = 3
#Output: 0
#Explanation: 3! = 6, no trailing zero.

#Example 2:
#Input: n = 5
#Output: 1
#Explanation: 5! = 120, one trailing zero.

#Example 3:
#Input: n = 10
#Output: 2
#Explanation: 10! = 3628800, two trailing zero.

#Example 4:
#Input: n = 0
#Output: 0

#Example 5:
#Input: n = 8
#Output: 1
#Explanation: 8! = 40320, one trailing zero.