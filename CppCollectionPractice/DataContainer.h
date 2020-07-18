#pragma once

class DataContainer
{
public:
	DataContainer(int value);
	DataContainer();

public:
	int GetValue();
	void SetValue(int value);

private:
	int _dataValue;
};