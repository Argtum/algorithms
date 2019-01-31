#ifndef ALG_LW2_TREE_H
#define ALG_LW2_TREE_H

#include "IOmodul.h"
#include "stek.h"

int buildTree(ifstream &inputFile, tree **tree_ptr, int status);
void processingBinaryTree(tree **tree_ptr);
bool setBans(tree **tree_ptr, stek **stek_top, bool ignoreStek);
void pushOrToStek(tree **tree_ptr, stek **stek_top);
bool checkNextSan(tree **stek_top);
void clearRead(stek **stek_ptr);
void changeSan(stek **stek_top);

void printStek(stek **stek_top);
void deleteStek(stek **stek_top);

void printTree(tree **root);
void deleteOptionsTree(tree **root);

#endif //ALG_LW2_TREE_H
