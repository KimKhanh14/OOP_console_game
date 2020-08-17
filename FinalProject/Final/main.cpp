#include "Console.h"
#include "Control.h"
//#include "CGAME.h"

int main()
{
	FixConsoleWindow();
	ShowCur(0);
	DisableSelection();
	ShowScrollBar(GetConsoleWindow(), SB_BOTH, 0);
	system("title Game");
	init();
	int level = 3;
	CTRAFFICLIGHT light;

	vector<CBIRD> bArr;
	vector<CDINOSAUR> dArr;
	vector<CTRUCK> tArr;
	vector<CCAR> cArr;

	levelUp(bArr, dArr, tArr, cArr, level);

	
	while (1)
	{
		display(bArr, dArr, tArr, cArr, light);
		handle(bArr, dArr, tArr, cArr, light);
		Sleep(100);
	}

	/*CGAME game;

	while (1)
	{
		game.startGame();
		game.updatePosVehicle();
		game.updatePosAnimal();
		Sleep(100);
	}*/

	/*HANDLE h = CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)printB, NULL, NULL,NULL);
	HANDLE h1 = CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)printD, NULL, NULL, NULL);
	WaitForSingleObject(h, INFINITE);
	CloseHandle(h);
	WaitForSingleObject(h1, INFINITE);
	CloseHandle(h1);*/
	/*thread Bird(t1);
	thread Dinosaur(t2);
	if (Bird.joinable()) Bird.join();
	if (Dinosaur.joinable()) Dinosaur.join();*/
	/*thread b(background);
	thread Bird(printB);
	thread Dinosaur(printD);
	Bird.join();
	Dinosaur.join();
	b.join();*/
	//CDINOSAUR d;
	//d.Tell();
	//background();
	
	/*thread dino(&CDINOSAUR::Tell,d);
	dino.join();
	*/
	
	return 0;
}