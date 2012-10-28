#ifndef INC_CENEMY_H
#define INC_CENEMY_H


//#ifndef INC_CSQUAREDATA_H
//#define INC_CSQUAREDATA_H


//#ifndef INC_ENUM_H
//#define INC_ENUM_H


//#ifndef INC_CCHARACTER_H
//#define INC_CCHARACTER_H
// needs to see 
#include "cSquareData.h"
#include "cCharacter.h"
#include "enum.h"

// cCharacter.h

//#include "cCharacter.h"
/////////////////////////////////////////////////////////////////
//	Enemy is derived from a character
//
//	has the ability to defend when attacked a retrun an attack
//
//	Does not pick up items or move from initialised location
/////////////////////////////////////////////////////////////////
class cEnemy:public cCharacter{
public:
	cEnemy(){ bringToLife();}
	virtual ~cEnemy(){;}
//	bool attack();
//	bool defend();
//	assignEnemys(cEnemy *,cEnemy *,cEnemy *,cEnemy *,cEnemy *,cSquareData *);

//	setupStats(game_char);
//	bool checkIfAlive(){return deadOrAlive;}		// is the enemy dead or alive
	
	// inherits from cCharacter above

};



//#endif
//#endif
#endif