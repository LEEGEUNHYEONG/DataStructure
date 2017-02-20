#include "base.h"

#include "Stack.h"

int StackSize = 5;

void AStack::StackMain()
{
	cout << "StackMain" << endl;

	ArrayStack* stack = NULL;
	createStack(&stack, StackSize);

	push(stack, 10);
	push(stack, 2);
	push(stack, 4);	
	push(stack, 8);
	push(stack, 6);

	print(stack);

	destroyStack(stack);
}

void AStack::print(ArrayStack* stack)
{
	int i = 0;
	for (i = 0; i < StackSize; i++)
	{		
		cout << pop(stack) << endl;
	}
}


void AStack::createStack(ArrayStack** stack, int size)
{
	//	stack �� ��������ҿ� ����
	(*stack) = (ArrayStack*)malloc(sizeof(ArrayStack));

	//	�Էµ� size �� ��带 ��������ҿ� ����
	(*stack)->node = (Node*)malloc(sizeof(Node)*size);

	//	size �� top �ʱ�ȭ
	(*stack)->size = size;
	(*stack)->top = 0;
}

void AStack:: destroyStack(ArrayStack* stack)
{
	//	��带 ��������ҿ��� ����
	free(stack->node);

	//	������ ��������ҿ��� ����
	free(stack);
}

void AStack:: push(ArrayStack* stack, ElementType node)
{
	//	���� top�� ��ġ�� Ȯ��
	int position = stack->top;

	//	top �� ��ġ�� node�� �߰�
	stack->node[position].Data = node;

	//	top �� ��ġ���� +1
	stack->top++;
}

ElementType AStack:: pop(ArrayStack* stack)
{
	//	���� top �� ��ġ���� 1 ���� ��ġ���� ���� ��
	int position = --(stack->top);

	//	������ ��ġ���� �����͸� return ��
	return stack->node[position].Data;
}