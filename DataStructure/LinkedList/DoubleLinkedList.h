#ifndef DoubleLinkedList_H
#define DoubleLinkedList_H

#include "DoubleNode.h"
/*
typedef int ElementType;

typedef struct doubleTagNode
{
	ElementType Data;
	struct doubleTagNode* nextNode;
	struct doubleTagNode* prevNode;
} DoubleNode;
*/


class DoubleLinkedList
{
public : 
	void DoubleLinkedListMain();	
	
private :
	DoubleNode* DLL_CreateNode(ElementType data);
	void DLL_DestroyNode(DoubleNode* dubleNode);	
	void DLL_AppendNode(DoubleNode** head, DoubleNode* newNode);
	DoubleNode* DLL_GetNodeAt(DoubleNode* head, int location);
	void DLL_RemoveNode(DoubleNode** head, DoubleNode* removeNode);
	void DLL_InsertAfter(DoubleNode* currentNode, DoubleNode* newNode);
	int DLL_GetNodeCount(DoubleNode* head);

};


#endif // !DoubleLinkedList
