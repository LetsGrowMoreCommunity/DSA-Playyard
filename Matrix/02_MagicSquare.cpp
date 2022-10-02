/* Magic square */
// A magic square is an arrangement of numbers (usually integers) in a square grid, where numbers in the forward and backward main diagonals, all add up to the same number. Write a program to find whether a given matrix is a magic square or not.

#include <iostream>
using namespace std;

int main()
{
    // Try out your code here
    int row, sumRo = 0, sumCo = 0, sumDia1 = 0, sumDia2 = 0;
    cin >> row;
    int sumRow[row] = {0}, sumCol[row] = {0}, sumDiag1[row] = {0}, sumDiag2[row] = {0};
    int magic[row][row] = {0};
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < row; j++)
        {
            cin >> magic[i][j];
        }
    }

    // Sum Row
    for (int i = 0; i < row; i++)
    {
        int sumRo = 0;
        for (int j = 0; j < row; j++)
        {
            sumRo = sumRo + magic[i][j];
        }
        sumRow[i] = sumRo;
    }

    // Sum Col
    for (int i = 0; i < row; i++)
    {
        int sumCo = 0;
        for (int j = 0; j < row; j++)
        {
            sumCo = sumCo + magic[j][i];
        }
        sumCol[i] = sumCo;
    }
    // Sum Diagnol
    for (int i = 0; i < row; i++)
    {
        int sumDia1 = 0;
        int sumDia2 = 0;

        for (int j = 0; j < row; j++)
        {
            if (i == j)
            {
                sumDia1 = sumDia1 + magic[i][j];
            }
            else if (i + j == (row - 1))
            {
                sumDia2 = sumDia2 + magic[i][j];
            }
        }
        sumDiag1[i] = sumDia1;
        sumDiag2[i] = sumDia2;
    }

    sumRo = 0;
    sumDia1 = 0;
    sumDia2 = 0;
    sumCo = 0;
    for (int i = 0; i < row; i++)
    {
        sumDia1 = sumDia1 + sumDiag1[i];
        sumDia2 = sumDia2 + sumDiag2[i];

        sumRo = sumRo + sumRow[i];
        sumCo = sumCo + sumCol[i];
    }

    if (sumRo == sumDia1 && sumCo == sumRo && sumRo == sumDia2)
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }
    return 0;
}