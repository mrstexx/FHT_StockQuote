#include <iostream>
#include "MainMenu.h"

using namespace std;

MainMenu::MainMenu()
{
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
		if (userInput < ADD || userInput > QUIT)
		{
			cout << "Falsche Eingabe! Versuchen Sie wieder." << endl;
		}
		switch (userInput)
		{
		case ADD:
			// add new stock to hashtable
			addNewStock();
			break;
		case DEL:
			// delete stock from hashtable
			deleteStock();
			break;
		case IMPORT:
			// import csv to specific stock
			importStockQuote();
			break;
		case SEARCH:
			// search for stock in hashtable
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
{}

void MainMenu::deleteStock()
{}

void MainMenu::importStockQuote()
{}

void MainMenu::searchStock()
{}

void MainMenu::plotStockQuote()
{}

void MainMenu::saveHashTable()
{}

void MainMenu::loadHashTable()
{}

MainMenu::~MainMenu()
{}
