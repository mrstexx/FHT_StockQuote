#include <iostream>
#include <sstream>
#include <fstream>
#include <ostream>
#include "HashTable.h"
#include "QuoteData.h"

#pragma once

using namespace std;

class IOHandler
{
private:
	HashTable* hashTable;
	string fileName;
public:
	IOHandler(HashTable*, string);
	IOHandler(string);
	~IOHandler();
	void saveHashFile();
	HashTable* loadHashFile();
	void importQuoteData(Stock*);
};

