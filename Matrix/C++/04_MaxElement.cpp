/*Maximum element in the matrix*/

#include <iostream>
using namespace std;

int main()
{
    int row, col, sumCo = 0, max = 0;
    cin >> row >> col;
    int sumCol[row] = {0};
    int matrix[row][col] = {0};
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> matrix[i][j];
        }
    }

    // Max in each Column
    for (int i = 0; i < col; i++)
    {
        sumCo = 0;
        for (int j = 0; j < row; j++)
        {
            if (sumCo < matrix[j][i])
            {

                sumCo = matrix[j][i];
            }

            else
                sumCo = sumCo;
        }
        sumCol[i] = sumCo;
    }

    // compare
    for (int i = 0; i < col; i++)
    {
        if (max < sumCol[i])
        {

            max = sumCol[i];
        }

        else
        {

            max = max;
        }
    }
    cout << "The maximum element is " << max;

    return 0;
}