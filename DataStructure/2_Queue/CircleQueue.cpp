#include "CircleQueue.h"

//	å�� ���� �ִ� Circle Queue�� ������ �̻��ϰ�, �����ϰ� �ٸ���
//	����� �ٸ��� ��µ� ... 

CircleQueue::CircleQueue()
{
	cout << "Circle Queue Main" << endl;

	int i = 100;

	Cqueue* queue;

	createQueue(&queue, 10);

	enqueue(queue, 1);
	enqueue(queue, 2);
	enqueue(queue, 3);
	enqueue(queue, 4);

	cout << dequeue(queue) << " : " << queue->front << " : " << queue->rear << endl;
	cout << dequeue(queue) << " : " << queue->front << " : " << queue->rear << endl;
	cout << dequeue(queue) << " : " << queue->front << " : " << queue->rear << endl;

	while ( isFull(queue) == 0)
	{
		enqueue(queue, i++);
	}

	cout << queue->size <<  " : " << getSize(queue) << endl;
	
	while ( isEmpty(queue) == 0)
	{
		cout << dequeue(queue) << " : " << queue->front << " : " << queue->rear << endl;
	}

}

/*
	Queue ����
*/
void CircleQueue :: createQueue(Cqueue** queue, int size)
{
	//	Queue�� ���� ����ҿ� ����
	(*queue) = (Cqueue*)malloc(sizeof(Cqueue));

	//	�Էµ� size ��ŭ�� ��带 ť ���� ����ҿ� ����
	(*queue)->node = (Cnode*)malloc(sizeof(Cnode) * (size + 1));

	(*queue)->size = size;
	(*queue)->front = 0;
	(*queue)->rear = 0;
}

/*
	Queue ����
*/
void CircleQueue::destroyQueue(Cqueue* queue)
{
	free(queue->node);
	free(queue);
}

/*
	Queue �� node ����
*/
void CircleQueue ::enqueue(Cqueue* queue, ElementType data)
{	
	/*
	int position = 0;

	if (queue->rear == queue->size)
	{
		queue->rear = 0;
		position = queue->rear;

		queue->node[position].data = data;	//	���� rear�� ��ġ�� ���� �߰� 		

		queue->rear++;
		cout << "2 enqueue : " << position << " : " << queue->node[position].data << endl;
	}
	else
	{	
		position = queue->rear;	//	���� rear�� ��ġ�� Ȯ��
			
		queue->node[position].data = data;	//	���� rear�� ��ġ�� ���� �߰� 
		
		cout << "1 enqueue : " << position << " : " << queue->node[position].data << endl;

		queue->rear++;	//	rear �� ��ġ�� ��ĭ �̵� ��Ŵ 
	}
	//queue->node[position].data = data;
	*/

	int position = 0;

	if ( queue->rear == queue->size + 1)
	{
		queue->rear = 0;
		position = 0;
	}
	else
	{
		position = queue->rear++;
	}
	queue->node[position].data = data;
}

/*
	Queue ���� ��带 ������
*/
ElementType CircleQueue::dequeue(Cqueue* queue)
{
	int position = queue->front;

	if (queue->front == queue->size)
	{
		queue->front = 0;		
	}
	else
	{
		queue->front++;
	}
	return queue->node[position].data;
}

int CircleQueue::getSize(Cqueue* queue)
{
	if (queue->front <= queue->rear)
	{
		return queue->rear - queue->front;
	}
	else
	{
		return queue->rear + (queue->size - queue->front) + 1;
	}
}


int CircleQueue::isEmpty(Cqueue* queue)
{
	return queue->front == queue->rear;
}

int CircleQueue::isFull(Cqueue* queue)
{
	if (queue->front < queue->rear)
	{
		return (queue->rear - queue->front) == queue->size;
	}
	else
	{
		return (queue->rear + 1) == queue->front;
	}
}
