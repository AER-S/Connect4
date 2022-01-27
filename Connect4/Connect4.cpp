#include "Game.h"
#include <iostream>
int main()
{
	Game newGame(4);
	while (!newGame.GameOver())
	{
		newGame.UpdatePlayer();
		std::cout << newGame.GetPlayer() << " Player Turn:\n";
		newGame.AddBall();
		newGame.board->Print();
	}
	if (newGame.Won()) newGame.PrintWinner();
	else std::cout << "The game is draw.\n";
}