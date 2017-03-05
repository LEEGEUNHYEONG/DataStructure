#pragma once
#ifndef BASE_H
#define BASE_H

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>

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

class Print
{
	public: Print(vector<int> list)
	{
		for (int i = 0; i < list.size(); i++)
		{
			cout << list[i] << " ";
		}
		cout << endl;
	}
};


#endif // !BASE_H

