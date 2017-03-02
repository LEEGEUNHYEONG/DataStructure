#ifndef BASICTREE_H
#define BASICTREE_H

#include "base.h"

typedef char NodeData;

typedef struct LRNode
{
	struct LRNode* leftChild;
	struct LRNode* rightChild;
	NodeData data;
};

class BasicTree
{
public:
	BasicTree();
private:
	LRNode* createNode(NodeData data);
	void destroyNode(LRNode* node);
	void destoryTree(LRNode* tree);
	void addChildNode(LRNode* parent, LRNode* child);
	void print(LRNode* tree, int depth);

};

class BinaryTree
{
public :
	BinaryTree();
private:
	LRNode* createNode(NodeData nodeData);
	void destroyNode(LRNode* node);
	void destroyTree(LRNode* root);
	void preorder(LRNode* node);
	void inorder(LRNode* node);
	void postorder(LRNode* node);
};
#endif // ! BASICTREE_H
