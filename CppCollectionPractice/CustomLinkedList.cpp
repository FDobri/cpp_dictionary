#include <iostream>
#include "CustomLinkedList.h"
#include "CustomLinkedListNode.h"

CustomLinkedList::CustomLinkedList()
{
	_size = 0;
	head = nullptr;
	tail = nullptr;
}

CustomLinkedList::~CustomLinkedList()
{
	CustomLinkedListNode* temp = head;
	while (_LoopEndConditionMet(temp->next))
	{
		CustomLinkedListNode* current = temp;
		temp = temp->next;
		delete current;
		current = nullptr;
	}
	head = nullptr;
	tail = nullptr;
}

int CustomLinkedList::GetSize()
{
	return _size;
}

DataContainer* CustomLinkedList::_GetElementAt(int index)
{
	int count = 0;
	CustomLinkedListNode* temp = head;
	while (_IndexLoopConditionMet(count, index))
	{
		++count;
		temp = temp->next;
		if (count == index)
		{
			break;
		}
	}
	return temp->data;
}

void CustomLinkedList::_SetElement(int index, DataContainer* data)
{
	int count = 0;
	CustomLinkedListNode* temp = head;
	while (_IndexLoopConditionMet(count, index))
	{
		++count;
		temp = temp->next;
		if (count == index)
		{
			break;
		}
	}
	temp->data = data;
}

void CustomLinkedList::_SwapElements(int index1, int index2)
{
	int lesserIndex, greaterIndex;
	if (index1 <= index2)
	{
		lesserIndex = index1;
		greaterIndex = index2;
	}
	else
	{
		lesserIndex = index2;
		greaterIndex = index1;
	}
	CustomLinkedListNode* firstNode = head;
	CustomLinkedListNode* secondNode = head;
	int count = 0;
	while (_IndexLoopConditionMet(count, lesserIndex))
	{
		++count;
		firstNode = firstNode->next;
	}
	secondNode = firstNode;
	while (_IndexLoopConditionMet(count, greaterIndex))
	{
		++count;
		secondNode = secondNode->next;
	}
	DataContainer* temp = firstNode->data;
	firstNode->data = secondNode->data;
	secondNode->data = temp;
}

void CustomLinkedList::_InsertAt(int index, DataContainer* data)
{
	int count = 0;
	CustomLinkedListNode* newNode = new CustomLinkedListNode(data);

	if (index != 0 && index != _size)
	{
		++_size;
		CustomLinkedListNode* elementBefore = head;
		CustomLinkedListNode* elementAfter = nullptr;
		while (count < index - 1)
		{
			++count;
			elementBefore = elementBefore->next;
		}
		elementAfter = elementBefore->next;
		elementBefore->next = newNode;
		newNode->next = elementAfter;
	}
	else if (index == 0)
	{
		_PushToStart(data);
	}
	else
	{
		_PushToEnd(data);
	}
}

void CustomLinkedList::_PushToEnd(DataContainer* data)
{
	CustomLinkedListNode* newNode = new CustomLinkedListNode(data);
	if (head != nullptr)
	{
		tail->next = newNode;
		tail = newNode;
	}
	else
	{
		head = newNode;
		tail = newNode;
	}
	++_size;
}

void CustomLinkedList::_PushToStart(DataContainer* data)
{
	CustomLinkedListNode* newNode = new CustomLinkedListNode(data);
	if (head != nullptr)
	{
		CustomLinkedListNode* temporaryNode = head;
		head = newNode;
		head->next = temporaryNode;
	}
	else
	{
		head = newNode;
		tail = newNode;
	}
	++_size;
}

void CustomLinkedList::_Remove(int index)
{
	if (index != 0 && index != _size - 1)
	{
		CustomLinkedListNode* previousNode = head;
		CustomLinkedListNode* currentNode = head;
		int count = 0;
		while (_IndexLoopConditionMet(count, index))
		{
			++count;
			previousNode = currentNode;
			currentNode = currentNode->next;
		}
		previousNode->next = currentNode->next;
		delete currentNode;
		currentNode = nullptr;
		previousNode = nullptr;
		delete previousNode;
		--_size;
	}
	else if (index == 0)
	{
		_RemoveFromStart();
	}
	else
	{
		_RemoveFromEnd();
	}
}

void CustomLinkedList::_RemoveFromEnd()
{
	CustomLinkedListNode* previousNode = head;
	CustomLinkedListNode* currentNode = head;
	while ((_LoopEndConditionMet(currentNode->next)))
	{
		previousNode = currentNode;
		currentNode = currentNode->next;
	}
	delete currentNode;
	tail = previousNode;
	tail->next = nullptr;
	previousNode = nullptr;
	delete previousNode;
	--_size;
}

void CustomLinkedList::_RemoveFromStart()
{
	CustomLinkedListNode* temp = head;
	head = head->next;
	delete temp;
	temp = nullptr;
	--_size;
}

bool CustomLinkedList::_IndexLoopConditionMet(int c, int i)
{
	return (c != i);
}

bool CustomLinkedList::_LoopEndConditionMet(CustomLinkedListNode* node)
{
	return node != nullptr;
}
