/*Серебряков Алексей. Задача №22

В строке текстового файла задано выражение из целых
чисел и операций '+', '-', '*', '/', '^'. Порядок вычислений
определяется приоритетом операций и круглыми скобками. Возможен
одноместный минус в начале выражения или после открывающей
скобки. Преобразовать выражение в постфиксную форму (алгоритм
Дейкстры) и вычислить его значение. Показать этапы выполнения*/

#include "main.h"

int main(int argc, char* argv[])
{
    string path;
    item *itemPtr = new item;

    if (argc != 2)
    {
        cout << "Введите имя файла: ";
        cin >> path;
    }
    else
    {
        path = argv[1];
    }

    ifstream inputFile(path);
    if(inputFile.is_open())
    {
        cout << "Все ОК! Файл открыт!\n" << endl;
        ReadInputData(inputFile);
        *itemPtr = GetPolishEntry();
        inputFile.close();
    }
    else
    {
        cout << "Файл не открыт!\n" << endl;
    }

    WriteData(&itemPtr);
    Calculation(&itemPtr);
    return 0;
}
