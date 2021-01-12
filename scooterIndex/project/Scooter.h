#pragma once
#include <iostream>
#include <string>

using std::string;

class Scooter
{
public:
	Scooter();
	Scooter(const string& a_manufacturer, const string& a_model, const string& a_serialnumber, int a_year, double a_maxLoad);
	Scooter(const Scooter& a_scooter) = delete;
	~Scooter();
	

	void setManufacturer(const string& a_manufacturer);
	void setModel(const string& a_model);
	void setSerialNumber(const string& a_serialnumber);
	void setYear(int a_year);
	void setMaxLoad(int a_maxLoad);

	string getManufacturer() const;
	string getModel() const;
	string getSerialnumber() const;
	int getYear() const;
	double getMaxLoad() const;

	virtual void askInfo();
	virtual void printScooter() const;

	static int getScooterCount();

private:
	static int m_scooterCount;

	string m_manufacturer;
	string m_model;
	string m_serialnumber;
	int m_year;
	double m_maxLoad;

	
};

