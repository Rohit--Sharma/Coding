#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <stack>
#include <map>
#include <queue>
#include <list>
#include <algorithm>

using namespace std;

// O(n^2)
class TicTacToe
{
  public:
	/** Initialize your data structure here. */
	TicTacToe(int n)
	{
		board = vector<vector<int>>(n, vector<int>(n, -1));
	}

	/** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
	int move(int row, int col, int player)
	{
		board[row][col] = player;
		return goalCheck();
	}

	void printBoard()
	{
		for (int i = 0; i < board.size(); i++)
		{
			for (int j = 0; j < board[i].size(); j++)
			{
				cout << board[i][j] << " ";
			}
			cout << endl;
		}
	}

  private:
	vector<vector<int>> board;

	int goalCheck()
	{
		// rows
		bool isGoal;
		int winningPlayer;
		for (int i = 0; i < board.size(); i++)
		{
			isGoal = true;
			winningPlayer = board[i][0];
			if (winningPlayer == -1)
				continue;
			for (int j = 1; j < board[i].size(); j++)
			{
				if (board[i][j] == -1 || board[i][j] != winningPlayer)
				{
					isGoal = false;
					break;
				}
			}
			if (isGoal)
				return winningPlayer;
		}

		// cols
		isGoal = true;
		for (int i = 0; i < board[0].size(); i++)
		{
			isGoal = true;
			winningPlayer = board[0][i];
			if (winningPlayer == -1)
				continue;
			for (int j = 1; j < board.size(); j++)
			{
				if (board[j][i] == -1 || board[j][i] != winningPlayer)
				{
					isGoal = false;
					break;
				}
			}
			if (isGoal)
				return winningPlayer;
		}

		// diags
		isGoal = true;
		winningPlayer = board[0][0];
		if (winningPlayer != -1)
			for (int i = 1; i < board.size(); i++)
			{
				if (board[i][i] == -1 || board[i][i] != winningPlayer)
				{
					isGoal = false;
					break;
				}
			}
		else
			isGoal = false;
		if (isGoal)
			return winningPlayer;

		isGoal = true;
		winningPlayer = board[0][board.size() - 1];
		if (winningPlayer != -1)
			for (int i = 1; i < board.size(); i++)
			{
				if (board[i][board.size() - i - 1] == -1 || board[i][board.size() - i - 1] != winningPlayer)
				{
					isGoal = false;
					break;
				}
			}
		else
			isGoal = false;
		if (isGoal)
			return winningPlayer;

		return 0;
	}
};

// O(1)
class TicTacToe_EfficientAndElegant
{
	/** Initialize your data structure here. */
  public:
	TicTacToe(int n)
	{
		rows = new int[n];
		cols = new int[n];
	}

	/** Player {player} makes a move at ({row}, {col}).
    @param row The row of the board.
    @param col The column of the board.
    @param player The player, can be either 1 or 2.
    @return The current winning condition, can be either:
            0: No one wins.
            1: Player 1 wins.
            2: Player 2 wins. */
	int move(int row, int col, int player)
	{
		int toAdd = player == 1 ? 1 : -1;

		rows[row] += toAdd;
		cols[col] += toAdd;
		if (row == col)
		{
			diagonal += toAdd;
		}

		if (col == (cols.length - row - 1))
		{
			antiDiagonal += toAdd;
		}

		int size = rows.length;
		if (Math.abs(rows[row]) == size ||
			Math.abs(cols[col]) == size ||
			Math.abs(diagonal) == size ||
			Math.abs(antiDiagonal) == size)
		{
			return player;
		}

		return 0;
	}


  private:
	int[] rows;
	int[] cols;
	int diagonal;
	int antiDiagonal;
}

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe obj = new TicTacToe(n);
 * int param_1 = obj.move(row,col,player);
 */

int
main()
{
	TicTacToe game = TicTacToe(3);
	cout << game.move(0, 0, 1) << endl;
	cout << game.move(0, 2, 2) << endl;
	cout << game.move(2, 2, 1) << endl;
	cout << game.move(1, 1, 2) << endl;
	cout << game.move(2, 0, 1) << endl;
	cout << game.move(1, 0, 2) << endl;
	// game.printBoard();
	cout << game.move(2, 1, 1) << endl;
	// game.printBoard();

	game = TicTacToe(2);
	cout << game.move(0, 0, 2) << endl;
	cout << game.move(1, 1, 1) << endl;
	// game.printBoard();
	cout << game.move(0, 1, 2) << endl;
	// game.printBoard();

	game = TicTacToe(3);
	cout << game.move(1, 0, 1) << endl;
	cout << game.move(1, 1, 1) << endl;
	cout << game.move(1, 2, 1) << endl;
	// game.printBoard();

	game = TicTacToe(3);
	cout << game.move(0, 0, 2) << endl;
	cout << game.move(2, 0, 2) << endl;
	cout << game.move(1, 0, 2) << endl;
	game.printBoard();

	return 0;
}