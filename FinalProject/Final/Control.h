#ifndef CONTROL_H
#define CONTROL_H

#include "CAnimal.h"
#include "CVEHICLE.h"

void background();
void init();
void displayAnimal(vector<CBIRD> bArr, vector<CDINOSAUR> dArr);
void handleAnimal(vector<CBIRD>& bArr, vector<CDINOSAUR>& dArr);
void displayVehicle(vector<CTRUCK> tArr, vector<CCAR> c, CTRAFFICLIGHT light);
void handleVehicle(vector<CTRUCK>& tArr, vector<CCAR>& c, CTRAFFICLIGHT& light);
void levelUp_animal(vector<CBIRD>& bArr, vector<CDINOSAUR>& dArr, int level);
void levelUp_vehicle(vector<CTRUCK>& tArr, vector<CCAR>& cArr, int level);
#endif // !CONTROL_H
