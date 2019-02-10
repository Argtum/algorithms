#include "polishEntry.h"

item *beginPolishEntry = NULL;
item *endPolishEntry = beginPolishEntry;

int SetPriority(char mathOperation)
{
    int priopity = 0;
    if(strchr(sum, mathOperation))
    {
        priopity = 1;
    }
    else if(strchr(multi, mathOperation))
    {
        priopity = 2;
    }
    else if(strchr(exponent, mathOperation))
    {
        priopity = 3;
    }
    else if(mathOperation == '#')
    {
        priopity = 4;
    }
    return priopity;
}

void PushSymbolToPolishEntry(char inputLexem)
{
    item *newEntry = new item;
    newEntry -> value = inputLexem;
    newEntry -> next = NULL;
    if(endPolishEntry != NULL)
    {
        (endPolishEntry) -> next = newEntry;
    }
    endPolishEntry = newEntry;
    if(beginPolishEntry == NULL)
    {
        beginPolishEntry = endPolishEntry;
    }
}

char readPolishEnrty()
{
    char readedLexem;
    readedLexem = beginPolishEntry -> value;
    beginPolishEntry = beginPolishEntry -> next;
    return readedLexem;
}

char lastLexem = '0';
int errorStatus = 0;

int writePolishEnrty(char lexem, item **stackTop)
{
    if(strchr(alphabet, lexem))
    {
        PushSymbolToPolishEntry(lexem);
    }
    else if(lexem == '-' && (lastLexem == '0' || lastLexem == '('))
    {
        PushSymbolToStack(stackTop, '#');
    }
    else if(strchr(mathSymbols, lexem))
    {
        if(*stackTop == NULL || (*stackTop) -> value == '(')
        {
            PushSymbolToStack(stackTop, lexem);
        }
        else
        {
            int inputPriopity = SetPriority(lexem);
            int stackPriopity = SetPriority((*stackTop) -> value);
            if(inputPriopity > stackPriopity)
            {
                PushSymbolToStack(stackTop, lexem);
            }
            if(strchr(leftAssociative, lexem) && inputPriopity <= stackPriopity)
            {
                while(*stackTop != NULL && (*stackTop) -> value != '(')
                {
                    PushSymbolToPolishEntry(PopSymbolFromStack(stackTop));
                }
                PushSymbolToStack(stackTop, lexem);
            }
            if(strchr(exponent, lexem) && inputPriopity <= stackPriopity)
            {
                while(*stackTop != NULL && (*stackTop) -> value != '(')
                {
                    PushSymbolToPolishEntry(PopSymbolFromStack(stackTop));
                }
                PushSymbolToStack(stackTop, lexem);
            }
        }
    }
    else if(lexem == '(')
    {
        PushSymbolToStack(stackTop, lexem);
    }
    else if(lexem == ')')
    {
        while((*stackTop) -> value != '(' && (*stackTop) -> next != NULL)
        {
            PushSymbolToPolishEntry(PopSymbolFromStack(stackTop));
        }
        if((*stackTop) -> next == NULL)
        {
            errorStatus = 1;
        }
        else
        {
            DeleteSymbolFromStack(stackTop);
        }
    }
    else
    {
        errorStatus = 2;
    }
    lastLexem = lexem;
    return errorStatus;
}

item GetPolishEntry()
{
    return *beginPolishEntry;
}
