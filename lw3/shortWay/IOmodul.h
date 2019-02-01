#ifndef IOMODUL_H
#define IOMODUL_H

#include <set>
#include <cmath>
#include <string>
#include <fstream>
#include <string.h>
#include <cstddef>
#include <iostream>

using namespace std;

const int OK = 0;
const int ERR_NO_FILE = 1;
const int ERR_NO_CITY_INDEX = 2;
const int ERR_NO_CITY_NAME = 3;

const bool YES = true;
const bool NO = false;

struct connect;
struct city;
struct cityParam;

const char accessSymbol[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

struct cityParam
{
    int index;
    char name;
};

struct city
{
    char index;
    char name;
    city *next;
    connect *connectTo;
};

struct connect
{
    city *dest;
    connect *next;
};

void printStatus(int status);
cityParam readStr(string inp_str, int status);

#endif //IOMODUL_H
