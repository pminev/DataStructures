#pragma once
#include <random>
#include <stdlib.h>
#include <ctime>
typedef int keyType;
typedef int valueType;
const int MAX_LEVELS = 5;

class SkipList
{
public:
	SkipList();
	SkipList(const SkipList&);
	SkipList& operator=(const SkipList&);
	~SkipList();

	void insert(keyType, valueType);
	bool remove(keyType);
	valueType find(keyType);

	void printAllLevels();


private:
	struct node
	{
		keyType key;
		valueType value;
		unsigned int numOfLevels;
		node* levels[MAX_LEVELS];

		node(keyType k, valueType v, unsigned int l = 0) :key(k), value(v) {
			numOfLevels = l == 0 ? (rand() % 5 + 1) : 5;
			for (int i = 0; i < numOfLevels; i++) {
				levels[i] = nullptr;
			}
		}

	};

	node* pFront;
	unsigned int size;
	static bool isSeeded;

private:
	void clear();
	void copyFrom(const SkipList&);

	node* findEl(keyType);

};