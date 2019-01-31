#include "tree.h"

int buildTree(ifstream &inputFile, tree **tree_ptr, int status)
{
    string inp_str;
    top_param new_top;
    tree *cur_ptr = new tree;
    cur_ptr = nullptr;

    while (getline(inputFile, inp_str) && status == OK) {
        new_top = readStr(inp_str, status);

        tree *new_ptr = new tree;
        new_ptr->name = new_top.topName;
        new_ptr->type = new_top.topType;
        new_ptr->level = new_top.level;
        new_ptr->ban = NO;
        new_ptr->read = NO;
        new_ptr->left = nullptr;
        new_ptr->right = nullptr;
        new_ptr->father = nullptr;

        if (*tree_ptr == nullptr) {
            *tree_ptr = new_ptr;
            cur_ptr = *tree_ptr;
        } else {
            if (cur_ptr == *tree_ptr) {
                new_ptr->father = cur_ptr;
                cur_ptr->left = new_ptr;
                cur_ptr = new_ptr;
            } else {
                while (new_ptr->level < cur_ptr->level) {
                    cur_ptr = cur_ptr->father;
                }
                if (new_ptr->level > cur_ptr->level) {
                    new_ptr->father = cur_ptr;
                    cur_ptr->left = new_ptr;
                    cur_ptr = cur_ptr->left;
                } else if (new_ptr->level == cur_ptr->level) {
                    new_ptr->father = cur_ptr->father;
                    cur_ptr->right = new_ptr;
                    cur_ptr = cur_ptr->right;
                }
            }
        }
    }
    return status;
}

void processingBinaryTree(tree **root)
{
    stek *stek_top = new stek;
    stek_top = nullptr;
    tree *tree_ptr = new tree;
    tree_ptr = nullptr;
    tree_ptr = *root;
    bool ignoreStek = YES;

    do {
        setBans(&tree_ptr, &stek_top, ignoreStek);
        printTree(root);
        while (stek_top && !checkNextSan(&stek_top->san)) {
            clearRead(&stek_top);
            pop(&stek_top);
        }
        ignoreStek = NO;
        cout << endl;
    } while (stek_top);

}

void clearRead(stek **stek_ptr)
{
    tree *san_ptr = new tree;
    san_ptr = (*stek_ptr)->top->left;

    while (san_ptr) {
        san_ptr->read = NO;
        san_ptr = san_ptr->right;
    }
}

bool checkNextSan(tree **sun_ptr)
{
    bool isSon = NO;

    if ((*sun_ptr)->right) {
        isSon = YES;
    }

    return isSon;
}

void changeSan(stek **stek_top)
{
    tree *san_ptr = new tree;
    san_ptr = (*stek_top)->san;
    san_ptr->ban = NO;
    san_ptr->read = YES;
    san_ptr = san_ptr->right;
    san_ptr->ban = YES;
    pushSan(stek_top, &san_ptr);
}

bool setBans(tree **tree_ptr, stek **stek_top, bool ignoreStek)
{
    if (*tree_ptr) {
        if ((*tree_ptr)->type == OR) {
            if (ignoreStek) {
                pushOrToStek(tree_ptr, stek_top);
            } else {
                if (*tree_ptr == (*stek_top)->top) {
                    ignoreStek = YES;
                    changeSan(stek_top);
                }
            }
        }
        ignoreStek = setBans(&(*tree_ptr)->left, stek_top, ignoreStek);
        if (!(*tree_ptr)->ban) {
            ignoreStek = setBans(&(*tree_ptr)->right, stek_top, ignoreStek);
        }
    }

    return ignoreStek;
}

void pushOrToStek(tree **tree_ptr, stek **stek_top)
{
    push(stek_top, tree_ptr);
    (*tree_ptr)->left->ban = YES;
    pushSan(stek_top, &(*tree_ptr)->left);
}

void printStek(stek **stek_top)
{
    stek *stek_ptr = new stek;
    stek_ptr = *stek_top;

    while (stek_ptr) {
        cout << stek_ptr->top->name << stek_ptr->san->name << endl;
        stek_ptr = stek_ptr->next;
    }
}

void deleteStek(stek **stek_top)
{
    stek *stek_ptr = new stek;
    stek_ptr = *stek_top;

    while (stek_ptr) {
        stek_ptr = stek_ptr->next;
        delete *stek_top;
        *stek_top = stek_ptr;
    }
}

void printTree(tree **root)
{
    tree *tree_ptr = new tree;
    tree_ptr = nullptr;
    tree_ptr = *root;

    if (tree_ptr) {
        if (tree_ptr->read != YES) {
            printTopLevel(tree_ptr->level);
            cout << tree_ptr->name << endl;
        }
        printTree(&tree_ptr->left);
        if (!tree_ptr->ban) {
            printTree(&tree_ptr->right);
        }
    }
}

void deleteOptionsTree(tree **root)
{
    tree *tree_ptr = new tree;
    tree_ptr = nullptr;
    tree_ptr = *root;

    if (tree_ptr) {
        deleteOptionsTree(&tree_ptr->left);
        deleteOptionsTree(&tree_ptr->right);
        delete tree_ptr;
    }
}

