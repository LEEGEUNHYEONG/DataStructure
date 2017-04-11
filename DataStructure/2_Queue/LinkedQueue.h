#pragma once

#include "base.h"

typedef int ElementType;

typedef struct Lnode
{
	ElementType data;
	struct Lnode* nextNode;
}Lnode;

typedef struct LQueue
{
	Lnode* front;
	Lnode* rear;
	int count;
}Lqueue;

class LinkedQueue
{
public:
	LinkedQueue();	
private:
	void createQueue(Lqueue** queue);
	void destroyQueue(Lqueue* queue);
	Lnode* createNode(ElementType data);
	void destroyNode(Lnode* node);
	void enqueue(Lqueue* queue, Lnode* node);
	Lnode* dequeue(Lqueue* queue);
	int isEmpty(Lqueue* queue);
};
