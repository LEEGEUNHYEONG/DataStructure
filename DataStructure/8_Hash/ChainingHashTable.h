#pragma once
#ifndef CHAININGHASHTABLE_H
#define CHAININGHASHTABLE_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

typedef char* KeyType;
typedef char* ValueType;

typedef struct ChaningNode
{
	KeyType key;
	ValueType value;

	struct ChaningNode* next;
}CNode;

typedef CNode* List;

typedef struct ChaningHashTable
{
	int size;
	List* table;
	
}CHashTable;


class ChainingHashTable
{
public:
	ChainingHashTable();	
private:
	CHashTable* createHashTable(int size);
	void destroyHashTable(CHashTable* hashTable);
	void destroyList(List list);
	CNode* createNode(KeyType key, ValueType vale);
	void destroyNode(CNode* node);
	void set(CHashTable* hashTable, KeyType key, ValueType value);
	ValueType get(CHashTable* hashTable, KeyType key);
	int hash(KeyType key, int length, int size);
};

#endif