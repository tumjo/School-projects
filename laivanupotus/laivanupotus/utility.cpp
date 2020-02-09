#include "utility.h"

/*--------------------------------------------------
*
* nimi: menu
* toiminta: pääloop, saa ohjelman alussa alustetut muuttujat. Valikon toimintokäsittely.
* parametri(t): shipsArray, ROWS, COLS, gameon, shipsleft, size, playArray, sizepArray, sizesArray
* paluuarvo(t):
*
*--------------------------------------------------*/
void menu(int shipsArray[][COLS], int rows, int cols, bool& gameon, int shipsleft[], int size, char playArray[][COLS], int sizepArray, int sizesArray)
{
	char mInput;

	do {

		printMenu();
		//printShips(shipsArray, ROWS, COLS); //poista
		//printShots(playArray, ROWS, COLS); //poista
		mInput = menuInput();

		switch (mInput)
		{
		case '1': run('1', shipsArray, ROWS, COLS, gameon, shipsleft, size, playArray, sizepArray, sizesArray);
			break;
		case '2': run('2', shipsArray, ROWS, COLS, gameon, shipsleft, size, playArray, sizepArray, sizesArray);
			break;
		case '3': run('3', shipsArray, ROWS, COLS, gameon, shipsleft, size, playArray, sizepArray, sizesArray);
			break;
		case '4': run('4', shipsArray, ROWS, COLS, gameon, shipsleft, size, playArray, sizepArray, sizesArray);
			break;
		case '5': run('5', shipsArray, ROWS, COLS, gameon, shipsleft, size, playArray, sizepArray, sizesArray);
			break;
		case 'l':
		case 'L': run('L', shipsArray, ROWS, COLS, gameon, shipsleft, size, playArray, sizepArray, sizesArray);
			break;
		default:  cerr << "\nAnnettu syote ei ollut laillinen! Yrita uudelleen.\n\n";
			system("pause");
			break;
		}
	} while ('L' != toupper(mInput));
}
/*--------------------------------------------------
*
* nimi: printMenu
* toiminta: tulostaa valikon tekstit ja tyhjentää näkymä
* parametri(t):
* paluuarvo(t):
*
*--------------------------------------------------*/
void printMenu()
{
	system("cls");
	cout << "\nLaivanupotuspeli\n================\n\nValinnat:\n\n1) Syota laivat\n2) Pelaa\n3) Arvo laivojen sijainnit\n4) Talleta pelitilanne\n5) Lataa pelitilanne\nL) Lopeta\n\nValintasi : ";
}
/*--------------------------------------------------
*
* nimi: menuInput
* toiminta: kysyä syöte, tarkistaa sen pituus ja palauttaa yhden merkin pituinen char
* parametri(t):
* paluuarvo(t): char
*
*--------------------------------------------------*/
char menuInput()
{
	string input1s;
	char input1c;
	getline(cin, input1s);
	//varmistetaan että syöte on oikean mittainen
	if (input1s.length() != 1) {
		return '\0'; //jos ei ollut oikean mittainen palauttaa "tyhjää" --> johtaa virheellisen syötteen ilmoitukseen menu() aliohjelmassa
	}
	input1c = input1s[0];
	return input1c; //palauttaa 1 merkin mittaiset syötteet. Toiminnon vastaavuus tarkastus menu() aliohjelmassa.

}
/*--------------------------------------------------
*
* nimi: run4
* toiminta: tiedon tallennustoiminnon käsittelyosa
* parametri(t): shipsArray, ROWS, COLS, gameon, shipsleft, size, playArray
* paluuarvo(t):
*
*--------------------------------------------------*/
void run4(int shipsArray[][COLS], int rows, int cols, bool& gameon, int shipsleft[], int size, char playArray[][COLS]) {
	if (gameon == true) {
		char input;
		fstream shipsFile;
		shipsFile.open("pelitilanne.txt", ios_base::out | ios_base::in);
		if (shipsFile.is_open()) {
			cout << "Tiedosto on jo olemassa! Tallennetaanko paalle(k/e): ";
			input = menuInput();
			shipsFile.close();
			if (input == 'k' || input == 'K') {
				savegame(shipsArray, ROWS, COLS, gameon, shipsleft, size, playArray);
			}
			else if (input == 'e' || input == 'E') {

			}
			else {
				cout << "Annettu syote ei ollut laillinen! Yrita uudelleen.\n\n";
			}
		}
		else {
			savegame(shipsArray, ROWS, COLS, gameon, shipsleft, size, playArray);
		}
	}
	else {
		cout << "\nVain kesken oleva pelitilanne voidaan tallentaa!\n\n";
	}
}
/*--------------------------------------------------
*
* nimi: run5
* toiminta: tiedon lataustoiminnon käsittelyosa
* parametri(t): shipsArray, ROWS, COLS, gameon, shipsleft, size, playArray
* paluuarvo(t):
*
*--------------------------------------------------*/
void run5(int shipsArray[][COLS], int rows, int cols, bool& gameon, int shipsleft[], int size, char playArray[][COLS]) {
	fstream shipsFile;
	shipsFile.open("pelitilanne.txt", ios_base::out | ios_base::in);
	if (shipsFile.is_open()) {
		shipsFile.close();
		loadgame(shipsArray, ROWS, COLS, gameon, shipsleft, size, playArray);
		gameon = true;
	}
	else {
		cout << "\nPelitilannetta ei voida ladata! Tiedostoa ei loydy.\n\n";
	}
}
/*--------------------------------------------------
*
* nimi: savegame
* toiminta: tiedon tallennustoiminnon toiminnallisuusosa
* parametri(t): shipsArray, ROWS, COLS, gameon, shipsleft, size, playArray
* paluuarvo(t):
*
*--------------------------------------------------*/
void savegame(int shipsArray[][COLS], int rows, int cols, bool& gameon, int shipsleft[], int size, char playArray[][COLS]) {
	ofstream shipsFile("pelitilanne.txt", ios::out);
	if (!shipsFile) {
		cerr << "Tiedostoa pelitilanne.txt ei voitu avata." << endl;
		exit(1);
	}
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			shipsFile << shipsArray[i][j] << " ";
		}
		shipsFile << endl;
	}
	shipsFile << endl;
	shipsFile << endl;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			shipsFile << playArray[i][j] << " ";
		}
		shipsFile << endl;
	}
	shipsFile << endl;
	shipsFile << endl;
	for (int i = 0; i < size; i++) {
		shipsFile << shipsleft[i] << " ";
	}
	shipsFile.close();
	cout << endl;
	cout << "Tilanne kirjoitettu tiedostoon!\n\n";
}
/*--------------------------------------------------
*
* nimi: loadgame
* toiminta: tiedon lataustoiminnon toiminnallisuusosa
* parametri(t): shipsArray, ROWS, COLS, gameon, shipsleft, size, playArray
* paluuarvo(t):
*
*--------------------------------------------------*/
void loadgame(int shipsArray[][COLS], int rows, int cols, bool& gameon, int shipsleft[], int size, char playArray[][COLS]) {
	ifstream shipsFile("pelitilanne.txt", ios::in);
	if (!shipsFile) {
		cerr << "Tiedostoa pelitilanne.txt ei voitu avata." << endl;
		exit(1);
	}
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			shipsFile >> shipsArray[i][j];
		}

	}

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			shipsFile >> playArray[i][j];
		}
	}
	for (int i = 0; i < size; i++) {
		shipsFile >> shipsleft[i];
	}
	shipsFile.close();
	cout << endl;
	cout << "Tilanne luettu tiedostosta!\n\n";
}
/*--------------------------------------------------
*
* nimi: run
* toiminta: kaikkien run-muotoisten aliohjelmien eli toimintojen hallinta
* parametri(t): char, shipsArray, ROWS, COLS, gameon, shipsleft, size, playArray, sizepArray, sizesArray
* paluuarvo(t):
*
*--------------------------------------------------*/
void run(char item, int shipsArray[][COLS], int rows, int cols, bool& gameon, int shipsleft[], int size, char playArray[][COLS], int sizepArray, int sizesArray)
{
	if ('l' != item && 'L' != item) {
		//cout << "\nSuoritetaan toiminto, jonka id = " << item << endl << endl;
		if (item == '1') {
			formatall(shipsArray, ROWS, COLS, shipsleft, size, playArray, sizepArray, sizesArray);
			run1(shipsArray, ROWS, COLS, gameon);
		}
		else if (item == '2') {
			run2(shipsArray, ROWS, COLS, gameon, shipsleft, size, playArray, sizepArray, sizesArray);
		}
		else if (item == '3') {
			formatall(shipsArray, ROWS, COLS, shipsleft, size, playArray, sizepArray, sizesArray);
			run3(shipsArray, ROWS, COLS, gameon);
		}
		else if (item == '4') {
			run4(shipsArray, ROWS, COLS, gameon, shipsleft, size, playArray);
		}
		else if (item == '5') {
			run5(shipsArray, ROWS, COLS, gameon, shipsleft, size, playArray);
		}
	}

	else
		cout << "\nPoistutaan ohjelmasta." << endl << endl;

	system("pause");
}
/*--------------------------------------------------
*
* nimi: formatall
* toiminta: alustaa laiva, peli ja laivaajäljellä taulukon
* parametri(t): shipsArray, ROWS, COLS, shipsleft, size, playArray, sizepArray, sizesArray
* paluuarvo(t):
*
*--------------------------------------------------*/
void formatall(int shipsArray[][COLS], int rows, int cols, int shipsleft[], int size, char playArray[][COLS], int sizepArray, int sizesArray) {
	memset(playArray, '\0', sizepArray); //tyhjätään
	memset(shipsArray, 0, sizesArray); //nollataan
	int j = size + 1;
	for (int i = 0; i < size; i++) {
		shipsleft[i] = j;
		j--;
	}
}
/*--------------------------------------------------
*
* nimi: run1
* toiminta: laivojen sijaintien manuaalimäärittely käsittelyosa
* parametri(t): shipsArray, ROWS, COLS, gameon
* paluuarvo(t):
*
*--------------------------------------------------*/
void run1(int shipsArray[][COLS], int rows, int cols, bool& gameon) {
	//printShips(shipsArray, ROWS, COLS); //testausta varten 
	inputShips(shipsArray, ROWS, COLS);
	//printShips(shipsArray, ROWS, COLS); //testausta varten 
	gameon = true;
}
/*--------------------------------------------------
*
* nimi: run2
* toiminta: pelaamisen käsittelyosa
* parametri(t): shipsArray, ROWS, COLS, gameon, shipsleft, size, playArray, sizepArray, sizesArray
* paluuarvo(t):
*
*--------------------------------------------------*/
void run2(int shipsArray[][COLS], int rows, int cols, bool& gameon, int shipsleft[], int size, char playArray[][COLS], int sizepArray, int sizesArray) {
	if (gameon != true) {
		cout << "Laivoja ei ole sijoitettu pelialueelle! Syota laivat, arvo laivojen sijainti tai lataa peli ensin.\n\n";
	}
	else {
		play(shipsArray, ROWS, COLS, shipsleft, size, playArray);
		//tarkastetaan onko peli pelattu loppuun. Jos on, asetetaan gameon false ja molemmat taulukot alustetaan.
		if (checkShipsnum(shipsleft, size) == 0) {
			printShots(playArray, ROWS, COLS);
			cout << "Onneksi olkoon, upotit kaikki laivat!\n\n";
			gameon = false; //Peli pelattu loppuun. Käyttäjän sijoitettava uudelleen laivat.
			formatall(shipsArray, ROWS, COLS, shipsleft, size, playArray, sizepArray, sizesArray);
		}
	}
}
/*--------------------------------------------------
*
* nimi: play
* toiminta: pelaamisen päätoiminnallisuusosa
* parametri(t): shipsArray, ROWS, COLS, gameon, shipsleft, size, playArray, sizepArray, sizesArray
* paluuarvo(t):
*
*--------------------------------------------------*/
void play(int shipsArray[][COLS], int rows, int cols, int shipsleft[], int size, char playArray[][COLS]) {
	int rownum; //rivi johon ammutaan 
	int columnnum; // sarake johon ammutaan
	int sett; //säilyttää aliohjelman convertCoordinates paluuarvon
	int shipsnum; //laivoja jäljellä 
	bool sink; //upposiko 
	const int SIZE = 500; //asetetaan niin suureksi kuin halutaan. Riittävän suuri on se, että arrayhyn mahtuu tavanomaiset virheelliset syötteet. Toteutustapa voisi olla parempikin, mutta kokeilu.
	char coordinate[SIZE]; //kestää tavanomaiset virheelliset syötteet. 
	bool toggle = true; //kun true, tulostetaan näytölle pelitilanne. Oletusarvo true
	do {
		//LISTÄTOIMINTOA varten if. Rakenne tehty näin, koska sijaintien vakoilu lisätty lisätoimintona jälkikäteen ja näin se oli helpoin lisätä
		if (toggle == true) {
			printShots(playArray, ROWS, COLS); //tulostetaan pelitilanne
		}
		toggle = true; //asetetaan toggle oletusarvoon  
		memset(coordinate, '\0', sizeof(coordinate)); //asetetaan "tyhjäksi"
		cout << "Anna ampumiskoordinaatit: ";
		cin >> coordinate;
		cout << endl;
		//jos halutaan poistua päävalikkoon
		if ((coordinate[0] == 'p' || coordinate[0] == 'P') && coordinate[1] == '\0') {
			break;
		}
		//LISTÄTOIMINTOA varten if.
		if (coordinate[0] == '\\' && coordinate[1] == '@' && coordinate[2] == '\0') {
			printShips(shipsArray, ROWS, COLS);
			toggle = false;
		}
		sett = convertCoordinates(coordinate, rownum, columnnum); //tarkastetaan koordinaattien laillisuus
		if (sett == 1) {
			//LISTÄTOIMINTOA varten if. 
			if (toggle != false) {
				cout << "Annettu koordinaattisyote ei ollut laillinen! Yrita uudelleen.\n";
			}
		}
		//jos laillinen syöte
		else if (sett == 0) {
			//jos kyseiseen kohtaan ei vielä ammuttu
			if (playArray[rownum][columnnum] == '\0') {
				//jos kyseisessä kohdassa on laiva
				if (shipsArray[rownum][columnnum] != 0) {
					sink = checkShips(shipsArray, ROWS, COLS, shipsleft, playArray, rownum, columnnum);
					//jos osui laivaan muttei upottanut
					if (sink == false) {
						cout << "Laukaus kohtaan ";
						cout << coordinate[0];
						cout << coordinate[1];
						cout << " osui laivaan.\n";
					}
					//jos osui laivaan ja upotti
					else if (sink == true) {
						cout << "Laukaus kohtaan ";
						cout << coordinate[0];
						cout << coordinate[1];
						cout << " upotti laivan.\n";
						//Merkataan laiva uponneeksi lisäämällä #-merkit.
						installsink(shipsArray, ROWS, COLS, playArray, rownum, columnnum);
					}
				}
				//jos kyseisessä kohdassa ei laivaa
				else {
					cout << "Laukaus kohtaan ";
					cout << coordinate[0];
					cout << coordinate[1];
					cout << " ei osunut.\n";
					playArray[rownum][columnnum] = 'x';
				}
			}
			//jos kyseiseen kohtaan on jo ammuttu
			else {
				cout << "Kyseiseen koordinaattiin on jo ammuttu! Yrita uudelleen.\n";
			}
		}
		shipsnum = checkShipsnum(shipsleft, size);
	} while (shipsnum != 0);
	cin.ignore(); //tarvitaan jotta valikon getline komentoa voidaan käyttää valikossa halutulla tavalla ilman virheitä
}
/*--------------------------------------------------
*
* nimi: installsink
* toiminta: pelaamisen toiminnallisuusosa laivan upottamisessa
* parametri(t): shipsArray, ROWS, COLS, playArray, rownum, columnnum
* paluuarvo(t):
*
*--------------------------------------------------*/
void installsink(int shipsArray[][COLS], int rows, int cols, char playArray[][COLS], int rownum, int columnnum) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (shipsArray[i][j] == shipsArray[rownum][columnnum]) {
				playArray[i][j] = '#';
			}
		}
	}
}
/*--------------------------------------------------
*
* nimi: checkShipsnum
* toiminta: pelaamisen toiminnallisuusosa laivojen määrän tarkastamisessa
* parametri(t): shipsleft, size
* paluuarvo(t): int
*
*--------------------------------------------------*/
int checkShipsnum(int shipsleft[], int size) {
	int shipscount = 0; //maaralaskuri
	for (int i = 0; i < size; i++) {
		if (shipsleft[i] != 0) {
			shipscount++;
		}
	}
	return shipscount;
}
/*--------------------------------------------------
*
* nimi: checkShips
* toiminta: pelaamisen toiminnallisuusosa osuman laitossa taulukkoon. paluuarvo true jos upposi
* parametri(t): shipsArray, ROWS, COLS, shipsleft, playArray, rownum, columnnum
* paluuarvo(t): bool
*
*--------------------------------------------------*/
bool checkShips(int shipsArray[][COLS], int rows, int cols, int shipsleft[], char playArray[][COLS], int rownum, int columnnum) {

	if (shipsArray[rownum][columnnum] == 5) {
		shipsleft[0]--;
		playArray[rownum][columnnum] = '*';
		if (shipsleft[0] == 0) {
			return true;
		}
	}
	else if (shipsArray[rownum][columnnum] == 4) {
		shipsleft[1]--;
		playArray[rownum][columnnum] = '*';
		if (shipsleft[1] == 0) {
			return true;
		}
	}
	else if (shipsArray[rownum][columnnum] == 3) {
		shipsleft[2]--;
		playArray[rownum][columnnum] = '*';
		if (shipsleft[2] == 0) {
			return true;
		}
	}
	else if (shipsArray[rownum][columnnum] == 2) {
		shipsleft[3]--;
		playArray[rownum][columnnum] = '*';
		if (shipsleft[3] == 0) {
			return true;
		}
	}
	return false;
}
/*--------------------------------------------------
*
* nimi: run3
* toiminta: sijaintien arpomisen käsittelyosa
* parametri(t): shipsArray, ROWS, COLS, gameon
* paluuarvo(t):
*
*--------------------------------------------------*/
void run3(int shipsArray[][COLS], int rows, int cols, bool& gameon) {
	cout << "\nLaivoja sijoitetaan...\n\n";
	randomShips(shipsArray, ROWS, COLS);
	gameon = true;
}
/*--------------------------------------------------
*
* nimi: randomShips
* toiminta: sijaintien arpomisen toiminnalissuusosa
* parametri(t): shipsArray, ROWS, COLS
* paluuarvo(t):
*
*--------------------------------------------------*/
void randomShips(int shipsArray[][COLS], int rows, int cols) {

	for (int i = 5; i > 1; i--) {
		srand((unsigned int)time(NULL));
		int rownum = rand() % ROWS;
		int columnnum = rand() % COLS;
		char direction[1];
		int dir = rand() % 4;
		if (dir == 0) {
			direction[0] = 'p';
		}
		else if (dir == 1) {
			direction[0] = 'i';
		}
		else if (dir == 2) {
			direction[0] = 'e';
		}
		else if (dir == 3) {
			direction[0] = 'l';
		}
		//käytetään hyödyksi laivojensijoittelu aliohjelmaa joka annettujen arvottujen parametrien avulla yrittää sijoittaa laivan
		if (installShips(shipsArray, ROWS, COLS, direction, i, rownum, columnnum) != true) {
			i++;
		}
	}
	//printShips(shipsArray, ROWS, COLS);
}
/*--------------------------------------------------
*
* nimi: convertCoordinates
* toiminta: muuntaa koordinaatin numeroiksi joita voidaan käyttää taulukoiden käsittelyyn. Paluaurvot 1 ja 0 (Olisi voinut tehdä boolilla, mutta kokeilu ja jos lisää jotain.)
* parametri(t): coordinate, rownum, columnnum
* paluuarvo(t): int
*
*--------------------------------------------------*/
int convertCoordinates(char* koordinaatti, int& riviind, int& sarakeind) {
	int wrong = 1;
	int right = 0;
	int vastine[] = { 6,5,4,3,2,1,0 }; // vastine kirjaimelle
	if (strlen(koordinaatti) == 2) { //tarkistaa ensin pituuden, jos oikean mittainen niin jatketaan. 
		if (tolower(koordinaatti[0]) <= 'g' && tolower(koordinaatti[0]) >= 'a') { //käytetään pieniä kirjaimia (jos pieni jo niin ei haittaa). Tarkistaa että kirjain oikealla välillä.  
			if (koordinaatti[1] <= '7' && koordinaatti[1] >= '1') { //tarkistaa että numero oikealla välillä 
				sarakeind = atoi(&koordinaatti[1]) - 1; //muuntaa char arvon int arvoksi ja tallentaa muuttujaan 
				int indeksi = 'g' - tolower(koordinaatti[0]);
				riviind = vastine[indeksi]; //valitaan oikea vastine 
				return right;
			}
		}
	}
	return wrong;
}
/*--------------------------------------------------
*
* nimi: checkDirection
* toiminta: tarkistaa oliko tuulensuuntasyöte oikean mittainen ja oliko arvo sallittu. Paluaurvot 1 ja 0 (Olisi voinut tehdä boolilla, mutta kokeilun vuoksi näin)
* parametri(t): direction
* paluuarvo(t): int
*
*--------------------------------------------------*/
int checkDirection(char* direction) {
	int wrong = 1;
	int right = 0;
	if (strlen(direction) == 1) { //tarkistaa ensin pituuden, jos oikean mittainen niin jatketaan. 
		if (tolower(direction[0]) == 'p' || tolower(direction[0]) == 'i' || tolower(direction[0]) == 'e' || tolower(direction[0]) == 'l') {
			return right; //jos jokin sallituista arvoista
		}
	}
	return wrong; // jos ei ollut oikean mittainen tai arvo ei ollut sallittu
}
/*--------------------------------------------------
*
* nimi: inputShips
* toiminta: laivojen sijaintien manuaalimäärittely kyselyn toiminnallisuusosa
* parametri(t): shipsArray, ROWS, COLS
* paluuarvo(t):
*
*--------------------------------------------------*/
void inputShips(int shipsArray[][COLS], int rows, int cols) {
	int rownum; //rivinumero taulukolle
	int columnnum; //sarakenumero taulukolle
	int sett; //säilyttää aliohjelman convertCoordinates paluuarvon 
	const int SIZE = 500; //asetetaan niin suureksi kuin halutaan. Riittävän suuri on se että arrayhyn mahtuu tavanomaiset virheelliset syötteet. Toteutustapa voisi olla parempikin, mutta tuli kokeiltua.
	char direction[SIZE]; //kestää tavanomaiset virheelliset syötteet. Toteutustapa voisi olla parempikin, mutta tuli kokeilu.
	char akoordinaatti[SIZE]; //kestää tavanomaiset virheelliset syötteet. Toteutustapa voisi olla parempikin, mutta kokeilu.
	for (int i = 5; i > 1; i--) {
		do {
			cout << endl;
			if (i == 5) {
				cout << "Anna viiden pituisen laivan alkupiste: ";
			}
			else if (i == 4) {
				cout << "Anna neljan pituisen laivan alkupiste: ";
			}
			else if (i == 3) {
				cout << "Anna kolmen pituisen laivan alkupiste: ";
			}
			else if (i == 2) {
				cout << "Anna kahden pituisen laivan alkupiste: ";
			}
			cin >> akoordinaatti;
			sett = convertCoordinates(akoordinaatti, rownum, columnnum);
			if (sett == 1) {
				cout << "Annettu koordinaattisyote ei ollut laillinen! Yrita uudelleen.\n";
				//printShips(shipsArray, ROWS, COLS); //testausta varten
				i++;
				break;
			}
			//Suunta kysely ja tarkistus
			cout << "Anna suunta (p(ohjoinen)/i(ta)/e(tela)/l(ansi)): ";
			cin >> direction;
			sett = checkDirection(direction);
			if (sett == 1) {
				cout << "Annettu ilmansuuntasyote ei ollut laillinen! Yrita uudelleen.\n";
				i++;
				break;
			}
			//laivan asettaminen 
			if (installShips(shipsArray, ROWS, COLS, direction, i, rownum, columnnum) != true) {
				cout << "Annettuun suuntaan tai kohtaan ei ole mahdollista asettaa laivaa! Yrita uudelleen.\n";
				i++;
				break;
			}
		} while (sett == 1);
		cin.ignore(); //tarvitaan jotta valikon getline komentoa voidaan käyttää valikossa halutulla tavalla ilman virheitä
	}
}
/*--------------------------------------------------
*
* nimi: installShips
* toiminta: laivojen sijaintien sijoittaminen toiminnallisuusosa. tarkastaa että ei yli kentän ja ei mene laivojen päälle. palauttaa true jos kaikki ok
* parametri(t): shipsArray, ROWS, COLS, direction, i, rownum, columnnum
* paluuarvo(t): bool
*
*--------------------------------------------------*/
bool installShips(int shipsArray[][COLS], int rows, int cols, char* direction, int i, int rownum, int columnnum) {
	int result; //säilyttää tietoa laivan loppupisteestä 
	int a = 0; //laskuri
	if (tolower(direction[0]) == 'p') {
		result = rownum - i + 1;
		if (result >= 0) {
			for (rownum; rownum >= result; rownum--) {
				if (shipsArray[rownum][columnnum] == 0) {
					shipsArray[rownum][columnnum] = i;
					a++;
				}
				else {
					rownum++;
					result = rownum + a;
					for (rownum; rownum < result; rownum++) {
						shipsArray[rownum][columnnum] = 0;
					}
					return false;
				}
			}
		}
		else {
			return false;
		}
	}
	else if (tolower(direction[0]) == 'i') {
		result = columnnum + i - 1;
		if (result < ROWS) {
			for (columnnum; columnnum <= result; columnnum++) {
				if (shipsArray[rownum][columnnum] == 0) {
					shipsArray[rownum][columnnum] = i;
					a++;
				}
				else {
					columnnum--;
					result = columnnum - a;
					for (columnnum; columnnum > result; columnnum--) {
						shipsArray[rownum][columnnum] = 0;
					}
					return false;
				}
			}
		}
		else {
			return false;
		}
	}
	else if (tolower(direction[0]) == 'e') {
		result = rownum + i - 1;
		if (result < ROWS) {
			for (rownum; rownum <= result; rownum++) {
				if (shipsArray[rownum][columnnum] == 0) {
					shipsArray[rownum][columnnum] = i;
					a++;
				}
				else {
					rownum--;
					result = rownum - a;
					for (rownum; rownum > result; rownum--) {
						shipsArray[rownum][columnnum] = 0;
					}
					return false;
				}

			}
		}
		else {
			return false;
		}
	}
	else if (tolower(direction[0]) == 'l') {
		result = columnnum - i + 1;
		if (result >= 0) {
			for (columnnum; columnnum >= result; columnnum--) {
				if (shipsArray[rownum][columnnum] == 0) {
					shipsArray[rownum][columnnum] = i;
					a++;
				}
				else {
					columnnum++;
					result = columnnum + a;
					for (columnnum; columnnum < result; columnnum++) {
						shipsArray[rownum][columnnum] = 0;
					}
					return false;
				}
			}
		}
		else {
			return false;
		}
	}
	return true;
}
/*--------------------------------------------------
*
* nimi: printTitle
* toiminta: tulostaa pelikentän numerot
* parametri(t): cols
* paluuarvo(t):
*
*--------------------------------------------------*/
void printTitle(const int cols)
{
	cout << "   ";
	for (int i = 0; i < cols; i++)
		cout << setw(2) << (char)('1' + i);
	cout << endl;
}
/*--------------------------------------------------
*
* nimi: printUnderline
* toiminta: tulostaa pelikentän vaakaviivat pelikenttään
* parametri(t): cols
* paluuarvo(t):
*
*--------------------------------------------------*/
void printUnderline(const int cols)
{
	cout << setw(3) << '-';
	for (int i = 0; i < cols; i++)
		cout << "--";
	cout << "--\n";
}
/*--------------------------------------------------
*
* nimi: printShips
* toiminta: tulostaa laivataulukon
* parametri(t): shipsArray, rows, cols
* paluuarvo(t):
*
*--------------------------------------------------*/
void printShips(int shipsArray[][COLS], int rows, int cols)
{
	cout << endl;

	cout << "Laivat sijaitsevat seuraavissa paikoissa:" << endl << endl;

	// Tulosta 1. sarakeotsikko
	printTitle(cols);

	// Tulosta 1. alleviivaus
	printUnderline(cols);

	// Tulosta kaikki rivit:
	for (int i = 0; i < rows; i++) {
		cout << setw(1) << (char)('A' + i) << setw(2) << '|';

		for (int j = 0; j < cols; j++)
			cout << setw(2) << shipsArray[i][j];

		cout << setw(2) << '|';
		cout << setw(2) << (char)('A' + i) << endl;
	}

	// Tulosta 2. alleviivaus
	printUnderline(cols);

	// Tulosta 2. sarakeotsikko
	printTitle(cols);

	cout << endl;

}
/*--------------------------------------------------
*
* nimi: printShots
* toiminta: tulostaa osumataulukon
* parametri(t): shipsArray, rows, cols
* paluuarvo(t):
*
*--------------------------------------------------*/
void printShots(const char playArray[][COLS], const int rows, const int cols)
{
	cout << endl;

	cout << "Pelitilanne on seuraava:" << endl << endl;

	// Tulosta 1. sarakeotsikko
	printTitle(cols);

	// Tulosta 1. alleviivaus
	printUnderline(cols);

	// Tulosta kaikki rivit:
	for (int i = 0; i < rows; i++) {
		cout << setw(1) << (char)('A' + i) << setw(2) << '|';

		for (int j = 0; j < cols; j++)
			cout << setw(2) << playArray[i][j];

		cout << setw(2) << '|';
		cout << setw(2) << (char)('A' + i) << endl;
	}

	// Tulosta 2. alleviivaus
	printUnderline(cols);

	// Tulosta 2. sarakeotsikko
	printTitle(cols);

	cout << endl;
}

