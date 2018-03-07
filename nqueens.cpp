/***************************************************************************************
 Name:Enis Tahiraj
 Date:02/28/2018
 Title:N queens problem
 Description:The program takes an input (int) n (between numbers 8 and 20), the program prints
            one possible way of arranging n queens (represented with 1) in a nxn board. The
            queens cant be in the same row, column or any of the diagonals.
 ***************************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
bool solveNQueens(int **board, int col, int &n);
bool isSafe(int **board, int row, int col, int &n);
void printSolutions(int **board, int &n);
bool solutionCheck(int n);
int getBoardSize();

int main()
{
    int n=getBoardSize();
    solutionCheck(n);
    
    return 0;
}

bool solveNQueens(int **board, int col, int &n)
{
    if (col == n)
    {
        return true;
    }
    
    for (int i=0; i<n; i++)
    {
        if (isSafe(board, i, col, n))
        {
            board[i][col] = 1;
            
            if (solveNQueens(board, col+1, n))
                return true;
            
            board[i][col] = 0;
        }
    }
    return false;
}

bool isSafe(int **board, int row, int col, int &n)
{
    int i,j;
    //check row in the left
    for (i=0; i<col; i++)
    {
        if (board[row][i])
        {
            return false;
        }
    }
    
    //check upper diagonal left
    for (i=row, j=col; i>=0 && j>=0; i--, j--)
    {
        if (board[i][j])
        {
            return false;
        }
    }
    
    //check lower diagonal left
    for (i=row, j=col; i<n && j>=0; i++, j--)
    {
        if (board[i][j])
        {
            return false;
        }
    }
    return true;
}

void printSolutions(int **board, int &n)
{
    for (int i=0; i<n; i++)
    {
        cout <<" ";
        for (int j=0; j<n; j++)
        {
            cout << board[i][j] <<" ";
            
        }
        cout << endl;
    }
}

bool solutionCheck(int n)
{
    int **board;
    board = new int *[n];
    for (int l=0; l<n; l++)
    {
        board[l] = new int [n];
    }
    
    for (int i=0; i<n; i++)
     {
         for (int j=0; j<n; j++)
         {
         board[i][j] = 0;
         }
     }
    if (solveNQueens(board, 0, n) == false)
    {
        cout <<"\nThere are no Solutions\n";
        return false;
    }
 
    printSolutions(board, n);
    return true;
}

int getBoardSize()
{
    int n=0;
    cout <<"\nEnter a number between 8 and 20 to create the board\n";
    cin >> n;
    while (n < 8 || n > 20)
    {
        cout <<"\nEnter a number between 8 and 20 to create the board\n";
        cin >> n;
        
    }
    return n;
}
