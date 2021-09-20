#include "node.h"
#include "tree.h"
#include <string>
#include <iostream>

using namespace std;

void Tree::buildTree(string input, Tree &thisTree) {
	string thisWord = "", tester;
	char x;
	int index = input.find(" ");
	node *newNode;
	newNode = new node;
	cout << "initializations";
	thisWord = input.substr(0, index);
	newNode->word = thisWord;
	newNode->firstLetter = thisWord[0];
	thisTree.root = newNode;
	thisWord = "";
	cout << "!";
	cin >> tester;
	for (int i = index + 1; i < input.length(); i++) {
		x = input[i];
		if (x == ' ') {
			newNode->firstLetter = thisWord[0];
			newNode->word = thisWord;
			cout << thisWord;
			thisTree.addNode (thisTree.root, newNode);
			thisWord = "";
		} else {
			thisWord += x;
		}
	}
	cout << "branches for loop";
	cin >> tester;	
	return;
}

void Tree::addNode (node *oldNode, node *newNode) {
	string tester;
	cout << "addNode";
	cin >> tester;
	if (newNode->firstLetter < oldNode->firstLetter) {
		if (oldNode->left == NULL) {
			oldNode->left = newNode;
			return;
		} else {
			addNode(oldNode->left, newNode);
		}
	} else {
		if (oldNode->right == NULL) {
			oldNode->right = newNode;
			return;
		} else {
			addNode(oldNode->right, newNode);
		}
	}
}

void Tree::printInorder(node* node) {
	if (node == NULL) {
		return;
	}
	
	printInorder(node->left);

	cout << node->word << " ";

	printInorder (node->right);
}

void Tree::printPreorder(node* node) {
	if (node == NULL) {
		return;
	}

	cout << node->word << " ";

	printPreorder (node->left);

	printPreorder (node->right);
}

void Tree::printPostorder(node* node) {
	if (node == NULL) {
		return;
	}

	printPostorder (node->left);

	printPostorder (node->right);

	cout << node->word << " ";
}
