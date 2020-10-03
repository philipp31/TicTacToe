#pragma once
#include <iostream>
using namespace std;

class AnalyzeGame {
private:
	char** field;

	int evaluateCrosses() {
		int counter = 0;
		for (int i = 0; i < 3; i++) {	// von oben links nach unten rechts
			if (field[i][i] == 'X') {
				counter++;
			}
		}
		if (counter == 3) {
			return 1;
		}
		counter = 0;
		for (int i = 0; i < 3; i++) {	// von oben links nach unten rechts
			if (field[i][i] == '0') {
				counter++;
			}
		}
		if (counter == 3) {
			return -1;
		}
		counter = 0;
		for (int i = 0; i < 3; i++) {	// von unten links nach oben rechts
			if (field[2 - i][i] == '0') {
				counter++;
			}
		}
		if (counter == 3) {
			return -1;
		}
		counter = 0;
		for (int i = 0; i < 3; i++) {	// von unten links nach oben rechts
			if (field[2 - i][i] == 'X') {
				counter++;
			}
		}
		if (counter == 3) {
			return 1;
		}
	}

	int evaluateRows() {
		int counter = 0;
		for (int i = 0; i < 3; i++) {	// Zeile für zeile
			for (int k = 0; k < 3; k++) { //jede reihe wird durchlaufen
				if (field[i][k] == 'X') {
					counter++;
				}
				if (counter == 3) {
					return 1;
				}
			}
			counter = 0;
		}
		counter = 0;
		for (int i = 0; i < 3; i++) {	// Zeile für zeile
			for (int k = 0; k < 3; k++) { //jede reihe wird durchlaufen
				if (field[i][k] == '0') {
					counter++;
				}
				if (counter == 3) {
					return -1;
				}
			}
			counter = 0;
		}
		return 0;
	}

	int evaluateColumns() {
		int counter = 0;
		for (int i = 0; i < 3; i++) {	// jede reihe
			for (int k = 0; k < 3; k++) { //jede spalte
				if (field[k][i] == 'X') {
					counter++;
				}
				if (counter == 3) {
					return 1;
				}
			}
			counter = 0;
		}
		counter = 0;
		for (int i = 0; i < 3; i++) {	// jede reihe
			for (int k = 0; k < 3; k++) { //jede spalte
				if (field[k][i] == '0') {
					counter++;
				}
				if (counter == 3) {
					return -1;
				}
			}
			counter = 0;
		}
		return 0;
	}

public: 

	AnalyzeGame(char** field) {
		this->field = field;
	}

	int evaluateWin() {
		int crossStatus = evaluateCrosses();
		int rowStatus = evaluateRows();
		int columnStatus = evaluateColumns();
		if (crossStatus == -1 || rowStatus == -1 || columnStatus == -1) {
			return -1;
		}
		else if (crossStatus == 1 || rowStatus == 1 || columnStatus == 1) {
			return 1;
		}
		else {
			return 0;
		}
	}

	bool isFieldFull() {
		for (int i = 0; i < 3; i++) {	// jede reihe
			for (int k = 0; k < 3; k++) { //jede spalte
				if (field[i][k] != 'X' && field[i][k] != '0') {
					return false;
				}
			}
		}
		return true;
	}

	~AnalyzeGame() {
		field = NULL;
		cout << "AnalyzeGame wurde geloescht";
	}
};