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

using namespace std;

const int OK = 0;
const int ERR_NO_FILE = 1;
const int ERR_NO_CITY_INDEX = 2;
const int ERR_NO_CITY_NAME = 3;

const bool YES = true;
const bool NO = false;

const char accessSymbol[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

struct cityParam
{
    int index;
    char name;
};

struct roadValue
{
    int dist;
    bool hazar;
};

struct roadParam
{
    int src;
    int dest;
    roadValue value;
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

#endif //IOMODUL_H
