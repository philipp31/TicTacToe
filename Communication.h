#pragma once
#include <iostream>
#include <string.h>
#include <string>

using namespace std;

class Communication {
private:

public:
	string getInput() {
		string cache;
		cin >> cache;
		return cache;
	}

	void printOutput(string message) {
		cout << message << endl;
	}

	int getXPosition() {
		cout << "Gib bitte die Zeile deines Zugs an:\n";
		string input;
		cin >> input;
		if (input.compare("exit") == 0 || input.compare("\n") == 0) {
			return -3;
		}
		try {
			int xPos = stoi(input);
			if (xPos < 1 || xPos > 3) {
				cout << "Du musst eine Zahl zwischen 1 und 3 angeben!\n";
				return getXPosition();
			}
			return xPos;
		}
		catch (exception& err) {
			cout << "Du musst eine Zahl zwischen 1 und 3 angeben!\n";
			return getXPosition();
		}
		return 0;
	}

	int getYPosition() {
		cout << "Gib bitte Die Spalte deines Zugs an:\n";
		string input;
		cin >> input;
		if (input.compare("exit") == 0 || input.compare("\n") == 0) {
			return -3;
		}
		try {
			int yPos = stoi(input);
			if (yPos < 1 || yPos > 3) {
				cout << "Du musst eine Zahl zwischen 1 und 3 angeben!\n";
				return getYPosition();
			}
			return yPos;
		}
		catch (exception& err) {
			cout << "Du musst eine Zahl zwischen 1 und 3 angeben!\n";
			return getYPosition();
		}
		return 0;
	}
};
