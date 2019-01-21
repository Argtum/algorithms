#include "tree.h"

string inp_str;
top_param new_top;

int buildTree(ifstream &inputFile, tree **tree_ptr, int status)
{
    tree *cur_ptr = new tree;
    cur_ptr = nullptr;

    while (getline(inputFile, inp_str) && status == OK) {
        new_top = readStr(inp_str, status);

        tree *new_ptr = new tree;
        new_ptr->name = new_top.topName;
        new_ptr->type = new_top.topType;
        new_ptr->level = new_top.level;
        new_ptr->left = nullptr;
        new_ptr->right = nullptr;
        new_ptr->father = nullptr;
        new_ptr->optionTree = nullptr;

        if (*tree_ptr == nullptr) {
            *tree_ptr = new_ptr;
            //cout << "null " << (*tree_ptr)->name << endl;
            cur_ptr = *tree_ptr;
        } else {
            if (cur_ptr == *tree_ptr) {
                new_ptr->father = cur_ptr;
                cur_ptr->left = new_ptr;
                cur_ptr = new_ptr;
                //cout << "father null " << cur_ptr->name << endl;
            } else {
                while (new_ptr->level < cur_ptr->level) {
                    cur_ptr = cur_ptr->father;
                    //cout << "< " << cur_ptr->name << endl;
                }
                if (new_ptr->level > cur_ptr->level) {
                    new_ptr->father = cur_ptr;
                    cur_ptr->left = new_ptr;
                    cur_ptr = cur_ptr->left;
                    //cout << "> " << cur_ptr->name << endl;
                } else if (new_ptr->level == cur_ptr->level) {
                    new_ptr->father = cur_ptr->father;
                    cur_ptr->right = new_ptr;
                    cur_ptr = cur_ptr->right;
                    //cout << "= " << cur_ptr->name << endl;
                }
            }
        }
    }
    return status;
}

void buildOptionsTree(tree **tree_ptr)
{
    if (*tree_ptr != nullptr) {
        buildOptionsTree(&(*tree_ptr)->left);
        buildOptionsTree(&(*tree_ptr)->right);
        (*tree_ptr)->left = nullptr;
        (*tree_ptr)->right = nullptr;
        insertTopToOptionTree(tree_ptr);
        addOptionTreeToFather(tree_ptr);
        cout << endl;
    }
}

void insertTopToOptionTree(tree **tree_ptr)
{
    tree *cur_ptr = new tree;
    cur_ptr = nullptr;
    tree *prev_ptr = new tree;
    prev_ptr = nullptr;

    if ((*tree_ptr)->optionTree != nullptr) {
        cur_ptr = (*tree_ptr)->optionTree;
        prev_ptr = (*tree_ptr)->optionTree;
        cout << " Now optionsTree_ptr " << cur_ptr->name << endl;
        while (cur_ptr != nullptr) {
            cout << "next optionsTree_ptr " << cur_ptr->name << endl;
            insertLeft(&cur_ptr, tree_ptr);
            cur_ptr = cur_ptr->right;
            if (prev_ptr != cur_ptr) {
                prev_ptr->right = cur_ptr;
                prev_ptr = cur_ptr;
            }
        }
    } else {
       (*tree_ptr)->optionTree = *tree_ptr;
       cout << "insert itself " << (*tree_ptr)->name << endl;
        //возможно сдулать вставкой новой вершины
    }
}

void addOptionTreeToFather(tree **tree_ptr)
{
    if ((*tree_ptr)->father != nullptr) {
        cout << "father is " << (*tree_ptr)->father->name;
        if ((*tree_ptr)->father->optionTree != nullptr) {
            cout << ", type is ";
            if ((*tree_ptr)->father->type == OR) {
                addToOrFather(&(*tree_ptr)->optionTree, &(*tree_ptr)->father->optionTree);
            } else {
                addToAndFather(&(*tree_ptr)->optionTree, &(*tree_ptr)->father->optionTree);
            }
        } else {
            (*tree_ptr)->father->optionTree = (*tree_ptr)->optionTree;
            cout << " - empty, adding " << (*tree_ptr)->optionTree->name << endl;
        }
    }
}

