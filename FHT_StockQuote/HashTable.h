#include <iostream>
#include <string>
#include <cmath>
#include "Stock.h"
#pragma once

using namespace std;

class HashTable
{
private:
	int const CAPACITY = 1000;
	Stock* stocks;
	int hashCode(string);
public:
	HashTable();
	~HashTable();
	void add(Stock&);
	void remove(string);
	bool search(string);

	// test function
	void listAll();
};

