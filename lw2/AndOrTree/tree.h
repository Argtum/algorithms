#ifndef ALG_LW2_TREE_H
#define ALG_LW2_TREE_H

#include "IOmodul.h"

struct tree
{
    char name;
    bool type;
    int level;
    tree *father;
    tree *left;
    tree *right;
    tree *optionTree;
};

int buildTree(ifstream &inputFile, tree **tree_ptr, int status);
void buildOptionsTree(tree **tree_ptr);
void insertTopToOptionTree(tree **tree_ptr);
void temp(tree **opt_tree, char topName);
void addOptionTreeToFather(tree **tree_ptr);
void addToOrFather(tree **tree_ptr, tree **fatherOptions_ptr);
void addToAndFather(tree **options_ptr, tree **fatherOptions_ptr);
void insertLeft(tree **fatherOptions_ptr, tree **opt_tree);
void printTopLevel(int level);
void printTree(tree **root);
void deleteOptionsTree(tree **root);

#endif //ALG_LW2_TREE_H
