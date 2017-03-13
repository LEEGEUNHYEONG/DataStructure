#include "Heap.h"


/*
	Heap

	트리 내의 모든 노드가, 부모 노드보다 크다는 규칙을 가지는 완전 이진 트리 
	-> 특정 값 검색 시 모든 노드를 순회 해야함 
	-> Heap 에서 최대값 or 최소값은 루트에 배치 됨
	-> 최대값 or 최소값을 빠르게 찾기 위해 사용 
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
	Heap 삽입
*/
void HeapMain::insert(Heap * heap, Data newData)
{
	int currentPosition = heap->count;
	int parentPosition = getParent(currentPosition);

	//	Heap의 노드 갯수가 전체 사이즈에 도달하면 사이즈를 늘림
	if (heap->count == heap->size)	
	{
		heap->size *= 2;					
		heap->node->resize(heap->size);	
	}

	heap->node->at(currentPosition).data = newData;

	//	부모 노드가 자식노드 보다 큰 경우, 두 위치를 바꿈 
	while (currentPosition > 0
		&& heap->node->at(currentPosition).data < heap->node->at(parentPosition).data)
		
	{
		swapNode(heap, currentPosition, parentPosition);

		currentPosition = parentPosition;
		parentPosition = getParent(currentPosition);
	}
	
	//	Heap의 노드 갯수를 증가 시킴 
	heap->count++;
}

/*
	최소값 ( Root )을 가지는 노드를 삭제
*/
void HeapMain::deleteMin(Heap * heap, HNode * root)
{
	int parentPosition = 0;
	int leftPosition = 0;
	int rightPosition = 0;

	memcpy(root, &heap->node->at(0), sizeof(HNode));
	memset(&heap->node->at(0), 0, sizeof(HNode));

	heap->count--;

	swapNode(heap, 0, heap->count);	//	Heap의 첫번째 (Root) 노드와 마지막 노드의 위치를 바꿈
	
	leftPosition = getLeftChild(0);
	rightPosition = leftPosition + 1;

	while (1)	//	Heap의 속성에 맞게 자식 노드와의 교환을 수행 함 
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
		

		//	Heap의 노드 갯수가 전체 사이즈의 절반이 안되는 경우, Heap의 전체 사이즈를 반으로 줄임
		if (heap->count < (heap->size / 2))
		{
			heap->size /= 2;
			heap->node->resize(heap->size);
			
		}
	}
}

/*
	index 노드의 부모 노드의 위치를 가져옴
*/
int HeapMain::getParent(int index)
{
	return (int)((index-1) / 2);	
}

/*
	index 노드의 왼쪽 노드의 위치를 가져옴 
*/
int HeapMain::getLeftChild(int index)
{
	return (2 * index) + 1;
}

/*
	두개의 노드를 swap 함 
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

