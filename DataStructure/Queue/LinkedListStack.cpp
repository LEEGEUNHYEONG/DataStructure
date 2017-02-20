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

	//	newNode�� ����� data�� ũ�⸸ŭ ���� ����ҿ� �Ҵ�
	newNode->Data = (char*)malloc(sizeof(strlen(data)+1));

	//	data�� ���ڿ��� newNode�� data�� ����
	strcpy(newNode->Data, data);

	//	newNode�� ���� ��带 �ʱ�ȭ
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

		//	����� top ��ġ�� �˻�
		while (oldTop->nextNode != NULL)
		{
			oldTop = oldTop->nextNode;
		}

		oldTop->nextNode = node;
	}
	//	stack �� top �� node�� ���
	stack->top = node;
}

LNode* LStack::pop(LinkedListStack* stack)
{
	//	���� �ֻ��� ����� �ּ�
	LNode* topNode = stack->top;

	if (stack->list == stack->top)
	{
		stack->list = NULL;
		stack->top = NULL;
	}
	else
	{
		//	���ο� �ֻ��� ��带 ������ top�� ���
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