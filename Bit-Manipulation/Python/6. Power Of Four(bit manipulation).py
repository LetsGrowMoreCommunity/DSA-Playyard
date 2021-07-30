# Power Of Four

# Given an integer n, return true if it is a power of four. Otherwise, return false.


def PowerOfFour(n):
    '''
     Here n should not be equal to 0 [Example: 16 is not equal to 0]
     Here use  a Bit-wise '&' operator to compare n and n-1 [ n=16[10000] and n-1=15[01111]]
     10000 & 01111 is zero 
     bits don’t '&' any part of the pattern 0xAAAAAAAA [0x10 & 0xAAAAAAAA is zero]
     Hence it will return true
     '''

	return (n != 0 and((n & (n - 1)) == 0) and not(n & 0xAAAAAAAA))

	# 0xAAAAAAAA is used as h bit representation is of powers of 2 that are not of 4. 


x = int(input("Enter Number \n"))  #For user to enter number
if(PowerOfFour(x)):
	print(True)   #if n is power of 4 
else:
	print(False)  #if n is not a power of 4


'''
OUTPUT:
Enter Number 
16
True

Enter Number 
20
False
'''

# Time Complexity :O(log4n)
# Space Complexity :O(1)

