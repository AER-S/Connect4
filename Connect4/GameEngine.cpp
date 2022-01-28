#include "GameEngine.h"
#include "Game.h"
#include <iostream>
#include <ios>
#include <limits>
#include <windows.h>

void GameEngine::Welcome()
{
	std::cout << "   ------------------------------\n";
	std::cout << "   |                            |\n";
	std::cout << "   |\tWELCOME TO CONNECT 4\t|\n";
	std::cout << "   |                            |\n";
	std::cout << "   ------------------------------\n";
}

void GameEngine::Rules()
{
	std::cout << "RULES:\n";
	std::cout << "1. Two-Player (red(R) & blue(B)) game.\n";
	std::cout << "2. Board size is 6 rows & 7 columns.\n";
	std::cout << "3. A player win if he/she is able to connect 4 dots horizontally, vertically or diagonally.\n";
	std::cout << "4. Draw when the board is fully filled.\n";
}

void GameEngine::HowToPlay()
{
	std::cout << "HOW TO PLAY:\n";
	std::cout << "1. Game is always starts with player - 1 i.e. Red(R).\n";
	std::cout << "2. In each step choose the column number in which you want to drop the ball.\n";
	std::cout << "3. Rows will be filled from bottom to top in any column.\n";
}

void GameEngine::AskForReplay(bool& _play)
{
	char input[80];
	do 
	{
		std::cout << "Do you want to play again? (Y/N): ";
		std::cin.getline(input, 80);
		std::cin.ignore(std::numeric_limits<std::streamsize>::infinity(), '\n');
		if (input[0] != 'y' && input[0] != 'Y' && input[0] != 'N' && input[0] != 'n') std::cout << "Invalid Answer! Please answer with 'Y' or 'N'!\n";
	} while (input[0] != 'y' && input[0] != 'Y' && input[0] != 'N' && input[0] != 'n');
	switch (input[0])
	{
	case 'y':
	case 'Y':
		_play = true;
		break;
	case 'N':
	case 'n':
		_play = false;
		break;
	default:
		break;
	}
}

void GameEngine::SetColor(int _texCol, int _backCol)
{
	if ((_texCol % 16) == (_backCol % 16))_texCol++;
	_texCol %= 16; _backCol %= 16;
	unsigned short wAttributes = ((unsigned)_backCol << 4) | (unsigned)_texCol;
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, wAttributes);
}

void GameEngine::PlayGame(Game* _game)
{
	bool play = true;
	do
	{
		_game = new Game(4);
		_game->GameStart();
		while (!_game->GameOver())
		{
			_game->UpdatePlayer();
			_game->PlayerTurn();
			_game->AddBall();
			_game->ShowBoard();
		}
		if (_game->Won()) _game->PrintWinner();
		else _game->PrintDraw();
		delete _game;
		_game = nullptr;
		GameEngine::AskForReplay(play);
	} while (play);
}
