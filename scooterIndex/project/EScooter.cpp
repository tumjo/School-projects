#include "EScooter.h"

using std::cout; using std::endl; using std::cin; using std::getline;

EScooter::EScooter() : m_maxSpeed{ 0 }, m_generalRange{ 0 }
{
    //cout << "EScooter luokan parametriton rakentaja " << this << endl;
}

EScooter::EScooter(const string& a_manufacturer, const string& a_model, const string& a_serialnumber, int a_year, double a_maxLoad, double a_maxSpeed, double a_generalRange) :
    Scooter{ a_manufacturer, a_model, a_serialnumber, a_year, a_maxLoad }, m_maxSpeed{ a_maxSpeed }, m_generalRange{ a_generalRange }
{
    //cout << "EScooter luokan parametrillinen rakentaja " << this << endl;
}

EScooter::~EScooter()
{
    //cout << "EScooter luokan purkaja " << this << endl;
}

void EScooter::setMaxSpeed(int a_maxSpeed)
{
    m_maxSpeed = a_maxSpeed;
}

void EScooter::setGeneralRange(int a_generalRange)
{
    m_generalRange = a_generalRange;
}

double EScooter::getMaxSpeed() const
{
    return m_maxSpeed;
}

double EScooter::getGeneralRange() const
{
    return m_generalRange;
}

void EScooter::askInfo()
{
    Scooter::askInfo();
    cout << "Max Speed (km/h): ";
    string maxSpeed;
    getline(cin, maxSpeed);
    m_maxSpeed = atof(maxSpeed.c_str());
    cout << "General Range (km): ";
    string generalRange;
    getline(cin, generalRange);
    m_generalRange = atof(generalRange.c_str());
}

void EScooter::printScooter() const
{
    cout << "Power source: electric engines ";
    Scooter::printScooter();
    cout << " Max Speed (km/h): " << m_maxSpeed << " General Range (km): " << m_generalRange;
}

