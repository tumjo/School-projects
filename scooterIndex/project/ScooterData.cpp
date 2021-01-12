#include "ScooterData.h"

shared_ptr<ScooterData> ScooterData::instance{};

shared_ptr<ScooterData> ScooterData::getInstance()
{
	if (!instance) {
		instance = shared_ptr<ScooterData>(new ScooterData());
	}
	return instance;
}

void ScooterData::addScooter()
{
	string select;
	cout << "1) Electric Scooter or 2) Kick Scooter: ";
	getline(cin, select);
	if (select == "1") {
		scooterSharedPtr scooter(new EScooter);
		scooter->askInfo();
		scooters.push_back(scooter);
		if (warningObserver) {
			warningObserver(scooter->getManufacturer(), scooter->getModel(), scooter->getSerialnumber());
		}
	}
	else if (select == "2") {
		scooterSharedPtr scooter(new KScooter);
		scooter->askInfo();
		scooters.push_back(scooter);
		if (warningObserver) {
			warningObserver(scooter->getManufacturer(), scooter->getModel(), scooter->getSerialnumber());
		}
	}
	else {
		cout << "invalid input" << endl;
	}
}

void ScooterData::updateScooter()
{
	string serialnumber = askSerialnumber();
	scooterSharedPtr scooter = searchScooterById(serialnumber);
	if (scooter) {
		cout << "The target scooter: " << endl;
		scooter->printScooter();
		cout << endl;
		scooter->askInfo();
		if (warningObserver) {
			warningObserver(scooter->getManufacturer(), scooter->getModel(), scooter->getSerialnumber());
		}
	}

}

void ScooterData::removeScooter()
{
	string serialnumber = askSerialnumber();
	for (unsigned int i = 0; i < scooters.size(); i++) {
		if (scooters[i]->getSerialnumber() == serialnumber) {
			scooters[i]->printScooter();
			string select;
			cout << endl << "Remove (Y/N): ";
			getline(cin, select);
			if (select == "Y" || select == "y") {
				if (warningObserver) {
					warningObserver(scooters[i]->getManufacturer(), scooters[i]->getModel(), scooters[i]->getSerialnumber());
				}
				scooters.erase(scooters.begin() + i); 
			}
		}
	}
}


void ScooterData::searchScooter() const
{
	string serialnumber = askSerialnumber();
	scooterSharedPtr scooter = searchScooterById(serialnumber);
	if (scooter) {
		scooter->printScooter();
	}
}

void ScooterData::printScooters() const
{
	for (auto s : scooters) { // or const shared_ptr<Scooter> s : scooters
		s->printScooter();
		cout << endl;
	}
}

void ScooterData::sortScooters() 
{
	if (policyObject) {
		sort(scooters.begin(), scooters.end(), policyObject);
		printScooters();
	}

	
}

void ScooterData::setPolicyObject(const function<bool(const scooterSharedPtr&, const scooterSharedPtr&)> a_policyObject)
{
	policyObject = a_policyObject;
}

void ScooterData::switchWarnings()
{
	if (!warningObserver) {
		setWarningObserver([](const string& a_manufacturer, const string& a_model, const string& a_serialnumber) {
			cout << "Warning! Scooter Database has been updated! The target scooter:" << endl << "Serialnumber: " << a_serialnumber << " Manufacturer: " << a_manufacturer << " Model: " << a_model << endl;
		});
		cout << "Switched on!";
	}
	else {
		setWarningObserver(nullptr);
		cout << "Switched off!";
	}

}

void ScooterData::setWarningObserver(function<void(const string&, const string&, const string&)> a_warningObserver)
{
	warningObserver = a_warningObserver;
}

scooterSharedPtr ScooterData::searchScooterById(const string& a_serialnumber) const
{
	for (scooterSharedPtr s : scooters) {
		if (s->getSerialnumber() == a_serialnumber) {
			return s; // return first
		}
	}
	cout << "Scooter not found. Input was " << a_serialnumber << endl;
	return nullptr; // not found
}

string ScooterData::askSerialnumber() const
{
	string serialnumber;
	cout << "Serialnumber: ";
	getline(cin, serialnumber);
	return serialnumber;
}

int ScooterData::getRecords()
{
	return Scooter::getScooterCount();
}
