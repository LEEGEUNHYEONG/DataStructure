#include "LinkedQueue.h"

LinkedQueue::LinkedQueue()
{
	Lnode* temp;

	Lqueue* queue;

	createQueue(&queue);

	enqueue(queue, createNode(2));
	enqueue(queue, createNode(4));
	enqueue(queue, createNode(6));	
	enqueue(queue, createNode(8));	
	enqueue(queue, createNode(10));	
	
	cout << "size : " << queue->count << endl;

	while (isEmpty(queue) == 0)
	{
		temp = dequeue(queue);
		cout << "dequeue : " << temp->data << endl;
		destroyNode(temp);
	}

	destroyQueue(queue);
}

/*
	Linked Queue ����
*/
void LinkedQueue::createQueue(Lqueue** queue)
{
	(*queue) = (Lqueue*)malloc(sizeof(Lqueue));
	(*queue)->front = NULL;
	(*queue)->rear = NULL;
	(*queue)->count = 0;
}


/*
	Linked Queue�� �Ҵ��� ������
*/
void LinkedQueue::destroyQueue(Lqueue* queue)
{
	while (!isEmpty(queue))
	{
		Lnode* temp = dequeue(queue);
		destroyNode(temp);
	}
	free(queue);
}

/*
	Linked Queue�� �߰��� node�� ����
*/
Lnode* LinkedQueue :: createNode(ElementType data)
{
	Lnode* node = (Lnode*)malloc(sizeof(Lnode));	
	node->data = data;
	node->nextNode = NULL;

	return node;
}


/*
	Linked Queue�� Node�� ���� �� 
*/
void LinkedQueue ::destroyNode(Lnode* node)
{	
	free(node);
}



/*
	Linked Queue�� node�� �߰���
*/
void LinkedQueue::enqueue(Lqueue* queue, Lnode* node)
{
	if (queue->front == NULL)
	{
		queue->front = node;
		queue->rear = node;		
	}
	else
	{
		queue->rear->nextNode = node;
		queue->rear = node;		
	}
	queue->count++;
}
Lnode* LinkedQueue::dequeue(Lqueue* queue)
{
	Lnode* front = queue->front;

	if (queue->front->nextNode == NULL)
	{
		queue->front = NULL;
		queue->rear = NULL;
	}
	else
	{
		queue->front = queue->front->nextNode;
	}
	queue->count--;

	return front;
}

int LinkedQueue ::isEmpty(Lqueue* queue)
{
	return (queue->front == NULL);
}