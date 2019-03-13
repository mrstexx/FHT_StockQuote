#include "HashTable.h"

HashTable::HashTable()
{
	stocks = new Stock[CAPACITY];
}

HashTable::~HashTable()
{}

void HashTable::add(Stock& stock)
{
	int hash = this->hashCode(stock.getStocktName());
	stocks[hash] = stock;
}

void HashTable::remove()
{}

int HashTable::search()
{
	return 0;
}

void HashTable::listAll()
{
	for (int i = 0; i < CAPACITY; i++)
	{
		if (stocks[i].getStocktName() != "")
		{
			cout << stocks[i].getStocktName() << endl;
		}
	}
}

int HashTable::hashCode(string name)
{
	int hash = 0;
	for (int i = 0; i < (int)name.size(); i++)
	{
		hash += (int)(name[i] * pow(31, (int)name.size() - 1));
	}
	return hash % CAPACITY;
}

