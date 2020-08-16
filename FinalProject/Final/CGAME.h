#ifndef _CGAME_H
#define _CGAME_H

#include <iostream>
#include <fstream>
#include <Windows.h>
#include <vector>
#include <thread>
#include "CVEHICLE.h"
#include "CAnimal.h"
#include "Console.h"

using namespace std;

class CGAME
{
private:
	vector <CTRUCK> truck;
	vector <CCAR> car;
	vector <CDINOSAUR> dinosaur;
	vector <CBIRD> bird;
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
