/*Que:
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
*/

/*
description:
here we have used binary search for finding the target in matrix.
first we find the index of the mid element using mid/m and mid%m as row and column index.
Now we check whether the element is smaller than or greater than mid element found using the given index.
again we continue the process until we get the exact position.
*/


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
       int n=matrix.size();
       int m=matrix[0].size();
        int low=0;
        int high=(n*m)-1;
        while(low<=high)
        {
            int midd=(low+(high-low)/2);
            
            if(matrix[midd/m][midd%m]==target)
            {
               return true; 
            }
            if(matrix[midd/m][midd%m]<target)
            {
                low=midd+1;
            }
            else
            {
                high=midd-1;
            }
            
        }
        return false;
    }
};

/*TestCases:
Input:
matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: 
true

Input:
matrix=[[2,5,6,9],[11,12,14,15],[17,18,20,21]],target=13
Output:
false
*/
