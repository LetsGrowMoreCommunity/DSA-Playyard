/*

Problem: Rectangle Area

Description: 
Given the coordinates of two rectilinear rectangles in a 2D plane, return the total area covered by the two rectangles.
The first rectangle is defined by its bottom-left corner (ax1, ay1) and its top-right corner (ax2, ay2).
The second rectangle is defined by its bottom-left corner (bx1, by1) and its top-right corner (bx2, by2).

This solution returns the total area cvered by the two rectangles.

*/

#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        
		int ans;
        
        int r1, r2, r3;
        r1=((ay2-ay1)*(ax2-ax1)); //Area of rectangle 1
        r2=((by2-by1)*(bx2-bx1)); //Area of rectangle 2
        ans=r1+r2; //Returns this if there is no overlap
        
        int ix1, ix2, iy1, iy2;
        ix1=max(ax1,bx1);
        iy1=max(ay1,by1);
        ix2=min(ax2,bx2);
        iy2=min(ay2,by2);
        
        
        // If the rectangles overlap
        if((ix1<ix2) && (iy1<iy2)) {
            r3=((iy2-iy1)*(ix2-ix1)); //Intersection area
            ans-=r3; // Subtracts the intersection area from the total area
        }
        
        return ans;    
    }
};

int main() {
	
	int t;
	cout<<"Enter the number of test cases: ";
	cin>>t;
	
	for(int i=0;i<t;i++) {
		
		Solution* s = new Solution;
		
		int AX1, AY1, AX2, AY2, BX1, BY1, BX2, BY2;
		// Enter the coordinate in the below given order.
		cout<<"Enter the coordinates: ";
		cin>>AX1>>AY1>>AX2>>AY2>>BX1>>BY1>>BX2>>BY2;
		
		int answer;
		answer=s->computeArea(AX1, AY1, AX2, AY2, BX1, BY1, BX2, BY2);
		cout<<"Answer: "<<answer<<endl;	
		
	}
	return 0;
}

/*
//Accepted

r1 represnts first rectangle
r2 represents second rectangle
The input has to be in the following order:
input-1: r1 bottom-left corner x coordinate
input-2: r1 bottom-left corner y coordinate
input-3: r1 top-right corner x coordinate
input-4: r1 top-right corner y coordinate
input-5: r2 bottom-left corner x coordinate
input-6: r2 bottom-left corner y coordinate
input-7: r2 top-right corner x coordinate
input-8: r2 top-right corner y coordinate


SAMPLE INPUT:
3                                     -> Number of testcases
-3 0 3 4 0 -1 9 2                     -> First testcase 
-2 -2 2 2 -2 -2 2 2                   -> Second testcase
-2 -2 2 2 3 3 4 4                     -> Third testcase

SAMPLE OUTPUT:
45                                    -> Total area covered by the two rectangle provided in first testcase
16
17

Explanation:
r3 represents area of intersection

Testcase 1: 
r1=24 r2=27 r3=6
Total area = 24+27-6 = 45

Testcase 2:
r1=16 r2=16 r3=16
Total area = 16+16-16 = 16

Testcase 3:
r1=16 r2=1 (r3 doesn't exist. Because the rectangles do not overlap)
Total area = 16+1 = 17

Time complexity: O(n)
n = number of testcases

*/
