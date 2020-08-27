#include "CVEHICLE.h"
//34,68
//4-4 -red
//10-10 - green
//23-24 - grey
//31-31- normal


//int main() {
//	//cout << "   ___   \n _/   \\_ \n|_______|\n O    O ";
//	//cout << endl << endl << endl << endl;
//	//cout << " _______    \n|       \\__ \n|__________|\n O     O   ";
//
//	
//
//	/*cout << "Number of vehicles: ";
//	int n;
//	cin >> n;
//	printVehicles(n);*/
//
//	//srand(time(NULL));
//	//CTRUCK truck(5,0);
//
//	//for (int i = 0; i < WIDTH; i++) {
//	//	if (truck.checkPos(i)) cout << "1";
//	//	else cout << "0";
//	//}
//	//cout << endl;
//
//	//for (int k = 0; k < 20; k++) {
//	//	truck.Move(k, 0);
//	//	for (int i = 0; i < WIDTH; i++) {
//	//		if (truck.checkPos(i)) cout << "1";
//	//		else cout << "0";
//	//	}
//	//	cout << endl;
//	//}
//	CTRAFFICLIGHT light;
//	CTRUCK truck(50,6);
//	//CTRUCK truck2(5 + 14, 6);
//	truck.Move(light);
//	//truck.Appear(50, 6);
//	//truck2.Move();
//	return 0;
//}

#include "CVEHICLE.h"

void CVEHICLE::Update(int x, int y)
{
	mX = x;
	mY = y;
}

void CTRUCK::Move(int color)
{
	int x = getX();
	int y = getY();
	buffer.square(y, x, ' ', color);
	for (int i = 1; i <= 7; i++)
		buffer.square(y, x + i, '_', color);
	for (int i = 9; i <= 11; i++)
		buffer.square(y, x + i, ' ', color);
	buffer.square(y + 1, x, '|', color);
	for (int i = 1; i <= 7; i++)
		buffer.square(y + 1, x + i, ' ', color);
	buffer.square(y + 1, x + 8, '\\', color);
	buffer.square(y + 1, x + 9, '_', color);
	buffer.square(y + 1, x + 10, '_', color);
	buffer.square(y + 1, x + 11, ' ', color);
	buffer.square(y + 2, x, '|', color);
	for (int i = 1; i <= 10; i++)
		buffer.square(y + 2, x + i, '_', color);
	buffer.square(y + 2, x + 11, '|', color);

	buffer.square(y + 3, x, ' ', color);
	buffer.square(y + 3, x + 1, 'O', color);
	for (int i = 2; i <= 7; i++)
		buffer.square(y + 3, x + i, ' ', color);
	buffer.square(y + 3, x + 8, 'O', color);
	for (int i = 9; i <= 11; i++)
		buffer.square(y + 3, x + i, ' ', color);
}


void CCAR::Move(int color)
{
	int x = getX();
	int y = getY();

	for (int i = 0; i <= 2; i++)
		buffer.square(y, x + i, ' ', color);
	for (int i = 3; i <= 5; i++)
		buffer.square(y, x + i, '_', color);
	for (int i = 6; i <= 8; i++)
		buffer.square(y, x + i, ' ', color);
	buffer.square(y + 1, x, ' ', color);
	buffer.square(y + 1, x + 1, '_', color);
	buffer.square(y + 1, x + 2, '/', color);
	for (int i = 3; i <= 5; i++)
		buffer.square(y + 1, x + i, ' ', color);
	buffer.square(y + 1, x + 6, '\\', color);
	buffer.square(y + 1, x + 7, '_', color);
	buffer.square(y + 1, x + 8, ' ', color);
	buffer.square(y + 2, x, '|', color);
	for (int i = 1; i <= 7; i++)
		buffer.square(y + 2, x + i, '_', color);
	buffer.square(y + 2, x + 8, '|', color);
	buffer.square(y + 3, x, ' ', color);
	buffer.square(y + 3, x + 1, 'O', color);
	for (int i = 2; i <= 6; i++)
		buffer.square(y + 3, x + i, ' ', color);
	buffer.square(y + 3, x + 7, 'O', color);
	buffer.square(y + 3, x + 8, ' ', color);

}

void CCAR::Tell()
{
	PlaySound(TEXT("Sounds/Car.wav"), NULL, SND_ASYNC);
}

void CTRUCK::Tell()
{
	PlaySound(TEXT("Sounds/Truck.wav"), NULL, SND_ASYNC);
}