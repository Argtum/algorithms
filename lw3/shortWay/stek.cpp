#include "stek.h"

void push(stek **stek_ptr, int index, int dist, bool hazar)
{
    stek *tmp_ptr = new stek;
    tmp_ptr->index = index;
    tmp_ptr->length = dist;
    tmp_ptr->emerg = hazar;
    tmp_ptr->next = *stek_ptr;
    *stek_ptr = tmp_ptr;
}

void pop(stek **stek_ptr)
{
    stek *tmp_ptr = new stek;
    tmp_ptr = *stek_ptr;
    *stek_ptr = (*stek_ptr)->next;
    delete tmp_ptr;
}

void printStek(stek **stek_ptr)
{
    cout << (*stek_ptr)->index;
    *stek_ptr = (*stek_ptr)->next;
}
