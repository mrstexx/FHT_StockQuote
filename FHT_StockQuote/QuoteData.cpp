#include "QuoteData.h"

QuoteData::QuoteData()
{}

QuoteData::QuoteData(string date, double open, double high, double low, double close, double adjClose, int volume)
{
	this->date = date;
	this->open = open;
	this->high = high;
	this->low = low;
	this->close = close;
	this->adjClose = adjClose;
	this->volume = volume;
}

string QuoteData::getDate()
{
	return this->date;
}

double QuoteData::getOpen()
{
	return this->open;
}

double QuoteData::getHigh()
{
	return this->high;
}

double QuoteData::getLow()
{
	return this->low;
}

double QuoteData::getClose()
{
	return this->close;
}

double QuoteData::getAdjClose()
{
	return this->adjClose;
}

int QuoteData::getVolume()
{
	return this->volume;
}

QuoteData::~QuoteData()
{}