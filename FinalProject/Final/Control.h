#ifndef CONTROL_H
#define CONTROL_H

#include "CAnimal.h"
#include "CVEHICLE.h"

void background();
void init();
void handle(vector<CBIRD>& bArr, vector<CDINOSAUR>& dArr, vector<CTRUCK>& tArr, vector<CCAR>& cArr, CTRAFFICLIGHT& light);
void display(vector<CBIRD> bArr, vector<CDINOSAUR> dArr, vector<CTRUCK> tArr, vector<CCAR> cArr, CTRAFFICLIGHT light);
void levelUp(vector<CBIRD>& bArr, vector<CDINOSAUR>& dArr, vector<CTRUCK>& tArr, vector<CCAR>& cArr, int level);
#endif // !CONTROL_H
