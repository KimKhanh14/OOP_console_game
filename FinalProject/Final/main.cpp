#include "Console.h"
//#include "Control.h"
#include "CGAME.h"

int main()
{
	FixConsoleWindow();
	ShowCur(0);
	DisableSelection();
	ShowScrollBar(GetConsoleWindow(), SB_BOTH, 0);
	system("title CROSSING ROAD");

	//int level = 3;
	/*CTRAFFICLIGHT light;

	vector<CBIRD> bArr;
	vector<CDINOSAUR> dArr;
	vector<CTRUCK> tArr;
	vector<CCAR> cArr;*/

	//levelUp(bArr, dArr, tArr, cArr, level);

	
	/*while (1)
	{
		display(bArr, dArr, tArr, cArr, light);
		handle(bArr, dArr, tArr, cArr, light);
		Sleep(100);
	}*/
	int k;
	CGAME game;
	game.drawGame();
	while (1)
	{
		game.startGame();
		game.updatePosVehicle();
		game.updatePosAnimal();
		if (game.endGame())
		{
			GotoXY(96, 17);
			cout << "GAME OVER!";
			GotoXY(93, 18);
			cout << "PRESS Y TO RESTART";
			if (_kbhit)
			{
				int k = _getch();
				if (k == 'Y' || k == 'y')
				{
					//restart game - them ham vo day nhe
					GotoXY(93, 19);
					cout << "Restart!";
				}
			}
			
		}
		if (game.levelUp())
		{
			GotoXY(96, 17);
			cout << "LEVEL UP!";
			game.UpLevel();
		}
		game.updatePosPeople();
		Sleep(100);
	}

	
	return 0;
}