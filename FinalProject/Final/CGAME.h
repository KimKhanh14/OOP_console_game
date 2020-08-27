#ifndef _CGAME_H
#define _CGAME_H

//#include <iostream>
#include <fstream>
//#include <Windows.h>
#include <vector>
#include <thread>
//#include "CVEHICLE.h"
//#include "CAnimal.h"
//#include "CVEHICLE.h"
#include "Console.h"
#include "CPEOPLE.h"
using namespace std;

template<class T>

//truyen vao level va toa do da luu trong file
void updateLevel(vector<T>& arr, int lane, int level, int savedX)
{
	//firstX dieu chinh toa do ban dau de khac nhau
	int firstX;
	if (lane == 6) firstX = 0;
	else if (lane == 11) firstX = 10;
	else if (lane == 16) firstX = 20;
	else firstX = 30;

	if (level <= 3) {
		arr.clear();
		for (int i = 0; i < level; i++) {
			if (firstX + savedX + (i)*WIDTH / level >= WIDTH - lengthB)
			{
				T tmp(firstX + savedX + (i)*WIDTH / level - 80, lane);
				arr.push_back(tmp);
			}
			else {
				T tmp(firstX + savedX + (i)*WIDTH / level, lane);
				arr.push_back(tmp);
			}
		}
	}
}


class CGAME
{
private:
	vector <CTRUCK> truck;
	vector <CCAR> car;
	vector <CDINOSAUR> dinosaur;
	vector <CBIRD> bird;
	CTRAFFICLIGHT light;
	CPEOPLE player; 
	int level;
	int key;
	int character_color[5]; 
public:
	CGAME();
	void drawGame();
	~CGAME();
	void resetGame();
	void exitGame();
	void startGame();
	void loadGame(int temp);
	void saveGame();
	void pauseGame();
	void UpLevel();
	bool endGame();
	bool levelUp();
	void updatePosPeople();
	void updatePosVehicle();
	void updatePosAnimal();
	void updateColor(int color[]);
	//ham lay toa do de luu vo file
	int getX_c();
	int getX_t();
	int getX_b();
	int getX_d();
};

void printLose();
void printWin();

extern 	CGAME game;
#endif
