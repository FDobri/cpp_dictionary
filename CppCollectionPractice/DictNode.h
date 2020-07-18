#pragma once
#include "DataContainer.h"
#include "CustomLinkedList.h"
#include "DictKey.h"

class DictNode : public DataContainer
{
public:
	DictNode(DictKey* dictKey, DataContainer* data);

public:
	DictKey* dictKey;
};
