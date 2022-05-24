#include "Player.h"
#include "Statistics.h"

using namespace std;

Player::Player(string name, char symbol) {
	this->name = name;
	this->symbol = symbol;
}

string Player::getName() {
	return this->name;
}

char Player::getSymbol() {
	return this->symbol;
}