#pragma once
#include <iostream>
#include "Scooter.h"
#include "EScooter.h"
#include "KScooter.h"
#include <vector>
#include <algorithm> 
#include <memory> 
#include <string>
#include <functional> 

using std::cout; using std::endl;  using std::vector; using std::unique_ptr; using std::make_unique; using std::make_shared;  using std::shared_ptr; using std::sort; using std::for_each; using std::function; using std::string; using std::cin; using std::getline;

// aliases
typedef vector<shared_ptr<Scooter>> scooterSharedPtrVector;
typedef shared_ptr<Scooter> scooterSharedPtr;

class ScooterData final // cannot be derived from
{
public:
	static shared_ptr<ScooterData> getInstance(); // singleton
	ScooterData(const ScooterData& a_scooterData) = delete; // not needed
	void operator=(ScooterData const& a_scooterData) = delete; // not needed
	static int getRecords();

	void addScooter();
	void updateScooter();
	void removeScooter();
	void searchScooter() const;
	void printScooters() const;
	void sortScooters();
	void setPolicyObject(const function<bool(const shared_ptr<Scooter>&, const shared_ptr<Scooter>&)> a_scooterPolicy);
	void switchWarnings(); 
	void setWarningObserver(function<void(const string&, const string&, const string&)> aObserver); 

private:
	static shared_ptr<ScooterData> instance; // singleton 
	ScooterData() = default; 

	scooterSharedPtrVector scooters; // scooter data vector

	scooterSharedPtr searchScooterById(const string& a_serialnumber) const; // helper
	string askSerialnumber() const; // helper



	function<void(const string&, const string&, const string&)> warningObserver{ nullptr }; // observer 
	function<bool(const scooterSharedPtr&, const scooterSharedPtr&)> policyObject{ nullptr }; // sort policy

};

