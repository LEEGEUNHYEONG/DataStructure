#include "Base.h"

/*
	�����Ʈ
	���� ��� ��Ȳ���� �־��� ����
	n^2
*/
BubbleSort::BubbleSort(vector<int> list)
{
	cout << "BubbleSort" << endl;

	int temp;

	//	���� ������ �������� �˻� ���� �ʾƵ� ��,
	//	j for �� �ȿ���, j�� j+1�� �������� �� �ϱ� ����
	for (int i = 0; i < list.size()-1; i++)
	{
		//	i ���� for ���� ������ �Ǹ� ���� �������� ���� 
		//	������ �� ���� �̹Ƿ� j ��° for ���� �������� �ϳ��� ����
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

