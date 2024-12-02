/**
 * Nick Galvez
 * 210 lab 36
 */
#include <iostream>
#include <fstream>
#include "StringBinaryTree.h"
using namespace std;

void loadCodes(StringBinaryTree &tree);

int main()
{
    // create a StringBinaryTree object
    StringBinaryTree tree;
    // insert some values
    loadCodes(tree);

    return 0;
}

/**
 * Load codes from a file.
 */
void loadCodes(StringBinaryTree &tree)
{
    // load codes.txt
    ifstream file("codes.txt");
    if (file.is_open())
    {
        string line;
        while (getline(file, line))
        {
            // add to the tree.
            tree.insertNode(line);
        }
        file.close();
    }
}