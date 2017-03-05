#include "Base.h"

/*
	���� ����
	�ڷ� �迭�� ��� ��Ҹ� �տ������� 
	���ʴ�� �̹� ���ĵ� �迭 �κа� ���Ͽ�, 
	�ڽ��� ��ġ�� ã�� ���������ν� ����

	������������ ���ĵǾ� �ִ� ��� �־�
	������������ ���ĵǾ� �ִ� ��� �ְ� 

	n^2
	in place �� 
*/
InsertionSort::InsertionSort(vector<int> list)
{
	cout << "InsertionSort" << endl;

	int temp;
	int position;
	
	//	����Ʈ�� 0��°�� �ƴ� 1��° �������� �������� ������
	for (int i = 1; i < list.size(); i++)
	{
		temp = list[i];
		position = i - 1;

		//	���� ������ -1 ���� 0 ��° �����Ǳ��� ���� ��, 
		//	���� ���鼭 ���ϴ� �� ���� �������� ������ ū ���� �ִٸ� 
		//	���������� ��ĭ�� �ű� 
		//	�� ������ ���� �� ������ ������ �׸���� ������ ��
		while ((position >= 0) && (list[position] > temp))
		{
			list[position + 1] = list[position];
			position--;
		}

		//	�˸��� ��ġ�� ���� ���� �� 
		list[position + 1] = temp;
	}
	SortPrinter sortPrinter(list);
}
