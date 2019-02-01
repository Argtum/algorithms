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

cityParam readStr(string inp_str, int status)
{
    cityParam new_city;

    new_city.index = inp_str[0] - '0';
    new_city.name = inp_str[1];

    return new_city;
}
