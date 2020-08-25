#include "CGAME.h"

CGAME::CGAME()
{
	for (int i = 0; i <= HEIGHT; i++)
		for (int j = 0; j <= WIDTH; j++)
			buffer.square(i, j, ' ');
	level = 1;
	updateLevel(bird, 11, level);
	updateLevel(dinosaur, 21, level);
	if (level == 3) updateLevel(truck, 6, level - 1);	//level 3 -> 2 trucks
	else updateLevel(truck, 6, level);
	updateLevel(car, 16, level);
}

CGAME::~CGAME()
{}

void CGAME::drawGame()
{
	//Draw scoreboard
	GotoXY(86, 0);
	for (int i = 0; i < 30; i++) cout << (char)196;
	cout << (char)191;

	GotoXY(86, 0); cout << (char)218;
	for (int i = 1; i < HEIGHT - 1; i++)
	{
		if (i == 13)
		{
			GotoXY(86, i);
			cout << (char)195;
		}
		else
		{
			GotoXY(86, i);
			cout << (char)179;
		}

	}
	GotoXY(86, HEIGHT - 1);
	cout << (char)192;
	for (int i = 0; i < 30; i++) cout << (char)196;
	GotoXY(87, 13);
	for (int i = 1; i < 30; i++) cout << (char)196;
	for (int i = 1; i < HEIGHT - 1; i++)
	{
		if (i == 13)
		{
			GotoXY(116, i);
			cout << (char)180;
		}
		else
		{
			GotoXY(116, i);
			cout << (char)179;
		}
	}
	GotoXY(116, HEIGHT - 1);
	cout << (char)217;

	//Information
	TextColor(14);
	GotoXY(96, 1);
	cout << "INFORMATION: ";
	TextColor(12);
	GotoXY(87, 3);
	cout << "LEVEL: " << level;
	TextColor(11);
	GotoXY(87, 4);
	cout << "SCORE: ";
	TextColor(7);
	GotoXY(87, 6);
	cout << "Press W to go straight";
	GotoXY(87, 7);
	cout << "Press S to go backward";
	GotoXY(87, 8);
	cout << "Press A to go left";
	GotoXY(87, 9);
	cout << "Press D to go right";
	GotoXY(87, 10);
	cout << "Press P to pause game";
	GotoXY(87, 11);
	cout << "Press E to exit game";
}
void CGAME::resetGame()
{
	player.Reset();
	level = 1;
	updateLevel(bird, 11, level);
	updateLevel(dinosaur, 21, level);
	if (level == 3) updateLevel(truck, 6, level - 1);	//level 3 -> 2 trucks
	else updateLevel(truck, 6, level);
	updateLevel(car, 16, level);
}

void CGAME::exitGame()
{
	exit(0);
}

void CGAME::startGame()
{
	for (int i = 0; i <= HEIGHT; i++)
		for (int j = 0; j < WIDTH; j++)
		{
			if (i == 0 && j == WIDTH - 1) buffer.square(i, j, (char)187);
			else if (i % 5 == 0)
			{
				if (j == WIDTH - 1) buffer.square(i, j, (char)185);
				else buffer.square(i, j, (char)205);
			}
			else if (j == WIDTH - 1)
				buffer.square(i, j, (char)186);
		}
	//Draw Bird
	for (int i = 0; i < bird.size(); i++)
		bird[i].Move(9);
	//Draw Dinosaur
	for (int i = 0; i < dinosaur.size(); i++)
		dinosaur[i].Move(10);
	//Draw Truck
	for (int i = 0; i < truck.size(); i++)
		truck[i].Move(11);
	//Draw Car
	for (int i = 0; i < car.size(); i++)
		car[i].Move(12);
	//Draw light
	light.print(WIDTH, 6);
	light.print(WIDTH, 16);

	//Draw people
	player.Draw(15);

	GotoXY(0, 0);
	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++)
		{
			TextColor(buffer.table[i][j].color);
			putchar(buffer.table[i][j].character);
			buffer.table[i][j].character = ' ';
		}
		if (i < HEIGHT - 1)
			putchar('\n');
	}
}

void CGAME::loadGame(int temp)
{
	level = temp;
	UpLevel();
	int k;
	while (1)
	{
		startGame();
		drawGame();
		updatePosVehicle();
		updatePosAnimal();
		if (endGame())
		{
			GotoXY(96, 20);
			cout << "GAME OVER!";
			GotoXY(88, 21);
			cout << "    PRESS Y TO RESTART     ";
			if (_kbhit)
			{
				int k = _getch();
				if (k == 'Y' || k == 'y')
				{
					resetGame();
					GotoXY(96, 20);
					cout << "          ";
					GotoXY(88, 21);
					cout << "         Restart!          ";
				}
				else
				{
					ofstream fo;
					fo.open("SaveLevel.txt");
					fo << 1;
					fo.close();
					printLose();
					exitGame();
				}
			}
		}
		if (levelUp())
		{
			GotoXY(88, 21);
			cout << "         LEVEL UP!          ";
			UpLevel();
		}
		updatePosPeople();
		pauseGame();
		saveGame();
		Sleep(100);
	}
}

