
#ifndef INC_CSQUAREDATA_H
#define INC_CSQUAREDATA_H

#include "enum.h"

//////////////////////////////////////////////////////////////////////
//	DATA	CLASS
//	cData
//
//  Dynamic Array will contain "Squares" which contains"cSquareData"
//////////////////////////////////////////////////////////////////////

// define type for required data
class cSquareData {
public:
	game_item itemName;		// the itemName
	game_char enemyName;
	game_item_type itemType;		// the Item Type
	game_char enemyType;
};						// End of the data class


#endif