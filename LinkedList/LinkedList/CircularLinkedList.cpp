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
	���ο� ȯ�� ���� ��ũ�� ����Ʈ ��� ����
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
	���ϴ� ����� �޸𸮸� ������
	@doubleNode		�޸� �����ϰ��� �ϴ� ���
*/
void CircularDoubleLinkedList::CDL_DestroyNode(DoubleNode* doubleNode)
{
	free(doubleNode);
}

/*
	���ο� ��带 �߰� ��
	@head		ȯ�� ���� ��ũ�� ����Ʈ�� ��� ����� ������
	@newNode	�߰��ϰ��� �ϴ� ��� ������
*/
void CircularDoubleLinkedList::CDL_AppendNode(DoubleNode** head, DoubleNode* newNode)
{
	if (*head == NULL)
	{
		//	head �� NULL �̶�� newNode �ڽ��� head �̸�, tail �� �� 
		*head = newNode;
		(*head)->nextNode = *head;
		(*head)->prevNode = *head;
	}
	else
	{
		DoubleNode* tail = (*head)->prevNode;

		tail->nextNode->prevNode = newNode;	//	tail->nextNode >> head Node�� ���� ��带 newNode�� ���� 
		tail->nextNode = newNode;			//	tail ����� ���� ��带 newNode�� ����, newNode�� tail �� ����

		newNode->nextNode = (*head);		//	newNode�� ���� ��带 head ���� ����
		newNode->prevNode = tail;			//	newNode�� ���� ��带 ������ tail ���� ���� 
	}
}

/*
	���ϴ� ��ġ�� ��� ���� Ž��
	@head		ȯ�� ���� ��ũ�� ����Ʈ�� ��� ����� ������
	@location	ã���� �ϴ� ��ġ
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
	���ϴ� ����� ����
	@head		ȯ�� ���� ��ũ�� ����Ʈ�� ��� ����� ������
	@removeNode	�����ϰ��� �ϴ� ���
*/
void CircularDoubleLinkedList::CDL_RemoveNode(DoubleNode** head, DoubleNode* removeNode)
{
	if (*head == removeNode)	//	�����ϰ��� �ϴ� ��尡 ����� ��ġ�� ��� 
	{
		(*head)->prevNode->nextNode = removeNode->nextNode;		//	head ���� ���� (tail) �� ���� ��带 �����ϴ� ����� ���� ���� ����
		(*head)->nextNode->prevNode = removeNode->prevNode;		//	head ����� ���� ����� ���� ��带, �����ϴ� ����� ���� ���� ����

		*head = removeNode->nextNode;		//		�����ϴ� ����� ���� ��带 head�� ����
	}
	else
	{
		DoubleNode* temp = removeNode;

		removeNode->prevNode->nextNode = temp->nextNode;		//	�����ϰ��� �ϴ� ��� ������ ��忡�� ���� ��带, �����ϴ� ����� ���� ���� ����
		removeNode->nextNode->prevNode = temp->prevNode;		//	�����ϰ��� �ϴ� ����� ���� ����� ���� ��带, �����ϴ� ����� ���� ���� ���� 
	}

	removeNode->prevNode = NULL;
	removeNode->nextNode = NULL;

	CDL_DestroyNode(removeNode);

}

/*
	���ο� ��带 ���ϴ� ��� ���� ��忡 �߰�
	@currentNode	�߰��ϰ��� �ϴ� ����� ��ġ
	@newNode		�߰��ϰ��� �ϴ� ���
*/
void CircularDoubleLinkedList::CDL_InsertAfter(DoubleNode* currentNode, DoubleNode* newNode)
{
	newNode->nextNode = currentNode->nextNode;
	newNode->prevNode = currentNode;

	currentNode->nextNode->prevNode = newNode;
	currentNode->nextNode = newNode;	
}

/*
���� ��ũ�� ����Ʈ�� ����� Ȯ��
@head	�����ϰ��� �ϴ� ���� ��ũ�� ����Ʈ
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

