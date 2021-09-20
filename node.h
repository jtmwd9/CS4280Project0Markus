#ifndef NODE_H
#define NODE_H
#include <string>

struct node {
	char firstLetter;
	std::string word;
	node* left = NULL;
	node* right = NULL;
};

#endif
