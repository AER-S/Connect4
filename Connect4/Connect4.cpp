#include "GameEngine.h"
#include <iostream>
int main()
{
	GameEngine::Welcome();
	std::cout << std::endl;
	GameEngine::Rules();
	std::cout << std::endl;
	GameEngine::HowToPlay();
	std::cout << std::endl;

	Game* newGame=nullptr;

	GameEngine::PlayGame(newGame);
}