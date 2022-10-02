/*Maximum element in each row*/

#include <iostream>
using namespace std;

int main()
{
    int row, col, sumRo = 0, max = 0;
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
    
    // Max element in each Row
    for (int i = 0; i < row; i++)
    {
        sumRo = 0;
        for (int j = 0; j < col; j++)
        {
            if (sumRo < arr[i][j])
            {

                sumRo = arr[i][j];
            }

            else
                sumRo = sumRo;
        }
        sumRow[i] = sumRo;
        cout << sumRow[i] << endl;
    }

    return 0;
}