#include "Koulu.h"
#include <iostream>
#include <fstream>


using std::cout; using std::cin; using std::endl; using std::getline;
using std::cout; using std::endl; using std::ofstream; using std::ifstream; using std::vector;

Koulu::Koulu() : nimi_(), koulutusohjelmat_()
{
}

Koulu::Koulu(string nimi) : nimi_(nimi), koulutusohjelmat_()
{
}


Koulu::~Koulu()
{
}

void Koulu::asetaNimi(string nimi)
{
	nimi_ = nimi;
}

string Koulu::annaNimi() const
{
	return nimi_;
}

void Koulu::lisaaKoulutusohjelma()
{
	string nimi;
	cout << "Anna koulutusohjelman nimi: ";
	getline(cin, nimi);
	koulutusohjelmat_.push_back(Koulutusohjelma(nimi));
}

void Koulu::tulostaKoulutusohjelmat() const
{
	for (unsigned int i = 0; i < koulutusohjelmat_.size(); i++) {
		cout << koulutusohjelmat_[i].annaNimi() << endl;
	}
}

void Koulu::tulostaKoulutusohjelmienMaara() const
{
	cout << koulutusohjelmat_.size() << endl;
}

void Koulu::lisaaKoulutusohjelmaanOpettaja()
{
	int indeksi = etsiKoulutusohjelma();
	if (indeksi >= 0) {
		koulutusohjelmat_[indeksi].lisaaOpettaja();
	}
	else {
		cout << "Koulutusohjelmaa ei loytynyt!" << endl;
	}
}

void Koulu::tulostaKoulutusohjelmanOpettajat() const
{
	int indeksi = etsiKoulutusohjelma();
	if (indeksi >= 0) {
		koulutusohjelmat_[indeksi].tulostaOpettajat();
	}
	else {
		cout << "Koulutusohjelmaa ei loytynyt!" << endl;
	}
}

void Koulu::lisaaKoulutusohjelmaanOpiskelija()
{
	int indeksi = etsiKoulutusohjelma();
	if (indeksi >= 0) {
		koulutusohjelmat_[indeksi].lisaaOpiskelija();
	}
	else {
		cout << "Koulutusohjelmaa ei loytynyt!" << endl;
	}
}

void Koulu::tulostaKoulutusohjelmanOpiskelijat() const
{
	int indeksi = etsiKoulutusohjelma();
	if (indeksi >= 0) {
		koulutusohjelmat_[indeksi].tulostaOpiskelijat();
	}
	else {
		cout << "Koulutusohjelmaa ei loytynyt!" << endl;
	}
}

void Koulu::poistaKoulutusohjelma()
{
	int indeksi = etsiKoulutusohjelma();
	if (indeksi >= 0) {
		koulutusohjelmat_.erase(koulutusohjelmat_.begin() + indeksi);
		cout << "Koulutusohjelma poistettu!" << endl;
	}
	else {
		cout << "Koulutusohjelmaa ei loytynyt!" << endl;
	}
}

void Koulu::poistaOpettaja()
{
	int indeksi = etsiKoulutusohjelma();
	if (indeksi >= 0) {
		koulutusohjelmat_[indeksi].poistaOpettaja();
	}
	else {
		cout << "Koulutusohjelmaa ei loytynyt!" << endl;
	}
}

void Koulu::poistaOpiskelija()
{
	int indeksi = etsiKoulutusohjelma();
	if (indeksi >= 0) {
		koulutusohjelmat_[indeksi].poistaOpiskelija();
	}
	else {
		cout << "Koulutusohjelmaa ei loytynyt!" << endl;
	}
}

void Koulu::paivitaKoulutusohjelma()
{
	string nimi;
	int indeksi = etsiKoulutusohjelma();
	if (indeksi >= 0) {
		cout << "Anna koulutusohjelman uusi nimi: ";
		getline(cin, nimi);
		koulutusohjelmat_[indeksi].asetaNimi(nimi);
		cout << "Koulutusohjelma paivitetty!" << endl;
	}
	else {
		cout << "Koulutusohjelmaa ei loytynyt!" << endl;
	}
}

void Koulu::paivitaOpettaja()
{
	int indeksi = etsiKoulutusohjelma();
	if (indeksi >= 0) {
		koulutusohjelmat_[indeksi].paivitaOpettaja();
	}
	else {
		cout << "Koulutusohjelmaa ei loytynyt!" << endl;
	}
}

void Koulu::paivitaOpiskelija()
{
	int indeksi = etsiKoulutusohjelma();
	if (indeksi >= 0) {
		koulutusohjelmat_[indeksi].paivitaOpiskelija();
	}
	else {
		cout << "Koulutusohjelmaa ei loytynyt!" << endl;
	}
}

