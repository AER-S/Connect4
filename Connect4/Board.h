#pragma once
class Board
{
	char** board;
	int rows;
	int cols;
	int* spaces;
	int connect;

	bool CheckHorizontal(char _color, int _row);
	bool CheckVertical(char _color, int _column);
	bool CheckDiagonalLeft(char _color, int _row, int _column);
	bool CheckDiagonalRight(char _color, int _row, int _column);

public:
	Board(int _connect,int _rows =6, int _cols=7);
	bool CheckSpaceInColumn(int _column);
	bool Put(char _color, int _column);
	void Print();
	bool CheckForWin(int _row, int _column);
	bool IsFull();
	~Board();
};

