#include "SingleLinkedList.h"

class SingleLinkedListClass
{
public:
	void SingleLinkedListMain();
	void print(Node* list);
};

void SingleLinkedListMain()
{
	int i = 0;
	int count = 0;
	Node* list = NULL;
	Node* current = NULL;
	Node* newNode = NULL;


	for (i = 0; i < 5; i++)
	{
		newNode = SLL_CreateNode(i);	//	새로운 노드를 생성 함
		SLL_AppendNode(&list, newNode);	//	생성한 노드를 list에 추가함 
	}

	

	
	print(list);	

	for (i = 0; i < SLL_GetNodeCount(list); i++)
	{
		current = SLL_GetNodeAt(list, i);
		SLL_RemoveNode(&list, current);
	}
}

void print(Node* list)
{
	int i = 0;
	Node* newNode;

	for (i = 0; i < SLL_GetNodeCount(list); i++)
	{
		newNode = SLL_GetNodeAt(list, i);	//	i 번째 위치의 node를 가져 옴
		cout << newNode->Data << endl;
	}
}



/*
	Node 생성
*/
Node* SLL_CreateNode(ElementType newData)
{	
	Node* newNode = (Node*)malloc(sizeof(Node));	//	자유 저장소에 메모리 할당 

	newNode->Data = newData;	//	데이터값 저장		
	newNode->nextNode = NULL;	//	현재 노드의 다음 노드 포인터를 NULL로 저장 
		
	return newNode;
}

/*
	Node 삭제
*/
void SLL_DestroyNode(Node* node)
{
	free(node);
}

/*
	Node 추가
*/
void SLL_AppendNode(Node** head, Node* newNode)
{
	if ((*head) == NULL)	//	head node 가 null 인 경우
	{
		*head = newNode;	//	newNode를 head node로 설정
	}	
	else					//	head node 가 null 이 아닌 경우 
	{
		Node* tail = (*head);
		while (tail->nextNode != NULL)	//	tail node를 찾음
		{
			tail = tail->nextNode;		
		}
		tail->nextNode = newNode;		//	tail node의 다음 node를 newNode로 설정
	}
}

/*
	Node 삽입
	@current	추가하고자 하는 위치에 존재하는 Node		
	@newNode	추가하고자 하는 새로운 Node
*/
void SLL_InsertAfter(Node* current, Node* newNode)
{
	newNode->nextNode = current->nextNode;
	current->nextNode = newNode;
}

/*
	Head 위치에 Node 삽입
	@head		LinkedList
	@newNode	삽입하고자 하는 Node
*/
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

/*
	Node 삭제 
	@head		삭제하고자 하는 Node가 포함된 LinkedList
	@removeNode	삭제하고자 하는 Node
*/
void SLL_RemoveNode(Node** head, Node* removeNode)
{
	if (*head == removeNode)		//	삭제하고자 하는 Node가 head 위치에 있는 경우 
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
			//	삭제하고자 하는 Node의 다음 Node를, 삭제하고자 하는 Node의 이전 Node의 NextNode로 설정함 
			current->nextNode = removeNode->nextNode;	
		}

		SLL_DestroyNode(removeNode);
	}
}

/*
	Node 탐색
	@head		찾고자 하는 Node가 포함된 LinkedList
	@location	전달된 위치의 Node 정보를 return 함
*/
Node* SLL_GetNodeAt(Node* head, int location)
{
	Node* current = head;

	while (current != NULL && (--location) >= 0)
	{
		current = current->nextNode;
	}

	return current;
}

/*
	LinkedList 의 사이즈 확인
	@head	사이즈를 측정하고자 하는 LinkedList
*/
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
