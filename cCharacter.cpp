#include "cCharacter.h"
//#include "cCounter.h"
//#include "cEnemy.h"
//#include "cPlayer.h"
//#include "cSquareData.h"
#include "enum.h"
//#include "llist.h"
//#include "RandomNum.h"

//#include "character.h"
//#include"header.h"
#include <iostream>
using namespace std;


///////////////////////////////////////////////
//	cCharacter class functions
//
///////////////////////////////////////////////

void cCharacter::statsStore(game_char character){

	switch (character){
	case Orc:
			//will have to changer to allow for night /day stats
			//set the orcs data

			name = Orc;
			type = Orc;
			attack = 25;
			//attackChance = 0.25;// will have to change all numbers to doubles or floats to allow for 2/3
			attackChance = 25;
			defence = 10;
			//defenceChance = 0.25;
			defenceChance = 25;
			health = 50;
			strength = 130;
			break;

	case Hobbit:
			name = Hobbit;
			type = Hobbit;
			 attack=25;
			 attackChance =33;
			 //attackChance =0.3333;
			 defence=20;
			 defenceChance = 66;
			 //defenceChance = 0.6666;
			 health=70;
			 strength=85;
			 break;

	case Dwarf:
			name = Dwarf;
			type = Dwarf;
			attack=30;
			 //attackChance= 0.6666;
			attackChance= 66;
			 defence=20;
			 //defenceChance = 0.6666;
			 defenceChance = 66;
			 health=50;
			 strength=130;
			 break;

	case Elf:
			name = Elf;
			type = Elf;
			 attack=40;
			 
			 attackChance = 100;
			 defence=10;
			 defenceChance = 25;
			 //defenceChance = 0.25;
			 health=40;
			 strength=70;
			 break;

	case Human:
			name = Human;
			type = Human;
			 attack=30;
			 attackChance = 66;
			 //attackChance = 0.6666;
			 defence=20;
			 defenceChance = 50;
			 //defenceChance = 0.5;
			 health=60;
			 strength=100;
			 
			 break;

	default:
		cout<< "ERROR: cCharacter::statStore() - stats not loaded into character\n";
	}


}


/////////////////////////////////////////////////
//Change the characters stats
//
/////////////////////////////////////////////////

///////////////////////////////////////////
//increaseAttack
///////////////////////////////////////////
cCharacter::increaseAttack(cCharacter *, int amount){
	int newAttack = amount + getAttack();

	attack = newAttack;

	//return;
}

///////////////////////////////////////////
//increaseDefence
///////////////////////////////////////////
cCharacter::increaseDefence(cCharacter *,int amount){
	int newDefence = amount + defence;

	defence = newDefence;
}

///////////////////////////////////////////
//increaseHealth
///////////////////////////////////////////
cCharacter::increaseHealth(cCharacter *,int amount){
	int newHealth = amount + health;

	health = newHealth;
}

///////////////////////////////////////////
//increaseStrength
///////////////////////////////////////////
cCharacter::increaseStrength(cCharacter *,int amount){
	int newStrength = amount + strength;

	strength = newStrength;
}

///////////////////////////////////////////////////
//decrease
///////////////////////////////////////////////////

///////////////////////////////////////////
//decreaseAttack
///////////////////////////////////////////
cCharacter::decreaseAttack(cCharacter *,int amount){
	int newAttack = attack - amount;
	attack = newAttack;
}


///////////////////////////////////////////
//decreaseDefence
///////////////////////////////////////////
cCharacter::decreaseDefence(cCharacter *,int amount){
	int newDefence = defence - amount;

	defence = newDefence;
}


///////////////////////////////////////////
//decreaseStrength
///////////////////////////////////////////
cCharacter::decreaseStrength(cCharacter *,int amount){
	int newStrength = strength - amount;

	defence = newStrength;
}

///////////////////////////////////////////
//decreaseHealth
//
///////////////////////////////////////////
cCharacter::decreaseHealth(cCharacter *,int amount){
	int newHealth = health - amount;

	health = newHealth;
}

///////////////////////////////////////////
//decreaseHealth 2
//
///////////////////////////////////////////
//cCharacter::decreaseHealth(int old ,int amount){
//	int newHealth = old - amount;

//	health = newHealth;
//}


///////////////////////////////////////////
// hitOrMiss(chance, random num)
// takes in a n int chance
// 1/3 == 0.33 OR
// 33/100 in int
////////////////////////////////////////////
bool cCharacter::hitOrMiss(int chance, int hitMiss){
bool result = false;// miss
//RandomNum hitMiss;

//int num = hitMiss.giveRandNum(100);

if (hitMiss < chance){

	//hit
	result = true;
}else{

	result = false;
	//miss
}
	return result;
}

////////////////////////////////////////////////
// setCharCol
//
////////////////////////////////////////////////
cCharacter::setCharCol(int newcol){

	char_col = newcol;

}

////////////////////////////////////////////////
// setCharRow
// takes in the new row to be set to
////////////////////////////////////////////////
cCharacter::setCharRow(int newrow){

	char_row = newrow;

}

///////////////////////////////////////////
//  die()
//  turns on the cEnemys dead flag.
//
///////////////////////////////////////////
cCharacter::die(){

	// change flag
	deadOrAlive = false;
}


