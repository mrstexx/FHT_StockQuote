#include "IOHandler.h"

IOHandler::IOHandler(HashTable *hashTable, string fileName)
{
	this->hashTable = hashTable;
	this->fileName = fileName;
}

IOHandler::IOHandler(string fileName)
{
	this->fileName = fileName;
	this->hashTable = new HashTable();
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
			output << stocks[i].getStockName() + "," << stocks[i].getWKN() + "," <<
				stocks[i].getStockShortcut() + "," << stocks[i].getQuoteDataFile() + "\n";
		}
	}
	output.close();
	stocks = NULL;
}

HashTable* IOHandler::loadHashFile()
{
	string stockName = "";
	string WKN = "";
	string stockShortcut = "";
	string stockQuoteDataFileName = "";
	ifstream input;
	input.open(this->fileName + ".csv");
	while (input.good())
	{
		string line = "";
		getline(input, line);
		stringstream ss(line);
		if (input.eof())
		{
			break;
		}
		getline(ss, stockName, ',');
		getline(ss, WKN, ',');
		getline(ss, stockShortcut, ',');
		getline(ss, stockQuoteDataFileName, ',');
		Stock newStock(stockName, WKN, stockShortcut);
		if (stockQuoteDataFileName != "")
		{
			newStock.setQuoteDataFile(stockQuoteDataFileName);
		}
		this->hashTable->add(newStock);
	}
	return this->hashTable;
}

IOHandler::~IOHandler()
{}