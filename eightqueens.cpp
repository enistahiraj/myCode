/***************************************************************************************
 Name:Enis Tahiraj
 Date:02/28/2018
 Title:Eight queens problem
 Description:The program doesn't take any input, it prints 10 different ways of arranging 8 queens
            (represented with '1') in a board 8x8. The queens can't be in the same row, column or any of the diagonals.
 ***************************************************************************************/
#include <iostream>
using namespace std;
#define arrSize 8
//variable to keep track for printing solutions
int t=0;
bool solveQueenPrb(int board[][arrSize], int col);
void printSolutions(int board[][arrSize]);
bool isSafe(int board[][arrSize], int row, int col);
void solutionCheck();


int main()
{
	
	solutionCheck();

	return 0;
}

bool solveQueenPrb(int board[][arrSize], int col)
{
	if(t == arrSize+2)
	{
		return 0;
	}
	if (col == arrSize)
	{
		//print solution number and call the print function
		cout <<"\n"<<t+1<<")" <<"\n";
		printSolutions(board);
		//increment printed times every time it prints a solution
		t++;
		return true;
	}

	for (int i=0; i<arrSize; i++)
	{
		if (isSafe(board, i, col))
		{
			board[i][col] = 1;
			solveQueenPrb(board, col + 1);
			
			board[i][col] = 0;
		}
	}
	return false;
}

void printSolutions(int board[][arrSize])
{
		for (int i=0; i<arrSize; i++)
		{
			cout <<" ";
			for (int j=0; j<arrSize; j++)
			{
				
				cout << board[i][j] <<" ";
				
			}
			cout << endl;
		}
	}

bool isSafe(int board[][arrSize], int row, int col)
{
	int i, j;

	//Check row in the left side
	for (i=0; i<col; i++)
	{
       // cout <<"\nchecking row in the left\n";
        //cout <<"row is = " <<row <<endl;
       // cout <<"i is = " <<i <<endl;
		if (board[row][i])
		{
			return false;
		}
	}

	//Check upper diagonal on the left
	for (i=row, j=col; i>=0 && j>=0; i--, j--)
	{
		if (board[i][j])
		{
			return false;
		}
	}

	//Check lower diagonal on the left
	for (i=row, j=col; i<arrSize && j>=0; i++, j--)
	{
		if (board[i][j])
		{
			return false;
		}
	}
	return true;
}

void solutionCheck()
{
	int board[arrSize][arrSize];
	for (int i=0; i<arrSize; i++)
	{
		for (int j=0; j<arrSize; j++)
		{
			board[i][j] = 0;
		}
	}

	if (solveQueenPrb(board, 0) == false)
	{
		return ;
	}
	return;
}
