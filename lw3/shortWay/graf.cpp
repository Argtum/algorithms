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
    int smallerValue = MAX_VALUE;
    bool isAllSolid = true;

    for (int i = 0; i < matrixSize; i++) {
        if (!arr[i].isSolid) {
            if (arr[lastSolid].distance + matrix[lastSolid][i] < arr[i].distance) {
                arr[i].distance = arr[lastSolid].distance + matrix[lastSolid][i];
                arr[i].mark = lastSolid;
            }
        }
    }
    for (int i = 0; i < matrixSize; i++) {
        if (!arr[i].isSolid) {
            if (arr[i].distance < smallerValue) {
                smallerValue = arr[i].distance;
                newLastSolid = i;
            }
        }
    }
    arr[newLastSolid].isSolid = true;
    for (int i = 0; i < matrixSize; i++) {
        if (!arr[i].isSolid) {
            isAllSolid = false;
        }
    }
    if (lastSolid == newLastSolid) {
        if (!isAllSolid) {
            cout << "пути из вершины " << ++start << " в вершину " << ++finish << " нет." << endl;
            exit(0);
        }
    } else {
        if (!arr[finish].isSolid) {
            arr[matrixSize] = dextra(newLastSolid, arr, matrixSize, matrix, start, finish);
        }
    }

    return arr[matrixSize];
}

void searchWay(int ( &matrix )[100][100], int matrixSize)
{
    marks arr[matrixSize];
    cityInterval interval = getIntervalCity(matrixSize);

    for (int i = 0; i < matrixSize; i++) {
        arr[i].isSolid = false;
        arr[i].distance = MAX_VALUE;
        arr[i].mark = 0;
    }
    int lastSolid = interval.start;
    arr[lastSolid].mark = 0;
    arr[lastSolid].isSolid = true;
    arr[lastSolid].distance = 0;

    arr[matrixSize] = dextra(lastSolid, arr, matrixSize, matrix, interval.start, interval.finish);

    printArr(arr, interval.start, interval.finish);
}
