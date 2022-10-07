/*
Pythagorian Triplet
*/
#include <bits/stdc++.h>
using namespace std;
bool check(int x, int y, int z)
{
    int a = max(x, max(y, z));
    int b, c;
    if (a == x)
    {
        b = y;
        c = z;
    }
    else if (a == y)
    {
        b = x;
        c = z;
    }
    else
    {
        b = x;
        c = y;
    }

    if (a * a == ((b * b) + (c * c)))
        return true;
    else
        return false;
}
int main()
{
    int side1, side2, side3;
    cout << "Enter the 3 sides : ";
    cin >> side1 >> side2 >> side3;
    if (check(side1, side2, side3))
        cout << "Pythagorean Triplet";
    else
        cout << "Not a Pythagorean Triplet";
    return 0;
}