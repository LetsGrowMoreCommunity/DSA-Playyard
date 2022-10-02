/*Greatest sum*/

/* Input consists of 2 integers and 1 2D-array. Integers correspond to the size of rows and columns.
SAMPLE INPUT & OUTPUT:
3
3
1 6 8
2 5 1
3 8 2
Sum of rows is 15 8 13
Row 1 has maximum sum
Sum of columns is 6 19 11
Column 2 has maximum sum
Case 1
Case 2
Case 3
Input (stdin)
3
3
1 2 3
4 5 6
7 8 9
Output (stdout)
Sum of rows is 6 15 24
Row 3 has maximum sum
Sum of columns is 12 15 18
Column 3 has maximum sum */


#include <iostream>
using namespace std;

int main()
{
    int row, col, sumRo = 0, sumCo = 0, maxRow = 0, maxCol = 0, rowNum = 0, colNum = 0;
    cin >> row >> col;
    int sumRow[row] = {0}, sumCol[row] = {0};
    int grt[row][col] = {0};
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> grt[i][j];
        }
    }

    // Sum of each Row

    for (int i = 0; i < row; i++)
    {
        int sumRo = 0;
        for (int j = 0; j < col; j++)
        {
            sumRo = sumRo + grt[i][j];
        }
        sumRow[i] = sumRo;
    }

    // Sum of each Column
    for (int i = 0; i < col; i++)
    {
        int sumCo = 0;
        for (int j = 0; j < row; j++)
        {
            sumCo = sumCo + grt[j][i];
        }
        sumCol[i] = sumCo;
    }

    cout << "Sum of rows is ";
    for (int i = 0; i < row; i++)
    {
        sumRo = 0;

        sumRo = sumRo + sumRow[i];
        cout << sumRo << " ";
        if (maxRow < sumRo)
        {
            maxRow = sumRo;
            rowNum++;
        }
    }
    cout << "\nRow " << rowNum << " has maximum sum" << endl;
    cout << "Sum of columns is ";
    for (int i = 0; i < row; i++)
    {
        sumCo = 0;
        sumCo = sumCo + sumCol[i];
        cout << sumCo << " ";
        if (maxCol < sumCo)
        {
            maxCol = sumCo;
            colNum++;
        }
    }
    cout << "\nColumn " << colNum << " has maximum sum" << endl;

    return 0;
}