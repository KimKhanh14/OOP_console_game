#include "CAnimal.h"

void CANIMAL::Update(int x, int y)
{
	mX = x;
	mY = y;
}

void CBIRD::Move( int color)
{
	int x = getX();
	int y = getY();
	buffer.square(y,x+3, '_', color);
	buffer.square(y,x+4, '_', color);
	buffer.square(y+1, x, '_', color);
	buffer.square(y + 1, x+1, '_', color);
	buffer.square(y + 1,x+2, '/', color);
	buffer.square(y + 1,x+3, '*', color);
	buffer.square(y + 1,x+4, ' ', color);
	buffer.square(y + 1,x+5, '>', color);
	buffer.square(y + 2, x-1, '/', color);
	buffer.square(y + 2, x,'_', color);
	buffer.square(y + 2, x+1,' ', color);
	buffer.square(y + 2, x+2,'_', color);
	buffer.square(y + 2, x+3,' ', color);
	buffer.square(y + 2, x+4,'/', color);
	buffer.square(y + 3, x,  'J', color);
	buffer.square(y + 3, x+1,' ', color);
	buffer.square(y + 3, x+2,'J', color);
}

void CBIRD::Tell()
{
	/*PlaySound(TEXT("Bird.wav"), NULL, SND_ASYNC);
	Sleep(3000);*/
}

void CDINOSAUR::Move (int color)
{
	int x = getX();
	int y = getY();
	buffer.square(y, x + 5, '_', color);
	buffer.square(y, x + 6, '_', color);

	buffer.square(y + 1, x + 4, '/', color);
	buffer.square(y + 1, x + 5, '*', color);
	buffer.square(y + 1, x + 6, '_', color);
	buffer.square(y + 1, x + 7, ']', color);

	buffer.square(y + 2, x , '_', color);
	buffer.square(y + 2, x+1, '_', color);
	buffer.square(y + 2, x+3, '/', color);
	buffer.square(y + 2, x+4, ' ', color);
	buffer.square(y + 2, x+5, '/', color);

	buffer.square(y + 3, x, 'l', color);
	buffer.square(y + 3, x+1, '_', color);
	buffer.square(y + 3, x+2, ' ', color);
	buffer.square(y + 3, x+3, '_', color);
	buffer.square(y + 3, x+4, '/', color);

	buffer.square(y + 4, x + 1, '/', color);
	buffer.square(y + 4, x + 2, ' ', color);
	buffer.square(y + 4, x + 3, '/', color);
}


void CDINOSAUR::Tell()
{
	PlaySound(TEXT("Dinosaur.wav"), NULL, SND_ASYNC);
	Sleep(3000);
}
