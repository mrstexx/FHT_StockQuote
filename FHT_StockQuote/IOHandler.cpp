#include "IOHandler.h"

IOHandler::IOHandler(HashTable *hashTable, string fileName)
{
	this->hashTable = hashTable;
	this->fileName = fileName;
}

IOHandler::IOHandler(string fileName)
{
	this->fileName = fileName;
}

void IOHandler::saveHashFile()
{
	ofstream output;
	output.open(this->fileName + ".csv");
	Stock* stocks = this->hashTable->getStocks();
	for (int i = 0; i < hashTable->CAPACITY; i++)
	{
		if (stocks[i].getStockName() != "")
		{
			output << i << "," << stocks[i].getStockName() + "," << stocks[i].getWKN() + "," << 
				stocks[i].getStockShortcut() + "," << stocks[i].getQuoteDataFile() + "\n";
		}
	}
	output.close();
	stocks = NULL;
}

HashTable* IOHandler::loadHashFile()
{
	ifstream input;
	input.open(this->fileName + ".csv");
	string temp = "";
	while (!input.eof())
	{
		string line = "";
		getline(input, line);
		stringstream lineAsStream (line);
		string word = "";
		while (lineAsStream >> word)
		{
			cout << word << endl;
		}
		//cout << line << endl;
	}
	return this->hashTable;
}

IOHandler::~IOHandler()
{
	delete this->hashTable;
	this->hashTable = nullptr;
}