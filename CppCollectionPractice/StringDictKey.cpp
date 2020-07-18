#include "StringDictKey.h"
#include <string.h>

StringDictKey::StringDictKey()
{
}

StringDictKey::StringDictKey(char* key)
{
	_Key = key;
}


StringDictKey::~StringDictKey()
{
}

int StringDictKey::GetHashCode()
{
	size_t len = strlen(_Key);
	int result = 0;
	for (int i = 0; i < len; i++)
	{
		result += _Key[i];
	}
	return result * result;
}

bool StringDictKey::operator==(DictKey &other)
{
	if (strcmp(_Key, dynamic_cast<StringDictKey*>(&other)->_Key) != 0)
	{
		return false;
	}
	return true;
}
