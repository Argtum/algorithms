#ifndef IOMODUL_H
#define IOMODUL_H

#include <set>
#include <cmath>
#include <string>
#include <fstream>
#include <string.h>
#include <cstddef>
#include <iostream>
#include <locale.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

using namespace std;

const int OK = 0;
const int ERR_NO_FILE = 1;
const int ERR_NO_CITY = 2;
const int ERR_NO_ROAD = 3;

const bool YES = true;
const bool NO = false;

const char accessSymbol[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

struct cityParam
{
    int index;
    char name;
};

struct marks
{
    int mark;
    bool isSolid;
    int distance;
};

struct roadParam
{
    int src;
    int dest;
    int value;
};

struct city
{
    char index;
    char name;
    city *next;
};

void printStatus(int status);
cityParam readCitys(string inp_str);
roadParam readRoads(string inp_str);
void printArr(marks arr[], int start, int finish);

#endif //IOMODUL_H
