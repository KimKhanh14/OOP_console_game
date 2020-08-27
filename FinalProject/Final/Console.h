#ifndef _CONSOLE_H
#define _CONSOLE_H
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#define ColorCode_Black			0
#define ColorCode_DarkBlue		1
#define ColorCode_DarkGreen		2
#define ColorCode_DarkCyan		3
#define ColorCode_DarkRed		4
#define ColorCode_DarkPink		5
#define ColorCode_DarkYellow	6
#define ColorCode_DarkWhite		7
#define ColorCode_Grey			8
#define ColorCode_Blue			9
#define ColorCode_Green			10
#define ColorCode_Cyan			11
#define ColorCode_Red			12
#define ColorCode_Pink			13
#define ColorCode_Yellow		14
#define ColorCode_White			15
using namespace std;


//screen: goto [x,y]
void GotoXY(int column, int line);

void FixConsoleWindow();

void clrscr();

//Doi mau nen/chu
void TextColor(int color);

//An/hien thanh cuon
void ShowScrollbar(bool Show);

//An/hien con tro chuot
void ShowCur(bool CursorVisibility);

//Vo hieu hoa boi den
void DisableSelection();

//Set color
void SetColor(int backgound_color, int text_color);

#endif