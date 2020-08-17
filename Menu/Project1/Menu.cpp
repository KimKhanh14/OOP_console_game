#include "Console.h"
typedef char str[31];

str options [4] = {"New game", "Load game", "Settings", "Exit game"};
enum state {UP,DOWN,LEFT,RIGHT, ENTER};

#define textcolor 15
#define backgroundcolor 176
state key(int z)
{
	if (z == 224)
	{
		char c;
		c = _getch();
		if (c == 72) return UP;
		if (c == 80) return DOWN;
		if (c == 77) return RIGHT;
		if (c == 75) return LEFT;
	}
	if (z == 13) return ENTER;
}

int menu(str options[4], int n)
{
	int now = 0;
	int* color = new int[n];
	for (int i = 0; i < n; i++)
		color[i] = textcolor;
	color[0] = backgroundcolor;
	while (1)
	{
		clrscr();
		//Ve tieu de Crossing Road
		GotoXY(25, 1);
		TextColor(14);
		cout << "_|_|_|_| _|_|_|_| _|_|_|_| _|_|_|_| _|_|_|_| _| _|      _|  _|_|_|_|";
		GotoXY(25, 2);
		cout << "_|       _|    _| _|    _| _|       _|       _| _|_|    _|  _|  ";
		GotoXY(25, 3);
		cout << "_|       _|_|_|_| _|    _| _|_|_|_| _|_|_|_| _| _|  _|  _|  _|  _|_|_|";
		GotoXY(25, 4);
		cout << "_|       _|  _|   _|    _|       _|       _| _| _|    _|_|  _|    _|" ;
		GotoXY(25, 5);
		cout << "_|_|_|_| _|    _| _|_|_|_| _|_|_|_| _|_|_|_| _| _|      _|  _|_|_|_|";

		GotoXY(40, 8);
		cout << "_|_|_|_| _|_|_|_|     _|     _|_|_|_|";
		GotoXY(40, 9);
		cout << "_|    _| _|    _|   _| _|    _|     _|";
		GotoXY(40, 10);
		cout << "_|_|_|_| _|    _| _|_|_|_|_| _|     _|";
		GotoXY(40, 11);
		cout << "_|  _|   _|    _| _|      _| _|     _|";
		GotoXY(40, 12);
		cout << "_|    _| _|_|_|_| _|      _| _|_|_|_|";
		//Ve khung menu
		TextColor(textcolor);
		GotoXY(56, 18);
		cout << "MENU";
		//Ve options
		for (int i = 0; i < n; i++)
		{
			GotoXY(53, 20+i);
			TextColor(color[i]);
			cout << i + 1 << " - " << options[i];
		}
		//Ve ten thanh vien
		TextColor(15);
		GotoXY(40, 27);
		cout << "UNIVERSITY OF SCIENCE - 19CLC5 - GROUP 9";
		int z = _getch();
		state State = key(z);
		switch (State)
		{
		case UP: 
		{
			if (now == 0) now = n - 1;
			else now--;
			break;
		}
		case DOWN:
		{
			if (now == n - 1) now = 0;
			else now++;
			break;
		}
		case ENTER:
		{
			for (int i = 0; i < n; i++)
			{
				GotoXY(53, 20 + i);
				TextColor(7);
				cout << i + 1 << " - " << options[i];
			}
			return now;
		}
		}
		for (int i = 0; i < n; i++)
			color[i] = textcolor;
		color[now] = backgroundcolor;
	}

}

int main()
{
	FixConsoleWindow();
	ShowCur(0);
	DisableSelection();
	ShowScrollBar(GetConsoleWindow(), SB_BOTH, 0);
	int key = menu(options, 4);
	clrscr();
	switch (key)
	{
	case 0: 
	{
		//new game
	}
	case 1: 
	{
		//load game
	}
	case 2:
	{
		//settings
	}
	default: 
	{
		//exit
	}
	}
	return 0;
}