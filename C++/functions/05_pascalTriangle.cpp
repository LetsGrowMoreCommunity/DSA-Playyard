/*

    1                           0c0
    1 1                         1c0 1c1
    1 2 1                       2c0 2c1 2c2
    1 3 3 1                     3c0 3c1 3c2 3c3
    1 4 6 4 1                   4c0 4c1 4c2 4c3 4c4

*/

#include <iostream>
using namespace std;
int fac(int num)
{
    int fact = 1;
    for (int i = 1; i <= num; i++)
    {
        fact = fact * i;
    }
    return fact;
}
int main()
{
    int row;
    cout << "Enter the row: ";
    cin >> row;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << (fac(i) / (fac(i - j) * fac(j))) << " ";
        }
        cout << endl;
    }

    return 0;
}