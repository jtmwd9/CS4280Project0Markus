#include "node.h"
#include "tree.h"
#include <string>

using namespace std;

void buildTree(string input) {
	Tree thisTree;
	string thisWord = "";
	string x;
	node token;
	for (int i = 0; i < input.size(); i++) {
		x = input[i];
		if (x == " ") {
			token.firstLetter = thisWord[0];
			token.word = thisWord;
		} else {
			thisWord.append(x);
		}
	}	
}

void printInorder() {

}

void printPreorder() {

}

void printPostorder() {

}
