# Python Program for merging two sorted arrays without extra space

# Function for merging two sorted arrays
def merge(M, N, A, B):

    # Traverse first array and check each element

    for i in range(M):
        # check if first element of second array is smaller
        if A[i] > B[0]:   
           A[i], B[0] = B[0], A[i]
           j = 0

           while j + 1 < N and B[j] > B[j + 1]:

                B[j], B[j + 1] = B[j + 1], B[j]
                j = j + 1

            # Print resultant array

            print(A)
            print(B)


M = 0
N = 0

# input size of both the arrays by user

M = int(input())

N = int(input())

# enter both the arrays

A = []
B = []

for i in range(M):
    a = int(input())
    A.append(a)

for i in range(N):
    a = int(input())
    B.append(a)
# Function call

merge(M, N, A, B)  

'''
Test Case:
Input:
A[ ] = { 1, 4 ,2, 3 }
B[ ] ={ 6, 5, 7 }

Output :
A[ ]= { 1, 2, 3, 4 }
B[ ]= { 5, 6, 7 }
'''

# Time Complexity:O(n*m)
# Space Complexity: constant space as no extra array is taken.
