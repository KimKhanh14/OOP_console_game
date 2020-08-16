#ifndef _CANIMAL_H
#define _CANIMAL_H_

#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <thread>
#include "Console.h"
#include "CDRAW.h"
using namespace std;

#define HEIGHT 30
#define WIDTH 80
#define lengthB 6
#define lengthD 8

class CANIMAL
{
private: int mX, mY;
public: 
	CANIMAL(): mX(1), mY(0) {}
	CANIMAL(int x, int y) : mX(x), mY(y) {}
	virtual void Move(int color) = 0;
	virtual void Tell() = 0;	void Update(int x, int y);
	void goRight() { mX++; }
	int getX() { return mX; }
	int getY() { return mY; }
};

class CBIRD : public CANIMAL
{
public: 
	CBIRD() : CANIMAL(1,11) {};
	CBIRD(int x, int y) : CANIMAL(x,y) {}
	void Move(int color);
	void Tell();
};

class CDINOSAUR : public CANIMAL
{
public:
	CDINOSAUR() : CDINOSAUR(1,21) {};
	CDINOSAUR(int x, int y) : CANIMAL(x, y) {}
	void Move(int color);
	void Tell();
};

#endif