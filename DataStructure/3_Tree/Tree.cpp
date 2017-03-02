#include "BasicTree.h"

BasicTree::BasicTree()
{
	cout << "Basic Tree" << endl;
}

LRNode * BasicTree::createNode(NodeData data)
{
	LRNode* newNode = (LRNode*)malloc(sizeof(LRNode));
	newNode->data = data;
	newNode->leftChild = NULL;
	newNode->rightChild = NULL;

	return newNode;
}

void BasicTree::destroyNode(LRNode* node)
{
	free(node);
}

void BasicTree::destoryTree(LRNode * tree)
{
	if (tree->rightChild != NULL)
	{
		destoryTree(tree->rightChild);
	}

	if (tree->leftChild != NULL)
	{
		destoryTree(tree->leftChild);
	}

	tree->leftChild = NULL;
	tree->rightChild = NULL;

	destroyNode(tree);
}

void BasicTree::addChildNode(LRNode * parent, LRNode* child)
{
	if (parent->leftChild == NULL)
	{
		parent->leftChild = child;
	}
	else
	{
		LRNode* tempNode = parent->leftChild;
		while (tempNode->rightChild != NULL)
		{
			tempNode = tempNode->rightChild;
		}
		tempNode->rightChild = child;
	}
}

void BasicTree::print(LRNode * tree, int depth)
{
	for (int i = 0; i < depth; i++)
	{
		cout << " ";
	}
	cout << tree->data;

	if (tree->leftChild != NULL)
	{
		print(tree->leftChild, depth+1);
	}
	if (tree->rightChild != NULL)
	{
		print(tree->rightChild, depth);
	}
}

