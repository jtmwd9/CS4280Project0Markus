#ifndef TREE_H
#define TREE_H

#include "node.h"
#include <list>
#include <string>

class Tree {
	public:
		node *root;

		void buildTree(std::string, Tree&);
		void printInorder(Tree, node*, std::string&, int);
		void printPreorder(Tree, node*, std::string&, int);
		void printPostorder(Tree, node*, std::string&, int);

		void addNode (Tree, node *, node *);
};

#endif


