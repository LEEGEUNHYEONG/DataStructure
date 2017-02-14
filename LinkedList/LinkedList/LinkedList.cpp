#include "LinkedList.h"


void LinkedListMain()
{
	int i = 0;
	int count = 0;
	Node* list = NULL;
	Node* current = NULL;
	Node* newNode = NULL;


	for (i = 0; i < 5; i++)
	{
		newNode = SLL_CreateNode(i);
		SLL_AppendNode(&list, newNode);
	}

	for (i = 0; i < SLL_GetNodeCount(list); i++)
	{
		newNode = SLL_GetNodeAt(list, i);
		cout << newNode->Data << endl;
	}

}


Node* SLL_CreateNode(ElementType newData)
{
	Node* newNode = (Node*)malloc(sizeof(Node));

	newNode->Data = newData;
	newNode->nextNode = NULL;

	//cout << newNode->Data << endl;

	return newNode;
}

void SLL_DestroyNode(Node* node)
{
	free(node);
}


void SLL_AppendNode(Node** head, Node* newNode)
{
	if ((*head) == NULL)
	{
		*head = newNode;
	}
	else
	{
		Node* tail = (*head);
		while (tail->nextNode != NULL)
		{
			tail = tail->nextNode;
		}
		tail->nextNode = newNode;
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
