#include "Heap.h"


/*
	Heap

	Ʈ�� ���� ��� ��尡, �θ� ��庸�� ũ�ٴ� ��Ģ�� ������ ���� ���� Ʈ�� 
	-> Ư�� �� �˻� �� ��� ��带 ��ȸ �ؾ��� 
	-> Heap ���� �ִ밪 or �ּҰ��� ��Ʈ�� ��ġ ��
	-> �ִ밪 or �ּҰ��� ������ ã�� ���� ��� 
*/
HeapMain::HeapMain()
{
	cout << "Heap" << endl;

	Heap *heap = create(3);

	HNode minNode;

	insert(heap, 12);
	insert(heap, 87);
	insert(heap, 111);
	insert(heap, 34);
	insert(heap, 16);
	insert(heap, 75);
	printNode(heap);

	deleteMin(heap, &minNode);
	printNode(heap);

	deleteMin(heap, &minNode);
	printNode(heap);

	deleteMin(heap, &minNode);
	printNode(heap);

	deleteMin(heap, &minNode);
	printNode(heap);

	deleteMin(heap, &minNode);
	printNode(heap);
}

Heap * HeapMain::create(int size)
{
	Heap *newHeap = new Heap();
	newHeap->size = size;
	newHeap->count = 0;
	
	newHeap->node->resize(size);
	
	return newHeap;
}

void HeapMain::destroy(Heap * heap)
{
	free(heap->node);
	free(heap);
}

/*
	Heap ����
*/
void HeapMain::insert(Heap * heap, Data newData)
{
	int currentPosition = heap->count;
	int parentPosition = getParent(currentPosition);

	//	Heap�� ��� ������ ��ü ����� �����ϸ� ����� �ø�
	if (heap->count == heap->size)	
	{
		heap->size *= 2;					
		heap->node->resize(heap->size);	
	}

	heap->node->at(currentPosition).data = newData;

	//	�θ� ��尡 �ڽĳ�� ���� ū ���, �� ��ġ�� �ٲ� 
	while (currentPosition > 0
		&& heap->node->at(currentPosition).data < heap->node->at(parentPosition).data)
		
	{
		swapNode(heap, currentPosition, parentPosition);

		currentPosition = parentPosition;
		parentPosition = getParent(currentPosition);
	}
	
	//	Heap�� ��� ������ ���� ��Ŵ 
	heap->count++;
}

/*
	�ּҰ� ( Root )�� ������ ��带 ����
*/
void HeapMain::deleteMin(Heap * heap, HNode * root)
{
	int parentPosition = 0;
	int leftPosition = 0;
	int rightPosition = 0;

	memcpy(root, &heap->node->at(0), sizeof(HNode));
	memset(&heap->node->at(0), 0, sizeof(HNode));

	heap->count--;

	swapNode(heap, 0, heap->count);	//	Heap�� ù��° (Root) ���� ������ ����� ��ġ�� �ٲ�
	
	leftPosition = getLeftChild(0);
	rightPosition = leftPosition + 1;

	while (1)	//	Heap�� �Ӽ��� �°� �ڽ� ������ ��ȯ�� ���� �� 
	{
		int selectedPosition = 0;

		if (leftPosition >= heap->count)
		{
			break;
		}
		if (rightPosition >= heap->count)
		{
			selectedPosition = leftPosition;
		}
		else
		{
			if (heap->node->at(leftPosition).data > heap->node->at(rightPosition).data)
			{
				selectedPosition = rightPosition;
			}
			else
			{
				selectedPosition = leftPosition;
			}
		}

		if ( heap->node->at(selectedPosition).data < heap->node->at(parentPosition).data)
		{
			swapNode(heap, parentPosition, selectedPosition);
			parentPosition = selectedPosition;
		}
		else
		{
			break;
		}

		leftPosition = getLeftChild(parentPosition);
		rightPosition = leftPosition + 1;
		

		//	Heap�� ��� ������ ��ü �������� ������ �ȵǴ� ���, Heap�� ��ü ����� ������ ����
		if (heap->count < (heap->size / 2))
		{
			heap->size /= 2;
			heap->node->resize(heap->size);
			
		}
	}
}

/*
	index ����� �θ� ����� ��ġ�� ������
*/
int HeapMain::getParent(int index)
{
	return (int)((index-1) / 2);	
}

/*
	index ����� ���� ����� ��ġ�� ������ 
*/
int HeapMain::getLeftChild(int index)
{
	return (2 * index) + 1;
}

/*
	�ΰ��� ��带 swap �� 
*/
void HeapMain::swapNode(Heap * heap, int index1, int index2)
{		
	
	HNode temp = heap->node->at(index1);

	heap->node->at(index1) = heap->node->at(index2);
	heap->node->at(index2) = temp;	
	
}

void HeapMain::printNode(Heap * heap)
{
	for (int i = 0; i < heap->count; i++)
	{
		cout << heap->node->at(i).data << " ";
	}
	cout << endl;
}

