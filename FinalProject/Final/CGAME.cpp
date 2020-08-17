#include "CGAME.h"

CGAME::CGAME()
{
	for (int i = 0; i <= HEIGHT; i++)
		for (int j = 0; j <= WIDTH; j++)
			buffer.square(i, j, ' ');
	level = 3;
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