void Koulu::lueTiedot()
{
	ifstream lue_opettajat;
	lue_opettajat.open("opettajat.csv");
	if (lue_opettajat.is_open()) {
		string koulutusohjelma, etunimi, sukunimi, osoite, puhelinnumero, palkka, tunnus, opetusala; //tietojen lukua varten
		int indeksi = -1;
		while (lue_opettajat.peek() != EOF) {
			getline(lue_opettajat, koulutusohjelma, ';');
			for (unsigned int i = 0; i < koulutusohjelmat_.size(); i++) {
				if (koulutusohjelma == koulutusohjelmat_[i].annaNimi()) {
					indeksi = i; //indeksi johon tiedot laitetaan
					break;
				}
			}
			if (indeksi < 0) { //jos koulutusohjelmaa ei vielä ollut
				koulutusohjelmat_.push_back(Koulutusohjelma(koulutusohjelma));
				indeksi = koulutusohjelmat_.size() - 1; //indeksin laskeminen
			}
			getline(lue_opettajat, etunimi, ';');
			getline(lue_opettajat, sukunimi, ';');
			getline(lue_opettajat, osoite, ';');
			getline(lue_opettajat, puhelinnumero, ';');
			getline(lue_opettajat, palkka, ';');
			getline(lue_opettajat, tunnus, ';');
			getline(lue_opettajat, opetusala);
			double opalkka = atof(palkka.c_str()); //muunnetaan string doubleksi
			Opettaja opettajatieto(etunimi, sukunimi, osoite, puhelinnumero, opalkka, tunnus, opetusala); //luodaan olio parametrein
			koulutusohjelmat_[indeksi].lisaaOpettajaTiedot(opettajatieto); //koulutusohjelman mukaisella indeksillä opettajat 
																		   //opettajatieto.tulosta(); //tarkistus
			indeksi = -1; //palautetaan indeksi alkuun
		}
		lue_opettajat.close();
	}
	else {
		cout << "Tiedostoa opettajat.csv ei saa avattua!" << endl;
	}

	ifstream lue_opiskelijat;
	lue_opiskelijat.open("opiskelijat.csv");
	if (lue_opiskelijat.is_open()) {
		string koulutusohjelma, etunimi, sukunimi, osoite, puhelinnumero, opiskelijanumero;
		int indeksi = -1;
		while (lue_opiskelijat.peek() != EOF) {
			getline(lue_opiskelijat, koulutusohjelma, ';');
			for (unsigned int i = 0; i < koulutusohjelmat_.size(); i++) {
				if (koulutusohjelma == koulutusohjelmat_[i].annaNimi()) {
					indeksi = i;
					break;
				}
			}
			if (indeksi < 0) {
				koulutusohjelmat_.push_back(Koulutusohjelma(koulutusohjelma));
				indeksi = koulutusohjelmat_.size() - 1;
			}
			getline(lue_opiskelijat, etunimi, ';');
			getline(lue_opiskelijat, sukunimi, ';');
			getline(lue_opiskelijat, osoite, ';');
			getline(lue_opiskelijat, puhelinnumero, ';');
			getline(lue_opiskelijat, opiskelijanumero);
			Opiskelija opiskelijatieto(etunimi, sukunimi, osoite, puhelinnumero, opiskelijanumero);
			koulutusohjelmat_[indeksi].lisaaOpiskelijaTiedot(opiskelijatieto);
			//opiskelijatieto.tulosta(); //tarkistus
			indeksi = -1; //palautetaan indeksi 'alkuun'
		}
		lue_opiskelijat.close();
	}
	else {
		cout << "Tiedostoa opettajat.csv ei saa avattua!" << endl;
	}
	cout << "Tiedot luettu!" << endl;
}

void Koulu::tallennaTiedot()
{
	ofstream kirj_opettajat;
	kirj_opettajat.open("opettajat.csv");
	if (kirj_opettajat.is_open()) {
		vector <Opettaja> opettajatiedot; //opettaja vektori
		for (unsigned int i = 0; i < koulutusohjelmat_.size(); i++) {
			opettajatiedot = koulutusohjelmat_[i].annaOpettajaTiedot(); //haetaan koulutusohjelma indeksi i opettajat
			for (unsigned int j = 0; j < opettajatiedot.size(); j++) { //kirjoitetaan tiedostoon koulutusohjelman indeksi i kaikki opettajat
				kirj_opettajat << koulutusohjelmat_[i].annaNimi() << ";"
					<< opettajatiedot[j].annaEtunimi() << ";"
					<< opettajatiedot[j].annaSukunimi() << ";"
					<< opettajatiedot[j].annaOsoite() << ";"
					<< opettajatiedot[j].annaPuhelinnumero() << ";"
					<< opettajatiedot[j].annaPalkka() << ";"
					<< opettajatiedot[j].annaTunnus() << ";"
					<< opettajatiedot[j].annaOpetusala() << endl;
			}
		}
		kirj_opettajat.close();
	}
	else {
		cout << "Tiedostoa opettajat.csv ei saa avattua!" << endl;
	}

	ofstream kirj_opiskelijat;
	kirj_opiskelijat.open("opiskelijat.csv");
	if (kirj_opiskelijat.is_open()) {
		vector <Opiskelija> opiskelijatiedot; //opiskelija vektori
		for (unsigned int i = 0; i < koulutusohjelmat_.size(); i++) {
			opiskelijatiedot = koulutusohjelmat_[i].annaOpiskelijaTiedot(); //haetaan koulutusohjelma indeksi i opiskelijat
			for (unsigned int j = 0; j < opiskelijatiedot.size(); j++) { //kirjoitetaan tiedostoon koulutusohjelman indeksi i kaikki opiskelijat
				kirj_opiskelijat << koulutusohjelmat_[i].annaNimi() << ";"
					<< opiskelijatiedot[j].annaEtunimi() << ";"
					<< opiskelijatiedot[j].annaSukunimi() << ";"
					<< opiskelijatiedot[j].annaOsoite() << ";"
					<< opiskelijatiedot[j].annaPuhelinnumero() << ";"
					<< opiskelijatiedot[j].annaOpiskelijanumero() << endl;
			}
		}
		kirj_opiskelijat.close();
	}
	else {
		cout << "Tiedostoa opiskelijat.csv ei saa avattua!" << endl;
	}
	cout << "Tiedot tallennettu!" << endl;
}

int Koulu::etsiKoulutusohjelma() const
{
	string nimi;
	cout << "Anna koulutusohjelman nimi: ";
	getline(cin, nimi);
	for (unsigned int i = 0; i < koulutusohjelmat_.size(); i++) {
		if (nimi == koulutusohjelmat_[i].annaNimi()) {
			return i;
		}
	}
	return -1; //ei loydy
}
