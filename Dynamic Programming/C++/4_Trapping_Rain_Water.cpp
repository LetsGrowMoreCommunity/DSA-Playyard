// Trapping Rain Water
// In this question , we have given n non-negative integers representing an elevation map where the width of each bar is 1, and we have to compute how much water it can trap after raining.

// Approach : Maintaing two array, Left and Right, which stores the maximum height at each index. Left array stores the maximum height from left side and 
//            right array stores  the maximum height from right side.
//            After that , initialize a variable sum =0  , iterate over the original array (height array) and update the sum by: 
//                     sum += min(leftmax[i], rightmax[i])- height[i]
//            and at last return the sum.

// code

#include <iostream>
using namespace std;

//  function to compute how much water can trap after raining.
int trap(int height[], int n) {
       
        int left[n+1], right[n+1];
        
        left[0] = height[0];
        for(int i=1;i<n;i++){
            left[i] = max(left[i-1],height[i]);
        }
        right[n-1] = height[n-1];
        for(int i=n-2;i>=0;i--){
            right[i] = max(right[i+1],height[i]);
        }
        
        int sum = 0;
        for(int i=0;i<n;i++){
        sum = sum + ( min(left[i], right[i]) - height[i] );
        }
        
        return sum;
    }

// main function
int main()
{
    int n;
    cin >> n;
    int height[n];
    for(int i=0;i<n;i++){
        cin>>height[i];
    }
    
    int res = trap(height, n);
    cout<<res;

    return 0;
}

// Input 1
// [4,2,0,3,2,5]
// Ouput : 9

// Input 2
// [0,1,0,2,1,0,1,3,2,1,2,1]
// Output : 6


// Complexity Analysis
// Time Complexity : 0(N), where N = size of the height array
// Space Complexity : 0(N),  extra space for left and right array
