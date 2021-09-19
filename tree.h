#ifndef TREE_H
#define TREE_H

#include "node.h"
#include <list>
#include <string>

class Tree {
	public:
		std::list<node> branches;
		void buildTree(std::string);
		void printInorder();
		void printPreorder();
		void printPostorder();
};

#endif
