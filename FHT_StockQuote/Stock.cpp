#include "Stock.h"

Stock::Stock()
{}

Stock::Stock(string name, string WKN, string shortcut)
{
	this->stockName = name;
	this->WKN = WKN;
	this->stockShortcut = shortcut;
}

Stock::~Stock()
{}

string Stock::getStocktName()
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
