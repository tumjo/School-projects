#include "Scooter.h"

using std::cout; using std::endl; using std::cin; using std::getline;

int Scooter::m_scooterCount{};


Scooter::Scooter() : 
    m_manufacturer{ "unnamed" }, m_model{ "unnamed" }, m_serialnumber{ "unknown" }, m_year{ 0 }, m_maxLoad{ 0 }
{
    //cout << "Scooter luokan parametriton rakentaja " << this << endl;
    m_scooterCount++;
}

Scooter::Scooter(const string& a_manufacturer, const string& a_model, const string& a_serialnumber, int a_year, double a_maxLoad) : 
    m_manufacturer{ a_manufacturer }, m_model{ a_model }, m_serialnumber{ a_serialnumber }, m_year{ a_year }, m_maxLoad{ a_maxLoad }
{
    //cout << "Scooter luokan parametrillinen rakentaja " << this << endl;
    m_scooterCount++;
}

Scooter::~Scooter()
{
    //cout << "Scooter luokan purkaja " << this << endl;
    m_scooterCount--;
}

void Scooter::setManufacturer(const string& a_manufacturer)
{
    m_manufacturer = a_manufacturer;
}

void Scooter::setModel(const string& a_model)
{
    m_model = a_model;
}

void Scooter::setSerialNumber(const string& a_serialnumber)
{
    m_serialnumber = a_serialnumber;
}

void Scooter::setYear(int a_year)
{
    m_year = a_year;
}

void Scooter::setMaxLoad(int a_maxLoad)
{
    m_maxLoad = a_maxLoad;
}

string Scooter::getManufacturer() const
{
    return m_manufacturer;
}

string Scooter::getModel() const
{
    return m_model;
}

string Scooter::getSerialnumber() const
{
    return m_serialnumber;
}

int Scooter::getYear() const
{
    return m_year;
}

double Scooter::getMaxLoad() const
{
    return m_maxLoad;
}

void Scooter::askInfo()
{
    cout << "Manufacturer: ";
    getline(cin, m_manufacturer);
    cout << "Model: ";
    getline(cin, m_model);
    cout << "Serialnumber: ";
    getline(cin, m_serialnumber);
    cout << "Year: ";
    string year;
    getline(cin, year);
    m_year = stoi(year);
    cout << "Max Load (kg): ";
    string maxLoad;
    getline(cin, maxLoad);
    m_maxLoad = atof(maxLoad.c_str());
}

void Scooter::printScooter() const
{
    cout << "Manufacturer: " << m_manufacturer << " Model: " << m_model << " Serialnumber: " << m_serialnumber << " Year: " << m_year << " Max load (kg): " << m_maxLoad;
}

int Scooter::getScooterCount()
{
    return m_scooterCount;
}



