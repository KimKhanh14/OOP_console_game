#include "Console.h"
#include "Control.h"
#include "CGAME.h"

int main()
{
	FixConsoleWindow();
	ShowCur(0);
	DisableSelection();
	ShowScrollBar(GetConsoleWindow(), SB_BOTH, 0);
	system("title CROSSING ROAD");

	int level = 3;
	CTRAFFICLIGHT light;

	vector<CBIRD> bArr;
	vector<CDINOSAUR> dArr;
	vector<CTRUCK> tArr;
	vector<CCAR> cArr;

	levelUp(bArr, dArr, tArr, cArr, level);

	
	/*while (1)
	{
		display(bArr, dArr, tArr, cArr, light);
		handle(bArr, dArr, tArr, cArr, light);
		Sleep(100);
	}*/

	CGAME game;
	game.drawGame();
	while (1)
	{
		game.startGame();
		game.updatePosVehicle();
		game.updatePosAnimal();
		if (game.endGame())
		{
			cout << "End Game";
			break;
		}
		if (game.levelUp()) cout << "Level up";
		game.updatePosPeople();
		Sleep(100);
	}

	
	return 0;
}