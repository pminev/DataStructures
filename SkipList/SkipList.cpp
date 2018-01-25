#include "SkipList.h"
#include <iostream>

SkipList::SkipList()
{
	pFront = nullptr;
	size = 0;
}

SkipList::SkipList(const SkipList& other)
{
	copyFrom(other);
}

SkipList& SkipList::operator=(const SkipList& other)
{
	if (this != &other)
	{
		clear();
		copyFrom(other);
	}

	return *this;
}

SkipList::~SkipList()
{
	clear();
}

void SkipList::copyFrom(const SkipList &other)
{
	node* otherNode = other.pFront;
	while (otherNode != nullptr)
	{
		insert(otherNode->key, otherNode->value);
		otherNode = otherNode->levels[0];
	}
}

SkipList::node * SkipList::findEl(keyType key)
{
	node* it = pFront;
	unsigned int num = pFront->numOfLevels;
	for (int i = num; i >0; i--)
	{
		while (it->levels[i - 1] != nullptr && it->levels[i - 1]->key <= key)
		{
			it = it->levels[i - 1];
			if (it->key == key)
				return it;
		}
	}

	return nullptr;
}

void SkipList::printAllLevels()
{
	for (int i = 4; i >= 0; i--)
	{
		std::cout << (i + 1) << ". ";
		node* it = pFront;
		for (int j = 0; j < size; j++)
		{
			if (i < it->numOfLevels) {
				std::cout << it->key << "  ";
			}
			else {
				std::cout << "    ";
			}
			it = it->levels[0];
		}
		std::cout << '\n';
	}
}

void SkipList::clear()
{
	node* destroyer;
	while (pFront != nullptr)
	{
		destroyer = pFront;
		pFront = pFront->levels[0];
		delete destroyer;
	}

	size = 0;
}

void SkipList::insert(keyType key, valueType val)
{
	if (size == 0) {
		pFront = new node(key, val, MAX_LEVELS);
		size++;
		return;
	}

	node* newEl = new node(key, val);
	node* it = pFront;
	unsigned int num = it->numOfLevels;

	while (num != 0) {
		//Skips elements forward reaching new correct destination		
		while (it->levels[num - 1] != nullptr && it->levels[num - 1]->key < key)
		{
			it = it->levels[num - 1];
		}
		//Redirect pointers of same levels
		if (num - 1 < newEl->numOfLevels)
		{
			node * next = it->levels[num - 1];
			it->levels[num - 1] = newEl;
			newEl->levels[num - 1] = next;
		}
		num--;
	}
	size++;
}

bool SkipList::remove(keyType key)
{
	if (size == 0) {
		return false;
	}

	node* it = pFront;
	unsigned int num = it->numOfLevels;
	node* found = findEl(key);

	if (found==nullptr)
		return false;

	//take care of redirection of pointers

	return true;
}

bool SkipList::find(keyType key)
{

	return (findEl(key)==nullptr) ? false:true;
}
