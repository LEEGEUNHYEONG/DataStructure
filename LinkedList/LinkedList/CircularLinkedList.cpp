#include <iostream>
#include <stdio.h>
#include <Windows.h>

#include "CircularLinkedList.h"

using namespace std;

void CircularDoubleLinkedList::CircularDoubleLinkedListMain()
{
	cout << "Circular Double Linked List" << endl;

	int i = 0;
	int count = 0;
	DoubleNode* list = NULL;
	DoubleNode* newNode = NULL;
	DoubleNode* currentNode = NULL;

	for (i = 0; i < 10; i++)
	{
		newNode = CDL_CreateNode(i);
		CDL_AppendNode(&list, newNode);
	}

	CDL_InsertAfter(CDL_GetNodeAt(list, 2), CDL_CreateNode(1000));
	CDL_RemoveNode(&list, CDL_GetNodeAt(list, 1));


	CDL_InsertAfter(CDL_GetNodeAt(list, 3), CDL_CreateNode(500));

	CDL_InsertAfter(CDL_GetNodeAt(list, 4), CDL_CreateNode(750));

	CDL_InsertAfter(CDL_GetNodeAt(list, 5), CDL_CreateNode(50));


	
	for (i = 0; i < CDL_GetNodeCount(list); i++)
	{
		currentNode = CDL_GetNodeAt(list, i);
		cout << currentNode->Data << endl;
	}
	
}

/*
	새로운 환형 더블 링크드 리스트 노드 생성
*/
DoubleNode* CircularDoubleLinkedList::CDL_CreateNode(ElementType data)
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
void CircularDoubleLinkedList::CDL_DestroyNode(DoubleNode* doubleNode)
{
	free(doubleNode);
}

/*
	새로운 노드를 추가 함
	@head		환형 더블 링크드 리스트의 헤드 노드의 포인터
	@newNode	추가하고자 하는 노드 포인터
*/
void CircularDoubleLinkedList::CDL_AppendNode(DoubleNode** head, DoubleNode* newNode)
{
	if (*head == NULL)
	{
		//	head 가 NULL 이라면 newNode 자신이 head 이며, tail 이 됨 
		*head = newNode;
		(*head)->nextNode = *head;
		(*head)->prevNode = *head;
	}
	else
	{
		DoubleNode* tail = (*head)->prevNode;

		tail->nextNode->prevNode = newNode;	//	tail->nextNode >> head Node의 이전 노드를 newNode로 설정 
		tail->nextNode = newNode;			//	tail 노드의 다음 노드를 newNode로 설정, newNode를 tail 로 설정

		newNode->nextNode = (*head);		//	newNode의 다음 노드를 head 노드로 설정
		newNode->prevNode = tail;			//	newNode의 이전 노드를 이전의 tail 노드로 지정 
	}
}

/*
	원하는 위치의 노드 정보 탐색
	@head		환형 더블 링크드 리스트의 헤드 노드의 포인터
	@location	찾고자 하는 위치
*/
DoubleNode* CircularDoubleLinkedList::CDL_GetNodeAt(DoubleNode* head, int location)
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
	@head		환형 더블 링크드 리스트의 헤드 노드의 포인터
	@removeNode	삭제하고자 하는 노드
*/
void CircularDoubleLinkedList::CDL_RemoveNode(DoubleNode** head, DoubleNode* removeNode)
{
	if (*head == removeNode)	//	삭제하고자 하는 노드가 헤드의 위치인 경우 
	{
		(*head)->prevNode->nextNode = removeNode->nextNode;		//	head 노의 이전 (tail) 의 다음 노드를 삭제하는 노드의 다음 노드로 설정
		(*head)->nextNode->prevNode = removeNode->prevNode;		//	head 노드의 다음 노드의 이전 노드를, 삭제하는 노드의 이전 노드로 설정

		*head = removeNode->nextNode;		//		삭제하는 노드의 다음 노드를 head로 설정
	}
	else
	{
		DoubleNode* temp = removeNode;

		removeNode->prevNode->nextNode = temp->nextNode;		//	삭제하고자 하는 노드 이전의 노드에서 다음 노드를, 삭제하는 노드의 다음 노드로 설정
		removeNode->nextNode->prevNode = temp->prevNode;		//	삭제하고자 하는 노드의 다음 노드의 이전 노드를, 삭제하는 노드의 이전 노드로 설정 
	}

	removeNode->prevNode = NULL;
	removeNode->nextNode = NULL;

	CDL_DestroyNode(removeNode);

}

/*
	새로운 노드를 원하는 노드 다음 노드에 추가
	@currentNode	추가하고자 하는 노드의 위치
	@newNode		추가하고자 하는 노드
*/
void CircularDoubleLinkedList::CDL_InsertAfter(DoubleNode* currentNode, DoubleNode* newNode)
{
	newNode->nextNode = currentNode->nextNode;
	newNode->prevNode = currentNode;

	currentNode->nextNode->prevNode = newNode;
	currentNode->nextNode = newNode;	
}

/*
더블 링크드 리스트의 사이즈를 확인
@head	측정하고자 하는 더블 링크드 리스트
*/
int CircularDoubleLinkedList::CDL_GetNodeCount(DoubleNode* head)
{
	int count = 0;

	DoubleNode* currentNode = head;

	while (currentNode != NULL)
	{
		currentNode = currentNode->nextNode;
		count++;

		if (currentNode == head)
		{
			break;
		}
	}
	return count;
}

