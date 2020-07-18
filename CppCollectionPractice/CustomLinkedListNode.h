#pragma once
#include "DataContainer.h"
#include "CustomLinkedListNode.h"

class CustomLinkedListNode
{
public:
	CustomLinkedListNode(DataContainer* data);
	~CustomLinkedListNode();

public:
	DataContainer* data;
	CustomLinkedListNode* next;
};
