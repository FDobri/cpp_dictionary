#include "IntDictKey.h"

IntDictKey::IntDictKey(int key)
{
	_Key = key;
}

int IntDictKey::GetHashCode()
{
	return _Key * _Key / 2;
}

bool IntDictKey::operator==(DictKey &other)
{
	return _Key == static_cast<IntDictKey*>(&other)->_Key;
}
