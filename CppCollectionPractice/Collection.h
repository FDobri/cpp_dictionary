#pragma once
#include "DataContainer.h"

class Collection
{
public:
	virtual ~Collection();
	//sort
	virtual void BubbleSort();

	//inserts
	void PushToEnd(DataContainer* data);
	void PushToStart(DataContainer* data);
	void InsertAt(int index, DataContainer* data);

	//removes
	void RemoveFromEnd();
	void RemoveFromStart();
	void Remove(int index);

	//misc
	virtual int GetSize() = 0;
	DataContainer* GetElementAt(int index);
	void SetElement(int index, DataContainer* dc);
	void SwapElements(int index1, int index2);
private:
	virtual void _SwapElements(int firstIndex, int secondIndex) = 0;

	virtual DataContainer* _GetElementAt(int index) = 0;
	virtual void _InsertAt(int index, DataContainer* data) = 0;
	virtual void _PushToEnd(DataContainer* data) = 0;
	virtual void _PushToStart(DataContainer* data) = 0;
	virtual void _SetElement(int index, DataContainer* dc) = 0;

	virtual void _Remove(int index) = 0;
	virtual void _RemoveFromEnd() = 0;
	virtual void _RemoveFromStart() = 0;

	void _InsertionCheck(int index);
	void _RemovalCheck(int index);
	void _GetElementCheck(int index); //used for both set and get index validation
};