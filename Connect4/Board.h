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
	void SetColor(int _texCol, int _backCol);

public:
	Board(int _connect,int _rows , int _cols);
	bool CheckSpaceInColumn(int _column);
	int Put(char _color, int _column);
	void Print();
	bool CheckForWin(char _color, int _row, int _column);
	bool IsFull();
	int GetColumns();
	int GetRows();
	~Board();
};

