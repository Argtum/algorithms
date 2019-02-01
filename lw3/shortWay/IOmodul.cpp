#include "IOmodul.h"

void printStatus(int status)
{
    switch (status) {
        case ERR_NO_FILE:
            cout << "ОШИБКА! Неправильно указан фаил" << endl << endl;
        break;
        case ERR_NO_CITY_INDEX:
            cout << "ОШИБКА! Не указан индекс города" << endl << endl;
        break;
        case ERR_NO_CITY_NAME:
            cout << "ОШИБКА! Не указано имя города" << endl << endl;
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
    new_road.value.dist = inp_str[3] - '0';
    if (inp_str[5] == 'y') {
        new_road.value.hazar = true;
    } else if (inp_str[5] == 'n') {
        new_road.value.hazar = false;
    } else {
        cout << "ERROR: неуказана аварийность дороги" << endl;
    }

    return new_road;
}
