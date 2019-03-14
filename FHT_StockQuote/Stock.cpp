#include "Stock.h"

Stock::Stock()
{
	this->stockName = "";
	this->WKN = "";
	this->stockShortcut = "";
	this->quoteDataFile = "";
}

Stock::Stock(string name, string WKN, string shortcut)
{
	this->stockName = name;
	this->WKN = WKN;
	this->stockShortcut = shortcut;
	this->quoteDataFile = "";
}

string Stock::getStockName()
{
	return this->stockName;
}

string Stock::getWKN()
{
	return this->WKN;
}

string Stock::getStockShortcut()
{
	return this->stockShortcut;
}

void Stock::setQuoteDataFile(string fileName)
{
	this->quoteDataFile = fileName;
}

string Stock::getQuoteDataFile()
{
	return this->quoteDataFile;
}

Stock::~Stock()
{}