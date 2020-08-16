#ifndef CVEHICLE_H
#define CVEHICLE_H

#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <thread>
#include "Console.h"
#include "CDRAW.h"
using namespace std;

#define lengthT 12
#define lengthC 9

//struct Point {
//	int x, y;
//};
//
//struct Shape {
//	char a[4][12];
//};
//class CTRAFFICLIGHT {
//private:
//	bool red = true;
//public:
//	CTRAFFICLIGHT() :red(true) {};
//	bool isRed() { return red; }
//	void changeColor() { red = !red; }
//	void print(int x, int y) {
//		GotoXY(x, y);
//		if (red) SetColor(4, 4);
//		else SetColor(23, 24);
//		cout << "OO" << endl;
//		GotoXY(x, y + 1);
//		if (red) SetColor(23, 24);
//		else SetColor(10, 10);
//		cout << "OO" << endl;
//		SetColor(31, 31);
//	}
//};
//
//
//class CVEHICLE {
//protected:
//	Point p;
//	Shape s;
//public:
//	CVEHICLE() { p.x = 1; p.y = 20; };
//	CVEHICLE(int x, int y) { p.x = x; p.y = y; };
//	virtual void Move(CTRAFFICLIGHT) = 0;
//	virtual bool Appear(int, int) = 0;
//};
//
//class CTRUCK :public CVEHICLE {
//public:
//	CTRUCK() {
//		//draw
//		for (int i = 0; i < 4; i++) {
//			for (int j = 0; j < 12; j++)
//				s.a[i][j] = ' ';
//			cout << endl;
//		}
//		for (int i = 1; i <= 7; i++) s.a[0][i] = '_';
//		for (int i = 1; i <= 11; i++) s.a[2][i] = '_';
//		s.a[1][9] = s.a[1][10] = '_';
//		s.a[1][0] = s.a[2][0] = s.a[2][11] = '|';
//		s.a[3][1] = s.a[3][8] = 'O';
//		s.a[1][8] = '\\';
//	};
//	CTRUCK(int x, int y) : CVEHICLE(x, y) {
//		//draw
//		for (int i = 0; i < 4; i++) {
//			for (int j = 0; j < 12; j++)
//				s.a[i][j] = ' ';
//			cout << endl;
//		}
//		for (int i = 1; i <= 7; i++) s.a[0][i] = '_';
//		for (int i = 1; i <= 11; i++) s.a[2][i] = '_';
//		s.a[1][9] = s.a[1][10] = '_';
//		s.a[1][0] = s.a[2][0] = s.a[2][11] = '|';
//		s.a[3][1] = s.a[3][8] = 'O';
//		s.a[1][8] = '\\';
//	}
//	bool Appear(int x, int y) {
//			p.x = x;
//			p.y = y;
//		if (x < WIDTH && x >= 0) {
//			
//			for (int iRow = 0; iRow < 4; iRow++) {
//				for (int iCol = 0; iCol < 12; iCol++) {
//					GotoXY(x + iCol, y + iRow);
//					cout << s.a[iRow][iCol];
//				}
//				cout << endl;
//			}
//			return true;
//		}
//		return false;
//	};
//	void Move(CTRAFFICLIGHT light) {
//		//while(true){
//		//	for (int i = 0; i < WIDTH; i++) {
//		//		if (!light.isRed()) {
//		//			if (!Appear(++p.x, p.y))
//		//				break;
//		//			Sleep(50);
//		//			clrscr();
//		//		}
//		//		else {
//		//			Appear(p.x, p.y);
//		//			Sleep(50);
//		//		}
//		//	}
//		//	//quay lai ban dau
//		//	p.x = 0;
//		while (true) {
//			for (int i = 0; i < WIDTH; i++) {
//				if (!light.isRed()) {
//					if (!Appear(++p.x, p.y))
//						break;
//					Sleep(50);
//					clrscr();
//					if (i % 20 == 0)light.changeColor();
//				}
//				else {
//					Appear(p.x, p.y);
//					Sleep(2000);
//					light.changeColor();
//				}
//			}
//			//quay lai ban dau
//			if (p.x >= WIDTH) p.x = 0;
//		}
//	}
//};
//
//class CCAR : public CVEHICLE {
//public:
//	CCAR() {};
//	CCAR(int x, int y) : CVEHICLE(x, y) {}
//	void Move(CTRAFFICLIGHT);
////	void StopMove();
//};

class CTRAFFICLIGHT {
private:
	bool red = true;
public:
	CTRAFFICLIGHT() :red(true) {};
	bool isRed() { return red; }
	void changeColor() { red = !red; }
	void print(int x, int y) {
		GotoXY(x, y);
		if (red) SetColor(4, 4);
		else SetColor(23, 24);
		cout << "OO" << endl;
		GotoXY(x, y + 1);
		if (red) SetColor(23, 24);
		else SetColor(10, 10);
		cout << "OO" << endl;
		SetColor(31, 31);
	}
};

class CVEHICLE
{
private:
	int mX, mY;
public:
	CVEHICLE() : mX(1), mY(0) {}
	CVEHICLE(int x, int y) : mX(x), mY(y) {}
	virtual void Move(int color) = 0;
	void Update(int x, int y);
	void goRight(CTRAFFICLIGHT& light) {
		if (!light.isRed()) mX++;
	}
	int getX() { return mX; }
	int getY() { return mY; }
};

class CTRUCK : public CVEHICLE
{
public:
	CTRUCK() : CVEHICLE(1, 6) {}
	CTRUCK(int x, int y) : CVEHICLE(x, y) {}
	void Move(int color);
};

class CCAR : public CVEHICLE
{
public:
	CCAR() : CVEHICLE(1, 16) {};
	CCAR(int x, int y) : CVEHICLE(x, y) {}
	void Move(int color);
};


#endif // !CVEHICLE_H
