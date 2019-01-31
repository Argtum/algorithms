#include "stek.h"

void push(stek **stek_ptr, tree **top_ptr)
{
    stek *tmp_ptr = new stek;
    tmp_ptr->top = *top_ptr;
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

void pushSan(stek **stek_ptr, tree **san_ptr)
{
    (*stek_ptr)->san = *san_ptr;
}
