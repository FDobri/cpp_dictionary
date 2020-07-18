#pragma once
#include "CustomVector.h"
#include "DictNode.h"
#include "StringDictKey.h"
#include "IntDictKey.h"

class CustomDictionary
{
public:
	CustomDictionary();
	~CustomDictionary();

private:
	CustomLinkedList** _HashArray;
	unsigned int _GetHashIndex(DictKey* dictKey);
	void _AddDictNode(int index, DictNode* data);
	void _Remove(DictKey* key);

public:
	static const unsigned int SIZE = 1024;
	void AddElement(char* key, DataContainer* dc);
	void AddElement(int key, DataContainer* dc);
	void RemoveElement(char* key);
	void RemoveElement(int key);
};
