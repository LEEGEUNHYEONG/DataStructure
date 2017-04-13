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
	�Է¹��� size�� HashTable�� ���� �� 
*/
DHashTable * DivideHash::createHashTable(int size)
{
	DHashTable *hashTable = new DHashTable();	
	hashTable->table = (DNode*)malloc(sizeof(DNode) * size);
	hashTable->tableSize = size;

	return hashTable;
}

/*
	HashTable�� key ���� ��ġ�� value�� �Է� 
*/
void DivideHash::set(DHashTable * hashTable, KeyType key, ValueType value)
{
	int address = hash(key, hashTable->tableSize);

	hashTable->table[address].key = key;
	hashTable->table[address].value = value;
	
}

/*
	HashTable�� key ���� ��ġ�� �����ϴ� value ���� ����
*/
ValueType DivideHash::get(DHashTable * hashtable, KeyType key)
{
	int address = hash(key, hashtable->tableSize);

	return hashtable->table[address].value;
}

/*
	HashTable�� �Ҵ�� �޸𸮸� ���� 
*/
void DivideHash::destroyHashTable(DHashTable * hashTable)
{
	free(hashTable->table);
	free(hashTable);
}

/*
	key ���� hashTable�� ����� �̿��Ͽ� ������ �ּҸ� ���� 
	
	* �Ʒ��� ���� �������� �̿��Ͽ� �ּҸ� ���ϴ� ����� �ּ��� �浹�� ���� ����� ������ *
*/
int DivideHash::hash(KeyType key, int tableSize)
{
	return key % tableSize;
}
