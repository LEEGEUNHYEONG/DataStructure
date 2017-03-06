#pragma once
#include "main.h"

typedef int Data;

typedef struct BSTNode
{
	struct BSTNode* left;
	struct BSTNode* right;
	Data data;
}BSTNode;

class BinarySearchTree
{	
public:
	BinarySearchTree();	
private :
	BSTNode* createNode(Data data);
	void destroyNode(BSTNode* node);
	void destroyTree(BSTNode* tree);
	BSTNode* searchNode(BSTNode* tree, Data target);
	BSTNode* searchMinNode(BSTNode* tree);
	void insertNode(BSTNode* tree, BSTNode *child);
	BSTNode* removeNode(BSTNode* tree, BSTNode* parent, Data target);
	void inorderPrinter(BSTNode* tree);
};

