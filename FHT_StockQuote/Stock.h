#pragma once
#include <string>
#include <vector>
#include "QuoteData.h"

using namespace std;

class Stock
{
private:
	string stockName;
	string WKN;
	string stockShortcut;
	string quoteDataFile;
public:
	Stock();
	Stock(string, string, string);
	~Stock();
	const int MAX_NUMBER_OF_QUOTES = 30;
	vector<QuoteData*> quotes;
	
	string getStockName();
	string getWKN();
	string getStockShortcut();
	void setQuoteDataFile(string);
	string getQuoteDataFile();
	void listQuoteData();
	vector<QuoteData*> getQuotes();
};

