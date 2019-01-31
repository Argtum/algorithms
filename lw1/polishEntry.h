#pragma once
#include <set>
#include <string.h>
#include "stack.h"

using namespace std;

const char sum[] = "-+";
const char multi[] = "*/";
const char exponent[] = "^";
const char leftAssociative[] = "-+*/";
const char mathSymbols[] = "-+*/^";
const char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

int SetPriority(char mathOperation);
void PushSymbolToPolishEntry(char inputLexem);
char readPolishEnrty();
int writePolishEnrty(char lexem, item **stackTop);
item GetPolishEntry();
