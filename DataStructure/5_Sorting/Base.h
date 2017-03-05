#pragma once
#ifndef BASE_H
#define BASE_H

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>

#include "SortPrinter.h"

using namespace std;

class BubbleSort
{
	public: 
		BubbleSort(vector<int> list);
};

class InsertionSort
{
	public :
		InsertionSort(vector<int> list);
};
#endif // !BASE_H

