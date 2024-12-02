/**
 * Nick Galvez
 * 210 lab 36
 */
#include <iostream>
#include <fstream>
#include "StringBinaryTree.h"
using namespace std;

void loadCodes(StringBinaryTree &tree);
void runTests(StringBinaryTree &tree);

int main()
{
    // create a StringBinaryTree object
    StringBinaryTree tree;
    // insert some values
    loadCodes(tree);

    // test
    runTests(tree);

    // display menu
    int choice;
    do
    {
        cout << "1. Add a code" << endl;
        cout << "2. Delete a code" << endl;
        cout << "3. Search for a code" << endl;
        cout << "4. Modify a code";
        cout << "5. List code";
        // cout << "9. Run tests" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();
        switch (choice)
        {
        case 1:
        {
            string code;
            cout << "Enter a code: ";
            getline(cin, code);
            tree.insertNode(code);
            break;
        }
        case 2:
        {
            string code;
            cout << "Enter a code to delete: ";
            getline(cin, code);
            tree.remove(code);
            break;
        }
        case 3:
        {
            string code;
            cout << "Enter a code to search for: ";
            getline(cin, code);
            if (tree.searchNode(code))
            {
                cout << "Code found." << endl;
            }
            else
            {
                cout << "Code not found." << endl;
            }
            break;
        }
        case 4:
            tree.modifyNode("zzrufvqX", "zzzzzzzz");
            break;  
        case 5:
            tree.displayInOrder();
            break;
        case 0:
            break;
        default:
            cout << "Invalid choice." << endl;
        }
    } while (choice !=0);

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
void runTests(StringBinaryTree &tree)
{
    cout <<"Running Tests" << endl << endl;
    if (tree.searchNode("XZYwXoDE")) {
        cout << "Found XZYwXoDE" << endl;
    }else {
        cout << "Search failed" << endl;
    }

    cout << "Modify node" << endl;
    // 2nd to last item, but it's modified to have a value that should be last.
    tree.modifyNode("zzrufvqX", "zzzzzzzzzzzzzz");
    tree.displayInOrder();
}