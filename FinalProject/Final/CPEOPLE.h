#ifndef _CPEOPLE_H
#define _CPEOPLE_H

#include "CDRAW.h"
#include "Console.h"
#include "CAnimal.h"
#include "CVEHICLE.h"
#include <vector>
#include <thread>
#define lengthP 3
#define widthP 3
#define heightO 4

class CPEOPLE
{
private: 
	int mX, mY;
	bool State; //song = true, chet = false
	bool isFinished; //ve dich = true
public: 
	CPEOPLE();
	void Draw(int color);
	void Up();
	void Down();
	void Left();
	void Right();
	bool isDead();
	bool isFinish();
	void Reset();
	int getY() { return mY; }
	int getX() { return mX; }
	void isImpact(vector<CBIRD>& b);
	void isImpact(vector<CDINOSAUR>& b);
	void isImpact(vector<CTRUCK>& b);
	void isImpact(vector<CCAR>& b);
};
#endif