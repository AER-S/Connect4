#include "GameEngine.h"
#include <windows.h>

void GameEngine::SetColor(int _texCol, int _backCol)
{
	if ((_texCol % 16) == (_backCol % 16))_texCol++;
	_texCol %= 16; _backCol %= 16;
	unsigned short wAttributes = ((unsigned)_backCol << 4) | (unsigned)_texCol;
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, wAttributes);
}
