#include <iostream>
#include <string.h>
#include <fstream>
#include "tree.h"

using namespace std;

string readFromInput () {
	string input;
	
	cout << "Enter a string\n";
	getline(cin, input);
	cout << "getline";	
	return input;
}

string readFromFile (string fileName) {
	string input;
	string line;
	ifstream myFile;
	myFile.open(fileName.c_str());
	
	if (myFile.is_open()) {
		while (getline (myFile, line)) {
			input.append(line);
		}
		myFile.close();
	}

	return input;	
}

int main (int argc, char* argv[]) {
	string input;

	if (argc > 1) {
		input = readFromFile(argv[1]);
	} else {
		input = readFromInput();
	}
	cout << "here?";
	cout << input;

	Tree thisTree;

	thisTree.buildTree(input, thisTree);
	
	cout << "In order:";
//	thisTree.printInorder(thisTree.root);
	cout << "\n";

	cout << "Pre order:";
//	thisTree.printPreorder(thisTree.root);
	cout << "\n";

	cout << "Post order:";
//	thisTree.printPostorder(thisTree.root);
	cout <<"\n";

	return 0;
}
