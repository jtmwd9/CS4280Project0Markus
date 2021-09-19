#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

string readFromInput () {
	string input;
	
	cout << "Enter a string\n";
	cin.ignore();
	getline(cin, input);
	
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
	
	cout << input;

	return 0;
}
