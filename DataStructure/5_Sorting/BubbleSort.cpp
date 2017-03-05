#include "Base.h"

/*
	버블소트
	거의 모든 상황에서 최악의 성능
	n^2
*/
BubbleSort::BubbleSort(vector<int> list)
{
	cout << "BubbleSort" << endl;

	int temp;

	//	가장 오른쪽 포지션은 검사 하지 않아도 됨,
	//	j for 문 안에서, j와 j+1의 포지션을 비교 하기 때문
	for (int i = 0; i < list.size()-1; i++)
	{
		//	i 번쨰 for 문이 끝나게 되면 가장 오른쪽의 값은 
		//	정렬이 된 상태 이므로 j 번째 for 문의 포지션을 하나씩 줄임
		for (int j = 0; j < list.size() - (i + 1); j++)
		{
			if (list[j] > list[j+1])
			{
				temp = list[j];
				list[j] = list[j + 1];
				list[j + 1] = temp;
			}
		}
	}

	Print *print = new Print(list);
}

