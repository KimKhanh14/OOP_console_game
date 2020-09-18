#ifndef _MENU_H
#define _MENU_H

#include "iostream"
#include "Console.h"
#include "CGAME.h"

using namespace std;

typedef char str[31];

str options[4] = { "New game", "Load game", "Settings", "Exit game" };
enum state { UP, DOWN, LEFT, RIGHT, ENTER };
bool isStarted = false;
int c_color[5] = { 9,10,11,12,15 }; //Bird- dino - truck - car - people
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
		TextColor(11);
		cout << "|=|=|=|=| |=|=|=|=|  |=|=|=|=| |=|=|=|=| |=|=|=|=| |=| |=|     |=| |=|=|=|=|";
		GotoXY(25, 2);
		cout << "|=|       |=|    |=| |=|   |=| |=|       |=|       |=| |=|=|   |=| |=|      ";
		GotoXY(25, 3);
		cout << "|=|       |=|=|=|=|  |=|   |=| |=|=|=|=| |=|=|=|=| |=| |=| |=| |=| |=| |=|=|=|";
		GotoXY(25, 4);
		cout << "|=|       |=|  |=|   |=|   |=|       |=|       |=| |=| |=|   |=|=| |=|   |=|";
		GotoXY(25, 5);
		cout << "|=|=|=|=| |=|    |=| |=|=|=|=| |=|=|=|=| |=|=|=|=| |=| |=|     |=| |=|=|=|=|";

		GotoXY(40, 8);
		cout << "|=|=|=|=|  |=|=|=|=|     |=|     |=|=|=|=|";
		GotoXY(40, 9);
		cout << "|=|    |=| |=|   |=|   |=| |=|   |=|     |=|";
		GotoXY(40, 10);
		cout << "|=|=|=|=|  |=|   |=| |=|=|=|=|=| |=|     |=|";
		GotoXY(40, 11);
		cout << "|=|  |=|   |=|   |=| |=|     |=| |=|     |=|";
		GotoXY(40, 12);
		cout << "|=|    |=| |=|=|=|=| |=|     |=| |=|=|=|=|";
		//Ve khung menu
		TextColor(textcolor);
		GotoXY(57, 18);
		cout << "MENU";
		//Ve options
		for (int i = 0; i < n; i++)
		{
			GotoXY(53, 20 + i);
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

void printMenu()
{
	int key = menu(options, 4);
	clrscr();
	switch (key)
	{
		case 0:
		{
		game.loadGame(0);
		}
		case 1:
		{
		game.loadGame(1);
		}
		case 2:
		{
			clrscr();
			GotoXY(0, 0);
			cout << "<" << (char)196 << " Back to Main Menu";
			GotoXY(0, 2);
			TextColor(15);
			cout << "SETTINGS" << endl;
			cout << "Color Code: " << endl;
			TextColor(1);
			cout << "Dark Blue: " << "1" << endl;
			TextColor(2);
			cout << "Dark Green: " << "2" << endl;
			TextColor(3);
			cout << "Dark Cyan: " << "3" << endl;
			TextColor(4);
			cout << "Dark Red: " << "4" << endl;
			TextColor(5);
			cout << "Dark Pink: " << "5" << endl;
			TextColor(6);
			cout << "Dark Yellow: " << "6" << endl;
			TextColor(7);
			cout << "Dark White: " << "7" << endl;
			TextColor(8);
			cout << "Dark Grey: " << "8" << endl;
			TextColor(9);
			cout << "Blue: " << "9" << endl;
			TextColor(10);
			cout << "Green: " << "10" << endl;
			TextColor(11);
			cout << "Cyan: " << "11" << endl;
			TextColor(12);
			cout << "Red: " << "12" << endl;
			TextColor(13);
			cout << "Pink: " << "13" << endl;
			TextColor(14);
			cout << "Yellow: " << "14" << endl;
			TextColor(15);
			cout << "White: " << "15" << endl;
			cout << "No change: -1" << endl << endl;
			int k;
			cout << "Bird: ";
			cin >> k;
			if (k != -1) c_color[0] = k;
			cout << "Dinosaur: ";
			cin >> k;
			if (k != -1) c_color[1] = k;
			cout << "Truck: ";
			cin >> k;
			if (k != -1) c_color[2] = k;
			cout << "Car: ";
			cin >> k;
			if (k != -1) c_color[3] = k;
			cout << "People: ";
			cin >> k;
			cin.ignore();
			if (k != -1) c_color[4] = k;
			game.updateColor(c_color);
			isStarted = true;
			printMenu();
			return;
		}
		default:
		{
		exit(0);
		}
	}
}

#endif