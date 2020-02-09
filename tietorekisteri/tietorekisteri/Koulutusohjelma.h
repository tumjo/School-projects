#pragma once
#include "Opettaja.h"
#include "Opiskelija.h"
#include <string>
#include <vector>
using std::string; using std::vector;
class Koulutusohjelma
{
public:
	Koulutusohjelma();
	Koulutusohjelma(string nimi);
	~Koulutusohjelma();
	void asetaNimi(string nimi);
	string annaNimi() const;
	vector <Opettaja> annaOpettajaTiedot() const; //antaa koulutusohjelman opettajat
	vector <Opiskelija> annaOpiskelijaTiedot() const; //antaa koulutusohjelman opiskelijat
	void lisaaOpettaja();
	void lisaaOpiskelija();
	void tulostaOpettajat() const;
	void tulostaOpiskelijat() const;
	void poistaOpettaja();
	void poistaOpiskelija();
	void paivitaOpettaja();
	void paivitaOpiskelija();
	void lisaaOpettajaTiedot(Opettaja tiedot); //olion tallennus vektoriin
	void lisaaOpiskelijaTiedot(Opiskelija tiedot); //olion tallennus vektoriin
private:
	int etsiOpettaja() const;
	int etsiOpiskelija() const;
	string nimi_;
	vector<Opiskelija> opiskelijat_;
	vector<Opettaja> opettajat_;
};

