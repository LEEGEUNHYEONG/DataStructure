#include "Base.h"

/*
	삽입 정렬
	자료 배열의 모든 요소를 앞에서부터 
	차례대로 이미 정렬된 배열 부분과 비교하여, 
	자신의 위치를 찾아 삽입함으로써 정렬

	내림차순으로 정렬되어 있는 경우 최악
	오름차순으로 정렬되어 있는 경우 최고 

	n^2
	in place 함 
*/
InsertionSort::InsertionSort(vector<int> list)
{
	cout << "InsertionSort" << endl;

	int temp;
	int position;
	
	//	리스트의 0번째가 아닌 1번째 포지션을 기준으로 시작함
	for (int i = 1; i < list.size(); i++)
	{
		temp = list[i];
		position = i - 1;

		//	기준 포지션 -1 부터 0 번째 포지션까지 내려 감, 
		//	내려 가면서 비교하는 중 기준 포지션의 값보다 큰 값이 있다면 
		//	오른쪽으로 한칸씩 옮김 
		//	이 동작을 수행 시 포지션 사이의 항목들은 정렬이 됨
		while ((position >= 0) && (list[position] > temp))
		{
			list[position + 1] = list[position];
			position--;
		}

		//	알맞은 위치에 값이 복사 됨 
		list[position + 1] = temp;
	}
	SortPrinter sortPrinter(list);
}
