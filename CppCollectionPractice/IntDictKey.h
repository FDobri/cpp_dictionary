#pragma once
#include "DictKey.h"
class IntDictKey : public DictKey
{
public:
	IntDictKey();
	IntDictKey(int key);
	~IntDictKey();
	int GetHashCode() override;
	bool operator == (DictKey &other) override;
	//bool operator == (IntDictKey* dictKey)
	//{
	//	return _Key == dictKey->_Key;
	//}
private:
	int _Key;
};
