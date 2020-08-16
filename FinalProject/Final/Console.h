#ifndef _CONSOLE_H
#define _CONSOLE_H
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <vector>
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

//Ke duong thang
//Mode 1: ke ngang, 2: ke doc
void Line(int x, int y, int length, int mode);

#endif