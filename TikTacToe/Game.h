#pragma once
#include "Player.h"
#include "Board.h"
class Game{
private:
	Board* board;
	vector<Player*> players;
	int currentPlayer;
	int numOfPlayers;
	vector<char> symbols = { 'O', 'X', '?', '*' };
	int numOfMoves;
public:
	~Game();
	void playGame();
	void startGame();
	void printGameState();
	int checkIfGameComplete(Player*, int, int);
};