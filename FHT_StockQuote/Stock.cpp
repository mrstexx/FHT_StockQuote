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

vector<QuoteData*> Stock::getQuotes()
{
	return this->quotes;
}

void Stock::listQuoteData()
{
	if (quotes.size() == 0)
	{
		cout << "Es gibt keine gespeicherte Aktienskursdaten" << endl;
		return;
	}
	for (unsigned int i = 0; i < quotes.size(); i++)
	{
		cout << quotes[i]->getDate() << " - " << quotes[i]->getOpen() << " - "
			<< quotes[i]->getHigh() << " - " << quotes[i]->getLow() << " - "
			<< quotes[i]->getClose() << " - " << quotes[i]->getAdjClose() << " - "
			<< quotes[i]->getVolume() << endl;
	}
}

Stock::~Stock()
{}