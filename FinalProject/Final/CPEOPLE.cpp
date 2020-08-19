#include "CPEOPLE.h"

CPEOPLE::CPEOPLE() : mX(WIDTH / 2), mY(26), State(true), isFinished(false)
{}
void CPEOPLE::Draw(int color)
{
	buffer.square(mY, mX, ' ', color);
	buffer.square(mY, mX+1,'O', color);

	buffer.square(mY+1, mX, '/', color);
	buffer.square(mY+1, mX+1, '|', color);
	buffer.square(mY+1, mX+2,(char)92, color);

	buffer.square(mY+2, mX, '/', color);
	buffer.square(mY+2, mX+1, ' ', color);
	buffer.square(mY+2, mX+2,(char)92, color);
}
void CPEOPLE::Up()
{
	mY -= 5;
	if (1 <= mY && mY <= 5) isFinished = true;
}
void CPEOPLE::Down()
{
	if (26 <= mY && mY <= HEIGHT) return;
	mY += 5;
}
void CPEOPLE::Left()
{
	if (mX > 0) mX--;
}
void CPEOPLE::Right()
{
	if (mX < WIDTH - widthP - 1) mX++;
}
bool CPEOPLE::isDead()
{
	return State;
}
bool CPEOPLE::isFinish()
{
	return isFinished;
}

//bool CPEOPLE::isImpact(vector<CANIMAL>& a)
//{
//	//for (int i = 0; i < a.size(); i++)
//
//}
//bool CPEOPLE::isImpact(vector<CVEHICLE>& v)
//{}