void addToOrFather(tree **options_ptr, tree **fatherOptions_ptr)
{
    tree *cur_ptr = new tree;
    cur_ptr = nullptr;
    tree *prev_ptr = new tree;
    prev_ptr = nullptr;

    cout << "OR" << endl;

    cur_ptr = *fatherOptions_ptr;
    prev_ptr = *fatherOptions_ptr;
    cout << " Now fatherOptionsTree " << cur_ptr->name << endl;
    while (cur_ptr->right != nullptr) {
        cur_ptr = cur_ptr->right;
        cout << "next fatherOptionsTree " << cur_ptr->name << endl;
        if (prev_ptr != cur_ptr) {
            prev_ptr->right = cur_ptr;
            prev_ptr = cur_ptr;
        }
    }
    cur_ptr->right = *options_ptr;
    cout << " Adding top: " << cur_ptr->right->name << endl;
}

void addToAndFather(tree **options_ptr, tree **fatherOptions_ptr)
{
    tree *cur_ptr = new tree;
    cur_ptr = nullptr;
    tree *prev_ptr = new tree;
    prev_ptr = nullptr;

    cout << "AND" << endl;

    cur_ptr = *fatherOptions_ptr;
    prev_ptr = *fatherOptions_ptr;
    cout << " Now fatherOptionsTree " << cur_ptr->name << endl;
    while (cur_ptr != nullptr) {
        cout << " Column start from: " << cur_ptr->name << endl;
        insertLeft(&cur_ptr, options_ptr);
        cur_ptr = cur_ptr->right;
        if (prev_ptr != cur_ptr) {
            prev_ptr->right = cur_ptr;
            prev_ptr = cur_ptr;
        }
    }
}

void insertLeft(tree **insert_ptr, tree **tree_ptr)
{
    tree *left_ptr = new tree;
    left_ptr = nullptr;
    tree *prev_ptr = new tree;
    prev_ptr = nullptr;

    left_ptr = *insert_ptr;
    prev_ptr = *insert_ptr;
    cout << " Now left_ptr " << left_ptr->name << endl;
    while (left_ptr != nullptr) {
        left_ptr = left_ptr->left;
        if (left_ptr != nullptr) {
            cout << " next left_ptr " << left_ptr->name << endl;
        }
        if (prev_ptr != left_ptr) {
            prev_ptr->left = left_ptr;
            prev_ptr = left_ptr;
        }
    }
    left_ptr = *tree_ptr;
    cout << " Adding top: " << left_ptr->name << endl;
}

void printTopLevel(int level)
{
    for (int i = 0; i < level; i++) {
        cout << '*';
    }
}

void printTree(tree **root)
{
    tree *cur_ptr = new tree;
    cur_ptr = nullptr;
    cur_ptr = *root;
    tree *left_ptr = new tree;
    left_ptr = nullptr;

    if (cur_ptr != nullptr) {
        left_ptr = cur_ptr;
        while (left_ptr != nullptr) {
            printTopLevel(left_ptr->level);
            cout << left_ptr->name << endl;
            left_ptr = left_ptr->left;
        }
        cur_ptr = cur_ptr->right;
        cout << endl;
    }
}

void deleteOptionsTree(tree **root)
{
    tree *cur_ptr = new tree;
    cur_ptr = nullptr;
    cur_ptr = *root;
    tree *left_ptr = new tree;
    left_ptr = nullptr;
    tree *next_ptr = new tree;
    next_ptr = nullptr;
    tree *next_left_ptr = new tree;
    next_left_ptr = nullptr;

    if (cur_ptr != nullptr) {
        next_ptr = cur_ptr->right;
        left_ptr = cur_ptr;
        while (left_ptr != nullptr) {
            next_left_ptr = left_ptr->left;
            delete left_ptr;
            left_ptr = next_left_ptr;
        }
        cur_ptr = next_ptr;
        cout << endl;
    }
}

