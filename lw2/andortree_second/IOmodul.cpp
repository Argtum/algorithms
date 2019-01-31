#include "IOmodul.h"

void printStatus(int status)
{
    switch (status) {
        case ERR_SYMBOL:
            cout << "название вершины должно быть в пределах A..Z или a..z, уровень дерева обозначаеться *" << endl << endl;
        break;
        case ERR_NO_FILE:
            cout << "Файл не открыт!" << endl << endl;
        break;
        default:
            cout << "неизвестная ошибка" << endl << endl;
    }
}

top_param readStr(string inp_str, int status)
{
    top_param top_stats;
    top_stats.level = 0;

    int str_size;
    str_size = inp_str.length();

    for (int i = 0; i < str_size && status == OK; i++) {
        if (strchr(accessSymbol, inp_str[i])) {
            top_stats.level = i;
            if (strchr(ar_and, inp_str[i])) {
                top_stats.topType = AND;
                top_stats.topName = inp_str[i];
            } else if (strchr(ar_or, inp_str[i])) {
                top_stats.topType = OR;
                top_stats.topName = inp_str[i];
            }
        } else {
            status = ERR_SYMBOL;
        }
    }

    return top_stats;
}

void printTopLevel(int level)
{
    for (int i = 0; i < level; i++) {
        cout << '*';
    }
}
