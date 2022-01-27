#include "Board.h"

int main()
{
	Board newBorard(4);
	newBorard.Print();
	newBorard.Put('B', 3);
	newBorard.Print();
	newBorard.Put('R', 3);
	newBorard.Print();
}