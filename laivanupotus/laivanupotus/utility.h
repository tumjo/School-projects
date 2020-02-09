#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int ROWS = 7; 
const int COLS = 7; 
void menu(int shipsArray[][COLS], int rows, int cols, bool& gameon, int shipsleft[], int size, char playArray[][COLS], int sizepArray, int sizesArray);
void printMenu();
char menuInput();
void run(char, int shipsArray[][COLS], int rows, int cols, bool& gameon, int shipsleft[], int size, char playArray[][COLS], int sizepArray, int sizesArray);
void run1(int shipsArray[][COLS], int rows, int cols, bool& gameon);
void run2(int shipsArray[][COLS], int rows, int cols, bool& gameon, int shipsleft[], int size, char playArray[][COLS], int sizepArray, int sizesArray);
void run3(int shipsArray[][COLS], int rows, int cols, bool& gameon);
void run4(int shipsArray[][COLS], int rows, int cols, bool& gameon, int shipsleft[], int size, char playArray[][COLS]);
void run5(int shipsArray[][COLS], int rows, int cols, bool& gameon, int shipsleft[], int size, char playArray[][COLS]);
void printTitle(const int cols);
void printUnderline(const int cols);
void printShips(int shipsArray[][COLS], int rows, int cols);
void printShots(const char playArea[][COLS], const int rows, const int cols);
int convertCoordinates(char*, int &, int &);
int checkDirection(char*);
void inputShips(int shipsArray[][COLS], int rows, int cols);
bool installShips(int shipsArray[][COLS], int rows, int cols, char* direction, int i, int rownum, int columnnum);
void randomShips(int shipsArray[][COLS], int rows, int cols);
void play(int shipsArray[][COLS], int rows, int cols, int shipsleft[], int size, char playArray[][COLS]);
bool checkShips(int shipsArray[][COLS], int rows, int cols, int shipsleft[], char playArray[][COLS], int rownum, int columnnum);
int checkShipsnum(int shipsleft[], int size);
void formatall(int shipsArray[][COLS], int rows, int cols, int shipsleft[], int size, char playArray[][COLS], int sizepArray, int sizesArray);
void installsink(int shipsArray[][COLS], int rows, int cols, char playArray[][COLS], int rownum, int columnnum);
void savegame(int shipsArray[][COLS], int rows, int cols, bool& gameon, int shipsleft[], int size, char playArray[][COLS]);
void loadgame(int shipsArray[][COLS], int rows, int cols, bool& gameon, int shipsleft[], int size, char playArray[][COLS]);