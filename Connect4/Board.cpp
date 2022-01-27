#include "Board.h"
#include <iostream>
#include <windows.h>

#define START_COUNTER int counter = 0
#define INCREMENT_COUNTER counter++
#define RESET_COUNTER counter = 0
#define COUNT_REACHED counter >= connect
#define SUBSCRIBE_ROW int i = _row;
#define SUBSCRIBE_COLUMN int j = _column;

bool Board::CheckHorizontal(char _color, int _row)
{
	START_COUNTER;
	for (int i=0; i<cols; i++)
	{
		if (board[_row][i] == _color)
		{
			INCREMENT_COUNTER;
			if (COUNT_REACHED) return true;
		}
		else
		{
			RESET_COUNTER;
		}
	}
	return false;
}

bool Board::CheckVertical(char _color, int _column)
{
	START_COUNTER;
	for (int i = 0; i < rows; i++)
	{
		if (board[i][_column] == _color)
		{
			INCREMENT_COUNTER;
			if (COUNT_REACHED) return true;
		}
		else
		{
			RESET_COUNTER;
		}
	}
	return false;
}

bool Board::CheckDiagonalLeft(char _color, int _row, int _column)
{
	SUBSCRIBE_ROW;
	SUBSCRIBE_COLUMN;
	while (i > 0 && j > 0)
	{
		i--;
		j--;
	}
	START_COUNTER;
	for (int k = 0; i + k < rows && j + k < cols; k++)
	{
		if (board[i + k][j + k] == _color)
		{
			INCREMENT_COUNTER;
			if (COUNT_REACHED) return true;
		}
		else
		{
			RESET_COUNTER;
		}
	}
	return false;
}

bool Board::CheckDiagonalRight(char _color, int _row, int _column)
{
	SUBSCRIBE_ROW;
	SUBSCRIBE_COLUMN;
	while (i > 0 && j < cols - 1)
	{
		i--;
		j++;
	}
	START_COUNTER;
	for (int k=0; i+k<rows && j-k>=0; k++)
	{
		if (board[i + k][j - k] == _color)
		{
			INCREMENT_COUNTER;
			if (COUNT_REACHED) return true;
		}
		else
		{
			RESET_COUNTER;
		}
	}
	return false;
}

void Board::SetColor(int _texCol, int _backCol)
{
	if ((_texCol % 16) == (_backCol % 16))_texCol++;
	_texCol %= 16; _backCol %= 16;
	unsigned short wAttributes = ((unsigned)_backCol << 4) | (unsigned)_texCol;
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	//CONSOLE_SCREEN_BUFFER_INFO csbi;
	SetConsoleTextAttribute(hStdOut, wAttributes);
}

Board::Board(int _connect, int _rows, int _cols)
{
	connect = _connect;
	rows = _rows;
	cols = _cols;
	spaces = new int[cols] {};
	board = new char* [rows];
	for (int i=0; i<rows; i++)
	{
		board[i] = new char[cols] {};		
	}
}

bool Board::CheckSpaceInColumn(int _column)
{
	return (spaces[_column] < rows);
}

int Board::Put(char _color, int _column)
{
	
	for (int i = rows - 1; i >= 0; i--)
	{
		if (board[i][_column] == NULL)
		{
			board[i][_column] = _color;
			spaces[_column]++;
			return i;
		}
	}
	return -1;
}

void Board::Print()
{
	std::cout << "***** The Board *****\n";
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			SetColor(7, 0);
			std::cout << "| ";
			int color = (board[i][j] == 'B') ? 3 : 12;
			SetColor(color,0);
			std::cout << ((board[i][j] != NULL) ? board[i][j] : ' ') << " ";
		}
		SetColor(7, 0);
		std::cout << "|\n";
	}
	std::cout << "***** ***** ***** *****\n";
}

bool Board::CheckForWin(char _color, int _row, int _column)
{
	if (!CheckVertical(_color, _column) && !CheckHorizontal(_color, _row) && !CheckDiagonalLeft(_color, _row, _column) && !CheckDiagonalRight(_color, _row, _column)) return false;
	return true;
}

bool Board::IsFull()
{
	for (int i = 0; i < cols; i++)
	{
		if (CheckSpaceInColumn(i)) return false;
	}
	return true;
}

int Board::GetColumns()
{
	return cols;
}

int Board::GetRows()
{
	return rows;
}

Board::~Board()
{
	for (int i = 0; i < rows; i++)
	{
		delete[] board[i];
	}
	delete[]board;
	board = nullptr;
}
