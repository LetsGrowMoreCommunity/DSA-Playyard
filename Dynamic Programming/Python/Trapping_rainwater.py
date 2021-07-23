#Program for trapping rainwater problem 
def maxWater(arr, n) :
    # res variable is used to store final ans.
    res = 0; 
    # So the basic logic is we will find the max from right and left side and then take minimum of both and subtract the current value..
    for i in range(1, n - 1) : 
        # Find the maximum element on its left 
        left = arr[i]; 
        for j in range(i) :
            left = max(left, arr[j]); 
        # Find the maximum element on its right 
        right = arr[i]; 
        for j in range(i + 1 , n) : 
            right = max(right, arr[j]);
        # Update the maximum water
        res = res + (min(left, right) - arr[i]); 
    return res; 
if __name__ == "__main__" : 
 
    arr = []
    n=int(input("Enter size : "))
    for i in range(n):
      e=int(input())
      arr.append(e)
    print(maxWater(arr, n)); 
    
#Example
#Input: 5
#4 1 2 3 0
#Output : 3