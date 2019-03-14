#include "HashTable.h"

HashTable::HashTable()
{
	stocks = new Stock[CAPACITY]();
}

void HashTable::add(Stock& stock)
{
	int i = 1;
	int hash = (int)(this->hashCode(stock.getStockName()) + pow(i, 2)) % CAPACITY;
	while (stocks[hash].getStockName() != "")
	{
		i++;
		hash = (int)(this->hashCode(stock.getStockName()) + pow(i, 2)) % CAPACITY;
	}
	stocks[hash] = stock;
}

void HashTable::remove(string userInput)
{
	int i = 0;
	while (i < CAPACITY)
	{
		int hash = (int)(this->hashCode(userInput) + pow(i + 1, 2)) % CAPACITY;
		if (stocks[hash].getStockName() == userInput)
		{
			Stock *replaceStock = new Stock();
			stocks[hash] = *replaceStock;
			break;
		}
		i++;
	}
}

bool HashTable::search(string userInput)
{
	int i = 0;
	while (i < CAPACITY)
	{
		int hash = (int)(this->hashCode(userInput) + pow(i + 1, 2)) % CAPACITY;
		if (stocks[hash].getStockName() == userInput)
		{
			return true;
		}
		i++;
	}
	return false;
}

void HashTable::listAll()
{
	for (int i = 0; i < CAPACITY; i++)
	{
		if (stocks[i].getStockName() != "")
		{
			cout << stocks[i].getStockName() << endl;
		}
	}
}

int HashTable::hashCode(string name)
{
	int hash = 0;
	int hashBase = 31;
	for (int i = 0; i < (int)name.size(); i++)
	{
		hash = (hash * hashBase + name[i]);
	}
	hash %= CAPACITY;
	if (hash < 0)
	{
		hash += CAPACITY;
	}
	//cout << "******" << hash << endl;
	return hash;
}

Stock *HashTable::getStocks()
{
	return this->stocks;
}

HashTable::~HashTable()
{
	delete[] stocks;
	stocks = nullptr;
}