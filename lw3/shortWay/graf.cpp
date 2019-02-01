#include "graf.h"

int createSityList(ifstream &cityes, city **sityList, int status)
{
    string inp_str;
    cityParam new_city;

    while (getline(cityes, inp_str) && status == OK) {
        new_city = readStr(inp_str, status);

        city *city_ptr = new city;
        city_ptr->name = new_city.name;
        city_ptr->index = new_city.index;
        city_ptr->next = nullptr;
        city_ptr->connectTo = nullptr;
    }

    return status;
}
