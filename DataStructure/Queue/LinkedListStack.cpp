#include "Stack.h"
#include "base.h"

void LStack::LStackMain()
{
	int i = 0;
	int count = 0;
	Node* poped;

	LinkedListStack* stack;

	createStack(&stack);

	push(stack, createNode("qq"));
	push(stack, createNode("ab"));
	push(stack, createNode("we"));
	pop(stack);
	push(stack, createNode("fd"));
	push(stack, createNode("xc"));
	
	print(stack);

}

void LStack::createStack(LinkedListStack** stack)
{
	(*stack) = (LinkedListStack*)malloc(sizeof(LinkedListStack));
	(*stack)->list = NULL;
	(*stack)->top = NULL;
}

void LStack::destroyStack(LinkedListStack* stack)
{
	while (!isEmpty(stack))
	{
		LNode* popNode = pop(stack);
		destroyNode(popNode);
	}

	free(stack);
}

LNode* LStack :: createNode(char* data)
{
	LNode* newNode = (LNode*)malloc(sizeof(LNode));

	//	newNode의 사이즈를 data의 크기만큼 자유 저장소에 할당
	newNode->Data = (char*)malloc(sizeof(strlen(data)+1));

	//	data의 문자열을 newNode의 data에 복사
	strcpy(newNode->Data, data);

	//	newNode의 다음 노드를 초기화
	newNode->nextNode = NULL;
	
	return newNode;
}

void LStack::destroyNode(LNode* node)
{
	free(node->Data);
	free(node);
}


void LStack::push(LinkedListStack* stack, LNode* node)
{
	if (stack->list == NULL)
	{
		stack->list = node;
	}
	else
	{
		LNode* oldTop = stack->list;

		//	노드의 top 위치를 검색
		while (oldTop->nextNode != NULL)
		{
			oldTop = oldTop->nextNode;
		}

		oldTop->nextNode = node;
	}
	//	stack 의 top 에 node를 등록
	stack->top = node;
}

LNode* LStack::pop(LinkedListStack* stack)
{
	//	현재 최상위 노드의 주소
	LNode* topNode = stack->top;

	if (stack->list == stack->top)
	{
		stack->list = NULL;
		stack->top = NULL;
	}
	else
	{
		//	새로운 최상위 노드를 스택의 top에 등록
		LNode* currentTop = stack->list;

		while ( currentTop != NULL && currentTop->nextNode != stack->top)
		{
			currentTop = currentTop->nextNode;
		}

		stack->top = currentTop;
		currentTop->nextNode = NULL;
	}

	return topNode;

}

void LStack::print(LinkedListStack* stack)
{
	int i;
	int count = getSize(stack);


	for (i = 0; i < count; i++)
	{
		LNode* node = pop(stack);

		cout << node->Data << endl;

		destroyNode(node);
		
	}
}

LNode* LStack::getTop(LinkedListStack* stack)
{
	return stack->top;
}

int LStack:: getSize(LinkedListStack* stack)
{
	int count = 0;
	LNode* current = stack->list;

	while (current != NULL)
	{
		current = current->nextNode;
		count++;
	}
	
	return count;
}

int LStack:: isEmpty(LinkedListStack* stack)
{
	return stack->list == NULL;
}