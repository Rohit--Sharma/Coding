#include <stdio.h>
#include <math.h>

char keyPad[][3]  = {{'1', '2', '3'},
					{'4', '5', '6'},
					{'7', '8', '9'},
					{'*', '0', '#'}};
		
// left, up, right, down move from current location
int row[] = {0, 0, -1, 0, 1};
int col[] = {0, -1, 0, 1, 0};
	
int validMoves(int r, int c, int len) 
{
	if (len <= 0)
	{
		printf("HI len");
	}
	if (len == 1)
	{
		return 1;
	}
	
	int moves , i, j, nMoves = 0;
	
	for (moves = 0; moves < 5; moves += 1)
	{
		i = r + row[moves];
		j = c + col[moves];
		
		if (i >= 0 && j >= 0 && i <= 3 && j <= 2 && keyPad[i][j] != '*' && keyPad[i][j] != '#') {
			nMoves += validMoves(i, j, len-1);
		}
	}
	return nMoves;
}
					
int mobileNumbers(int x)
{
	if (x <= 0)
	{
		printf("HI");
	}
	if (x == 1)
	{
		return 10;
	} 
	
	int count = 0;
	
	int i, j;
		
	for (i = 0; i < 4; i += 1)
	{
		for (j = 0; j < 3; j += 1)
		{
			if (keyPad[i][j] != '*' && keyPad[i][j] != '#')
			{
				count += validMoves(i, j, x);
				printf("\t%d %d: %d\n", i, j, validMoves(i, j, x));
			}
		}
	} 
	
	return count;

}

int main (int argc, char *argv[])
{
	int n; scanf("%d", &n);
	
	
	printf("%d\n", mobileNumbers(n));
	
	return 0;
}
