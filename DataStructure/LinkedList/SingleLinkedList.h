#ifndef SINGLELINKEDLIST_H
#define SINGLELINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

typedef int ElementType;

typedef struct tagNode
{
	ElementType Data;
	struct tagNode* nextNode;
} Node;


/*
	Single Linked List	
*/
void SingleLinkedListMain();
Node* SLL_CreateNode(ElementType newData);
void SLL_DestroyNode(Node* node);
void SLL_AppendNode(Node** head, Node* newNode);
void SLL_InsertAfter(Node* current, Node* newNode);
void SLL_InsertNewHead(Node** head, Node* newHead);
void SLL_RemoveNode(Node** head, Node* removeNode);
Node* SLL_GetNodeAt(Node* head, int location);
int SLL_GetNodeCount(Node* head);
void print(Node* list);

#endif
