#include "DictNode.h"

DictNode::DictNode(DictKey* dictKey, DataContainer* data)
{
	this->dictKey = dictKey;
	this->SetValue(data->GetValue());
}
