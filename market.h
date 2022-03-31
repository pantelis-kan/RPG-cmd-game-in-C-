#ifndef MARKET_H
#define MARKET_H
#include <iostream>
#include <vector>
#include "RPG_classes.h"


using namespace std;

//////////////////////////////////////////////////
///////////////		MARKET		//////////////////
//////////////////////////////////////////////////

class Market{
	
	public:
		Market();
		void ShowMarket();	

	private:
		vector<Item *> market;
};

#endif
