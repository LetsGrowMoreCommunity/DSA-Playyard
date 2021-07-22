/* 
Problem: Valid Sudoku on LeetCode
Solution by AtrikGit 6174

The program carefully checks for the validity of a Sudoku problem by first
1. Checking the rows and columns where it discovers a number=filled cell
2. Cheking the 3X3 mini-grid of which the found number-filled cell is a part of 
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution 
{
public:
    bool isValidSudoku(vector<vector<char>>& board) 
    {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        
        for (int i=0; i<9; i++)
        {
            //calculated for mini-grid check
            int row_start= 3*(i/3);
            int row_end= row_start+2;
            
            for (int j=0; j<9; j++)
            {
                //calculated for mini-grid check
                int col_start= 3*(j/3);
                int col_end= col_start+2;
                
                if (isdigit(board[i][j]))
                {
                    //row-col check
                    for (int k=0; k<9; k++)
                    {
                        if ( (k!=j && board[i][k]==board[i][j]) || (k!=i && board[k][j]==board[i][j]) )
                            return false;
                    }
                    
                    //mini-grid check
                    for (int row= row_start; row<=row_end; row++)
                    {
                        if (row!=i)
                        {
                            for (int col= col_start; col<=col_end; col++)
                            {
                                if (col!=j)
                                {
                                    if (board[row][col]==board[i][j])
                                        return false;
                                }
                            }
                        }
                    }
                }
            }
        }
        
        return true;        
    }
};

int main() 
{
	cout<<"\nEnter the number of test cases: ";
	int t; cin>>t;
	
	for (int count=1; count<=t; count++)
	{
	    cout<<"\nTEST CASE "<<count<<"\nEnter the Sudoku. \".\" for empty cells\n";
	    
	    vector<vector<char>> board (9);
	    char temp;
	    //input
	    for (int i=0; i<9; i++)
	    {
	        for (int j=0; j<9; j++)
	        {
	            cin>>temp;
	            board[i].push_back(temp);
	        }
	    }
	   
	    //display
	    cout<<"\nDISPLAY\n";
	    for (int i=0; i<9; i++)
	    {
	        for (int j=0; j<9; j++)
	            cout<<board[i][j]<<" ";
	       
	        cout<<"\n";
	    }
	    
	    Solution *ob;
	    cout<<"\n"<<((ob->isValidSudoku(board)) ? "true" : "false")<<"\n";
	}
	return 0;
}

/*
SAMPLE INPUT
2                       <-- NUMBER OF TEST CASES
5 3 . . 7 . . . .
6 . . 1 9 5 . . .
. 9 8 . . . . 6 .
8 . . . 6 . . . 3
4 . . 8 . 3 . . 1
7 . . . 2 . . . 6
. 6 . . . . 2 8 .
. . . 4 1 9 . . 5
. . . . 8 . . 7 9

8 3 . . 7 . . . .
6 . . 1 9 5 . . .
. 9 8 . . . . 6 .
8 . . . 6 . . . 3
4 . . 8 . 3 . . 1
7 . . . 2 . . . 6
. 6 . . . . 2 8 .
. . . 4 1 9 . . 5
. . . . 8 . . 7 9

SAMPLE OUTPUT (excluding interactive instructions)
true
false       <-- FIRST COLUMN 8 REPEATS

*/
