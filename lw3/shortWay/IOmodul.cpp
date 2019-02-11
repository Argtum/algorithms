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
    new_road.dest = inp_str[2] - '0';
    new_road.value = inp_str[4] - '0';
    if (inp_str[6] == 'y') {
        new_road.value *= 100;
    }

    return new_road;
}

void printArr(marks arr[], int start, int finish)
{
    int curr = finish;

    cout << "кратчайший путь из " << start + 1 << " в " << finish + 1 << ": " << endl << finish  + 1 << " ";

    while (curr != start) {
        cout << arr[curr].mark + 1 << " ";
        curr = arr[curr].mark;
    }
    cout << endl;
}

cityInterval getIntervalCity(int matrixSize)
{
    cityInterval interval;

    do {
        do {
            cout << endl << "Введите номер стартовой вершины: ";
            cin >> interval.start;
            if(cin.good()) {
                interval.start--;
                if (interval.start >= matrixSize || interval.start < 0) {
                    cout << "Номер вершины должен быть небольше размера матрицы, но больше 0" << endl;
                }
            } else {
                cout << endl << "Введённые данные не являються числом" << endl;
                exit(1);
            }
        } while (interval.start >= matrixSize || interval.start < 0);
        do {
            cout << "В какую вершину надо прийти: ";
            cin >> interval.finish;
            if(cin.good()) {
                interval.finish--;
                if (interval.finish >= matrixSize || interval.finish < 0) {
                    cout << "Номер вершины должен быть небольше размера матрицы, но больше 0" << endl;
                }
            } else {
                cout << endl << "Введённые данные не являються числом" << endl;
                exit(1);
            }
        } while (interval.finish >= matrixSize || interval.finish < 0);
        if (interval.start == interval.finish) {
            cout << "вершины должны быть разные" << endl;
        }
    } while (interval.start == interval.finish);

    return interval;
}
