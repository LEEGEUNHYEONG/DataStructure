#pragma once
#ifndef CIRCULARLINKEDLIST_H
#define CIRCULARLINKEDLIST_H

#include "DoubleNode.h"

class CircularDoubleLinkedList
{
public:
	void CircularDoubleLinkedListMain();

private:
	DoubleNode* CDL_CreateNode(ElementType data);
	void CDL_DestroyNode(DoubleNode* dubleNode);
	void CDL_AppendNode(DoubleNode** head, DoubleNode* newNode);
	DoubleNode* CDL_GetNodeAt(DoubleNode* head, int location);
	void CDL_RemoveNode(DoubleNode** head, DoubleNode* removeNode);
	void CDL_InsertAfter(DoubleNode* currentNode, DoubleNode* newNode);
	int CDL_GetNodeCount(DoubleNode* head);
	void printList(DoubleNode* list);
};


#endif // ! CIRCULARLINKEDLIST_H
