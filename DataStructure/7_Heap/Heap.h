#pragma once
#ifndef HEAP_H
#define HEAP_H

#include <vector>
#include "main.h"

typedef int Data;

typedef struct HNode
{
	Data data;
};

typedef struct Heap
{
	//HNode* node;
	vector<HNode> *node = new vector<HNode>;
	int size;
	int count;
};

class HeapMain
{
public:
	HeapMain();
private :
	Heap* create(int size);
	void destroy(Heap* heap);
	void insert(Heap* heap, Data newData);
	void deleteMin(Heap* heap, HNode* root);
	int getParent(int index);
	int getLeftChild(int index);
	void swapNode(Heap* heap, int index1, int index2);
	void printNode(Heap* heap);

};

#endif // !HEAP_H