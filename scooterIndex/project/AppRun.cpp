#include "AppRun.h"

using std::endl; using std::cout; using std::cin; using std::getline;

AppRun::AppRun() : m_name("unnamed")
{
	//cout << "a";
}

AppRun::AppRun(string a_name) : m_name(a_name)
{
	//cout << "b";
}


AppRun::~AppRun()
{
	//cout << "z";
}

void AppRun::setName(string a_name)
{
	m_name = a_name;
}

string AppRun::getName() const
{
	return m_name;
}

int AppRun::getRecords() const
{
	return ScooterData::getRecords();
}

void AppRun::run() const
{
	//EScooter* my = new EScooter{"Xiaomi", "m1", "12354aas", 2, 2, 25, 50};
	//my->printScooter();
	//delete my;
	//system("pause");
	auto scooterData = ScooterData::getInstance();
	string select;
	cout  << "--" << getName() << " database--" << endl;
	do {
		select = printMenu();
		cout << endl;
		if (select == "1") {
			scooterData->addScooter();
		}
		else if (select == "2") {
			scooterData->updateScooter();
		}
		else if (select == "3") {
			scooterData->removeScooter();
		}
		else if (select == "4") {
			scooterData->searchScooter();
		}
		else if (select == "5") {
			scooterData->printScooters();
		}
		else if (select == "6") {
			scooterData->setPolicyObject([](const shared_ptr<Scooter>& a, const shared_ptr<Scooter>& b) {
				return a->getManufacturer() < b->getManufacturer();
			});
			scooterData->sortScooters();
		}
		else if (select == "7") {
			scooterData->setPolicyObject([](const shared_ptr<Scooter>& a, const shared_ptr<Scooter>& b) {
				return a->getSerialnumber() < b->getSerialnumber();
			});
			scooterData->sortScooters();
		}
		else if (select == "8") {
			scooterData->switchWarnings();
		}
		else if (select == "0") {

		}
		else {
			cout << "Invalid input!" << endl;
		}

	} while (select != "0");


}

string AppRun::printMenu() const
{
	string select;
	cout << endl << "There are " << getRecords() <<" records in the database" << endl;
	cout << "1) Add a new scooter\n2) Update the scooter \n3) Remove the scooter\n4) Search and print the scooter\n5) Print scooters\n6) Sort scooters by manufacturer \n7) Sort scooters by serialnumber\n8) Switch on/off the warnings when data changes\n0) Quit" << endl;
	cout << endl;
	cout << "Select: ";
	getline(cin, select);
	return select;
}