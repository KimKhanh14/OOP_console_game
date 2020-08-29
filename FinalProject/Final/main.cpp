#include "Console.h"
#include "CGAME.h"
#include "Menu.h"

int main()
{
	FixConsoleWindow();
	ShowCur(0);
	DisableSelection();
	ShowScrollBar(GetConsoleWindow(), SB_BOTH, 0);
	system("title CROSSING ROAD");
	PlaySound(TEXT("Sounds/Theme.wav"), NULL, SND_LOOP|SND_ASYNC);
	while (1)
	{
		printMenu();
	}
	
	return 0;
}