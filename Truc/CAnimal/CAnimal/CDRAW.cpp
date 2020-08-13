#include "CDRAW.h"

CDRAW buffer;

void CDRAW::square(int line, int colum, char k, int color )
{
	table[line][colum].character = k;
	table[line][colum].color = color;
}