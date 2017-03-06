#include "BinarySearch.h"

BinarySearch ::BinarySearch(vector<int> *list)
{
	cout << "Binary Search Main : size : " << (*list).size() << endl << endl;

	int searchNumber;

	cout << "input number : ";
	cin >> searchNumber;

	//	원하는 값을 찾아 결과를 받아 오는 부분 
	int result = binarySearch(list, searchNumber);
		
	if (result == -1)	//	입력받은 값이 리스트에 존재하지 않는 경우 
	{
		cout << "result : not found" << endl;
	}
	else				//	입력받은 값이 존재하는 position을 출력
	{
		cout << "result : " << result << endl;
	}	
}

int BinarySearch::binarySearch(vector<int> *list, int target)
{
	int left, right, mid;
		
	left = 0;							//	리스트의 탐색 시작 부분
	right = (*list).size() - 1;			//	리스트의 탐색 마지막 부분
	
	while (left <= right)				//	탐색 시작 부분이 마지막 부분을 만나지 않는 동안
	{
		mid = (left + right) / 2;		//	리스트의 가운데 값을 mid 로 설정

		if (target == (*list)[mid])		//	리스트의 mid 위치의 값과 target의 값이 같으면
		{
			return mid;					//	mid 위치의 값을 return
		}
		else if (target > (*list)[mid])	//	target의 값이 mid 위치의 값 보다 크다면 
		{
			left = mid + 1;				//	리스트의 탐색 시작 부분을 mid + 1로 지정
		}
		else							//	target의 값이 mid 위치의 값 보다 작다면
		{	
			right = mid - 1;			//	리스트의 탐색 마지막 부분을 mid -1 로 지정
		}
	}

	//	값을 찾지 못한 경우 return 하는 값 
	return -1;
}