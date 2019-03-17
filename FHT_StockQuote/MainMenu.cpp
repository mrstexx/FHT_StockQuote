#include <iostream>
#include "MainMenu.h"

using namespace std;

MainMenu::MainMenu()
{
	hashTable = new HashTable();
	printHeader();
	printMainMenu();
	inputHandler();
}

void MainMenu::printMainMenu()
{
	cout << "Verfuegbare Menueoptionen:" << endl;
	cout << "1. ADD - Eine Aktie mit Namen, WKN und Kuerzel wird hinzugefuegt" << endl;
	cout << "2. DEL - Aktie wird geloescht." << endl;
	cout << "3. IMPORT - Kurswerte fuer eine Aktie werden aus einer csv Datei importiert" << endl;
	cout << "4. SEARCH - Eine Aktie wird in der Hashtabelle gesucht" << endl;
	cout << "5. PLOT - Die Schlusskurse der letzten 30 Tage einer Aktie werden als ASCII Grafik ausgegeben" << endl;
	cout << "6. SAVE - Programm speichert die Hashtabelle in eine Datei ab" << endl;
	cout << "7. LOAD - Programm laedt die Hashtabelle aus einer Datei" << endl;
	cout << "8. QUIT - Programm wird beendet" << endl;

	cout << endl;
}

void MainMenu::printHeader()
{
	cout << "*************************************" << endl;
	cout << "| Willkommen zur Aktienkurs Manager |" << endl;
	cout << "*************************************" << endl;
	cout << endl;
}

void MainMenu::printCategoryNavigation()
{
	cout << "0. Zurueck zum Hauptmenu" << endl;
}

void MainMenu::cleanScreen()
{
	system("CLS");
	printHeader();
}

void MainMenu::inputHandler()
{
	int userInput = 0;
	while (userInput != QUIT)
	{
		cout << "Benutzer Eingabe(Nummer): ";
		cin >> userInput;
		if (userInput < ADD || userInput > QUIT || cin.fail())
		{
			cout << "Falsche Eingabe! Versuchen Sie wieder." << endl;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		switch (userInput)
		{
		case ADD:
			addNewStock();
			break;
		case DEL:
			deleteStock();
			break;
		case IMPORT:
			// import csv to specific stock
			importStockQuote();
			break;
		case SEARCH:
			searchStock();
			break;
		case PLOT:
			// print out graphic for csv data
			plotStockQuote();
			break;
		case SAVE:
			// save hashtable
			saveHashTable();
			break;
		case LOAD:
			// load hashtable
			loadHashTable();
			break;
		case QUIT:
			// close program
			break;
		default:
			break;
		}
	}
}

void MainMenu::addNewStock()
{
	string stockName = "";
	string WKN = "";
	string stockShortcut = "";
	cout << "Aktionsname: ";
	cin.ignore();
	getline(cin, stockName);
	cout << "WKN: ";
	cin >> WKN;
	cout << "Aktionskuerzel: ";
	cin >> stockShortcut;
	Stock* newStock = new Stock(stockName, WKN, stockShortcut);
	hashTable->add(newStock);
}

void MainMenu::deleteStock()
{
	string stockName = "";
	cout << "Aktionsname: ";
	cin.ignore();
	getline(cin, stockName);
	hashTable->remove(stockName);
}

void MainMenu::importStockQuote()
{
	string stockName = "";
	string quoteFileName = "";
	cout << "Geben Sie Aktiensname ein: ";
	cin.ignore();
	getline(cin, stockName);
	cout << "Geben Sie Aktienskurse Dateiname ein: ";
	getline(cin, quoteFileName);
	Stock *stock = hashTable->getStock(stockName);
	IOHandler io(quoteFileName);
	io.importQuoteData(stock);
}

void MainMenu::searchStock()
{
	string stockName = "";
	cout << "Geben Sie Aktiensname oder WKN ein: ";
	cin.ignore();
	getline(cin, stockName);
	if (!hashTable->search(stockName))
	{
		cout << "Eingegeben Name/WKN existiert nicht." << endl;
	}
}

void MainMenu::plotStockQuote()
{
	//cout << this->hashTable->getStocks()[561].getStockName() << endl;
	hashTable->listAll();
}

void MainMenu::saveHashTable()
{
	string fileName = "";
	cout << "Geben Sie Datei Name ein: ";
	cin.ignore();
	getline(cin, fileName);
	IOHandler io(hashTable, fileName);
	io.saveHashFile();
}

void MainMenu::loadHashTable()
{
	string fileName = "";
	cout << "Geben Sie Datei Name ein: ";
	cin.ignore();
	getline(cin, fileName);
	IOHandler io(fileName);
	this->hashTable = io.loadHashFile();
}

MainMenu::~MainMenu()
{
	delete this->hashTable;
	this->hashTable = nullptr;
}
