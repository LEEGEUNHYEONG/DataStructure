#pragma once
#ifndef OPENADDRESSINGHASH_H
#define OPENADDRESSINGHASH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;

typedef char* keyType;
typedef char* valueType;

enum ElementStatus
{
	EMPTY = 0,
	OCCUPIED = 1
};

typedef struct tagElementType
{
	keyType key;
	valueType value;


	enum ElementStatus status;
}ElementType;

typedef struct tagHashTable
{
	int occupiedCount;
	int tableSize;

	ElementType* table;
}HashTable;


class OpenAddressingHash
{
public:
	OpenAddressingHash();
	~OpenAddressingHash();
private:
	HashTable* createHashTable(int size);
	void destroyHashTable(HashTable* hashTable);
	void clearElement(ElementType* element);

	void set(HashTable** hashTable, keyType key, valueType value);
	valueType get(HashTable* hashTable, keyType key);
	int hash(keyType key, int length, int size);
	int hash2(keyType key, int length, int size);

	void rehash(HashTable** hashTable);

};

#endif // q!