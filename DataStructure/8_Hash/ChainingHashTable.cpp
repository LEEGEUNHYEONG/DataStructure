#include "ChainingHashTable.h"


ChainingHashTable::ChainingHashTable()
{
	cout << "Chaining HashTable Main" << endl << endl;

	CHashTable* hashTable = createHashTable(12289);

	set(hashTable, "MSFT", "Microsft Corporation" );
	set(hashTable, "JAVA", "Oracle");
	set(hashTable, "REDH", "Red Hat Linux");
	set(hashTable, "APAC", "Apache Org");	
	set(hashTable, "IBM", "IBM Ltd.");
	set(hashTable, "ZYMZZ", "Unisys Ops Check");	
	set(hashTable, "ORCL", "Oracle Corporation");
	set(hashTable, "CSCO", "Cisco Systems Inc.");
	set(hashTable, "GOOG", "Google Inc.");
	set(hashTable, "YHOO", "Yahoo Inc.");	
	set(hashTable, "BIZD", "Blizzard Entertainment");	

	cout << "MSFT > " << get(hashTable, "MSFT") << endl;
	cout << "JAVA > " << get(hashTable, "JAVA") << endl;
	cout << "REDH > " << get(hashTable, "REDH") << endl;
	cout << "APAC > " << get(hashTable, "APAC") << endl;
	cout << "IBM > " << get(hashTable, "IBM") << endl;
	cout << "ZYMZZ > " << get(hashTable, "ZYMZZ") << endl;
	cout << "ORCL > " << get(hashTable, "ORCL") << endl;
	cout << "CSCO > " << get(hashTable, "CSCO") << endl;
	cout << "GOOG > " << get(hashTable, "GOOG") << endl;
	cout << "BIZD > " << get(hashTable, "BIZD") << endl;
	
	return;
}


/*
	입력받은 size의 Chaining HashTable을 생성 
	HashTable은 Node 리스트로 구성되어 있음 
*/
CHashTable * ChainingHashTable::createHashTable(int size)
{
	CHashTable* hashTable = new CHashTable();
	
	hashTable->table = (List*)malloc(sizeof(List) * size);

	hashTable->size = size;

	return hashTable;
}

/*
	Chaining HashTable에 할당된 메모리를 해제함 
*/
void ChainingHashTable::destroyHashTable(CHashTable * hashTable)
{	
	for (int i = 0; i < hashTable->size; i++)
	{
		List l = hashTable->table[i];

		destroyList(l);
	}

	free(hashTable->table);
	free(hashTable);
}

/*
	Chaining HashTable의 해당 address에 생성되어 있는 List의 메모리를 해제 함 
*/
void ChainingHashTable::destroyList(List list)
{
	if (list == NULL)
	{
		return;
	}
	if (list->next != NULL)
	{
		destroyList(list->next);
	}
	destroyNode(list);

}

/*
	Chaining HashTable의 해당 address에 List에 추가될 Key값과 Value값을 가지는 Node를 생성 
*/
CNode * ChainingHashTable::createNode(KeyType key, ValueType vale)
{
	CNode* node = new CNode();

	node->key = key;

	node->value = vale;

	return node;	
}

/*
	Node에 할당된 메모리를 해제 
*/
void ChainingHashTable::destroyNode(CNode * node)
{
	free(node->key);
	free(node->value);
	free(node);
}

/*
	Key 가 입력될 address를 확인하여 value를 저장
	
	이미 동일한 address에 다른 value값이 있다면, 
	생성한 node의 next postion을 기존의 list와 연결함 
*/
void ChainingHashTable::set(CHashTable * hashTable, KeyType key, ValueType value)
{
	int address = hash(key, strlen(key), hashTable->size);
	CNode *node = createNode(key, value);

	//	HashTable의 address에 list에 node가 없는경우, 생성한 node를 지정 함 
	if (hashTable->table[address] == NULL)
	{
		hashTable->table[address] = node;
	}
	else
	{
		//	HashTable의 address에 node가 존재하므로, 
		//	생성한 node의 다음 노드를 기존에 존재하던 node 들의 list로 연결 함 
		List list = hashTable->table[address];
		node->next = list;
		hashTable->table[address] = node;
	}
}


/*
	key를 이용하여 HashTable에 저장된 value를 가져 옴 

	key를 이용하여 해당 HashTable에서 list를 불러오며, 
	list에서 순차적으로 key값을 대조하여 일치 여부를 확인하여 value값을 return 

*/
ValueType ChainingHashTable::get(CHashTable * hashTable, KeyType key)
{
	int address = hash(key, strlen(key), hashTable->size);

	//	HashTable의 address에 위치하는 node들의 list를 가져 옴 
	List list = hashTable->table[address];

	//	검색하고 하는 key 값이 저장된 node를 저장 
	List target = NULL;

	if (list == NULL)
	{
		return NULL;
	}

	while (1)
	{
		//	list에 저장된 key 값과, 전달받은 key 값을 대조하여 target으로 지정 
		if (strcmp(list->key, key) == 0)
		{
			target = list;
			break;
		}

		if (list->next == NULL)
		{
			break;
		}
		else
		{
			//	현재 list가 위치하는 node의 key 값이 전달받은 key 값과 다르므로, 다음 node로 넘어감 
			list = list->next;
		}
	}
	//	target으로 지정된 node의 value 값을 return 
	return target->value;
}

/*
	Chaining 방식으로 hash address를 구함 

	hashValue를 3비트씩 왼쪽으로 이동시키며, key 문자열의 아스키 코드 값만큼 더함 
	이 값을 size 와 모듈러 연산을 통해 최종 hashValue를 return 함 

*/
int ChainingHashTable::hash(KeyType key, int length, int size)
{
	int hashValue = 0;

	for (int i = 0; i < length; i++)
	{
		hashValue = (hashValue << 3) + key[i];

		hashValue = hashValue % size;
	}
	return hashValue;
}
