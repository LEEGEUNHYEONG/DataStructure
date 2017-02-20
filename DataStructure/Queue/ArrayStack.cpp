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
	//	stack 을 자유저장소에 생성
	(*stack) = (ArrayStack*)malloc(sizeof(ArrayStack));

	//	입력된 size 의 노드를 자유저장소에 생성
	(*stack)->node = (Node*)malloc(sizeof(Node)*size);

	//	size 및 top 초기화
	(*stack)->size = size;
	(*stack)->top = 0;
}

void AStack:: destroyStack(ArrayStack* stack)
{
	//	노드를 자유저장소에서 해제
	free(stack->node);

	//	스택을 자유저장소에서 해제
	free(stack);
}

void AStack:: push(ArrayStack* stack, ElementType node)
{
	//	현재 top의 위치를 확인
	int position = stack->top;

	//	top 의 위치에 node를 추가
	stack->node[position].Data = node;

	//	top 의 위치값을 +1
	stack->top++;
}

ElementType AStack:: pop(ArrayStack* stack)
{
	//	현재 top 의 위치에서 1 낮은 위치값을 가져 옴
	int position = --(stack->top);

	//	가져온 위치값의 데이터를 return 함
	return stack->node[position].Data;
}