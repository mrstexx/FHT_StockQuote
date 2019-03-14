#include <iostream>
#include <fstream>
#include <ostream>
#pragma once

using namespace std;

class IOHandler
{
private:

public:
	IOHandler();
	~IOHandler();
	void saveFile(string);
	void loadFile(string);
};

