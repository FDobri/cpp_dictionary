#pragma once

class DictKey
{
public:
	virtual ~DictKey() = 0;
	virtual int GetHashCode() = 0;
	
	virtual bool operator == (DictKey &other) = 0;
};
