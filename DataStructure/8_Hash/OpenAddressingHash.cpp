#include "OpenAddressingHash.h"


OpenAddressingHash::OpenAddressingHash()
{
	cout << "Open Addressing Hash" << endl;

	HashTable* hashTable = createHashTable(11);

	set(&hashTable, "MSFT", "Microsft Corporation");
	set(&hashTable, "JAVA", "Oracle");
	set(&hashTable, "REDH", "Red Hat Linux");
	set(&hashTable, "APAC", "Apache Org");
	set(&hashTable, "IBM", "IBM Ltd.");
	set(&hashTable, "ZYMZZ", "Unisys Ops Check");
	set(&hashTable, "ORCL", "Oracle Corporation");
	set(&hashTable, "CSCO", "Cisco Systems Inc.");
	set(&hashTable, "GOOG", "Google Inc.");
	set(&hashTable, "YHOO", "Yahoo Inc.");
	set(&hashTable, "BIZD", "Blizzard Entertainment");

	cout << endl;

	cout << "MSFT > " << get(hashTable, "MSFT") << endl;
	cout << "JAVA > " << get(hashTable, "JAVA") << endl;
	cout << "REDH > " << get(hashTable, "REDH") << endl;
	cout << "APAC > " << get(hashTable, "APAC") << endl;
	cout << "IBM > " << get(hashTable, "IBM") << endl;
	cout << "ZYMZZ > " << get(hashTable, "ZYMZZ") << endl;
	cout << "ORCL > " << get(hashTable, "ORCL") << endl;
	cout << "CSCO > " << get(hashTable, "CSCO") << endl;
	cout << "BIZD > " << get(hashTable, "BIZD") << endl;
	cout << "GOOG > " << get(hashTable, "GOOG") << endl;
	
}


OpenAddressingHash::~OpenAddressingHash()
{
}

/*
	size 크기의 HashTable을 생성 함 
*/
HashTable * OpenAddressingHash::createHashTable(int size)
{
	HashTable* hashTable = (HashTable*)malloc(sizeof(HashTable));
	//HashTable* hashTable = new HashTable();	
	hashTable->table = (ElementType*)malloc(sizeof(ElementType) * size);

	memset(hashTable->table, 0, sizeof(ElementType) * size);

	hashTable->tableSize = size;
	hashTable->occupiedCount = 0;

	return hashTable;
}

/*
	HashTable에 할당된 메모리를 해제
*/
void OpenAddressingHash::destroyHashTable(HashTable * hashTable)
{
	for (int i = 0; i < hashTable->tableSize; i++)
	{
		//	table 의 각 항목들을 자유 저장소에서 제거
		clearElement(&(hashTable->table[i]));
	}

	free(hashTable->table);
	free(hashTable);
}

/*
	Element 의 각 값들에 대한 메모리를 해제
*/
void OpenAddressingHash::clearElement(ElementType * element)
{
	if (element->status == EMPTY)
	{
		return;
	}
	free(element->key);
	free(element->value);
}

/*

*/
void OpenAddressingHash::set(HashTable ** hashTable, keyType key, valueType value)
{
	int keyLen, address, step;
	double useage;

	//	Hash 의 사용량이 50% 넘어간 경우 새롭게 해싱을 수행 함 
	useage = (double)(*hashTable)->occupiedCount / (*hashTable)->tableSize;
	
	if (useage > 0.5)
	{
		rehash(hashTable);
	}

	keyLen = strlen(key);
	address = hash(key, keyLen, (*hashTable)->tableSize);
	step = hash2(key, keyLen, (*hashTable)->tableSize);
	
	while ((*hashTable)->table[address].status != EMPTY 
		&& strcmp((*hashTable)->table[address].key, key) != 0)
	{		
		address = (address + step) % (*hashTable)->tableSize;
		//cout << "set : collision : key : " << key << " address : " << address << " step : " << step << endl;
	}

	(*hashTable)->table[address].key = (char*)malloc(sizeof(char) * (keyLen + 1));
	strcpy((*hashTable)->table[address].key, key);

	(*hashTable)->table[address].value = (char*)malloc(sizeof(char) * (strlen(value) + 1));
	strcpy((*hashTable)->table[address].value, value);

	(*hashTable)->table[address].status = OCCUPIED;
	(*hashTable)->occupiedCount++;

	cout << "key : " << key << " enter address : " << address << endl;
}

valueType OpenAddressingHash::get(HashTable * hashTable, keyType key)
{
	int keyLen = strlen(key);
	int address = hash(key, keyLen, hashTable->tableSize);
	int step = hash2(key, keyLen, hashTable->tableSize);

	//cout << "get : " << keyLen << " address : " << address << " step : " << step << endl;

	while (hashTable->table[address].status != EMPTY &&
		strcmp(hashTable->table[address].key, key) != 0)
	{
		address = (address + step) % hashTable->tableSize;
	}
	return hashTable->table[address].value;
}

int OpenAddressingHash::hash(keyType key, int length, int size)
{
	int hashValue = 0;

	for (int i = 0; i < length; i++)
	{
		hashValue = (hashValue << 3) + key[i];
	}

	hashValue = hashValue % size;

	return hashValue;
}

int OpenAddressingHash::hash2(keyType key, int length, int size)
{
	int hashValue = 0;

	for (int i = 0; i < length; i++)
	{
		hashValue = (hashValue << 2) + key[i];
	}

	hashValue = hashValue % (size - 3 );

	return hashValue + 1;
}

void OpenAddressingHash::rehash(HashTable ** hashTable)
{
	ElementType* oldTable = (*hashTable)->table;

	HashTable* newHashTable = createHashTable((*hashTable)->tableSize * 2);
	cout << "\nRe Hash Table size : " << newHashTable->tableSize << endl << endl;

	for (int i = 0; i < (*hashTable)->tableSize; i++)
	{
		if (oldTable[i].status == OCCUPIED)
		{
			set(&newHashTable, oldTable[i].key, oldTable[i].value);
		}
	}

	destroyHashTable(*hashTable);
	(*hashTable) = newHashTable;
}
