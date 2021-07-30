# Check wether number entered by user is power of 2 or not

# This function checks if the given x is power of 2 or not
def isPowerOfTwo (x):

	# First x in the below expression
	# is for the case when x is 0 
	# let us consider x is 4(100) x-1 is 3(011)
	# 100 & 011 will be 0 it will give true as output
	return (x and (not(x & (x - 1))) )

# simple condition to check which will call isPowerOfTwo
n= int(input("Enter Number\n"))
if(isPowerOfTwo(n)):
	print('True')
else:
	print('False')

'''
OUTPUT:
Enter Number
35
False

Enter Number
4
True

'''	
		
#Time complexity : O(1)

#Space complexity : O(1) 

	
	
	

	




