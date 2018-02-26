#include <stdio.h>
#define N 9
#define UNASSIGNED 0
int sudoku[N][N];

void print_line()
{
	int i;
	for(i = 0; i < 25; i++)
	{
		if(i % 8 == 0)
			printf("+");
		else
			printf("-");
	}
	printf("\n");
}

void print()
{
	int i, j;
	for(i = 0; i < N; i++)
	{
		for(j = 0; j < N; j++)
			printf("%d ", sudoku[i][j]);
		printf("\n");
	}
}

void print_stylized()
{
	int i, j;
	for(i = 0; i < N; i++)
	{
		if(i % 3 == 0)
			print_line();
		printf("| ");
		for(j = 0; j < N; j++)
		{
			if(j == 3 || j == 6)
				printf("| ");
			printf("%d ", sudoku[i][j]);
		}
		printf("|\n");
	}
	print_line();
}

int find_next_unassigned(int *row, int *col)
{
	int i, j;
	
	// find the next unassigned cell and store in row and col
	for(i = 0; i < N; i++)
	{
		for(j = 0; j < N; j++)
		{
			if(sudoku[i][j] == UNASSIGNED)
			{
				*row = i;
				*col = j;
				return 1;
			}
		}
	}
	return 0;
}

int used_in_row(int row, int col, int num)
{
	int i = row, j;
	
	// check if num is present in any cell in row
	for(j = 0; j < N; j++)
	{
		if(j != col)
		{
			if(num == sudoku[i][j])
				return 1;
		}
	}
	return 0;
}

int used_in_col(int row, int col, int num)
{
	int i, j = col;
	
	// check if num is present in any cell in column
	for(i = 0; i < N; i++)
	{
		if(i != row)
		{
			if(num == sudoku[i][j])
				return 1;
		}
	}
	return 0;
}

int used_in_box(int row, int col, int num)
{
	int start_i, start_j, end_i, end_j, i, j;
	start_i = row/3;
	start_j = col/3;
	
	start_i *= 3;
	start_j *= 3;
	end_i = start_i + 3;
	end_j = start_j + 3;
	
	// check if num is present in the 3x3 box
	for(i = start_i; i < end_i; i++)
	{
		for(j = start_j; j < end_j; j++)
		{
			if(!(i == row && j == col))
			{
				if(num == sudoku[i][j])
					return 1;
			}
		}
	}
	return 0;
}

int is_safe(int row, int col, int num)
{
	if(used_in_row(row, col, num) || used_in_col(row, col, num) || used_in_box(row, col, num))
		return 0;
	return 1;
}

int is_solvable()
{
	// consider some row and column and num (which runs from 1 to 9)
	int row, col, num;
	
	// if there is any unassigned cell, fetch the co-ordinates and store in row and column
	// else puzzle is done
	if(!find_next_unassigned(&row, &col))
		return 1;
	
	// start with num = 1 for any cell
	for(num = 1; num <= N; num++)
	{
		if(is_safe(row, col, num))
		{
			// if num can be assigned to this cell store it assuming it to be true
			sudoku[row][col] = num;
			
			// if storing num in that cell leads to solution continue
			if(is_solvable())
				return 1;
			
			// else remove the num from that cell and backtrack
			sudoku[row][col] = UNASSIGNED;
		}
	}
	
	return 0;
}

void solve()
{
	if(is_solvable())
		print_stylized();
	else
		printf("No Solution Exists!\n");
}

int main()
{
	int i, j;
	for(i = 0; i < N; i++)
		for(j = 0; j < N; j++)
			scanf("%d", &sudoku[i][j]);
	
	solve();
	
	return 0;
}

