# Function to find the majority element present in a given array using hash table

def findMajorityElement(A):
 
    # Firstly create empty hash table
    # Insert all elements in a hash table
    H = {}
 
    # store each element's occurence
    for i in A:
        H[i] = H.get(i, 0) + 1

    # Check if frequency of any element is n/2 or more.
    # return the element if its count is more than n/2
    for key,value in H.items():
        if value > len(A) / 2:
            return key
 
    # no majority element is present
    return -1
 
 
if __name__ == '__main__':
 
    # Input size of array
    n=int(input("size"))
    A=[]
    for i in range (0,n):
        b=int(input("Enter elements of array")) # Input elements of array
        A.append(b)
 
    ans = findMajorityElement(A)
    if ans != -1:
        print("The majority element is", ans)
    else:
        print("The majority element is not present")


OUTPUT :  
size 5
Enter elements of array 2
Enter elements of array 2
Enter elements of array 5
Enter elements of array 6
Enter elements of array 2
The majority element is 2

Time Complexity : O(n)
Space Complexity : O(n) { due to hash table }

        
        