#include <iostream>
#include "RPG_classes.h"

using namespace std;

int MarketMenu(){
	
	int selection;
	
	do{
	cout <<"1. Buy Items/Spells"<<endl<<"2. Sell Items/spells"<<endl<<"3. Exit"<<endl;
	cin >> selection;
	}while(selection != 1 && selection != 2 && selection != 3);
	
	return selection;
}

int BattleMenu(){
	int selection;
	
	cout<<"1. Attack"<<endl
		<<"2. Cast Spell"<<endl
		<<"3. Use potion"<<endl
		<<"4. Equip Weapon/Armor"<<endl
		<<"Selection : ";
	
	do{
		cin >> selection;	
	}while(selection < 1 && selection > 4);
	
	return selection;
}

void Main_Menu(){
	
	int selection;
	
	cout<<endl<<endl<<"______________________________________________________________________"<<endl;
	cout<<"<< Sword in hand, a warrior clutches stone to breast."<<endl 
	<<"In sword etched his fading memories. In stone, his tempered skill."<<endl 
	<<"By sword attested, by stone revealed. Their tale can now be told. >> "<<endl;
	cout<<"______________________________________________________________________"<<endl<<endl;
	
	cout<<"---------------------- WELCOME ----------------------"<<endl<<endl;
	
	Grid world;



do{
	cout<<endl<<"Choose one of the following:"<<endl;	
	cout<<"1. Display Map"<<endl
		<<"2. Move Up"<<endl
		<<"3. Move Down"<<endl
		<<"4. Move Left"<<endl
		<<"5. Move Right"<<endl
		<<"6. Quit Game"<<endl;
	cout<<endl<<"Selection : ";
	cin	>> selection;
	
	switch(selection){
		case 1:{
			world.DisplayMap();
			break;
		}
		case 2:{
			world.move(UP);
			break;
		}
		case 3:{
			world.move(DOWN);
			break;
		}
			case 4:{
			world.move(LEFT);
			break;
		}
		case 5:{
			world.move(RIGHT);
			break;
		}
		default:
			break;
	}

}while(selection != 6);

cout <<endl<<"Thank you for playing!"<<endl;


}


