#ifndef ALG_LW2_STEK_H
#define ALG_LW2_STEK_H

struct tree
{
    char name;
    bool type;
    int level;
    bool ban;
    bool read;
    tree *father;
    tree *left;
    tree *right;
};

struct stek
{
    tree *top;
    tree *san;
    stek *next;
};

void push(stek **stek_ptr, tree **top_ptr);
void pop(stek **stek_ptr);
void pushSan(stek **stek_ptr, tree **san_ptr);
tree popSan(stek **stek_ptr);

#endif //ALG_LW2_STEK_H
