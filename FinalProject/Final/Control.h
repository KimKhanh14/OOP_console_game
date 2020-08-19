#ifndef CONTROL_H
#define CONTROL_H

#include <vector>
//#include "CAnimal.h"
//#include "CVEHICLE.h"
#include "CPEOPLE.h"
void background();
void init();
void handle(vector<CBIRD>& bArr, vector<CDINOSAUR>& dArr, vector<CTRUCK>& tArr, vector<CCAR>& cArr, CTRAFFICLIGHT& light);
void display(vector<CBIRD> bArr, vector<CDINOSAUR> dArr, vector<CTRUCK> tArr, vector<CCAR> cArr, CTRAFFICLIGHT light);
void levelUp(vector<CBIRD>& bArr, vector<CDINOSAUR>& dArr, vector<CTRUCK>& tArr, vector<CCAR>& cArr, int level);
#endif // !CONTROL_H
