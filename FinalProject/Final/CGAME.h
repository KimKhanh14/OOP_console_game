#ifndef _CGAME_H
#define _CGAME_H

//#include <iostream>
#include <fstream>
//#include <Windows.h>
#include <vector>
#include <thread>
#include <string>
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
	int firstX, l;
	if (lane == 6) { firstX = 0; l = lengthT; }
	else if (lane == 11) { firstX = 10; l = lengthB; }
	else if (lane == 16) { firstX = 20; l = lengthC; }
	else { firstX = 30; l = lengthD; }

	if (level <= 3) {
		arr.clear();
		for (int i = 0; i < level; i++) {
			if (firstX + savedX + (i)*WIDTH / level >= WIDTH - l)
			{
				T tmp(firstX + savedX + (i)*WIDTH / level - (WIDTH - l), lane);
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
	int score;
	int  scoreFlag;
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
	void UpLevel(int& temp, int playerX, int playerY, int truckX, int birdX, int carX, int dinosaurX);
	bool endGame();
	bool levelUp();
	void updatePosPeople();
	void updatePosVehicle();
	void updatePosAnimal();
	void updateColor(int color[]);
	void updateScore();
	//ham lay toa do de luu vo file
	int getX_c();
	int getX_t();
	int getX_b();
	int getX_d();

	void readFile(int temp, int& level, int& score, int& playerX, int& playerY, int& truckX, int& birdX, int& carX, int& dinosaurX);
};

void printLose();
void printWin();

extern 	CGAME game;
#endif
