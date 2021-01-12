#include "KScooter.h"

using std::cout; using std::endl; using std::cin; using std::getline;

KScooter::KScooter() : m_forProfessionals{ false }
{
	//cout << "KScooter luokan parametriton rakentaja " << this << endl;
}

KScooter::KScooter(const string& a_manufacturer, const string& a_model, const string& a_serialnumber, int a_year, double a_maxLoad, bool a_forProfessionals) : 
	Scooter{ a_manufacturer, a_model, a_serialnumber, a_year, a_maxLoad }, m_forProfessionals{ a_forProfessionals }
{
	//cout << "KScooter luokan parametrillinen rakentaja " << this << endl;
}

KScooter::~KScooter()
{
	//cout << "KScooter luokan purkaja " << this << endl;
}

void KScooter::setForProfessionals(bool a_forProfessionals)
{
	m_forProfessionals = a_forProfessionals;
}

bool KScooter::getForProfessionals() const
{
	return m_forProfessionals;
}

void KScooter::askInfo()
{
	Scooter::askInfo();
	string select;
	cout << "Is it for professionals (Y/N): ";
	getline(cin, select);
	if (select == "Y" || select == "y") {
		m_forProfessionals = true;
	}
	else if (select == "N" || select == "n") {
		m_forProfessionals = false;
	}
	else {
		cout << "invalid input...But I think you mean it is not for pros " << endl;
		m_forProfessionals = false;
	}
}

void KScooter::printScooter() const
{
	cout << "Power source: human muscle power ";
	Scooter::printScooter();
	if (m_forProfessionals) {
		cout << " The scooter is for professionals";
	}
	else {
		cout << " The scooter is not for professionals";
	}
}
