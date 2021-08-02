/*Question:
Given an array of integers nums, sort the array in ascending order.(using Heap)

Explanation:
the program sorts the given array using heap sort.
here a function to build max heap and other function to check whether the element in nums[i] is largest if not change the largest to either left or right child by checking 
which one is larger.Now num[i] is interchaged with num[largest].
*/
 

#include<iostream>
using namespace std;
 

    void Array(int nums[],int i,int n){
        int largest=i;
        int left=2*i+1;
        int right =2*i+2;
        if(nums[left]>nums[largest] && left<n)
        {
            largest=left;//if the element in left index is larger point larger to left index
        }
        if(nums[right]>nums[largest] && right<n)
        {
            largest=right;//if the element in right index is larger point larger to right index
        }
        if(largest!=i)
        {
            swap(nums[i],nums[largest]);
            Array(nums,largest,n);
        }
    }
    
    void sortArray(int nums[],int n)
    {
        
        for(int i=n/2-1;i>=0;--i)
        {
            Array(nums,i,n); //for non-leaf nodes
        }
        for(int i=n-1;i>=0;--i)
        {
            swap(nums[0],nums[i]); 
            Array(nums,0,i);
        }
    }
    //to print the sorted array
  void sorted_array(int arr[],int n)
  {
      for(int i=0;i<n;i++)
      {
          cout<<arr[i]<<" ";
      }
      
  }
  int main()
  {
      int num[10];
      int n;
      cin>>n;
      for(int i=0;i<n;i++)
      {
          cin>>num[i];
          
      }
      
    sortArray(num,n);
      
    sorted_array(num,n);
    
      
  }
  
  /*
  Test Cases:
  Input:
  4 (size of array)
  8  (input array)
  5
  3
  2
  Output:
  2 3 5 8
  
  Input:
  5 (size of array)
  22 (input array)
  34
  11
  66
  44
  Output:
  11 22 34 44 66
  
  */
  
  
  
  
  
    
    
