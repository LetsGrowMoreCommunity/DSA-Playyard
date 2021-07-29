# Sort an array(Heap)
# In this max heap is used to sort the array in ascending order.

def heapify(arr, n, i):
      largest = i   # Finding largest element
      l = 2 * i + 1
      r = 2 * i + 2
  
      if l < n and arr[i] < arr[l]:
          largest = l
  
      if r < n and arr[largest] < arr[r]:
          largest = r
  
      # If root is not largest, swap with largest and continue heapifying
      if largest != i:
          arr[i], arr[largest] = arr[largest], arr[i]
          heapify(arr, n, largest)
  
  
def heapSort(arr,n):
      # Build max heap
      for i in range(n//2, -1, -1):
          heapify(arr, n, i)
  
      for i in range(n-1, 0, -1):
          # Swap
          arr[i], arr[0] = arr[0], arr[i]
  
          # Heapify root element
          heapify(arr, i, 0)
   
arr = []
n = int(input("Size"))
for i in range(n):
    b= int(input("enter element"))
    arr.append(b)
heapSort(arr,n)

# printing sorted array

print("Sorted array is")
for i in range(n):
   print("%d " % arr[i], end='')


''' 
Output:
Size 5
enter element 23
enter element 45
enter element 12
enter element 5
enter element 56
Sorted array is
5 12 23 45 56 

'''
# Time Complexity : O(nlog n)
# Space Complexity : O(1)


  
