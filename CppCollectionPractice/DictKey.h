#pragma once

class DictKey
{
public:
	virtual bool operator == (DictKey &other) = 0;

public:
	virtual int GetHashCode() = 0;
};
