#include "Console.h"
#include "Control.h"


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

	//vector<CBIRD> bArr;
	//vector<CDINOSAUR> dArr;
	vector<CTRUCK> tArr;
	vector<CCAR> cArr;

	//function update level for animal
	//levelUp_animal(bArr, dArr, level);

	//function update level for vehicle
	levelUp_vehicle(tArr, cArr, level);

	
	while (1)
	{
		displayVehicle(tArr, cArr, light);
		handleVehicle(tArr, cArr, light);
		/*displayAnimal(bArr, dArr);
		handleAnimal(bArr, dArr);*/
		//Sleep(500);
	}

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