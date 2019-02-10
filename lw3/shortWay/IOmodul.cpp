#include "IOmodul.h"

void printStatus(int status)
{
    switch (status) {
        case ERR_NO_FILE:
            cout << "ОШИБКА! Неправильно указано имя фаил или такого файла нет" << endl << endl;
        break;
        case ERR_NO_CITY:
            cout << "ОШИБКА! Фаил с городами пуст" << endl << endl;
        break;
        case ERR_NO_ROAD:
            cout << "ОШИБКА! Фаил с дорогами пуст" << endl << endl;
        break;
        default:
            cout << "неизвестная ошибка" << endl << endl;
    }
}

cityParam readCitys(string inp_str)
{
    cityParam new_city;

    new_city.index = inp_str[0] - '0';
    new_city.name = inp_str[2];

    return new_city;
}

roadParam readRoads(string inp_str)
{
    roadParam new_road;

    new_road.src = inp_str[0] - '0';
    new_road.dest = inp_str[1] - '0';
    new_road.value = inp_str[3] - '0';
    if (inp_str[5] == 'y') {
        new_road.value *= 100;
    }

    return new_road;
}

void printArr(marks arr[], int start, int finish)
{
    int curr = finish;

    cout << "кратчайший путь из " << start << " в " << finish << ": " << endl << finish << " ";

    while (curr != start) {
        cout << arr[curr].mark << " ";
        curr = arr[curr].mark;
    }
}
