#include <iostream>
#include <stdio.h>
#include <Windows.h>

#include "DoubleLinkedList.h"

using namespace std;


void DoubleLinkedList::DoubleLinkedListMain()
{
	cout << "Double Linked List" << endl;

	int i = 0;
	int count = 0;
	DoubleNode* list = NULL;
	DoubleNode* newNode = NULL;
	DoubleNode* currentNode = NULL;

	for (i = 0; i < 5; i++)
	{
		newNode = DLL_CreateNode(i);
		DLL_AppendNode(&list, newNode);
	}

	DLL_InsertAfter(DLL_GetNodeAt(list, 2), DLL_CreateNode(1000));
	DLL_RemoveNode(&list, DLL_GetNodeAt(list, 1));



	for (i = 0; i < DLL_GetNodeCount(list); i++)
	{
		currentNode = DLL_GetNodeAt(list, i);
		cout << currentNode->Data << endl;
	}
	
}

/*
	새로운 더블 링크드 리스트 노드 생성
*/
DoubleNode* DoubleLinkedList :: DLL_CreateNode(ElementType data)
{
	DoubleNode* newNode = (DoubleNode*)malloc(sizeof(DoubleNode));
	newNode->Data = data;
	newNode->prevNode = NULL;
	newNode->nextNode = NULL;

	return newNode;
}

/*
	원하는 노드의 메모리를 해제함
	@doubleNode		메모리 해제하고자 하는 노드
*/
void DoubleLinkedList::DLL_DestroyNode(DoubleNode* doubleNode)
{
	free(doubleNode);
}

/*
	새로운 노드를 추가 함 
	@head		더블 링크드 리스트의 헤드 노드의 포인터
	@newNode	추가하고자 하는 노드 포인터
*/
void DoubleLinkedList :: DLL_AppendNode(DoubleNode** head, DoubleNode* newNode)
{
	if (*head == NULL)
	{
		*head = newNode;
	}
	else
	{
		DoubleNode* tail = *head;
		while (tail->nextNode != NULL)
		{
			tail = tail->nextNode;
		}

		tail->nextNode = newNode;
		newNode->prevNode = tail;
	}
}

/*
	원하는 위치의 노드 정보 탐색
	@head		더블 링크드 리스트의 헤드 노드의 포인터
	@location	찾고자 하는 위치
*/
DoubleNode* DoubleLinkedList::DLL_GetNodeAt(DoubleNode* head, int location)
{
	DoubleNode* current = head;

	while (current != NULL && (--location) >= 0)
	{
		current = current->nextNode;
	}

	return current;
}

/*
	원하는 노드의 삭제
	@head		더블 링크드 리스트의 헤드 노드의 포인터
	@removeNode	삭제하고자 하는 노드
*/
void DoubleLinkedList :: DLL_RemoveNode(DoubleNode** head, DoubleNode* removeNode)
{
	if (*head == removeNode)	//	삭제하고자 하는 노드가 헤드의 위치인 경우 
	{
		*head = removeNode->nextNode;	//	삭제하고자 하는 노드의 다음 노드를 헤드로 설정
		
		if (*head != NULL)				//	다음 노드가 널이 아닌 경우
		{
			(*head)->prevNode = NULL;	//	다음 노드의 이전 노드를 널로 설정
		}

		removeNode->nextNode = NULL;
		removeNode->prevNode = NULL;
	}
	else
	{
		DoubleNode* temp = removeNode;	

		//	삭제하고자 하는 노드 이전 노드의 다음 노드에 대한 포인터를
		//	삭제하고자 하는 노드의 다음 노드로 설정
		removeNode->prevNode->nextNode = temp->nextNode;	

		//	다음 노드가 널이 아닌 경우, 다음 노드의 이전 노드를 삭제하고자 하는 노드의 이전 노드로 설정
		if (removeNode->nextNode != NULL)
		{
			removeNode->nextNode->prevNode = temp->prevNode;
		}

		removeNode->nextNode = NULL;
		removeNode->prevNode = NULL;

		DLL_DestroyNode(removeNode);
	}
}

/*
	새로운 노드를 원하는 노드 다음 노드에 추가
	@currentNode	추가하고자 하는 노드의 위치
	@newNode		추가하고자 하는 노드 
*/
void DoubleLinkedList::DLL_InsertAfter(DoubleNode* currentNode, DoubleNode* newNode)
{
	newNode->nextNode = currentNode->nextNode;
	newNode->prevNode = currentNode;

	if (currentNode ->nextNode != NULL)
	{
		currentNode->nextNode->prevNode = newNode;
	}

	currentNode->nextNode = newNode;
}

/*
	더블 링크드 리스트의 사이즈를 확인
	@head	측정하고자 하는 더블 링크드 리스트 
*/
int DoubleLinkedList::DLL_GetNodeCount(DoubleNode* head)
{
	int count = 0;

	DoubleNode* currentNode = head;

	while (currentNode != NULL)
	{
		currentNode = currentNode->nextNode;
		count++;
	}
	return count;
}


