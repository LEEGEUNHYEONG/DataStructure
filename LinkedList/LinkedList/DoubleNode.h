#pragma once
#ifndef DOUBLENODE_H
#define DOUBLENODE_H

typedef int ElementType;

typedef struct doubleTagNode
{
	ElementType Data;
	struct doubleTagNode* nextNode;
	struct doubleTagNode* prevNode;
} DoubleNode;

#endif // !DOUBLENODE_H
