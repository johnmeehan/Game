
#ifndef _INC_CCHARACTER_H
#define _INC_CCHARACTER_H

//#ifndef _INC_ENUM_H
//#define _INC_ENUM_H

#include"enum.h"

/////////////////////////////////////////////////////////////////
//	cCharacters a derived class from the base class square 
//	it is a template class (ie can be the player or a enemy)
//
/////////////////////////////////////////////////////////////////
class cCharacter{

	// whats common to both player and enemy??
public:
	// for allowing acesess to private variables
	int getAttack() {return attack;}
	int getDefence() {return defence;}
	int getHealth() {return health;}
	int getStrength() {return strength;}
	int getAttackChance() {return attackChance;}
	int getDefenceChance() {return defenceChance;}
	game_char getName(){return name;}

	// change cCharacters stats
	increaseHealth(cCharacter *,int amount);  // pick up ring
	increaseAttack(cCharacter *,int amount);	// picked up a weapon
	increaseDefence(cCharacter *,int amount);	// picked up a armour or shield
	increaseStrength(cCharacter *,int amount); //pick up any rings?

	decreaseHealth(cCharacter *,int amount); // got hit
	decreaseAttack(cCharacter *,int amount); // drop the sword
	decreaseDefence(cCharacter *,int amount);	// drop a armour or shield
	decreaseStrength(cCharacter *,int amount); // drop a ring


	// set its location
	setCharCol(int);
	setCharRow(int);

	void bringToLife(){ deadOrAlive = true;}

	// give out its location
	int getCharRow(){return char_row;}
	int getCharCol(){return char_col;}
	game_char getCharName(){return name;}

	// gives each character there original stats
	void statsStore(game_char); // where stats on characters are stored.takes in the type

	// bool hitOrMiss() takes in the chance of hitting and returns a bool if its good or bad.
	bool hitOrMiss(int,int);

	bool checkIfAlive(){return deadOrAlive;}		// is the enemy dead or alive
	die();


private:

	// would it be easier to make public??
	// do enemy and player inherit private variables????? 
	game_char name;
	game_char type;
	int strength;
	int attack;
	int defence;
	int health;
	int attackChance;
	int defenceChance;
	int char_row;		//	for identifying where i am
	int char_col;
	bool deadOrAlive;
};



#endif