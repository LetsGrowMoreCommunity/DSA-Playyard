/* Write a C++ program to find the sum of Zig-Zag pattern in a given matrix. FUNCTIONAL REQUIREMENTS: int sumZigZag(int, int, int **);
INPUT & OUTPUT FORMAT:
Input consists of 2 integers and 1 2D-array. Integers correspond to the size of rows and columns.
SAMPLE INPUT:
3
3
1 2 3
4 5 6
7 8 9
SAMPLE OUTPUT:
Sum of Zig-Zag pattern is 35
*/

#include <iostream>
using namespace std;

int main()
{
    int row, col, sumRo = 0, sumDia = 0;
    cin >> row >> col;
    int sumRow[row - 1] = {0}, sumDiag[row] = {0};
    int matrix[row][col] = {0};
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> matrix[i][j];
        }
    }

    // Sum Row
    for (int i = 0; i < row; i++)
    {
        sumRo = 0;
        if (row != 2 && i == row / 2)
            continue;
        else
        {

            for (int j = 0; j < row; j++)
            {
                if (row == 2 && j < i || i == 0 && j > i && row == 2 || i + j == row - 1)
                {
                    continue;
                }
                sumRo = sumRo + matrix[i][j];
            }
        }
        sumRow[i] = sumRo;
    }

    // Sum Diagonal
    for (int i = 0; i < row; i++)
    {

        for (int j = 0; j < row; j++)
        {
            if ((i + j) == (row - 1))
            {
                sumDiag[i] = matrix[i][j];
            }
        }
    }

    sumRo = 0;
    sumDia = 0;
    for (int i = 0; i < row; i++)
    {
        cout << "Diagonal value at " << i << " is" << sumDiag[i] << endl;
        sumDia = sumDia + sumDiag[i];
        cout << "Row value at " << i << " is" << sumRow[i] << endl;

        sumRo = sumRo + sumRow[i];
    }
    cout << "Sum of Zig-Zag pattern is " << (sumDia + sumRo);
    return 0;
}