#include<iostream>
#include "Game.h"
#include "Board.h"
#include "Player.h"

using namespace std;

Game::~Game() {
	if (board) {
		delete board;
	}
	for (int i = 0; i < players.size(); ++i) {
		delete players[i];
	}
}


void Game::startGame() {
	int boardSize, numOfPlayers;
	string playerName;
	numOfMoves = 0;
	currentPlayer = -1;
	
	cout << "Enter Board Size: ";
	cin >> boardSize;
	board = new Board(boardSize);

	cout << "Enter Number of Players: ";
	cin >> numOfPlayers;
	this->numOfPlayers = numOfPlayers;
	currentPlayer = 0;
	for (int i = 0; i < numOfPlayers; ++i) {
		cout << "Enter Player " << i+1 << " Name: ";
		cin >> playerName;
		players.push_back(new Player(playerName, symbols[i]));
	}
}


void Game::playGame() {
	int row, col;
	bool gameComplete = false;
	while (!gameComplete) {
		this->currentPlayer = (this->currentPlayer + 1)%numOfPlayers;
		bool moveDone = false;
		moveDone = false;
		while (!moveDone) {
			printGameState();
			cout << "\nEnter row and column to make move (space separated): ";
			cin >> row >> col;
			row--, col--;
			if (board->isValidPosition(row,col)) {
				board->makeMove(players[this->currentPlayer], row, col);
				moveDone = true;
				numOfMoves++;
				int isGameComplete = checkIfGameComplete(players[this->currentPlayer], row, col);
				switch (isGameComplete) {
					case 1: cout << players[this->currentPlayer]->getName() << " Won!";
						gameComplete = true;
						break;
					case 2: cout << "Draw!";
						gameComplete = true;
						break;
					default: 
						continue;
				}
			}
			else {
				cout << "\nInvalid Position!" << endl;
			}
		}
	}
}


void Game::printGameState() {
	cout << "\n\n\n-----------------------------------------------------------------------------------------\n\n";
	board->printBoardState();
	for (int i = 0; i < this->players.size(); ++i) {
		cout << players[i]->getName() << " " << players[i]->getSymbol()<<endl;
	}
	cout << "Current Player: " << players[this->currentPlayer]->getName() << endl;
	cout << "-----------------------------------------------------------------------------------------\n";
}

int Game::checkIfGameComplete(Player* player, int row, int col) {
	if (board->isWinning(player->getSymbol(), row, col)) {
		return 1;
	}
	else if (board->isDraw(numOfMoves)) {
		return 2;
	}
	return 0;
}
