#pragma once
#include "Board.h"

enum Player
{
	Blue,
	Red
};

class Game
{
public:
	Board* board;
	int player;
	bool won;

	
public:
	Game(int _connect, int _rows = 6, int _cols = 7);
	void GameStart();
	int AskForColumn();
	void AddBall();
	bool GameOver();
	void UpdatePlayer();
	char Character(int _player);
	void PrintWinner();
	void PrintDraw();
	const char* GetPlayer();
	bool Won();
	void PlayerTurn();
	void ShowBoard();
	~Game();
};

