#ifndef ALG_LW2_IOMODUL_H
#define ALG_LW2_IOMODUL_H

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
const int ERR_SYMBOL = 2;

const bool AND = true;
const bool OR = false;

const bool YES = true;
const bool NO = false;

const char ar_and[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const char ar_or[] = "abcdefghijklmnopqrstuvwxyz";
const char accessSymbol[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz*";

struct top_param
{
    char topName;
    bool topType;
    int level;
};

void printStatus(int status);
top_param readStr(string inp_str, int status);
void printTopLevel(int level);

#endif //ALG_LW2_IOMODUL_H
