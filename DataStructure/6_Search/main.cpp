#include "main.h"

#include "BinarySearch.h"
#include "BinarySearchTree.h"

int main()
{
	cout << "Search Main" << endl;

	vector<int> *list = new vector<int>;

	list->push_back(2);
	list->push_back(17);
	list->push_back(29);
	list->push_back(37);
	list->push_back(46);
	list->push_back(53);
	list->push_back(65);
	list->push_back(77);
	list->push_back(82);
	list->push_back(99);

	//BinarySearch binarySearch(list);
	BinarySearchTree binarySearchTree;
	return 0;

}
