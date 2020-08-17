#include "Control.h"

void background()
{
	PlaySound(TEXT("a.wav"), NULL, SND_LOOP | SND_ASYNC);

}

void init()
{
	for (int i = 0; i <= HEIGHT; i++)
		for (int j = 0; j <= WIDTH; j++)
			buffer.square(i, j, ' ');
}

//display and handle animal
void display(vector<CBIRD> bArr, vector<CDINOSAUR> dArr, vector<CTRUCK> tArr, vector<CCAR> cArr, CTRAFFICLIGHT light)
{
	//Draw background
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
	for (int i = 0; i < bArr.size(); i++)
		bArr[i].Move(9);
	//Draw Dinosaur
	for (int i = 0; i < dArr.size(); i++)
		dArr[i].Move(10);
	//Draw Truck
	for (int i = 0; i < tArr.size(); i++)
		tArr[i].Move(11);
	//Draw Car
	for (int i = 0; i < cArr.size(); i++)
		cArr[i].Move(12);
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
void handle(vector<CBIRD>& bArr, vector<CDINOSAUR>& dArr, vector<CTRUCK>& tArr, vector<CCAR>& cArr, CTRAFFICLIGHT& light)
{
	//bird
	for (int i = 0; i < bArr.size(); i++) {
		bArr[i].goRight();
		if (bArr[i].getX() == WIDTH - lengthB) bArr[i].Update(1, 11);
	}
	//dinosaur
	for (int i = 0; i < dArr.size(); i++) {
		dArr[i].goRight();
		if (dArr[i].getX() == WIDTH - lengthD) dArr[i].Update(1, 21);
	}
	//truck
	for (int i = 0; i < tArr.size(); i++)
	{
		tArr[i].goRight(light);
		if (tArr[i].getX() == WIDTH - lengthT) tArr[i].Update(1, 6);
	}
	//car
	for (int i = 0; i < cArr.size(); i++) {
		cArr[i].goRight(light);
		if (cArr[i].getX() == WIDTH - lengthC) cArr[i].Update(1, 16);
	}

	if (bArr[0].getX() % 20 == 0) {
		light.changeColor();
	}

}

//tang so con trong array, CGAME khong
template<class T>
void updateLevel(vector<T>& arr, int lane, int level) {
	for (int i = 0; i < level; i++) {
		T tmp((i)*WIDTH / level, lane);
		arr.push_back(tmp);
	}
}

//tang level
void levelUp(vector<CBIRD>& bArr, vector<CDINOSAUR>& dArr, vector<CTRUCK>& tArr, vector<CCAR>& cArr, int level) {
	updateLevel(bArr, 11, level);
	updateLevel(dArr, 21, level);
	if (level == 3) updateLevel(tArr, 6, level - 1);	//level 3 -> 2 trucks
	else updateLevel(tArr, 6, level);
	updateLevel(cArr, 16, level);
}
