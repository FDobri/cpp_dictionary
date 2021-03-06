#include <iostream>
#include "CustomVector.h"
#include "CustomLinkedList.h"
#include "CustomDictionary.h"

void PrintCollectionElements(Collection &collection)
{
	std::cout << "========================" << std::endl;
	for (int i = 0; i < collection.GetSize(); i++)
	{
		std::cout << collection.GetElementAt(i)->GetValue() << " ";
	}
	std::cout << std::endl << "========================" << std::endl;
}

void TestInserts(Collection &customCollection)
{
	std::cout << "Inserts:" << std::endl;
	DataContainer* data = new DataContainer(69);
	try
	{
		customCollection.InsertAt(25, data);
	}
	catch (int error)
	{
		std::cout << error << std::endl;
	}

	customCollection.PushToEnd(data);
	PrintCollectionElements(customCollection);
	customCollection.PushToStart(data);
	PrintCollectionElements(customCollection);
	customCollection.InsertAt(15, data);
	PrintCollectionElements(customCollection);
}

void TestRemovals(Collection &customCollection)
{
	std::cout << "Removals:" << std::endl;

	try
	{
		customCollection.Remove(35);
	}
	catch (int error)
	{
		std::cout << error << std::endl;
	}

	customCollection.RemoveFromEnd();
	PrintCollectionElements(customCollection);
	customCollection.RemoveFromStart();
	PrintCollectionElements(customCollection);
	customCollection.Remove(5);
	PrintCollectionElements(customCollection);
}

void TestBubbleSort(Collection &customCollection)
{
	std::cout << "Sorting test:" << std::endl;
	customCollection.BubbleSort();
	PrintCollectionElements(customCollection);
}

int main()
{
	CustomDictionary* dict = new CustomDictionary();
	try
	{
		dict->AddElement(2121, new DataContainer(5));
		char nekiChar[10] = { 'c', 'h', 'a', 'r', 'a', 'c', 't', 'e', 'r', '\0' };
		dict->AddElement(nekiChar, new DataContainer(5));
		dict->RemoveElement(2121);
		dict->RemoveElement(nekiChar);
		dict->AddElement(2121, new DataContainer(5));
		dict->RemoveElement(52309);
	}
	catch (int error)
	{
		std::cout << error << std::endl;
	}

	int x;
	std::cin >> x;
	return 0;
}
