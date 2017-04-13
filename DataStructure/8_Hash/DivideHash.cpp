#include "DivideHash.h"



DivideHash::DivideHash()
{
	cout << "DivideHash Main" << endl;

	DHashTable * hashTable = createHashTable(193);

	set(hashTable, 418, 32114);
	set(hashTable, 9, 514);
	set(hashTable, 27, 8917);
	set(hashTable, 1031, 286);
	set(hashTable, 1119, 19891119);

	cout << "key : " << 418 << " > " << get(hashTable, 418) << endl;
	cout << "key : " << 9 << " > " << get(hashTable, 9) << endl;
	cout << "key : " << 27 << " > " << get(hashTable, 27) << endl;
	cout << "key : " << 1031 << " > " << get(hashTable, 1031) << endl;
	cout << "key : " << 1119 << " > " << get(hashTable, 1119) << endl;

	return;
}

/*
	입력받은 size의 HashTable을 생성 함 
*/
DHashTable * DivideHash::createHashTable(int size)
{
	DHashTable *hashTable = new DHashTable();	
	hashTable->table = (DNode*)malloc(sizeof(DNode) * size);
	hashTable->tableSize = size;

	return hashTable;
}

/*
	HashTable의 key 값의 위치에 value를 입력 
*/
void DivideHash::set(DHashTable * hashTable, KeyType key, ValueType value)
{
	int address = hash(key, hashTable->tableSize);

	hashTable->table[address].key = key;
	hashTable->table[address].value = value;
	
}

/*
	HashTable의 key 값의 위치에 존재하는 value 값을 리턴
*/
ValueType DivideHash::get(DHashTable * hashtable, KeyType key)
{
	int address = hash(key, hashtable->tableSize);

	return hashtable->table[address].value;
}

/*
	HashTable에 할당된 메모리를 해제 
*/
void DivideHash::destroyHashTable(DHashTable * hashTable)
{
	free(hashTable->table);
	free(hashTable);
}

/*
	key 값과 hashTable의 사이즈를 이용하여 저장할 주소를 구함 
	
	* 아래와 같은 나머지를 이용하여 주소를 구하는 방법은 주소의 충돌에 대한 우려가 존재함 *
*/
int DivideHash::hash(KeyType key, int tableSize)
{
	return key % tableSize;
}
