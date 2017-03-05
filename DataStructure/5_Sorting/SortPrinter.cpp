#include "SortPrinter.h"

SortPrinter::SortPrinter()
{

}

SortPrinter::SortPrinter(vector<int> list)
{
	for (int i = 0; i < list.size(); i++)
	{
		cout << list[i] << " ";
	}
	cout << endl;
}

SortPrinter::~SortPrinter()
{
}
