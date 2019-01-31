#include "stack.h"

void DeleteSymbolFromStack(item **topPtr)
{
    item *itemPtr = new item;
    *topPtr = (*topPtr) -> next;
    delete itemPtr;
}

void Delete(item **ptr)
{
    item *itemPtr = new item;
    while(*ptr != NULL)
    {
        itemPtr = *ptr;
        *ptr = (*ptr) -> next;
        delete itemPtr;
    }
}

char PopSymbolFromStack(item **topPtr)
{
    char tmp;
    item *itemPtr = new item;
    itemPtr = *topPtr;
    tmp = (*topPtr) -> value;
    *topPtr = (*topPtr) -> next;
    delete itemPtr;
    return tmp;
}

float PopNumberFromStack(floatItem **topPtr)
{
    float tmp;
    floatItem *itemPtr = new floatItem;
    itemPtr = *topPtr;
    tmp = (*topPtr) -> value;
    *topPtr = (*topPtr) -> next;
    delete itemPtr;
    return tmp;
}

void PushSymbolToStack(item **topPtr, char inputLexem)
{
    item *stackPtr = new item;
    stackPtr -> value = inputLexem;
    stackPtr -> next = *topPtr;
    *topPtr = stackPtr;
}

void PushNumberToStack(floatItem **topPtr, float inputNumber)
{
    floatItem *stackPtr = new floatItem;
    stackPtr -> value = inputNumber;
    stackPtr -> next = *topPtr;
    *topPtr = stackPtr;
}

memCell *memCellTop = new memCell;
float value;

void PushValueToStack(char var, float val)
{
    memCell *cellPtr = new memCell;
    cellPtr -> variable = var;
    cellPtr -> value = val;
    cellPtr -> next = memCellTop;
    memCellTop = cellPtr;
}

bool HasValue(char var)
{
    memCell *cellPtr = new memCell;
    cellPtr = memCellTop;
    while(cellPtr != NULL && cellPtr -> variable != var)
    {
        cellPtr = cellPtr -> next;
    }
    if(cellPtr == NULL)
    {
        return false;
    }
    else
    {
        value = cellPtr -> value;
        return true;
    }
}

float getValue()
{
    return value;
}
