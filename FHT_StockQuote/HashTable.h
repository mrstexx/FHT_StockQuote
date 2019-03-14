#include <iostream>
#include <string>
#include <cmath>
#include "Stock.h"
#pragma once

using namespace std;

class HashTable
{
private:
	Stock* stocks;
	int hashCode(string);
public:
	HashTable();
	~HashTable();
	void add(Stock&);
	void remove(string);
	bool search(string);
	Stock* getStocks();
	int const CAPACITY = 1000;
	// test function
	void listAll();
};

