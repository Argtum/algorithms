/*Серебряков Алексей. Задача №5
Имеется сеть автомобильных  дорог.  Известны  расстояния
всех   участков   дорог.   Некоторые  участки  аварийноопасны.
Требуется найти лучший путь из пункта  А  в  пункт  В.  Лучшим
считается путь,  имеющий в первую очередь наименьшую суммарную
протяженность аварийноопасных,  а во вторую очередь наименьшую
длину*/

#include "graf.h"

using namespace std;

int main(int argc, char* argv[])
{
    int status = OK;
    string cityFile;
    string connectionFile;
    city *cityList = new city;
    cityList = nullptr;

    if (argc != 3) {
        cout << "Введите имя файла c городами: ";
        cin >> cityFile;
        cout << "Введите имя файла с дорогами: ";
        cin >> connectionFile;
    } else {
        cityFile = argv[1];
        connectionFile = argv[2];
    }
    ifstream cityes(cityFile);
    ifstream connections(connectionFile);

    if (cityes.is_open() && connections.is_open()) {
        cout << "Все ОК! Оба файла открыты!\n" << endl;
        status = createSityList(cityes, &cityList, status);

        cityes.close();
        connections.close();
    }
    else {
        status = ERR_NO_FILE;
    }

    if (status == OK) {

    } else {
        printStatus(status);
    }

    return 0;
}
