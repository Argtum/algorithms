#pragma once
#include <iostream>

struct item
{
    char value;
    item *next;
};

struct floatItem
{
    float value;
    floatItem *next;
};

struct memCell
{
    char variable;
    float value;
    memCell *next;
};

void DeleteSymbolFromStack(item **topPtr);
void Delete(item **topPtr);
char PopSymbolFromStack(item **topPtr);
float PopNumberFromStack(floatItem **topPtr);
void PushSymbolToStack(item **topPtr, char inputLexem);
void PushNumberToStack(floatItem **topPtr, float inputLexem);
void PushValueToStack(char var, float val);
bool HasValue(char var);
float getValue();
