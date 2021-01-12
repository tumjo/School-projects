#pragma once
#include <iostream>
#include "ScooterData.h"
#include <string>
using std::string;

class AppRun
{
public:
	AppRun();
	AppRun(string a_name);
	~AppRun();
	void setName(string a_name);
	string getName() const;
	int getRecords() const;
	void run() const;
private:
	string printMenu() const;
	string m_name;
};

