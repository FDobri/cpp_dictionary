#pragma once
#include "DictKey.h"

class IntDictKey : public DictKey
{
public:
	IntDictKey(int key);

	bool operator == (DictKey &other) override;

public:
	int GetHashCode() override;

private:
	int _Key;
};
