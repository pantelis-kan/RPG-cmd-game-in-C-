#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "RPG_classes.h"
#include <stdlib.h>

using namespace std;

bool to_bool(string &str){
	return (str.compare("true") == 0);
}

Market::Market(){

	string name,lvl,cost,dmg,two_handed;
    ifstream Weapons;
    Weapons.open("Weapons.txt");

    while(Weapons.good()){

    	Weapons >> name >> cost >> lvl >> dmg >> two_handed;
    	Weapon weapon(name,atoi(cost.c_str()),atoi(lvl.c_str()),atoi(dmg.c_str()),to_bool(two_handed));
      	stock.weapons.push_back(weapon);
	}
	Weapons.close();

	string reduce_dmg;
	ifstream Armors;
	Armors.open("Armors.txt");
	
	  while(Armors.good()){

    	Armors >> name >> cost >> lvl >> reduce_dmg;
    	Armor armor(name,atoi(cost.c_str()),atoi(lvl.c_str()),atoi(reduce_dmg.c_str()));
      	stock.armors.push_back(armor);
	}
	Armors.close();
	
	ifstream Potions;
	Potions.open("Potions.txt");
	  while(Potions.good()){	
		Potions >> name >> cost >> lvl >> reduce_dmg;
		Potion potion(name,atoi(cost.c_str()),atoi(lvl.c_str()),atoi(reduce_dmg.c_str()));
		stock.potions.push_back(potion);
	}
	Potions.close();
	
	ifstream Spells;
	string low_bound,high_bound,effect,identifier,MP;
	Spells.open("Spells.txt");
	while(Spells.good()){
		Spells >> identifier >> name >> cost >> lvl >> low_bound >> high_bound >>MP>> effect;
    	if(identifier.compare("f") == 0){
			FireSpell spell(name,atoi(cost.c_str()),atoi(lvl.c_str()),atoi(low_bound.c_str()),atoi(high_bound.c_str()),atoi(MP.c_str()),atoi(effect.c_str()));
      		FireSpell *ptr = new FireSpell(spell);
			stock.spells.push_back(ptr);		
		}
		else if(identifier.compare("i")){
			IceSpell spell(name,atoi(cost.c_str()),atoi(lvl.c_str()),atoi(low_bound.c_str()),atoi(high_bound.c_str()),atoi(MP.c_str()),atoi(effect.c_str()));
      		IceSpell *ptr = new IceSpell(spell);
			stock.spells.push_back(ptr);	
		}
		else{		
		 	LightingSpell spell(name,atoi(cost.c_str()),atoi(lvl.c_str()),atoi(low_bound.c_str()),atoi(high_bound.c_str()),atoi(MP.c_str()),atoi(effect.c_str()));
      		LightingSpell *ptr = new LightingSpell(spell);
			stock.spells.push_back(ptr);
			}
	}
	Spells.close();
	
}


extern int MarketMenu();

void Market::ShowMarket(Grid &A){


	vector<Spell*>::iterator itA = stock.spells.begin();
	vector<Hero*>::iterator itH = A.Heroes.begin();

	cout <<endl;
	int i = 1,selection,sell;


	cout <<"-----------------------------------"<<endl
		<< "------ WELCOME TO THE MARKET! -----"<<endl
		<< "-----------------------------------"<<endl;


	selection = MarketMenu();

	if(selection == 1){
	
		cout <<"//------------------- WEAPONS -------------------//"<<endl<<endl;
			vector<Weapon>::iterator it = stock.weapons.begin();
		cout <<"0. Nothing"<<endl;
		while(it != stock.weapons.end()){
			cout<<i<<". ";
			(*it).ShowItem();
			++it;
			++i;
			cout <<endl;
		}
		
		cout <<endl<<endl;
		
		cout <<"//------------------- ARMORS -------------------//"<<endl<<endl;
		vector<Armor>::iterator it2 = stock.armors.begin();
		while(it2 != stock.armors.end()){
			cout<<i<<". ";
			(*it2).ShowItem();
			++it2;
			++i;
			cout <<endl;
		}
		
		cout <<endl<<endl;
		
		cout <<"//------------------- POTIONS -------------------//"<<endl<<endl;
		vector<Potion>::iterator it3 = stock.potions.begin();
		while(it3 != stock.potions.end()){
			cout<<i<<". ";
			(*it3).ShowItem();
			++it3;
			++i;
			cout <<endl;
		}
		
		cout <<endl<<endl;
		
		cout <<"//------------------- SPELLS -------------------//"<<endl<<endl;
		
		while(itA != stock.spells.end()){
			cout<<i<<". ";
			(*itA)->ShowSpell();
			++itA;
			++i;
			cout <<endl;
		}
		
		cout <<"What would you like to buy? (0-30)"<<endl;
		
	
		while(itH != A.Heroes.end()){
			cout << (*itH)->get_name() <<": I want... ";
			do{
				cin >> selection;
			}while(selection < 0 || selection > 30);
			if(selection != 0){
				if(selection <= stock.weapons.size() ){
					(*itH)->buy(stock.weapons.at(selection- 1));			
				}
				else if(selection <= stock.weapons.size() + stock.armors.size()){
					(*itH)->buy(stock.armors.at(selection-stock.weapons.size()- 1));
				}
				else if(selection <= stock.weapons.size()+stock.armors.size()+stock.potions.size()){
					(*itH)->buy(stock.potions.at(selection-stock.armors.size()-stock.weapons.size()- 1));
				}
				else{
					(*itH)->buy((*stock.spells.at(selection-stock.armors.size()-stock.potions.size()-stock.weapons.size()-1)));
				}
		}
		else  ++itH;;
		cout<<endl;
		}
	}
	else if(selection == 2){
		vector<Hero *>::iterator it5 = A.Heroes.begin();
		while(it5 != A.Heroes.end()){
			(*it5)->sell();
			++it5;
		}
	}
	else if(selection == 3){
		return;
	}


	cout <<"--<Please come again!>--"<<endl;
	

}

