/*Серебряков Алексей. Задача №18
Имеется И-ИЛИ дерево, соответствующее некоторому
множеству конструкций. Требуется выдать на экран в наглядном
виде все элементы дерева*/

#include "tree.h"

tree *root = new tree;

int main(int argc, char* argv[])
{
    int status = OK;
    string path;
    root = nullptr;

    if (argc != 2) {
        cout << "Введите имя файла: ";
        cin >> path;
    } else {
        path = argv[1];
    }
    ifstream inputFile(path);

    if (inputFile.is_open()) {
        cout << "Все ОК! Файл открыт!\n" << endl;
        status = buildTree(inputFile, &root, status);
        inputFile.close();
    } else {
        status = ERR_NO_FILE;
    }

    if (status == OK) {
        processingBinaryTree(&root);
    } else {
        printStatus(status);
    }

    deleteOptionsTree(&root);

    return 0;
}
