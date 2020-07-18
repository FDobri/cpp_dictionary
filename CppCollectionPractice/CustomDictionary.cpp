#include "CustomDictionary.h"

CustomDictionary::CustomDictionary()
{
	_HashArray = new CustomLinkedList*[SIZE];
	for (int i = 0; i < SIZE; i++)
	{
		_HashArray[i] = nullptr;
	}
}

CustomDictionary::~CustomDictionary()
{
	delete[] _HashArray;
	_HashArray = nullptr;
}

void CustomDictionary::AddElement(char* key, DataContainer* dc)
{
	StringDictKey* stringKey = new StringDictKey(key);
	DictNode* newNode = new DictNode(stringKey, dc);
	_AddDictNode(_GetHashIndex(stringKey), newNode);
}

void CustomDictionary::AddElement(int key, DataContainer* dc)
{
	IntDictKey* intKey = new IntDictKey(key);
	DictNode* newNode = new DictNode(intKey, dc);
	_AddDictNode(_GetHashIndex(intKey), newNode);
}

void CustomDictionary::RemoveElement(char* key)
{
	StringDictKey* stringKey = new StringDictKey(key);
	_Remove(stringKey);
}

void CustomDictionary::RemoveElement(int key)
{
	IntDictKey* intKey = new IntDictKey(key);
	_Remove(intKey);
}

void CustomDictionary::_Remove(DictKey* key)
{
	CustomLinkedList* list = _HashArray[_GetHashIndex(key)];
	if (list == nullptr || list->GetSize() == 0)
	{
		throw -1;
	}
	CustomLinkedListNode* temp = list->head;
	DictNode* node = static_cast<DictNode*>(temp->data);
	int listSize = list->GetSize();
	int index = 0;
	while (index != listSize)
	{
		if (*node->dictKey == *key)
		{
			break;
		}
		temp = temp->next;
		++index;
	}
	list->Remove(index);
}

unsigned int CustomDictionary::_GetHashIndex(DictKey* dictKey)
{
	return (dictKey->GetHashCode() % SIZE);
}

void CustomDictionary::_AddDictNode(int index, DictNode* data)
{
	if (_HashArray[index] == nullptr)
	{
		_HashArray[index] = new CustomLinkedList();
	}
	else
	{
		int count = 0;
		int linkedListSize = _HashArray[index]->GetSize();

		CustomLinkedListNode* temp = _HashArray[index]->head;

		while (count < linkedListSize)
		{
			DictNode* node = static_cast<DictNode*>(temp->data);
			if ((*node->dictKey) == (*data->dictKey))
			{
				throw - 1;
			}
			++count;
		}
	}
	_HashArray[index]->PushToEnd(data);
}

