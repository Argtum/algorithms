#ifndef GRAF_H
#define GRAF_H

#include "stek.h"

int createSityList(ifstream &cityes, city **sityList);
marks dextra(int lastSolid, marks arr[], int matrixSize, int ( &matrix )[100][100], int start, int finish);
void searchWay(int ( &matrix )[100][100], int matrixSize);

#endif //GRAF_H
