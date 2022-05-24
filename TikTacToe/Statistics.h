#pragma once
#include<unordered_map>
#include "Player.h"
using namespace std;
class Statistics{
private:
	unordered_map<int,Player> mp;
public:
	int getUniqueId();
};

