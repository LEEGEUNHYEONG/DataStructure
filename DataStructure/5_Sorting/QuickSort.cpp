#include "QuickSort.h"

/*
	����Ʈ
	���� ��� �κп��� ����,
	Divide and Conquer
	nlog(n)

	�̹� ���ĵǾ� �ְų� ������ ��� ����Ʈ ( n^2 )
*/

QuickSort::QuickSort(vector<int> *list)
{
	cout << "Quick Sort" << endl;

	QuickSort(list, 0, list->size()-1);

	SortPrinter sortPrinter(*list);
}

QuickSort::QuickSort(vector<int>* list, int left, int right)
{
	int i = left;
	int j = right;
	int pivot = list->at( (left + right) / 2 );

	while (i < j )
	{
		while (list->at(i) < pivot)
			i++;
		while (list->at(j) > pivot)
			j--;

		swap(list, i, j);
	}

	if ( i < right)
	{
		QuickSort(list, i+1, right);
	}
	if (left < j)
	{
		QuickSort(list, left, j-1);
	}
}

void QuickSort::swap(vector<int> *list, int a, int b)
{
	int temp = list->at(a);
	list->at(a) = list->at(b);
	list->at(b) = temp;
}