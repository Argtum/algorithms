#ifndef STEK_H
#define STEK_H

#include "IOmodul.h"

struct stek
{
    int index;
    int length;
    bool emerg;
    stek *next;
};

void push(stek **stek_ptr, int index, int dist, bool hazar);
void pop(stek **stek_ptr);

#endif //STEK_H
