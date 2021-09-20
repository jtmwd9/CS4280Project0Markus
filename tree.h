#ifndef TREE_H
#define TREE_H

#include "node.h"
#include <list>
#include <string>

class Tree {
	public:
		node *root;

		void buildTree(std::string, Tree&);
		void printInorder(node*);
		void printPreorder(node*);
		void printPostorder(node*);

		void addNode (node *, node *);
};

#endif


