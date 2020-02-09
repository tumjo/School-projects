#include "Koulutusohjelma.h"
#include <iostream>
using std::cout; using std::cin; using std::endl; using std::getline;


Koulutusohjelma::Koulutusohjelma() : nimi_(), opiskelijat_(), opettajat_()
{
}

Koulutusohjelma::Koulutusohjelma(string nimi) : nimi_(nimi), opiskelijat_(), opettajat_()
{
}


Koulutusohjelma::~Koulutusohjelma()
{
}

void Koulutusohjelma::asetaNimi(string nimi)
{
	nimi_ = nimi;
}

string Koulutusohjelma::annaNimi() const
{
	return nimi_;
}

vector<Opettaja> Koulutusohjelma::annaOpettajaTiedot() const
{
	return opettajat_;
}

vector<Opiskelija> Koulutusohjelma::annaOpiskelijaTiedot() const
{
	return opiskelijat_;
}

void Koulutusohjelma::lisaaOpettaja()
{
	Opettaja ope;
	ope.kysyTiedot();
	opettajat_.push_back(ope); //vector olion metodi. lis‰t‰‰n vectoriin ope olio
}

void Koulutusohjelma::lisaaOpiskelija()
{
	Opiskelija opisk;
	opisk.kysyTiedot();
	opiskelijat_.push_back(opisk);
}

void Koulutusohjelma::tulostaOpettajat() const
{
	for (unsigned int i = 0; i < opettajat_.size(); i++) {
		opettajat_[i].tulosta();
	}
}

void Koulutusohjelma::tulostaOpiskelijat() const
{
	for (unsigned int i = 0; i < opiskelijat_.size(); i++) {
		opiskelijat_[i].tulosta();
	}
}

void Koulutusohjelma::poistaOpettaja()
{
	int indeksi = etsiOpettaja();
	if (indeksi >= 0) {
		opettajat_.erase(opettajat_.begin() + indeksi);
		cout << "Opettaja poistettu!" << endl;
	}
	else {
		cout << "Opettajaa ei loytynyt!" << endl;
	}
}

void Koulutusohjelma::poistaOpiskelija()
{
	int indeksi = etsiOpiskelija();
	if (indeksi >= 0) {
		opiskelijat_.erase(opiskelijat_.begin() + indeksi);
		cout << "Opiskelija poistettu!" << endl;
	}
	else {
		cout << "Opiskelijaa ei loytynyt!" << endl;
	}
}

void Koulutusohjelma::paivitaOpettaja()
{
	int indeksi = etsiOpettaja();
	if (indeksi >= 0) {
		Opettaja paivitaope;
		paivitaope.kysyTiedot();
		opettajat_[indeksi] = paivitaope;
		cout << "Opettajan tiedot paivitetty!" << endl;
	}
	else {
		cout << "Opettajaa ei loytynyt!" << endl;
	}
}

void Koulutusohjelma::paivitaOpiskelija()
{
	int indeksi = etsiOpiskelija();
	if (indeksi >= 0) {
		Opiskelija paivitaopisk;
		paivitaopisk.kysyTiedot();
		opiskelijat_[indeksi] = paivitaopisk;
		cout << "Opiskelijan tiedot paivitetty!" << endl;
	}
	else {
		cout << "Opiskelijaa ei loytynyt!" << endl;
	}
}

void Koulutusohjelma::lisaaOpettajaTiedot(Opettaja tiedot)
{
	opettajat_.push_back(tiedot); //asetetaan tiedot vektoriin
}

void Koulutusohjelma::lisaaOpiskelijaTiedot(Opiskelija tiedot)
{
	opiskelijat_.push_back(tiedot); //asetetaan tiedot vektoriin
}

int Koulutusohjelma::etsiOpettaja() const
{
	string tunnus;
	cout << "Anna opettajan tunnus: ";
	getline(cin, tunnus);
	for (unsigned int i = 0; i < opettajat_.size(); i++) {
		if (tunnus == opettajat_[i].annaTunnus()) {
			return i;
		}
	}
	return -1; //ei loydy
}

int Koulutusohjelma::etsiOpiskelija() const
{
	string opiskelijanumero;
	cout << "Anna opiskelijan opiskelijanumero: ";
	getline(cin, opiskelijanumero);
	for (unsigned int i = 0; i < opiskelijat_.size(); i++) {
		if (opiskelijanumero == opiskelijat_[i].annaOpiskelijanumero()) {
			return i;
		}
	}
	return -1; //ei loydy
}
