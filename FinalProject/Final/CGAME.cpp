#include "CGAME.h"

CGAME::CGAME()
{
	CTRUCK t;
	CCAR c;
	CDINOSAUR d;
	CBIRD b;
	truck.push_back(t);
	car.push_back(c);
	dinosaur.push_back(d);
	bird.push_back(b);
}
void CGAME::resetGame()
{

}

void CGAME::exitGame(HANDLE thread)
{
	TerminateThread(thread, 0);
}

void CGAME::startGame()
{

}

void CGAME::pauseGame(HANDLE thread)
{
	SuspendThread(thread);
}

void CGAME::resumeGame(HANDLE thread)
{

}