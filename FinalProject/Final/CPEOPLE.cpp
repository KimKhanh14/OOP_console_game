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
	if (mY >= 6) mY -= 5;
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
	return (!State);
}
bool CPEOPLE::isFinish()
{
	if (mY == 1) isFinished = true;
	return isFinished;
}

void CPEOPLE::Reset()
{
	mX = WIDTH / 2;
	mY = 26;
	State = true;
	isFinished = false;
}

void CPEOPLE::isImpact(vector<CBIRD>& b)
{
	for (int i = 0; i < b.size(); i++)
	{
		if (mX + 3 < b[i].getX() || mX > b[i].getX() + b[i].getLength() - 1 ||
			mY + 3 < b[i].getY() || mY > b[i].getY() + heightO)
			State = true;
		else
		{
			State = false;
			b[i].Tell();
			return;
		}
	}
}

void CPEOPLE::isImpact(vector<CDINOSAUR>& b)
{
	for (int i = 0; i < b.size(); i++)
	{
		if (mX + 3 < b[i].getX() || mX > b[i].getX() + b[i].getLength() - 1 ||
			mY + 3 < b[i].getY() || mY > b[i].getY() + heightO)
			State = true;
		else
		{
			State = false;
			b[i].Tell();
			return;
		}
	}
}

void CPEOPLE::isImpact(vector<CTRUCK>& b)
{
	for (int i = 0; i < b.size(); i++)
	{
		if (mX + 3 < b[i].getX() || mX > b[i].getX() + b[i].getLength() - 1 ||
			mY + 3 < b[i].getY() || mY > b[i].getY() + heightO)
			State = true;
		else
		{
			State = false;
			b[i].Tell();
			return;
		}
	}
}

void CPEOPLE::isImpact(vector<CCAR>& b)
{
	for (int i = 0; i < b.size(); i++)
	{
		if (mX + 3 < b[i].getX() || mX > b[i].getX() + b[i].getLength() - 1 ||
			mY + 3 < b[i].getY() || mY > b[i].getY() + heightO)
			State = true;
		else
		{
			State = false;
			b[i].Tell();
			return;
		}
	}
}