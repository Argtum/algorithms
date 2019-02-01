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
    string cityFile;
    string roadFile;
    city *cityList = new city;
    cityList = nullptr;
    roadValue matrix[100][100];
    int matrixSize;

    if (argc != 3) {
        cout << "Введите имя файла c городами: ";
        cin >> cityFile;
        cout << "Введите имя файла с дорогами: ";
        cin >> roadFile;
    } else {
        cityFile = argv[1];
        roadFile = argv[2];
    }
    ifstream cityes(cityFile);
    ifstream roads(roadFile);

    if (cityes.is_open() && roads.is_open()) {
        cout << "Все ОК! Оба файла открыты!\n" << endl;

        matrixSize = createSityList(cityes, &cityList);
        if (matrixSize) {
            string inp_str;
            roadParam new_roads;

            while (getline(roads, inp_str)) {
                new_roads = readRoads(inp_str);
                matrix[new_roads.src - 1][new_roads.dest - 1] = new_roads.value;
            }

            for(int j = 0; j < matrixSize; j++){
                for(int i = 0; i < matrixSize; i++){
                    cout << matrix[i][j].dist << " ";
                }
                cout << endl;
            }
        } else {
            cout << "ОШИБКА! Нулевая матрица, нет городов" << endl << endl;
        }

        cityes.close();
        roads.close();
    }
    else {
        cout << "ОШИБКА! Неправильно указан фаил" << endl << endl;
    }

    return 0;
}
