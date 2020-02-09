#pragma once
#include "Koulutusohjelma.h"
#include <string>
#include <vector>

using std::string; using std::vector;

class Koulu
{
public:
	Koulu();
	Koulu(string nimi);
	~Koulu();
	void asetaNimi(string nimi);
	string annaNimi() const;

	void lisaaKoulutusohjelma();
	void tulostaKoulutusohjelmat() const;
	void tulostaKoulutusohjelmienMaara() const;
	void lisaaKoulutusohjelmaanOpettaja();
	void tulostaKoulutusohjelmanOpettajat() const;
	void lisaaKoulutusohjelmaanOpiskelija();
	void tulostaKoulutusohjelmanOpiskelijat() const;
	void poistaKoulutusohjelma();
	void poistaOpettaja();
	void poistaOpiskelija();
	void paivitaKoulutusohjelma();
	void paivitaOpettaja();
	void paivitaOpiskelija();

	void lueTiedot(); // lukee opettajat.csv ja opiskelijat.csv
	void tallennaTiedot(); // tallentaa opettajat.csv ja opiskelijat.csv
private:
	int etsiKoulutusohjelma() const;
	string nimi_;
	vector <Koulutusohjelma> koulutusohjelmat_;
};

