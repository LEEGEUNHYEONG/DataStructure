#include "LinkedList.h"

class LinkedListClass
{
public:
	void LinkedListMain();
};

void LinkedListMain()
{
	int i = 0;
	int count = 0;
	Node* list = NULL;
	Node* current = NULL;
	Node* newNode = NULL;


	for (i = 0; i < 5; i++)
	{
		newNode = SLL_CreateNode(i);	//	���ο� ��带 ���� ��
		SLL_AppendNode(&list, newNode);	//	������ ��带 list�� �߰��� 
	}

	for (i = 0; i < SLL_GetNodeCount(list); i++)
	{
		newNode = SLL_GetNodeAt(list, i);	//	i ��° ��ġ�� node�� ���� ��
		cout << newNode->Data << endl;		
	}
}



/*
	Node ����
*/
Node* SLL_CreateNode(ElementType newData)
{	
	Node* newNode = (Node*)malloc(sizeof(Node));	//	���� ����ҿ� �޸� �Ҵ� 

	newNode->Data = newData;	//	�����Ͱ� ����		
	newNode->nextNode = NULL;	//	���� ����� ���� ��� �����͸� NULL�� ���� 

	//cout << newNode->Data << endl;
	return newNode;
}

/*
	Node ����
*/
void SLL_DestroyNode(Node* node)
{
	free(node);
}

/*
	Node �߰�
*/
void SLL_AppendNode(Node** head, Node* newNode)
{
	if ((*head) == NULL)	//	head node �� null �� ���
	{
		*head = newNode;	//	newNode�� head node�� ����
	}	
	else					//	head node �� null �� �ƴ� ��� 
	{
		Node* tail = (*head);
		while (tail->nextNode != NULL)	//	tail node�� ã��
		{
			tail = tail->nextNode;		
		}
		tail->nextNode = newNode;		//	tail node�� ���� node�� newNode�� ����
	}
}

void SLL_InsertAfter(Node* current, Node* newNode)
{
	newNode->nextNode = current->nextNode;
	current->nextNode = newNode;
}

void SLL_InsertNewHead(Node** head, Node* newHead)
{
	if (*head == NULL)
	{
		(*head) = newHead;
	}
	else
	{
		newHead->nextNode = (*head);
		(*head) = newHead;
	}
}

void SLL_RemoveNode(Node** head, Node* removeNode)
{
	if (*head == removeNode)
	{
		*head = removeNode->nextNode;
	}
	else
	{
		Node* current = *head;

		while ( current != NULL && current->nextNode != removeNode)
		{
			current = current->nextNode;
		}

		if ( current != NULL)
		{
			current->nextNode = removeNode->nextNode;
		}
	}
}

Node* SLL_GetNodeAt(Node* head, int location)
{
	Node* current = head;

	while (current != NULL && (--location) >= 0)
	{
		current = current->nextNode;
	}

	return current;
}

int SLL_GetNodeCount(Node* head)
{
	int count = 0;
	Node* current = head;

	while (current != NULL)
	{
		current = current->nextNode;
		count++;
	}

	return count;
}
