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
	���ο� ���� ��ũ�� ����Ʈ ��� ����
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
	���ϴ� ����� �޸𸮸� ������
	@doubleNode		�޸� �����ϰ��� �ϴ� ���
*/
void DoubleLinkedList::DLL_DestroyNode(DoubleNode* doubleNode)
{
	free(doubleNode);
}

/*
	���ο� ��带 �߰� �� 
	@head		���� ��ũ�� ����Ʈ�� ��� ����� ������
	@newNode	�߰��ϰ��� �ϴ� ��� ������
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
	���ϴ� ��ġ�� ��� ���� Ž��
	@head		���� ��ũ�� ����Ʈ�� ��� ����� ������
	@location	ã���� �ϴ� ��ġ
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
	���ϴ� ����� ����
	@head		���� ��ũ�� ����Ʈ�� ��� ����� ������
	@removeNode	�����ϰ��� �ϴ� ���
*/
void DoubleLinkedList :: DLL_RemoveNode(DoubleNode** head, DoubleNode* removeNode)
{
	if (*head == removeNode)	//	�����ϰ��� �ϴ� ��尡 ����� ��ġ�� ��� 
	{
		*head = removeNode->nextNode;	//	�����ϰ��� �ϴ� ����� ���� ��带 ���� ����
		
		if (*head != NULL)				//	���� ��尡 ���� �ƴ� ���
		{
			(*head)->prevNode = NULL;	//	���� ����� ���� ��带 �η� ����
		}

		removeNode->nextNode = NULL;
		removeNode->prevNode = NULL;
	}
	else
	{
		DoubleNode* temp = removeNode;	

		//	�����ϰ��� �ϴ� ��� ���� ����� ���� ��忡 ���� �����͸�
		//	�����ϰ��� �ϴ� ����� ���� ���� ����
		removeNode->prevNode->nextNode = temp->nextNode;	

		//	���� ��尡 ���� �ƴ� ���, ���� ����� ���� ��带 �����ϰ��� �ϴ� ����� ���� ���� ����
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
	���ο� ��带 ���ϴ� ��� ���� ��忡 �߰�
	@currentNode	�߰��ϰ��� �ϴ� ����� ��ġ
	@newNode		�߰��ϰ��� �ϴ� ��� 
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
	���� ��ũ�� ����Ʈ�� ����� Ȯ��
	@head	�����ϰ��� �ϴ� ���� ��ũ�� ����Ʈ 
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


