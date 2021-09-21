/*
JamesMarkus
CS 4280 Project 0

generate and parse a binary tree from input or file data
 */

#include <iostream>
#include <string.h>
#include <fstream>
#include "tree.h"

using namespace std;

string readFromInput () {				//both readFrom function gather data
	string input;
	
	cout << "Enter a string\n";
	getline(cin, input);

	return input;
}

string readFromFile (string fileName) {
	fileName.append(".fl2021");
	string input;
	string line;
	ifstream myFile;
	myFile.open(fileName.c_str());
	
	if (myFile.is_open()) {
		while (getline (myFile, line)) {
			input.append(line + " ");
		}
		myFile.close();
	}

	return input;	
}

int main (int argc, char* argv[]) {
	string input, outputName, output = "";

	if (argc > 1) {
		input = readFromFile(argv[1]);
		outputName = argv[1];
	} else {
		input = readFromInput();
		outputName = "output";
	}						//output tree files
	string outputName2 = outputName;
	string outputName3 = outputName;
	outputName.append(".inorder");
	outputName2.append(".preorder");
	outputName3.append(".postorder");
	ofstream myFile1, myFile2, myFile3;
	myFile1.open(outputName.c_str());
	myFile2.open(outputName2.c_str());
	myFile3.open(outputName3.c_str());

	Tree thisTree;

	thisTree.buildTree(input, thisTree);
	
	thisTree.printInorder(thisTree, thisTree.root, output, 0);
	myFile1 << output;
	myFile1.close();
	output = "";

	thisTree.printPreorder(thisTree, thisTree.root, output, 0);
	myFile2 << output;
	myFile2.close();
	output= "";

	thisTree.printPostorder(thisTree, thisTree.root, output, 0);
	myFile3 << output;
	myFile3.close();
	output = "";

	return 0;
}
