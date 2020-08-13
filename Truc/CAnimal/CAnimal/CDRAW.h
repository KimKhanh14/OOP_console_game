#ifndef _CDRAW_H
#define _CDRAW_H
#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <conio.h>

#define HEIGHT 30
#define WIDTH 80

class Square
{
public:
	char character;
	int color;
};
class CDRAW
{
public:
	Square table[HEIGHT][WIDTH];
	void square(int line, int colum, char k, int color = 7);
};

extern CDRAW buffer;

#endif // !_CDRAW_H
