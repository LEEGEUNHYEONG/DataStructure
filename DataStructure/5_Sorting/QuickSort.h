#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>

#include "SortPrinter.h"

using namespace std;

class QuickSort
{
public:
	QuickSort(vector<int> *list);

private :
	QuickSort(vector<int> *list, int left, int right);
//vector<int> list;
	void swap(vector<int> *list, int a, int b);
	int partition(vector<int> *list, int left, int right);
};