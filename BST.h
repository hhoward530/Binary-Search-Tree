#pragma once
#include <iostream>
#include <string>
using namespace std;

class BST {


private:
	struct node
	{
		string word;
		node* leftChild = NULL;
		node* rightChild = NULL;
		node* parent = NULL;
	};
	node* root = NULL;

	void traversal(node* x) {
		if (x->leftChild != NULL)
			traversal(x->leftChild);
		cout << x->word << endl;;
		if (x->rightChild != NULL)
			traversal(x->rightChild);
	}

	void transplant(node* x, node* y)
	{
		if (x->parent == NULL)
			root = y;
		else if (x == x->parent->leftChild)
			x->parent->leftChild = y;
		else
			x->parent->rightChild = y;

		if (y != NULL)
			y->parent = x->parent;
	}


public:

	BST();
	~BST();

	void insert(string word);
	void remove(string word);
	int search(string word);
	string next(string word);
	string prev(string word);
	string parent(string word);
	string child(string word);
	node* min(node* x);
	string getMinWord();
	string max();
	void list();
	void help();

};