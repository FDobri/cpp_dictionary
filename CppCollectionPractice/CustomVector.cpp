#include <iostream>
#include "CustomVector.h"

#pragma region Setup

CustomVector::CustomVector()
{
	_allocatedSize = INITIAL_ARRAY_SIZE;
	_vectorArray = (DataContainer*)malloc(_allocatedSize * sizeof(DataContainer));
	_size = 0;
}

CustomVector::CustomVector(int desiredSize)
{
	_vectorArray = (DataContainer*)malloc(desiredSize * sizeof(DataContainer));
	_size = 0;
	_allocatedSize = desiredSize;
}

CustomVector::~CustomVector()
{
	if (_allocatedSize != 0)
	{
		free(_vectorArray);
	}
	_vectorArray = nullptr;
}

#pragma endregion

#pragma region Inserts

void CustomVector::_PushToEnd(DataContainer* value)
{
	_AllocateAndInsert(_size, value);
}

void CustomVector::_PushToStart(DataContainer* value)
{
	_AllocateAndInsert(0, value);
}

void CustomVector::_InsertAt(int index, DataContainer* value)
{
	_AllocateAndInsert(index, value);
}

#pragma endregion

#pragma region Removes

void CustomVector::_RemoveFromEnd()
{
	_AllocateAndRemove(_size - 1);
}

void CustomVector::_RemoveFromStart()
{
	_AllocateAndRemove(0);
}


void CustomVector::_Remove(int index)
{
	_AllocateAndRemove(index);
}

#pragma endregion

#pragma region Misc

int CustomVector::GetSize()
{
	return _size;
}

DataContainer* CustomVector::_GetElementAt(int index)
{
	return &_vectorArray[index];
}

void CustomVector::_SetElement(int index, DataContainer* data)
{
	_vectorArray[index] = *data;
}

void CustomVector::_SwapElements(int index1, int index2)
{
	DataContainer temp = _vectorArray[index2];
	_vectorArray[index2] = _vectorArray[index1];
	_vectorArray[index1] = temp;
}

#pragma endregion

#pragma region Private

void CustomVector::_AllocateAndInsert(int index, DataContainer* elementToInsert)
{
	++_size;
	int requiredAllocatedSize = _GetRequiredAllocatedSize(_size);
	if (requiredAllocatedSize != _allocatedSize)
	{
		_allocatedSize = requiredAllocatedSize;
		DataContainer* temp = (DataContainer*)malloc(_allocatedSize * sizeof(DataContainer));
		for (int i = 0; i < index; i++)
		{
			temp[i] = _vectorArray[i];
		}
		temp[index] = *elementToInsert;
		for (int i = index; i < _size - 1; i++)
		{
			temp[i + 1] = _vectorArray[i];
		}
		free(_vectorArray);
		_vectorArray = temp;
		temp = nullptr;
	}
	else
	{
		if (index == _size)
		{
			_vectorArray[index] = *elementToInsert;
		}
		else
		{
			for (int i = _size - 1; i > index; --i)
			{
				_vectorArray[i] = _vectorArray[i - 1];
			}
			_vectorArray[index] = *elementToInsert;
		}
	}
}

void CustomVector::_AllocateAndRemove(int index)
{
	int requiredAllocatedSize = _GetRequiredAllocatedSize(_size);
	if (_allocatedSize == requiredAllocatedSize)
	{
		for (int i = index; i < _size - 1; ++i)
		{
			_vectorArray[i] = _vectorArray[i + 1];
		}
	}
	else
	{
		//realloc could be very useful here
		DataContainer* temp = (DataContainer*)malloc((_allocatedSize * sizeof(DataContainer)));
		for (int i = 0; i < index; i++)
		{
			temp[i] = _vectorArray[i];
		}
		for (int i = index; i < _size - 1; ++i)
		{
			temp[i] = _vectorArray[i + 1];
		}
	}
	--_size;
}

int CustomVector::_GetRequiredAllocatedSize(int size)
{
	int tempSize = 2;
	while (tempSize < size)
	{
		tempSize *= 2;
	}

	return tempSize;
}

#pragma endregion