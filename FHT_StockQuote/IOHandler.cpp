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
	Stock** stocks = this->hashTable->getStocks();
	for (int i = 0; i < hashTable->CAPACITY; i++)
	{
		if (stocks[i]->getStockName() != "")
		{
			output << stocks[i]->getStockName() + "," << stocks[i]->getWKN() + "," <<
				stocks[i]->getStockShortcut() + "," << stocks[i]->getQuoteDataFile() + "\n";
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
		Stock* newStock = new Stock(stockName, WKN, stockShortcut);
		if (stockQuoteDataFileName != "")
		{
			newStock->setQuoteDataFile(stockQuoteDataFileName);
		}
		this->hashTable->add(newStock);
	}
	return this->hashTable;
}

void IOHandler::importQuoteData(Stock *stock)
{
	stock->setQuoteDataFile(this->fileName);
	string date = "";
	string open = "";
	string high = "";
	string low = "";
	string close = "";
	string adjClose = "";
	string volume = "";
	ifstream input;
	string tmpLine = "";
	int counter = 0;
	input.open(this->fileName + ".csv");
	getline(input, tmpLine);
	while (input.good() || counter < stock->MAX_NUMBER_OF_QUOTES)
	{
		string line = "";
		getline(input, line);
		stringstream ss(line);
		if (input.eof())
		{
			break;
		}
		getline(ss, date, ',');
		getline(ss, open, ',');
		getline(ss, high, ',');
		getline(ss, low, ',');
		getline(ss, close, ',');
		getline(ss, adjClose, ',');
		getline(ss, volume, ',');
		QuoteData *quote = new QuoteData(date, stod(open), stod(high), stod(low), stod(close), stod(adjClose), stoi(volume));
		//quotes[counter] = qd;
		stock->quotes.push_back(quote);
	}
}

IOHandler::~IOHandler()
{}