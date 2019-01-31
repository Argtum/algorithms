#include "IOModul.h"

char lexem;
int cnt = 0;
item *stackTop = NULL;
floatItem *floatStackTop = NULL;
int status = 0; // 0 - всё хорошо,

void ReadInputData(ifstream &inputFile)
{
    while((lexem = inputFile.get()) != EOF && status == 0)
    {
        cnt++;
        status = writePolishEnrty(lexem, &stackTop);
    }
    while(stackTop != NULL && stackTop -> value != '(' && status == 0)
    {
        PushSymbolToPolishEntry(PopSymbolFromStack(&stackTop));
    }
    if(stackTop != NULL && status == 0)
    {
        status = 3;
    }
}

void PrintError(int status)
{
    if(status == 1)
    {
        cout << "Нехватает открывабщей скобки" << endl;
    }
    else if(status == 2)
    {
        cout << "ОШИБКА в " << cnt << " символе" << endl;
    }
    else if(status == 3)
    {
        cout << "Нехватает закрывающей скобки" << endl;
    }
    else if(status == 4)
    {
        cout << "на ноль делить нельзя" << endl;
    }
    else if(status == 5)
    {
        cout << "значением переменных может быть только число!" << endl;
    }
}

void WriteData(item **itemPtr)
{
    if(status == 0)
    {
        item *outPtr = new item;
        outPtr = *itemPtr;
        while (outPtr != NULL)
        {
            cout << (outPtr) -> value;
            outPtr = (outPtr) -> next;
        }
        cout << endl;
    }
}

float elem, elem1, elem2;

void Calculation(item **itemPtr)
{
    while(*itemPtr != NULL && status == 0)
    {
        if((*itemPtr) -> value == '#')
        {
            elem1 = PopNumberFromStack(&floatStackTop);
            cout << 0 - elem1 << endl;
            PushNumberToStack(&floatStackTop, 0 - elem1);
        }
        else if(strchr(mathSymbols, (*itemPtr) -> value))
        {
            elem2 = PopNumberFromStack(&floatStackTop);
            elem1 = PopNumberFromStack(&floatStackTop);
            if((*itemPtr) -> value == '+')
            {
                cout << elem1 << "+" << elem2 << "=" << elem1 + elem2 << endl;
                PushNumberToStack(&floatStackTop, elem1 + elem2);
            }
            if((*itemPtr) -> value == '-')
            {
                cout << elem1 << "-" << elem2 << "=" << elem1 - elem2 << endl;
                PushNumberToStack(&floatStackTop, elem1 - elem2);
            }
            if((*itemPtr) -> value == '*')
            {
                cout << elem1 << "*" << elem2 << "=" << elem1 * elem2 << endl;
                PushNumberToStack(&floatStackTop, elem1 * elem2);
            }
            if((*itemPtr) -> value == '/')
            {
                if(elem2 != 0)
                {
                    cout << elem1 << "/" << elem2 << "=" << elem1 / elem2 << endl;
                    PushNumberToStack(&floatStackTop, (elem1 / elem2));
                }
                else
                {
                    status = 4;
                }
            }
            if((*itemPtr) -> value == '^')
            {
                cout << elem1 << "^" << elem2 << "=" << pow(elem1, elem2) << endl;
                PushNumberToStack(&floatStackTop, pow(elem1, elem2));
            }
        }
        else
        {
            if(HasValue((*itemPtr) -> value))
            {
                elem = getValue();
            }
            else
            {
                cout << (*itemPtr) -> value << " = ";
                if (cin>>elem && cin.good())
                {
                    PushValueToStack((*itemPtr) -> value, elem);
                }
                else
                {
                    status = 5;
                }
            }
            PushNumberToStack(&floatStackTop, elem);
        }
        *itemPtr = (*itemPtr) -> next;
    }
    if(status != 0)
    {
        PrintError(status);
    }
}
