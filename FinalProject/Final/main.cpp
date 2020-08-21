#include "Console.h"
//#include "Control.h"
#include "CGAME.h"
#include "Menu.h"

int main()
{
	FixConsoleWindow();
	ShowCur(0);
	DisableSelection();
	ShowScrollBar(GetConsoleWindow(), SB_BOTH, 0);
	system("title CROSSING ROAD");

	while (1)
	{
		printMenu();
	}
	
	return 0;
}