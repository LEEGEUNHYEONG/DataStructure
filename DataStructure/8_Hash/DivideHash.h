#pragma once
#ifndef DIVIDEHASH_H
#define DIVIDEHASH_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

typedef int KeyType;
typedef int ValueType;


typedef struct DivideNode
{
	KeyType key;
	ValueType value;
}DNode;


typedef struct DivideHashTable
{
	int tableSize;
	DNode* table;
}DHashTable;

class DivideHash
{
public:
	DivideHash();
private:
	DHashTable* createHashTable(int size);
	void set(DHashTable* hashtable, KeyType key, ValueType value);
	ValueType get(DHashTable* hasTtable, KeyType key);
	void destroyHashTable(DHashTable* hashTable);
	int hash(KeyType key, int tableSize);	
};

#endif