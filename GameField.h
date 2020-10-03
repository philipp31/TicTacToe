#pragma once
#include <iostream>
#include "AnalyzeGame.h"
#include "Communication.h"

using namespace std;

class GameField {

private:
	char** field;
	unique_ptr<AnalyzeGame> gameAnalyzer;
	unique_ptr<Communication> console;

	void printSeperation() {
		cout << "  ------- \n";
	}

public:
	GameField() {
		initField();
		gameAnalyzer = unique_ptr<AnalyzeGame>(new AnalyzeGame(field));
	}

	void initField() {
		// initialisieren des Feldes:
		field = new char* [3]; 
		for (int h = 0; h < 3; h++) {
			field[h] = new char[3];
		}
		// Befüllen des Feldes:
		for (int i = 0; i < 3; i++) {
			for (int k = 0; k < 3; k++) {
				field[i][k] = ' ';
			}
		}
	}

	bool insertPosition(int posX, int posY, char val) {
		if (val != 'X' && val != '0') {
			cout << "Die Position für insertion ist invalid!" << endl;
			return false;
		}
		else if (field[posX][posY] != ' ') {
			cout << "Die Position die Sie angegeben haben ist leider schon besetzt!\n";
			return false;
		}
		else {
			try {
				field[posX][posY] = val;
			}
			catch (exception& err) {
				cout << "Error for X , Y : " << posX << ", " << posY << endl;
			}
			return true;
		}
	}

	bool isFieldFull() {
		return this->gameAnalyzer->isFieldFull();
	}

	int evaluateWin() {
		return this->gameAnalyzer->evaluateWin();
	}

	void printField() {
		cout << "\n\n";
		cout << "  1  2  3" << endl;
		for (int i = 0; i < 3; i++) {	// zeile für zeile
			for (int k = 0; k < 3; k++) { // Jede spalte einer reihe wird erzeut
				if (k == 0) {
					cout << i + 1;	// am Anfang jeder Zeile die Zeilen-Nr. printen
				}
				cout << " ";
				if (k == 0) {
					cout << field[i][k] << "|";
				}
				else if (k == 1) {
					cout << field[i][k] << " " << "|";
				}
				else {
					cout << field[i][k] << "\n";	// am Ende jeder Zeile new Line
				}
			}
			if (i < 2) {
				printSeperation();
			}
		}
	}

	~GameField() {
		for (int i = 0; i < 3; ++i) {
			delete[] field[i];
		}
		delete[] field;
		field = NULL;
		cout << "char[][] speicher wurde freigegeben \n";
		cout << "GameField-Instanz wurde geloescht \n";
	}
};