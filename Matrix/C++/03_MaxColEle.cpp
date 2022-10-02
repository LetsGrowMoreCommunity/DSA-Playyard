/* Maximum element in each column */

#include <iostream>
using namespace std;

int main()
{
    int row, col, sumCo = 0;
    cin >> row >> col;
    int sumCol[col] = {0};
    int party[row][col] = {0};
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> party[i][j];
        }
    }

    // Max Column
    for (int i = 0; i < col; i++)
    {
        sumCo = 0;
        for (int j = 0; j < row; j++)
        {
            if (sumCo < party[j][i])
                sumCo = party[j][i];
            else
                sumCo = sumCo;
        }
        cout << sumCo << endl;
    }

    return 0;
}