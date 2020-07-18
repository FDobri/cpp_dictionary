#pragma once
#include "DictKey.h"

class StringDictKey : public DictKey
{
public:
	StringDictKey();
	StringDictKey(char* key);
	~StringDictKey();
	int GetHashCode() override;
	bool operator == (DictKey &other) override;
private:
	char* _Key;
};
