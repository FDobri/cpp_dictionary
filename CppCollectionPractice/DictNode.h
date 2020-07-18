#pragma once
#include "DataContainer.h"
#include "CustomLinkedList.h"
#include "DictKey.h"

class DictNode : public DataContainer
{
public:
	DictNode();
	DictNode(DictKey* dictKey, DataContainer* data);
	~DictNode();

	DictKey* dictKey;
};
