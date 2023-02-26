#include "BST.h"
#include <iostream>
#include <string>

BST::BST()
{
    root = NULL;
}

BST::~BST()
{

}

/*
Insert
*/
void BST::insert(string word)
{
    node* y = NULL;
    node* x = root;

    while (x != NULL)
    {
        y = x;
        if (word < x->word)
            x = x->leftChild;
        else
            x = x->rightChild;
    }

    node* z = new node;				//create node and initialize
    z->leftChild = NULL;
    z->rightChild = NULL;
    z->parent = NULL;
    z->word = word;

    z->parent = y;
    if (y == NULL)
        root = z;
    else if (z->word < y->word)
        y->leftChild = z;
    else
        y->rightChild = z;
}

/*
Remove
*/
void BST::remove(string word)
{
    node* x = root;
    node* y = root;

    while (x != NULL)
    {
        if (x->word == word)
        {
            break;
        }
        x = word < x->word ? x->leftChild : x->rightChild;
    }

    if (x->leftChild == NULL)
        transplant(x, x->rightChild);
    else if (x->rightChild == NULL)
        transplant(x, x->leftChild);
    else
    {
        y = min(x->rightChild);
        if (y->parent != x)
        {
            transplant(y, y->rightChild);
            y->rightChild = x->rightChild;
            y->rightChild->parent = y;
        }
        transplant(x, y);
        y->leftChild = x->leftChild;
        y->leftChild->parent = y;
        root = y;
    }

}

int BST::search(string word)		//This function searches for a word
{									//in the tree and gives its count
    node* x = root;

    while (x != NULL) {
        if (x->word == word) {
            cout << word << "\n\n";
            return 1;
        }
        x = word < x->word ? x->leftChild : x->rightChild;
    }
    cout << word << " 0\n\n";
    return 0;
}

BST::node* BST::min(node* x)		//This function gives the minimum 
{						//value in the tree
    while (x->leftChild != NULL)
        x = x->leftChild;
    return x;
}

string BST::getMinWord()
{
    if (root == NULL) {
        cout << endl;
        return " ";
    }
    node* x = min(root);
    string minWord = x->word;
    return minWord;
}

string BST::max()		//This function gives the maximum
{						//value in the tree
    node* x = root;
    if (root == NULL) 
    {
        cout << endl;
        return " ";
    }
    while (x->rightChild != NULL) 
    {
            x = x->rightChild;
    }
    return x->word;
}

string BST::child(string word)		//this function finds
{									//a nodes children
    node* x = root;

    while (x != NULL) {
        if (x->word == word) {
            node* y = x->leftChild;
            node* z = x->rightChild;

            if (y == NULL) {
                cout << "NULL, ";
            }
            else cout << y->word << ", ";

            if (z == NULL) {
                cout << "NULL\n\n";
            }
            else cout << z->word << "\n\n";

            return word;
        }
        x = word < x->word ? x->leftChild : x->rightChild;
    }
    cout << word << " was not found.\n\n";
    return word;
}

string BST::parent(string word)		//this function finds 
{									//the parent of a node
    node* x = root;

    while (x != NULL) {
        if (x->word == word) {
            node* y = x->parent;
            if (y != NULL) {
                cout << y->word << "\n\n";
                return y->word;
            }
            else {
                cout << "\n\n";
                return word;
            }
        }
        x = word < x->word ? x->leftChild : x->rightChild;
    }
    cout << word << " was not found.\n\n";
    return word;
}
string BST::prev(string word)		//this function finds the 
{									//predecessor of a desired word
    node* x = root;

    while (x != NULL) {
        if (x->word == word) {				//if we find the word
            if (x->leftChild != NULL) {		// if there is a leftChild; min of x->leftChild

                x = x->leftChild;
                node* y = NULL;

                while (x != NULL) {
                    y = x;
                    x = x->rightChild;
                }
                cout << y->word << "\n\n";
                return y->word;
            }

            else if (word == getMinWord()) {
                cout << word << "\n\n";
                return word;
            }

            else {
                node* y = x->parent;
                while (y != NULL && x == y->leftChild) {
                    x = y;
                    y = y->parent;
                }
                cout << y->word << "\n\n";
                return y->word;
            }
        }
        x = word < x->word ? x->leftChild : x->rightChild;
    }
    cout << word << " was not found.\n\n";
    return word;
}

string BST::next(string word)	//This function finds the 
{								//successor of a desired word
    node* x = root;

    while (x != NULL) {
        if (x->word == word) {	//if we find the word


            if (x->rightChild != NULL) {	// if there is a rightChild; min of x->rightChild
                x = x->rightChild;
                node* y = NULL;

                while (x != NULL) {
                    y = x;
                    x = x->leftChild;
                }
                cout << y->word << "\n\n";
                return y->word;
            }

            else if (word == max()) {
                cout << word << "\n\n";
                return word;
            }

            else {
                node* y = x->parent;
                while (y != NULL && x == y->rightChild) {
                    x = y;
                    y = y->parent;
                }
                cout << y->word << "\n\n";
                return y->word;
            }

        }
        x = word < x->word ? x->leftChild : x->rightChild;
    }
    cout << word << " was not found.\n\n";
    return word;

}

void BST::help()
{
    cout << "\n'insert' to insert a word into the tree.\n";
    cout << "'delete' to delete a word from the tree.\n";
    cout << "'search' to search for a word in the tree.\n";
    cout << "'next' to see what comes after a word.\n";
    cout << "'prev' to see what comes before a word\n";
    cout << "'parent' to see a node's parent node.\n";
    cout << "'child' to see a node's children nodes.\n";
    cout << "''min' to see the minimum value in the tree.\n";
    cout << "'max' to see the maximum value in the tree.\n";
    cout << "'quit' to quit out of program.\n\n";
}

void BST::list()
{
    traversal(root);
    cout << "\n\n";
}