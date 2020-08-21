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

void updateLevel(vector<T>& arr, int lane, int level) 
{
	arr.clear();
	for (int i = 0; i < level; i++) {
		T tmp((i)*WIDTH / level, lane);
		arr.push_back(tmp);
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
};

#endif
