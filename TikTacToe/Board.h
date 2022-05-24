#pragma once
#include<vector>
#include "Player.h"
using namespace std;
class Board{
private:
	int size;
	vector<vector<char>> board;
public:
	Board(int);
	int getSize();
	void printBoardState();
	void makeMove(Player*,int,int);
	bool isValidPosition(int,int);
	bool isWinning(char, int, int);
	bool isDraw(int);
};

