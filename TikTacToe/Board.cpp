#include "Board.h"
#include "Player.h"
#include <vector>
#include <iostream>
using namespace std;

Board::Board(int size) {
	this->size = size;
	this->board.resize(size, vector<char>(size,' '));
}

int Board::getSize() {
	return this->size;
}

void Board::printBoardState() {
	for (int i = 0; i < this->size; ++i) {
		cout << "|";
		for (int j = 0; j < this->size; ++j) {
			cout << board[i][j] << "|";
		}
		cout << endl;
	}
	cout << endl;
}

void Board::makeMove(Player* player, int row, int col) {
	this->board[row][col] = player->getSymbol();
}

bool Board::isValidPosition(int row, int col) {
	return row >= 0 && row < this->size && col >=0 && col < this->size && board[row][col]==' ';
}

bool Board::isDraw(int numOfMoves) {
	return numOfMoves == (this->size * this->size); 
}

bool Board::isWinning(char symbol, int row, int col) {
	bool rowCheck = true, colCheck = true, digCheck = true, revDigCheck = true;
	for (int i = 0; i < this->size; ++i) {
		if (board[row][i]!=symbol) {
			rowCheck = false;
		}
		if (board[i][col] != symbol) {
			colCheck = false;
		}
		if (board[i][i] != symbol) {
			digCheck = false;
		}
		if (board[this->size-i-1][i] != symbol) {
			revDigCheck = false;
		}
	}
	return rowCheck || colCheck || digCheck || revDigCheck;
}