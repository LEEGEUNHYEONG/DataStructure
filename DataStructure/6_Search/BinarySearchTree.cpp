#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree()
{	
	BSTNode* tree = createNode(123);
	BSTNode* node = NULL;

	insertNode(tree, createNode(22));
	insertNode(tree, createNode(9918));
	insertNode(tree, createNode(424));
	insertNode(tree, createNode(17));
	insertNode(tree, createNode(3));

	insertNode(tree, createNode(98));
	insertNode(tree, createNode(34));

	insertNode(tree, createNode(760));
	insertNode(tree, createNode(317));
	insertNode(tree, createNode(1));

	inorderPrinter(tree);
	cout << endl;

	cout << "Remove 98 ..." << endl;
	node = removeNode(tree, NULL, 98);
	destroyNode(node);

	inorderPrinter(tree);
	cout << endl;

	cout << "Insert 111 ... " << endl;
	insertNode(tree, createNode(111));

	inorderPrinter(tree);
	cout << endl;

	destroyTree(tree);
}

BSTNode * BinarySearchTree::createNode(Data data)
{
	BSTNode *newNode = new BSTNode();
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->data = data;

	return newNode;
}

void BinarySearchTree::destroyNode(BSTNode * node)
{
	free(node);
}

void BinarySearchTree::destroyTree(BSTNode * tree)
{
	if (tree->right != NULL)
	{
		destroyNode(tree->right);
	}
	if (tree->left != NULL)
	{
		destroyNode(tree->left);
	}
	tree->right = NULL;
	tree->left = NULL;

	destroyNode(tree);
}

BSTNode * BinarySearchTree::searchNode(BSTNode * tree, Data target)
{
	if (tree == NULL)
	{
		return NULL;
	}

	if(tree->data < target)
	{
		return searchNode(tree->left, target);
	}
	else if (tree->data > target)
	{
		return searchNode(tree->right, target);
	}
	else
	{
		return NULL;
	}
}

BSTNode * BinarySearchTree::searchMinNode(BSTNode * tree)
{
	if (tree == NULL)
	{
		return NULL;
	}

	if (tree->left == NULL)
	{
		return tree;
	}
	else
	{
		return searchMinNode(tree->left);
	}
}

void BinarySearchTree::insertNode(BSTNode * tree, BSTNode * child)
{
	if (tree->data < child->data)
	{
		if (tree->right == NULL)
		{
			tree->right = child;
		}
		else
		{
			insertNode(tree->right, child);
		}
	}
	else if (tree->data > child->data)
	{
		if (tree->left == NULL)
		{
			tree->left = child;
		}
		else
		{
			insertNode(tree->left, child);
		}
	}
}

BSTNode* BinarySearchTree::removeNode(BSTNode * tree, BSTNode * parent, Data target)
{
	BSTNode* removed = NULL;

	if (tree == NULL)
	{
		return NULL;
	}

	if (tree->data > target)
	{
		removed = removeNode(tree->left, tree, target);
	}
	else if (tree->data < target)
	{
		removed = removeNode(tree->right, tree, target);
	}
	else
	{
		removed = tree;

		if (tree->left == NULL && tree->right == NULL)
		{
			if (parent->left == tree)
			{
				parent->left = NULL;
			}
			else
			{
				parent->right = NULL;
			}
		}
		else
		{
			if (tree->left != NULL && tree->right != NULL)
			{
				BSTNode* minNode = searchMinNode(tree->right);
				minNode = removeNode(tree, NULL, minNode->data);
				tree->data = minNode->data;
			}
			else
			{
				BSTNode* temp = NULL;
				if (tree->left != NULL)
				{
					temp = tree->left;
				}
				else
				{
					temp = tree->right;
				}

				if (parent->left == tree)
				{
					parent->left = temp;
				}
				else
				{
					parent->right = temp;
				}
			}
		}
	}
	return removed;
}

void BinarySearchTree::inorderPrinter(BSTNode * tree)
{
	if (tree == NULL)
	{
		return;
	}

	inorderPrinter(tree->left);

	cout << tree->data << " ";

	inorderPrinter(tree->right);
}

