#include "DictNode.h"

DictNode::DictNode()
{
}

DictNode::DictNode(DictKey* dictKey, DataContainer* data)
{
	this->dictKey = dictKey;
	this->SetValue(data->GetValue());
}

DictNode::~DictNode()
{
}
