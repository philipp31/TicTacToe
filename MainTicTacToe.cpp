#include "GameField.h"
#include <iostream>

using namespace std;

void printInfo();

int main() {
	unique_ptr<Communication> console = unique_ptr<Communication>(new Communication());
	unique_ptr<GameField> fieldObj = unique_ptr<GameField>(new GameField());
	string input;
	bool player = false; // false heißt Spieler X, true == Spieler 0
	printInfo();

	int x = 0;
	int y = 0;
	bool goOn = true;
	bool insertSuccessfull;
	int winSituation = 0;
	do {
		fieldObj->printField();
		if (player) {
			do {
				console->printOutput("Spieler '0' ist dran.");
				x = console->getXPosition();
				if (x == -3) {
					goOn = false;
					break;
					break;
				}
				y = console->getYPosition();
				if (y == -3) {
					goOn = false;
					break;
					break;
				}
				insertSuccessfull = fieldObj->insertPosition(x - 1, y - 1, '0');
			} while (insertSuccessfull == false);	// solange eine besetzte Position angegeben wird wiederholen
		}
		else {
			do {
				console->printOutput("Spieler 'X' ist dran.");
				x = console->getXPosition();
				if (x == -3) {
					goOn = false;
					break;
					break;
				}
				y = console->getYPosition();
				if (y == -3) {
					goOn = false;
					break;
					break;
				}
				insertSuccessfull = fieldObj->insertPosition(x - 1, y - 1, 'X');
			}  while (insertSuccessfull == false);
		}
		winSituation = fieldObj->evaluateWin();
		if (winSituation != 0) {
			goOn = false;
			if (winSituation == -1) {
				fieldObj->printField();
				cout << "**** Spieler '0' hat gewonnen. ****";
			}
			else if (winSituation == 1) {
				fieldObj->printField();
				cout << "**** Spieler 'X' hat gewonnen. ****";
			}
		}
		player = !player;
	} while (goOn);
	cout << "****** Das Spiel wurde beendet ******\n";
	cout << "\n\n\n\n";
	return 0;
}

void printInfo() {
	cout << "Willkommen bei TicTacToe!\n";
	cout << "Wenn Sie das Spiel verlassen wollen geben Sie 'exit' oder 'Enter' ein \n"; 
}