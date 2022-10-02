/* To find sum of each row */

#include <iostream>
using namespace std;

int main()
{
    int row, col, sumRo = 0;
    cin >> row >> col;
    int sumRow[row] = {0};
    int arr[row][col] = {0};
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> arr[i][j];
        }
    }

    // Sum Row

    for (int i = 0; i < row; i++)
    {
        int sumRo = 0;
        for (int j = 0; j < col; j++)
        {
            sumRo = sumRo + arr[i][j];
        }
        sumRow[i] = sumRo;
        cout << sumRow[i] << endl;
    }
    return 0;
}