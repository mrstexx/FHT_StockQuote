#include <string>
#pragma once

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
	string getStocktName();
	string getWKN();
	string getStockShortcut();
	void setQuoteDataFile(string);
};

