#ifndef BASICTREE_H
#define BASICTREE_H

#include "base.h"

typedef int NodeData;

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
#endif // ! BASICTREE_H
