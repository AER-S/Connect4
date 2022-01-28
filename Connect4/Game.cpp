
#include "GameEngine.h"
#include <iostream>
#include <string>



Game::Game(int _connect, int _rows /*= 6*/, int _cols /*= 7*/)
{
	board = new Board(_connect, _rows, _cols);
	player = 0;
	won = false;
}

void Game::GameStart()
{
	std::cout << std::endl << std::endl;
	std::cout << "   ------------------------------\n";
	
	std::cout << "   |\t      GAME STARTS\t|\n";
	
	std::cout << "   ------------------------------\n";
}

int Game::AskForColumn()
{
	int input=0;
	std::string sInput="0";
	do 
	{
		std::cout << "Enter a column :";
		std::getline(std::cin, sInput);
		sInput = "0" + sInput;
		input = std::stoi(sInput,nullptr,0);
		
		if (input > board->GetColumns() || input <= 0) std::cout << "Invalid Input! Retry!\n";
	} while (input> board->GetColumns() || input<=0);
	return input;
}

void Game::AddBall()
{
	int col;
	do 
	{
		col = AskForColumn()-1;
		if (!board->CheckSpaceInColumn(col)) std::cout << "Column " << col << " is full! Try another!\n";
	} while (!board->CheckSpaceInColumn(col));
	char color = Character(player);
	int row = board->Put(color, col);
	if (board->CheckForWin(color, row, col)) won = true;
}

bool Game::GameOver()
{
	return (won || board->IsFull());
}

void Game::UpdatePlayer()
{
	player++;
	player = player % 2;
}

char Game::Character(int _player)
{
	switch (_player)
	{
	case 0: return 'B';
	default: return 'R';
	}
}

void Game::PrintWinner()
{
	int color = (player == 0) ? 3 : 12;
	GameEngine::SetColor(color, 0);
	std::cout << "   ------------------------------\n";
	std::cout << "   |                            |\n";
	std::cout << "   |\t      GAME OVER\t\t|\n";
	std::cout << "   |\tThe " << GetPlayer() << " Player Wins!!\t|\n" ;
	std::cout << "   |                            |\n";
	std::cout << "   ------------------------------\n";
	GameEngine::SetColor(7, 0);
}

void Game::PrintDraw()
{
	std::cout << "   ------------------------------\n";
	std::cout << "   |                            |\n";
	std::cout << "   |\t      GAME OVER\t\t|\n";
	std::cout << "   |\tThe game is a draw!!\t|\n";
	std::cout << "   |                            |\n";
	std::cout << "   ------------------------------\n";
}

const char* Game::GetPlayer()
{
	switch (player)
	{
	case 0: return "Blue";
	default: return "Red";
	}
}

bool Game::Won()
{
	return won;
}

void Game::PlayerTurn()
{
	int color = (player == 0) ? 3 : 12;
	GameEngine::SetColor(color, 0);
	std::cout << GetPlayer();
	GameEngine::SetColor(7, 0);
	std::cout << " Player Turn:\n";
}

void Game::ShowBoard()
{
	board->Print();
}

Game::~Game()
{
	delete board;
}
