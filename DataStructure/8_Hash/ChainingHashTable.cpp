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

CHashTable * ChainingHashTable::createHashTable(int size)
{
	CHashTable* hashTable = new CHashTable();
	
	hashTable->table = (List*)malloc(sizeof(List) * size);

	hashTable->size = size;

	return hashTable;
}

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

CNode * ChainingHashTable::createNode(KeyType key, ValueType vale)
{
	CNode* node = new CNode();

	node->key = key;

	node->value = vale;

	return node;	
}

void ChainingHashTable::destroyNode(CNode * node)
{
	free(node->key);
	free(node->value);
	free(node);
}

void ChainingHashTable::set(CHashTable * hashTable, KeyType key, ValueType value)
{
	int address = hash(key, strlen(key), hashTable->size);
	CNode *node = createNode(key, value);

	if (hashTable->table[address] == NULL)
	{
		hashTable->table[address] = node;
	}
	else
	{
		List list = hashTable->table[address];
		node->next = list;
		hashTable->table[address] = node;
	}

}

ValueType ChainingHashTable::get(CHashTable * hashTable, KeyType key)
{
	int address = hash(key, strlen(key), hashTable->size);

	List list = hashTable->table[address];

	List target = NULL;

	if (list == NULL)
	{
		return NULL;
	}

	while (1)
	{
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
			list = list->next;
		}
	}
	return target->value;
}

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
