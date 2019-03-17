#pragma once
#include <iostream>

using namespace std;

class QuoteData
{
private:
	string date = "";
	double open = 0;
	double high = 0;
	double low = 0;
	double close = 0;
	double adjClose = 0;
	int volume = 0;
public:
	QuoteData();
	QuoteData(string, double, double, double, double, double, int);
	~QuoteData();
	string getDate();
	double getOpen();
	double getHigh();
	double getLow();
	double getClose();
	double getAdjClose();
	int getVolume();
};

