/* Print the addition of two matrices */

#include <iostream>
using namespace std;
int main()
{
    int row, col;
    cin >> row >> col;
    int arr1[row][col], arr2[row][col], sum[row][col];
    // 1st array
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> arr1[i][j];
        }
    }
    // 2nd array
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> arr2[i][j];
        }
    }
    // sum array
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            sum[i][j] = arr1[i][j] + arr2[i][j];
        }
    }
    // printing array sum
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << sum[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
