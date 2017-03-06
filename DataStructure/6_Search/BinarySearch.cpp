#include "BinarySearch.h"

BinarySearch ::BinarySearch(vector<int> *list)
{
	cout << "Binary Search Main : size : " << (*list).size() << endl << endl;

	int searchNumber;

	cout << "input number : ";
	cin >> searchNumber;

	//	���ϴ� ���� ã�� ����� �޾� ���� �κ� 
	int result = binarySearch(list, searchNumber);
		
	if (result == -1)	//	�Է¹��� ���� ����Ʈ�� �������� �ʴ� ��� 
	{
		cout << "result : not found" << endl;
	}
	else				//	�Է¹��� ���� �����ϴ� position�� ���
	{
		cout << "result : " << result << endl;
	}	
}

int BinarySearch::binarySearch(vector<int> *list, int target)
{
	int left, right, mid;
		
	left = 0;							//	����Ʈ�� Ž�� ���� �κ�
	right = (*list).size() - 1;			//	����Ʈ�� Ž�� ������ �κ�
	
	while (left <= right)				//	Ž�� ���� �κ��� ������ �κ��� ������ �ʴ� ����
	{
		mid = (left + right) / 2;		//	����Ʈ�� ��� ���� mid �� ����

		if (target == (*list)[mid])		//	����Ʈ�� mid ��ġ�� ���� target�� ���� ������
		{
			return mid;					//	mid ��ġ�� ���� return
		}
		else if (target > (*list)[mid])	//	target�� ���� mid ��ġ�� �� ���� ũ�ٸ� 
		{
			left = mid + 1;				//	����Ʈ�� Ž�� ���� �κ��� mid + 1�� ����
		}
		else							//	target�� ���� mid ��ġ�� �� ���� �۴ٸ�
		{	
			right = mid - 1;			//	����Ʈ�� Ž�� ������ �κ��� mid -1 �� ����
		}
	}

	//	���� ã�� ���� ��� return �ϴ� �� 
	return -1;
}