void CGAME::saveGame()
{
	if (key == 'E' || key == 'e')
	{
		ofstream fo;
		fo.open("SaveLevel.txt");
		fo << level;
		GotoXY(88, 21);
		cout << "         Saved!         ";
		fo.close();
		exitGame();
	}
}

void CGAME::pauseGame()
{
	if (key == 'P' || key == 'p')
	{
		GotoXY(88, 21);
		cout << "PRESS P 2 TIMES TO CONTINUE";
		int key1 = _getch();
		if(key1!='P' || key1!='p')
		{
			key1 = _getch();
		}
		GotoXY(88, 21);
		cout << "                            ";
		key = '_';
	}
}

void CGAME::updatePosAnimal()
{
	//bird
	for (int i = 0; i < bird.size(); i++) {
		bird[i].goRight();
		if (bird[i].getX() == WIDTH - lengthB) bird[i].Update(1, 11);
	}
	//dinosaur
	for (int i = 0; i < dinosaur.size(); i++) {
		dinosaur[i].goRight();
		if (dinosaur[i].getX() == WIDTH - lengthD) dinosaur[i].Update(1, 21);
	}
	if (bird[0].getX() % 20 == 0) {
		light.changeColor();
	}
}

void CGAME::updatePosVehicle()
{
	//truck
	for (int i = 0; i < truck.size(); i++)
	{
		truck[i].goRight(light);
		if (truck[i].getX() == WIDTH - lengthT) truck[i].Update(1, 6);
	}
	//car
	for (int i = 0; i < car.size(); i++) {
		car[i].goRight(light);
		if (car[i].getX() == WIDTH - lengthC) car[i].Update(1, 16);
	}
}

void CGAME::updatePosPeople()
{
	if (_kbhit())
	{
		key = _getch();
		if (key == 'A' || key == 'a') player.Left();
		else if (key == 'W' || key == 'w') player.Up();
		else if (key == 'D' || key == 'd') player.Right();
		else if (key == 'S' || key == 's') player.Down();
	}
}

void CGAME::UpLevel()
{
	level+=1;
	if (level > 4) {
		ofstream fo;
		fo.open("SaveLevel.txt");
		fo << 1;
		fo.close();
		printWin();
		exitGame();
	}
	updateLevel(bird, 11, level);
	updateLevel(dinosaur, 21, level);
	if (level == 3) updateLevel(truck, 6, level - 1);	//level 3 -> 2 trucks
	else updateLevel(truck, 6, level);
	updateLevel(car, 16, level);
	player.Reset();
}

bool CGAME::endGame()
{
	if (player.getY() == 21) player.isImpact(dinosaur);
	else if (player.getY() == 16) player.isImpact(car);
	else if (player.getY() == 11) player.isImpact(bird);
	else player.isImpact(truck);
	if (player.isDead()) return true;
	return false;
}

bool CGAME::levelUp()
{
	if (player.isFinish()) 
		return true;
	return false;
}

void printLose()
{
	GotoXY(0, 0);
	for (int i = 0; i <= HEIGHT; i++)
	{
		for (int j = 0; j <= WIDTH+36; j++)
			cout << " ";
		cout << endl;
	}
	//Ve tieu de Lose
	GotoXY(49, 10);
	cout << "                                     ";
	GotoXY(49, 11);
	TextColor(14);
	cout << " _|       _|_|_|_| _|_|_|_| _|_|_|_| ";
	GotoXY(49, 12);
	cout << " _|       _|    _| _|       _|       ";
	GotoXY(49, 13);
	cout << " _|       _|    _| _|_|_|_| _|_|_|_| ";
	GotoXY(49, 14);
	cout << " _|       _|    _|       _| _|       ";
	GotoXY(49, 15);
	cout << " _|_|_|_| _|_|_|_| _|_|_|_| _|_|_|_| ";
	GotoXY(49, 16);
	cout << "                                     ";
}

void printWin()
{
	for (int i = 0; i <= HEIGHT; i++)
		for (int j = 0; j <= WIDTH; j++)
			buffer.square(i, j, ' ');

	//Ve tieu de Win
	GotoXY(45, 10);
	cout << "                      ";
	GotoXY(45, 11);
	TextColor(14);
	cout << " _|        _| _| _|_|    _| ";
	GotoXY(45, 12);
	cout << " _|        _| _| _| _|   _| ";
	GotoXY(45, 13);
	cout << " _|  _|_|  _| _| _|  _|  _| ";
	GotoXY(45, 14);
	cout << " _| _|  _| _| _| _|   _| _| ";
	GotoXY(45, 15);
	cout << " _|_|    _|_| _| _|    _|_| ";
	GotoXY(45, 16);
	cout << "                      ";
}