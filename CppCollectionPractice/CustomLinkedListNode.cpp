#include "CustomLinkedListNode.h"

CustomLinkedListNode::CustomLinkedListNode(DataContainer* dataContainer)
{
	data = dataContainer;
	next = nullptr;
}

CustomLinkedListNode::~CustomLinkedListNode()
{
	next = nullptr;
}
