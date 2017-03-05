#include "Base.h"

#include "QuickSort.h"

int main()
{
	cout << "Sort Main" << endl;

	vector<int> *list = new vector<int>;	

	list->push_back(10);
	list->push_back(4);
	list->push_back(7);
	list->push_back(6);
	list->push_back(2);
	list->push_back(3);
	list->push_back(8);
	list->push_back(1);
	list->push_back(5);
	list->push_back(9);
	
	//BubbleSort *bubbleSort = new BubbleSort(list);
	//InsertionSort *insrtionSort = new InsertionSort(list);
	QuickSort quickSort(list);
}