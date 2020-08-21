#include "CGAME.h"

CGAME::CGAME()
{
	for (int i = 0; i <= HEIGHT; i++)
		for (int j = 0; j <= WIDTH; j++)
			buffer.square(i, j, ' ');
	level = 1;
	updateLevel(bird, 11, level);
	updateLevel(dinosaur, 21, level);
	//if (level == 3) updateLevel(truck, 6, level - 1);	//level 3 -> 2 trucks
	//else 
	updateLevel(truck, 6, level);
	updateLevel(car, 16, level);
}

CGAME::~CGAME()
{}

void CGAME::drawGame()
{
	for (int i = 0; i <= HEIGHT; i++)
		for (int j = 0; j <= WIDTH; j++)
			buffer.square(i, j, ' ');
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

	//Draw scoreboard
	GotoXY(86, 0);
	for (int i = 0; i < 30; i++) cout << (char)196;
	cout << (char)191;

	GotoXY(86, 0); cout << (char) 218;
	for (int i = 1; i < HEIGHT - 1; i++)
	{
		if (i == 10)
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
	GotoXY(87, 10);
	for (int i = 1; i < 30; i++) cout << (char)196;
	for (int i = 1; i < HEIGHT - 1; i++)
	{
		if (i == 10)
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
	cout << "Press P to pause game";
	GotoXY(87, 7);
	cout << "Press R to resume game";
	GotoXY(87, 8);
	cout << "Press L to load game";
	GotoXY(87, 9);
	cout << "Press S to save game";

}

void CGAME::pauseGame(HANDLE thread)
{
	SuspendThread(thread);
}

void CGAME::resumeGame(HANDLE thread)
{

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
		int key = _getch();
		if (key == 'A' || key == 'a') player.Left();
		else if (key == 'W' || key == 'w') player.Up();
		else if (key == 'D' || key == 'd') player.Right();
		else player.Down();
	}
}

void CGAME::UpLevel()
{
	level += 1;
	updateLevel(bird, 11, 1);
	updateLevel(dinosaur, 21, 1);
	//if (level == 3) updateLevel(truck, 6, level - 1);	//level 3 -> 2 trucks
	//else 
	updateLevel(truck, 6, 1);
	updateLevel(car, 16, 1);
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
	if (player.isFinish()) return true;
	return false;
}