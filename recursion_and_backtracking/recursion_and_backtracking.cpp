/**
 *
 * \file recursion_and_backtracking.cpp
 *
 * \brief Solution to https://www.hackerearth.com/practice/basic-programming/recursion/recursion-and-backtracking/tutorial/
 *
 * \author Mardava Gubbi <mrdv.rjgpl@gmail.com>
 *
 */
#include <iostream>

using namespace std;

/**
 *
 * \brief Attempt the placement of a queen on the given board at (row_index, col_index).
 *
 * \details Set all squares attacked by the new queen to 2 in the input_board array.
 *
 * \param[in] board_size The size of the board
 * \param[in] input_board The input board before the placement of the queen
 * \param[in] row_index The row index to place the new queen
 * \param[in] col_index The col index to place the new queen
 *
 * \author Mardava Gubbi <mrdv.rjgpl@gmail.com>
 *
 */
void AttemptQueenPlacement(int board_size, int **input_board, int row_index, int col_index)
{
	int i;
	/* Place a queen on this spot. */
	/* Update the row and column attacked by the new queen. */
	for(i = 0; i < board_size; ++i)
	{
		input_board[row_index][i] = 2;
		input_board[i][col_index] = 2;
	}

	/* Update the diagonal elements above the queen. */
	for(i = 1; i <= row_index; ++i)
	{
		if(i <= col_index)
		{
			input_board[row_index - i][col_index - i] = 2;
		}

		if(col_index + i < board_size)
		{
			input_board[row_index - i][col_index + i] = 2;
		}
	}

	/* Update the diagonal elements below the queen. */
	for(i = 1; row_index + i < board_size; ++i)
	{
		if(i <= col_index)
		{
			input_board[row_index + i][col_index - i] = 2;
		}

		if(col_index + i < board_size)
		{
			input_board[row_index + i][col_index + i] = 2;
		}
	}

	input_board[row_index][col_index] = 1;
}

/**
 *
 * \brief Copy the placement of queens from the input to the output board.
 *
 * \details This function is used to reset an attempt placement of a queen.
 *
 * \param[in] board_size The size of the board
 * \param[in] input_board The input board before the placement of the queen
 * \param[out] output_board The board to be reset to the input_board's configuration
 *
 * \author Mardava Gubbi <mrdv.rjgpl@gmail.com>
 *
 */
void CopyQueenPlacement(int board_size, int **input_board,
		int **output_board)
{
	int i;
	int j;

	for(i = 0; i < board_size; ++i)
	{
		for(j = 0; j < board_size; ++j)
		{
			output_board[i][j] = input_board[i][j];
		}
	}
}

/**
 *
 * \brief Determine whether or not the required number of queens can be placed on the given board.
 *
 * \details The queens are placed one by one, and removed if it is found that a new queen cannot be placed. Queens can
 * only be placed in positions out of the line of attack of other queens. This function is recursive, and will exit if
 * the queens cannot be placed, or a placement is found for all queens.
 *
 * \param[in] board_size The size of the board, and the initial number of queens to be placed
 * \param[in] input_board The input board before the placement of the newest queen
 * \param[in] num_queens The number of queens to be placed in the current call to the function
 *
 * \return true if the queens can be placed
 * \return false if the queens cannot be placed
 *
 * \author Mardava Gubbi <mrdv.rjgpl@gmail.com>
 *
 */
bool PlaceQueens(int board_size, int **input_board, int num_queens)
{
	bool queens_placed = false;
	int i;
	int j;
	int *output_board[board_size];

	for(i = 0; i < board_size; ++i)
	{
		output_board[i] = new int[board_size];
	}

	if(num_queens > 0)
	{
		CopyQueenPlacement(board_size, input_board, output_board);

		for(i = 0; i < board_size; ++i)
		{
			for(j = 0; j < board_size; ++j)
			{
				if(output_board[i][j] == 0)
				{
					/* If the current position is empty, then attempt the placement of a queen. */
					AttemptQueenPlacement(board_size, output_board, i, j);
					/* Attempt the placement of the remaining queens with this new configuration. */
					queens_placed = PlaceQueens(board_size, output_board, num_queens - 1);

					if(queens_placed == true)
					{
						/* Copy the queen positions to the output. */
						CopyQueenPlacement(board_size, output_board, input_board);

						break;
					}
					else
					{
						/* Reset the board to the input configuration, and look for a new empty position. */
						CopyQueenPlacement(board_size, input_board, output_board);
					}
				}
			}

			if(queens_placed == true)
			{
				break;
			}
		}
	}
	else
	{
		/* All queens have been placed by the calling functions. */
		queens_placed = true;
	}

	return queens_placed;
}

/**
 *
 * \brief Print to output the placement of the queens.
 *
 * \details Positions occupied by queens are marked with the number 1. Positions under attack from one or more queens
 * are marked with the number 2. Positions free from all queens and their attacks are marked with the number zero. While
 * printing, we are only concerned with the placement of the queens, and not with the positions they attack. Hence, all
 * positions devoid of queenly presence are printed as "0".
 *
 * \param[in] board_size The size of the board
 * \param[in] input_board The input board after the attempt to place all queens is complete
 *
 * \author Mardava Gubbi <mrdv.rjgpl@gmail.com>
 *
 */
void PrintBoard(int board_size, int **input_board)
{
	int i;
	int j;

	for(i = 0; i < board_size; ++i)
	{
		for(j = 0; j < board_size; ++j)
		{
			cout << input_board[i][j] % 2 << " ";
		}

		cout << endl;
	}
}

int main(int argc, char **argv)
{
	int b;
	int i;
	int j;

	cin >> b;

	int *board[b];

	for(i = 0; i < b; ++i)
	{
		board[i] = new int[b];

		for(j = 0; j < b; ++j)
		{
			board[i][j] = 0;
		}
	}

	if(PlaceQueens(b, board, b))
	{
		cout << "YES" << endl;
		PrintBoard(b, board);
	}
	else
	{
		cout << "NO" << endl;
	}

	return 0;
}

