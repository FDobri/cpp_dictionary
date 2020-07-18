#include "DataContainer.h"
#include <iostream>

DataContainer::DataContainer(int x)
{
	_dataValue = x;
}

DataContainer::DataContainer()
{
	_dataValue = 0;
}

int DataContainer::GetValue()
{
	return _dataValue;
}

void DataContainer::SetValue(int x)
{
	_dataValue = x;
}