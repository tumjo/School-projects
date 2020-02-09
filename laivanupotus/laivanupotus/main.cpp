#include "utility.h"

int main()
{
	bool gameon = false; //Kertoo onko peli pelattavissa. Oletusarvo false. True, kun laivat taulukossa
	int shipsArray[ROWS][COLS] = {}; //laivataulukko nollattuna 
	char playArray[ROWS][COLS] = {}; //pelitaulukko "tyhjänä" (\0)
	int shipsleft[] = { 5, 4, 3, 2 }; //laivat pelissä 
	int size = sizeof(shipsleft) / sizeof(int); //taulukon koko
	int sizepArray = sizeof(playArray); //taulukon koko
	int sizesArray = sizeof(shipsArray); //taulukon koko

	menu(shipsArray, ROWS, COLS, gameon, shipsleft, size, playArray, sizepArray, sizesArray); //main

	return 0;
}

