class GameEndException 
{
public:
	char *what()
	{
		return "Game has been ended, cannot make any more moves";
	}
}gameEndException;

class AlreadyTakenException
{
public:
	char* what()
	{
		return "This place has been taken";
	}
}alreadyTakenException;

class TicTacToe
{
private:

	char board[3][3];
	char currentPlayerMark;
	bool gameEnd;

public:

	TicTacToe()
	{
		initialize();
	}

	char getCurrentPlayer()
	{
		return currentPlayerMark;
	}

	void initialize()
	{
		gameEnd = false;
		currentPlayerMark = 'x';

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				board[i][j] = '-';
			}
		}
	}

	bool isBoardFull()
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (board[i][j] == '-')
				{
					return false;
				}
			}
		}
		gameEnd = true;
		return true;
	}

	void changePlayer()
	{
		if (currentPlayerMark == 'x')
		{
			currentPlayerMark = 'o';
		}
		else
		{
			currentPlayerMark = 'x';
		}
	}

	bool move(int row, int col)
	{
		if (gameEnd)
		{
			throw gameEndException;
		}
		if (board[row][col] != '-')
		{
			throw alreadyTakenException;
		}
		board[row][col] = currentPlayerMark;
		bool win;
		//check row
		win = true;
		for (int i = 0; i < 3; i++)
		{
			if (board[row][i] != currentPlayerMark)
			{
				win = false;
				break;
			}
		}
		if (win)
		{
			gameEnd = true;
			return win;
		}
		//check column
		win = true;
		for (int i = 0; i < 3; i++)
		{
			if (board[i][col] != currentPlayerMark)
			{
				win = false;
				break;
			}
		}
		if (win)
		{
			gameEnd = true;
			return win;
		}
		//check back diagonal
		win = true;
		for(int i = 0; i < 3; i++)
		{
			if (board[i][i] != currentPlayerMark)
			{
				win = false;
				break;
			}
		}
		if (win)
		{
			gameEnd = true;
			return win;
		}
		//check forward diagonal
		win = true;
		for (int i = 0; i < 3; i++)
		{
			if (board[i][3 - i - 1] != currentPlayerMark)
			{
				win = false;
				break;
			}
		}
		if (win)
		{
			gameEnd = true;
            return win;
		}
		changePlayer();
		return win;
	}

};
