/*
Problem: Valid Square

Description: 
1. Given the coordinates of four points in 2D space p1, p2, p3 and p4, return true if the four points construct a square.
2. The coordinate of a point pi is represented as [xi, yi]. The input is not given in any order.
3. A valid square has four equal sides with positive length and four equal angles (90-degree angles).
*/

#include <iostream>
using namespace std;

struct Point {
	int x, y;
};

int distSq(Point p, Point q)
{
	return (p.x - q.x) * (p.x - q.x) + (p.y - q.y) * (p.y - q.y);
}

bool isSquare(Point p1, Point p2, Point p3, Point p4) //if p1,p2,p3,p4 forms a square otherwise returns false.
{
	int d2 = distSq(p1, p2); // p1 to p2
	int d3 = distSq(p1, p3); // p1 to p3
	int d4 = distSq(p1, p4); // p1 to p4

	if (d2 == 0 || d3 == 0 || d4 == 0) //if any of the points are similar
		return false;

	if (d2 == d3 && 2 * d2 == d4 && 2 * distSq(p2, p4) == distSq(p2, p3)) {
		return true;
	}

	if (d3 == d4 && 2 * d3 == d2 && 2 * distSq(p3, p2) == distSq(p3, p4)) {
		return true;
	}
	if (d2 == d4 && 2 * d2 == d3 && 2 * distSq(p2, p3) == distSq(p2, p4)) {
		return true;
	}

	return false;
}
int main()
{
	Point p1 = {0,0}, p2 = {1,1}, p3 = {1,0}, p4 = {0,1};
	isSquare(p1, p2, p3, p4) ? cout << "True" : cout << "False";
	return 0;
}

/*
Time Complexity : O(1)

Points:
Square has 4 sides they must be the same.
Square has 2 diagonal they must be the same.
All fours sides formed by points are the same.
The angle between any two sides is 90 degree.

Algorithm:
1. Declare a structure name point.
2. Declare function which will help to find deistance of two points. Let take p&q.
3. Declare one more function to check if point p1,p2,p3,p4 forms a square. If it satisfy the condition then return true, else false.
4. If lengths if (p1, p2) and (p1, p3) : Square of length of (p1, p4) is same as twice the square of (p1, p2).
                                         Square of length of (p2, p3) is same as twice the square of (p2, p4).
5. Declare drivers function i.e. int main().
6. Call the point function and take input.
7. Display the output as true if the condition is satisfied else false.
8. Finished.
*/
