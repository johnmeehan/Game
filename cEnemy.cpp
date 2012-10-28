/*
#include "character.h"
#include "RandomNum.h"
///////////////////////////////////////////////////
// cEnemy class functions
//
////////////////////////////////////////////////////
//possible boardfunction
assignEnemys(cEnemy *orc,cEnemy *elf,cEnemy *dwarf,cEnemy *hobbit,cEnemy *human,cSquareData *gameBoard[boardRow][boardCol]){
	//////////////////////////////
	// assign enemys
	// one of each on the board
	// and set there locations
	//////////////////////////////
	// assign each of the cEnemy cCharacters their stats
game_char gchar;
	cRandomNumGen xRand, yRand;
	int itsRow;
	int itsCol;
	//////////////
	//Orc
	//////////////

	orc->statsStore(gchar = Orc);// give orc its battle stats
	//random x and y
	itsRow = xRand.giveRandNum(boardRow-1);
	itsCol = yRand.giveRandNum(boardCol-1);
	cout << "Row:\t" << itsRow << "\tCol:\t" << itsCol<< "\n";	//**************test
	//set its location
	orc->setCharRow(itsRow);
	orc->setCharCol(itsCol);
	orc->bringToLife();

	// tellits location it has one
	//which goes to the gameBoard[x][y] and sets the character atributes of gameBoard[][].enemyName etc......
	gameBoard[itsRow][itsCol].enemyName = Orc;
	gameBoard[itsRow][itsCol].enemyType = Orc;

/*
	////////
	// ELF
	////////
	 elf.statsStore(gchar = Elf);
	//random x and y
	itsRow = xRand.giveRandNum(boardRow-1);
	itsCol = yRand.giveRandNum(boardCol-1);
	cout << "Row:\t" << itsRow << "\tCol:\t" << itsCol<< "\n";			//**************test
	//set its location
	orc.setCharRow(itsRow);
	orc.setCharCol(itsCol);
	orc.bringToLife();
	// tellits location it has one
	//which goes to the gameBoard[x][y] and sets the character atributes of gameBoard[][].enemyName etc......
	gameBoard[itsRow][itsCol].enemyName = Elf;
	gameBoard[itsRow][itsCol].enemyType = Elf;

	///////////////
	//Hobbit
	////////////////
	hobbit.statsStore(gchar = Hobbit);
		//random x and y
	itsRow = xRand.giveRandNum(boardRow-1);
	itsCol = yRand.giveRandNum(boardCol-1);
	cout << "Row:\t" << itsRow << "\tCol:\t" << itsCol<< "\n";			//**************test
	//set its location
	orc.setCharRow(itsRow);
	orc.setCharCol(itsCol);
	orc.bringToLife();

	// tellits location it has one
	//which goes to the gameBoard[x][y] and sets the character atributes of gameBoard[][].enemyName etc......
	gameBoard[itsRow][itsCol].enemyName = Hobbit;
	gameBoard[itsRow][itsCol].enemyType = Hobbit;

	///////////////
	//Dwarf
	///////////////
	dwarf.statsStore(gchar  = Dwarf);
		//random x and y
	itsRow = xRand.giveRandNum(boardRow-1);
	itsCol = yRand.giveRandNum(boardCol-1);
	cout << "Row:\t" << itsRow << "\tCol:\t" << itsCol<< "\n";			//**************test
	//set its location
	orc.setCharRow(itsRow);
	orc.setCharCol(itsCol);
	orc.bringToLife();

	// tellits location it has one
	//which goes to the gameBoard[x][y] and sets the character atributes of gameBoard[][].enemyName etc......
	gameBoard[itsRow][itsCol].enemyName = Dwarf;
	gameBoard[itsRow][itsCol].enemyType = Dwarf;

	////////////////
	//Human
	////////////////
	human.statsStore(gchar =  Human);
		//random x and y
	itsRow = xRand.giveRandNum(boardRow-1);
	itsCol = yRand.giveRandNum(boardCol-1);
	cout << "Row:\t" << itsRow << "\tCol:\t" << itsCol<< "\n";			//**************test
	//set its location
	orc.setCharRow(itsRow);
	orc.setCharCol(itsCol);
	orc.bringToLife();

	// tellits location it has one
	//which goes to the gameBoard[x][y] and sets the character atributes of gameBoard[][].enemyName etc......
	gameBoard[itsRow][itsCol].enemyName = Human;
	gameBoard[itsRow][itsCol].enemyType = Human;


*/

//}//func

//*/