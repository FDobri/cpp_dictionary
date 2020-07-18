#pragma once
#include "DictKey.h"

class StringDictKey : public DictKey
{
public:
	StringDictKey(char* key);

	bool operator == (DictKey &other) override;

public:
	int GetHashCode() override;

private:
	char* _Key;
};
