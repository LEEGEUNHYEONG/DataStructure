#pragma once

#include "base.h"

typedef int ElementType;

typedef struct Cnode
{
	ElementType data;
}Cnode;

typedef struct Cqueue
{
	int size;
	int front;
	int rear;
	Cnode* node;
}Cqueue;

class CircleQueue
{
public:
	CircleQueue();	
private:
	void createQueue(Cqueue** queue, int size);
	void destroyQueue(Cqueue* queue);
	void enqueue(Cqueue* queue, ElementType data);
	ElementType dequeue(Cqueue* queue);
	int getSize(Cqueue* queue);
	int isEmpty(Cqueue* queue);
	int isFull(Cqueue* queue);
};
