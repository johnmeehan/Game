
#ifndef INC_CPLAYER_H
#define INC_CPLAYER_H

//#ifndef INC_CSQUAREDATA_H
//#define INC_CSQUAREDATA_H


//#ifndef INC_CCHARACTER_H
//#define INC_CCHARACTER_H

//#ifndef INC_ENUM_H
//#define INC_ENUM_H


#include"cSquareData.h"
#include"cCharacter.h"
#include"enum.h"
#include"RandomNum.h"
#include "cEnemy.h"


/////////////////////////////////////////////////////////////////
//	cPlayer is derived from a character
//
//	has the ability to move, pick up, iniciate attack etc......
/////////////////////////////////////////////////////////////////
class cPlayer:public cCharacter{
// ALL FUNCTIONS SHOULD BE PASSED THE POINTER TO THE CURRENT SQUARE AND A LOCAL ONE MADE IN THE FUNCTION
public:
	cPlayer(){ gold =0;}// constructor and set initial gold to 0
	~cPlayer(){;}		// deconstructor


	char gameMenu();						// in game menu
	game_char pickCharacter();				//lets the user pick its character
	bool move(char, int *, int*, cEnemy *,cEnemy *,cEnemy *,cEnemy *,cEnemy *);			// change the current location to new location

	bool checkSquare(cSquareData *);		// first see if something is there ,(for llist)

	char selectAttack();			// menu for the user . returns a char i.e direction
	void look(cSquareData *);			// print to screen whats in current square
	void look(cSquareData *, cEnemy *,cEnemy *,cEnemy *,cEnemy  *,cEnemy *);			// print to screen whats in current square

	bool attack(cPlayer *,cCharacter *,cRandomNumGen *);			// attack a enemy if present on the square
	bool defend();

	addGold(int);				// add winnings to total
	int getGold(){return gold;}				//return how much gold player has
				
	exit();					//Quit Game Destroy Board, squares

private:

	int gold;	// The amount of gold collected

	// inherits stats from cCharacter above

};



//#endif
//#endif
#endif