#include "Util.h"
#include <Windows.h>

Util::Util()
{
}

void Util::GotoXY(int X, int Y)
{
	COORD Cur;
	Cur.X = X;
	Cur.Y = Y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);

}
