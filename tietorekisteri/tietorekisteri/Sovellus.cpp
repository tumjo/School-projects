#include "Sovellus.h"
#include "Koulu.h"

#include <iostream>
using std::endl; using std::cout; using std::cin; using std::getline;

Sovellus::Sovellus() :nimi_()
{
}

Sovellus::Sovellus(string nimi) : nimi_(nimi)
{
}


Sovellus::~Sovellus()
{
}

void Sovellus::asetaNimi(string nimi)
{
	nimi_ = nimi;
}

string Sovellus::annaNimi() const
{
	return nimi_;
}

void Sovellus::aja() const
{
	Koulu korkeakouluamk(nimi_);
	string valinta;
	cout << "Tervetuloa " << nimi_ << "-rekisteriin";
	do {
		valinta = tulostaValikko();
		if (valinta == "1") {
			korkeakouluamk.lisaaKoulutusohjelma();
		}
		else if (valinta == "2") {
			korkeakouluamk.tulostaKoulutusohjelmat();
		}
		else if (valinta == "3") {
			korkeakouluamk.tulostaKoulutusohjelmienMaara();
		}
		else if (valinta == "4") {
			korkeakouluamk.lisaaKoulutusohjelmaanOpettaja();
		}
		else if (valinta == "5") {
			korkeakouluamk.tulostaKoulutusohjelmanOpettajat();
		}
		else if (valinta == "6") {
			korkeakouluamk.lisaaKoulutusohjelmaanOpiskelija();
		}
		else if (valinta == "7") {
			korkeakouluamk.tulostaKoulutusohjelmanOpiskelijat();
		}
		else if (valinta == "8") {
			korkeakouluamk.poistaKoulutusohjelma();
		}
		else if (valinta == "9") {
			korkeakouluamk.poistaOpettaja();
		}
		else if (valinta == "10") {
			korkeakouluamk.poistaOpiskelija();
		}
		else if (valinta == "11") {
			korkeakouluamk.paivitaKoulutusohjelma();
		}
		else if (valinta == "12") {
			korkeakouluamk.paivitaOpettaja();
		}
		else if (valinta == "13") {
			korkeakouluamk.paivitaOpiskelija();
		}
		else if (valinta == "14") {
			korkeakouluamk.lueTiedot();
		}
		else if (valinta == "15") {
			korkeakouluamk.tallennaTiedot();
		}
		else if (valinta == "0") {

		}
		else {
			cout << "Virheellinen valinta!" << endl;
		}

	} while (valinta != "0");


}

string Sovellus::tulostaValikko() const
{
	string valinta;
	cout << "\n1) Lisaa koulutusohjelma\n2) Tulosta koulutusohjelmien nimet\n3) Tulosta koulutusohjelmien maara\n4) Lisaa koulutusohjelmaan opettaja\n5) Tulosta koulutusohjelman opettajat\n6) Lisaa koulutusohjelmaan opiskelija\n7) Tulosta koulutusohjelman opiskelijat\n8) Poista koulutusohjelma\n9) Poista opettaja\n10) Poista opiskelija\n11) Paivita koulutusohjelman nimi\n12) Paivita opettajan tiedot\n13) Paivita opiskelijan tiedot\n14) Lue tiedot\n15) Tallenna tiedot\n0) Lopeta";
	cout << endl;
	cout << "Anna valintasi: ";
	getline(cin, valinta);
	return valinta;
}