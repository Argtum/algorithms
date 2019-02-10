#include "graf.h"

int createSityList(ifstream &cityes, city **sityList)
{
    string inp_str;
    cityParam new_city;
    int matrixSize = 0;

    while (getline(cityes, inp_str)) {
        new_city = readCitys(inp_str);

        city *city_ptr = new city;
        city_ptr->name = new_city.name;
        city_ptr->index = new_city.index;
        city_ptr->next = nullptr;

        if (!*sityList) {
            *sityList = city_ptr;
        } else {
            city_ptr->next = *sityList;
            *sityList = city_ptr;
        }
        matrixSize++;
    }

    return matrixSize;
}

marks dextra(int lastSolid, marks arr[], int matrixSize, int ( &matrix )[100][100], int start, int finish)
{
    int newLastSolid = 0;
    int smallerValue = 999;
    bool isAllSolid = true;

    for (int i = 1; i <= matrixSize; i++) {
        if (!arr[i].isSolid && lastSolid != i) {
            if (arr[lastSolid].distance + matrix[lastSolid][i] < arr[i].distance) {
                arr[i].distance = arr[lastSolid].distance + matrix[lastSolid][i];
                arr[i].mark = lastSolid;
            }
        }
    }
    for (int i = 1; i <= matrixSize; i++) {
        if (!arr[i].isSolid) {
            if (arr[i].distance < smallerValue) {
                smallerValue = arr[i].distance;
                newLastSolid = i;
            }
        }
    }

    arr[newLastSolid].isSolid = true;

    for (int i = 1; i <= matrixSize; i++) {
        if (!arr[i].isSolid) {
            isAllSolid = false;
        }
    }

    if (lastSolid == newLastSolid) {
        if (!isAllSolid) {
            cout << "пути из вершины " << start << " в вершину " << finish << " нет." << endl;
            exit(0);
        }
    } else {
        if (!arr[finish].isSolid) {
            arr[matrixSize + 1] = dextra(newLastSolid, arr, matrixSize, matrix, start, finish);
        }
    }

    cout << endl;
    for (int i = 1; i <= matrixSize; i++) {
        cout << arr[i].distance << " ";
    }
    cout << endl;

    return arr[matrixSize + 1];
}
/*
void verificationNumber(string inputData)
{
    bool isNumer = false;

    if (isdigit(inputData)) {
        isNumer = true;
    }

    return isNumer;
}
*/

void searchWay(int ( &matrix )[100][100], int matrixSize)
{
    int start;
    int finish;
    marks arr[matrixSize + 1];

    do {
        do {
            //bool typeNumber = true;
            cout << endl << "Введите номер стартовой вершины: ";
            cin >> start;
            if (start >= matrixSize + 1 || start == 0) {
                cout << "Номер вершины должен быть меньше размера матрицы, но больше 0" << endl;
            }
        } while (start >= matrixSize + 1 || start == 0);

        //&& verificationNumber(start)

        do {
            cout << "В какую вершину надо прийти: ";
            cin >> finish;
            if (finish >= matrixSize + 1 || finish == 0) {
                cout << "Номер вершины должен быть меньше размера матрицы, но больше 0" << endl;
            }
        } while (finish >= matrixSize + 1 || finish == 0);

         //&& verificationNumber(finish)

        if (start == finish) {
            cout << "вершины должны быть разные" << endl;
        }
    } while (start == finish);
    cout << endl;

    for (int i = 1; i <= matrixSize; i++) {
        arr[i].isSolid = false;
        arr[i].distance = 999;
    }
    int lastSolid = start;
    arr[lastSolid].mark = 0;
    arr[lastSolid].isSolid = true;

    arr[matrixSize + 1] = dextra(lastSolid, arr, matrixSize, matrix, start, finish);

    printArr(arr, start, finish);
}
