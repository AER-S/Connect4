#pragma once
#include "Game.h"

class GameEngine
{
public:
	static void Welcome();
	static void Rules();
	static void HowToPlay();
	static void AskForReplay(bool& _play);
	static void SetColor(int _texCol, int _backCol);
	static void PlayGame(Game* _game);
};

