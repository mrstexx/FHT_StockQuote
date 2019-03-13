#include "HashTable.h"
#include "Stock.h"
#pragma once

#define ADD 1
#define DEL 2
#define IMPORT 3
#define SEARCH 4
#define PLOT 5
#define SAVE 6
#define LOAD 7
#define QUIT 8

class MainMenu
{
private:
	// UI
	void printHeader();
	void printCategoryNavigation();
	void printMainMenu();
	void cleanScreen();

	// handling user inputs
	void inputHandler();
	void addNewStock();
	void deleteStock();
	void importStockQuote();
	void searchStock();
	void plotStockQuote();
	void saveHashTable();
	void loadHashTable();
	
	// hash table
	HashTable* hashTable;
public:
	MainMenu();
	~MainMenu();
};

