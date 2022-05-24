#pragma once
#include<string>
using namespace std;
class Player{
private:
	string name;
	double winPercentage;
	char symbol;
public:
	Player(string, char);
	string getName();
	char getSymbol();
};

