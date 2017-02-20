#pragma once
#ifndef STACK_H
#define STACK_H

typedef int ElementType;

/*	Array Stack	Start	*/
typedef struct tagNode
{
	ElementType Data;
	struct tagNode* nextNode;
} Node;

typedef struct arrayStack
{
	int size;
	int top;
	Node* node;
}ArrayStack;

class AStack
{
public:
	void StackMain();
private:
	void createStack(ArrayStack** stack, int size);
	void destroyStack(ArrayStack* stack);
	void push(ArrayStack* stack, ElementType node);
	ElementType pop(ArrayStack* stack);
	void print(ArrayStack* stack);
};
/*	Array Stack	End	*/

/*	Linked List Stack Start	*/
typedef struct Lnode
{
	char* Data;
	struct Lnode* nextNode;
	
}LNode;

typedef struct linkedListStack
{
	LNode* list;
	LNode* top;
}LinkedListStack;

class LStack
{
public :
	void LStackMain();
private:
	void createStack(LinkedListStack** stack);
	void destroyStack(LinkedListStack* stack);
	LNode* createNode(char* data);
	void destroyNode(LNode* node);
	void push(LinkedListStack* stack, LNode* node);
	LNode* pop(LinkedListStack* stack);
	void print(LinkedListStack* stack);
	LNode* getTop(LinkedListStack* stack);
	int getSize(LinkedListStack* stack);
	int isEmpty(LinkedListStack* stack);
};

/*	Linked List Stack End	*/
#endif // !STACK_H
