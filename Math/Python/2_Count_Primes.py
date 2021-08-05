# Count the number of prime numbers less than a non-negative number, n
# problem statement: https://leetcode.com/problems/count-primes/

"""
Solution: Simple solution, first find the prime numbers less than n and increment the counter when ever you find prime number.
"""
class Solution:
    def countPrimes(self, n: int) -> int:
        count = 0             # set counter to 0
        for i in range(2, n + 1):      # start  loop 2 to n
            if i >= 1:
                for j in range(2, (i // 2) + 1):      # loop for find prime
                    if i % j == 0:            # check number is divisible or not
                        break        # number is divisible then break
                else:
                    count += 1      # not divisible increment counter
        return count       # return counter value

num = int(input("enter Number:"))      # take input from user
print(Solution.countPrimes(Solution,num))    # calling to function

''' 
Example 1:
Input: n = 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.

Example 2:
Input: n = 25
Output: 9
Explanation: There are 9 prime numbers less than 25, they are 2, 3, 5, 7, 11, 13, 17, 19, 23.

Example 3:
Input: n = 50
Output: 15
Explanation: There are 15 prime numbers less than 50, they are 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47.

Example 4:
Input: n = 0
Output: 0
Explanation: There are no prime numbers less than 0.

Example 5:
Input: n = 1
Output: There are no prime numbers less than 1.
'''