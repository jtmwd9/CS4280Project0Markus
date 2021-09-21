#include "node.h"
#include "tree.h"
#include <string>
#include <iostream>

using namespace std;

void Tree::buildTree(string input, Tree &thisTree) {		//takes data and builds a binary tree with it
	string thisWord = "";
	char x;

	node *newNode;
	newNode = new node;

	thisTree.root = NULL;

	for (int i = 0; i < input.length(); i++) {		//separates string into words, adds words to nodes
		x = input[i];
	
		if (x == ' ') {
			newNode = new node;
			newNode->firstLetter = thisWord[0];
			newNode->word = thisWord;
			newNode->right = NULL;
			newNode->left = NULL;
			
			if (thisTree.root == NULL) {		//creates root node or branch node
				thisTree.root = newNode;	
			} else {
				thisTree.addNode(thisTree, thisTree.root, newNode);
			}
			
			thisWord = "";
		} else {
			thisWord += x;
		}
	}

	newNode = new node;
	newNode->firstLetter = thisWord[0];
	newNode->word = thisWord;
	newNode->right = NULL;
	newNode->left = NULL;
			
	if (thisTree.root == NULL) {
		thisTree.root = newNode;	
	} else {
		thisTree.addNode(thisTree, thisTree.root, newNode);
	}

	return;
}

void Tree::addNode (Tree tree, node *oldNode, node *newNode) {	//adds nodes to the tree
	if (oldNode->firstLetter > newNode->firstLetter) {
		if (oldNode->left == NULL) {
			oldNode->left = newNode;
			return;
		} else {
			tree.addNode (tree, oldNode->left, newNode);
		}
	} else if (oldNode->firstLetter == newNode->firstLetter) {
		oldNode->word.append(" " + newNode->word);
		delete newNode;
	} else {
		if (oldNode->right == NULL) {
			oldNode->right = newNode;
			return;
		} else {
			tree.addNode(tree, oldNode->right, newNode);
		}
	}
}

void Tree::printInorder(Tree tree, node* node, string &output, int count) {	//each uses reference string to save node data
	if (node == NULL) {
		return;
	}

	count++;		//keep track of indentations for final output	
	tree.printInorder(tree, node->left, output, count);
	count--;
	
	for(int i = 0; i <= 2 * count; i++) {
		output.append(" ");
	}
	output += node->word[0];
	output.append(": " + node->word + "\n");

	count++;
	tree.printInorder (tree, node->right, output, count);
	count--;
}

void Tree::printPreorder(Tree tree, node* node, string &output, int count) {
	if (node == NULL) {
		return;
	}

	for(int i = 0; i <= 2 * count; i++) {
		output.append(" ");
	}
	output += node->word[0];
	output.append(": " + node->word + "\n");

	count++;
	tree.printPreorder (tree, node->left, output, count);
	count--;
	count++;
	tree.printPreorder (tree, node->right, output, count);
	count--;
}

void Tree::printPostorder(Tree tree, node* node, string &output, int count) {
	if (node == NULL) {
		return;
	}
	count++;
	tree.printPostorder (tree, node->left, output, count);
	count--;
	count++;
	tree.printPostorder (tree, node->right, output,count);
	count--;
	for(int i = 0; i <= 2 * count; i++) {
		output.append(" ");
	}
	output += node->word[0];
	output.append(": " + node->word + "\n");

}
