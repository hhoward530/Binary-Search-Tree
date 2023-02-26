// BinarySearchTree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "BST.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
    BST* myTree = new BST();
    string function;

    while (true)
    {
        cout << "Enter a function: (Type 'help' for list of commands)\n";
        cin >> function;

        if (function == "help")
            myTree->help();
        else if (function == "insert") 
        {
            string addWord;
            cout << "Enter a word:\n";
            cin >> addWord;
            myTree->insert(addWord);
            cout << "\n";
        }
        else if (function == "remove") 
        {
            string removeWord;
            cout << "Enter a word:\n";
            cin >> removeWord;
            myTree->remove(removeWord);
            cout << "\n";
        }
        else if (function == "search") 
        {
            string searchWord;
            cout << "Enter a word:\n";
            cin >> searchWord;
            myTree->search(searchWord);
            searchWord = "";
        }
        else if (function == "min")
            cout << myTree->getMinWord() << "\n\n";
        else if (function == "max")
            cout << myTree->max() << "\n\n";
        else if (function == "list") 
        {
            cout << endl;
            myTree->list();
        }
        else if (function == "prev") 
        {
            string prevWord;
            cout << "Enter a word:\n";
            cin >> prevWord;
            myTree->prev(prevWord);
        }
        else if (function == "child") 
        {
            string childWord;
            cout << "Enter a word:\n";
            cin >> childWord;
            myTree->child(childWord);
        }
        else if (function == "parent") 
        {
            string parentWord;
            cout << "Enter a word:\n";
            cin >> parentWord;
            myTree->parent(parentWord);
        }
        else if (function == "next") 
        {
            string nextWord;
            cout << "Enter a word:\n";
            cin >> nextWord;
            myTree->next(nextWord);
        }
        else if (function == "quit")
            exit(EXIT_SUCCESS);
        else
            cout << "\nNot a valid function.\n\n";
    }
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
