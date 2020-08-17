#ifndef _CGAME_H
#define _CGAME_H

//#include <iostream>
//#include <fstream>
//#include <Windows.h>
//#include <vector>
#include <thread>
#include "CVEHICLE.h"
//#include "CAnimal.h"
//#include "CVEHICLE.h"
#include "Control.h" //M chuyen ham LevelUp qua CGAME thi khong can include control.h nua
#include "Console.h"

using namespace std;

template<class T>

void updateLevel(vector<T>& arr, int lane, int level) 
{
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
	int level;
public:
	CGAME();
	void drawGame();
	~CGAME();
	//CPEOPLE getPEOPLE();
	vector <CVEHICLE> getVehicle();
	vector <CANIMAL> getAnimal();
	void resetGame();
	void exitGame(HANDLE thread);
	void startGame();
	void loadGame(istream);
	void saveGame(istream);
	void pauseGame(HANDLE thread);
	void resumeGame(HANDLE thread);
	void updatePosPeople(char);
	void updatePosVehicle();
	void updatePosAnimal();
};

#endif
