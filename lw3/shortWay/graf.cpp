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
