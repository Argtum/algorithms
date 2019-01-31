#pragma once
#include <fstream>
#include <cmath>
#include <float.h>
#include "polishEntry.h"

void WriteData(item **itemPtr);
void ReadInputData(ifstream &inputFile);
void Calculation(item **itemPtr);
void PrintError(int status);
