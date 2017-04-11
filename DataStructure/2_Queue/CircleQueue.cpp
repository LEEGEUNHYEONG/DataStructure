#include "CircleQueue.h"

//	책에 나와 있는 Circle Queue는 동작이 이상하고, 설명하고도 다르고
//	결과도 다르게 출력됨 ... 

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
	Queue 생성
*/
void CircleQueue :: createQueue(Cqueue** queue, int size)
{
	//	Queue를 자유 저장소에 생성
	(*queue) = (Cqueue*)malloc(sizeof(Cqueue));

	//	입력된 size 만큼의 노드를 큐 자유 저장소에 생성
	(*queue)->node = (Cnode*)malloc(sizeof(Cnode) * (size + 1));

	(*queue)->size = size;
	(*queue)->front = 0;
	(*queue)->rear = 0;
}

/*
	Queue 삭제
*/
void CircleQueue::destroyQueue(Cqueue* queue)
{
	free(queue->node);
	free(queue);
}

/*
	Queue 에 node 삽입
*/
void CircleQueue ::enqueue(Cqueue* queue, ElementType data)
{	
	/*
	int position = 0;

	if (queue->rear == queue->size)
	{
		queue->rear = 0;
		position = queue->rear;

		queue->node[position].data = data;	//	현재 rear의 위치에 값을 추가 		

		queue->rear++;
		cout << "2 enqueue : " << position << " : " << queue->node[position].data << endl;
	}
	else
	{	
		position = queue->rear;	//	현재 rear의 위치를 확인
			
		queue->node[position].data = data;	//	현재 rear의 위치에 값을 추가 
		
		cout << "1 enqueue : " << position << " : " << queue->node[position].data << endl;

		queue->rear++;	//	rear 의 위치를 한칸 이동 시킴 
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
	Queue 에서 노드를 가져옴
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
