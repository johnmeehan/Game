#include "cCharacter.h"
//#include "cCounter.h"
//#include "cEnemy.h"
#include "cPlayer.h"
#include "cSquareData.h"
#include "enum.h"
//#include "llist.h"
//#include "RandomNum.h"


//#include"header.h"
//#include "character.h"
#include <iostream>
using namespace std;

////////////////////////////////////////////////
//  cPlayer class functions
//
////////////////////////////////////////////////



/////////////////////////////////////////////////////
// move()
// adjusts the players current location in the array
//		col
//		------------	
//  row| cSquareData|
//		------------
//
// takes in the direction the user wants to go 
// then adjusts it current location to the new one
/////////////////////////////////////////////////////

bool cPlayer::move(char direction, int *boardRow, int *boardCol,  cEnemy *orc,cEnemy *hobbit,cEnemy *human,cEnemy  *elf,cEnemy *dwarf){

//	cout<< "**im in move\n";
//	system("pause");


	bool moveResult = false;
	int row=0, col=0;

	switch(direction){

		/////////////////////////////////
		// [row][col]
		//  x     y
		// n -1 row
		// s +1 row
		// w -1 col
		// e +1 col
		//////////////////////////////////
	case 'n': 
	case 'N':
		//////////////////////////////////
		// adjust the row number only
		//  -1
		//////////////////////////////////

		// get my row
		row = getCharRow();
		// if row is not zero do move
		if(row != 0){
			row = row-1;
			setCharRow(row);
			moveResult = true; // move was good
		}else {
			break;//get out leaving variable unchanged
		}
		break;

	case 's':
	case 'S':
		//////////////////////////////////
		// adjust the row number only
		//  +1
		//////////////////////////////////

		// get my row
		 row = getCharRow();
		// if row is not zero do move
		 if(row != (*boardRow-1)){
			row = row+1;
			setCharRow(row);
			moveResult = true;
		}else {
			break;//get out leaving variable unchanged
		}
		break;
		//if character row = boardRow - 1
		// i cant move s
		// else row = row +1
		break;

	case 'w': 
	case 'W':
		//////////////////////////////////
		// adjust the col number only
		//  -1
		//////////////////////////////////
		// get my col
		col = getCharCol();
		// if row is not zero do move
		if(col != 0){
			col = col-1;
			setCharCol(col);
			moveResult = true;
		}else {
			break;//get out leaving variable unchanged
		}
		break;
		//if character row = boardRow - 1
		// i cant move s
		// else row = row +1

	case 'e' :
	case 'E':

		//////////////////////////////////
		// adjust the col number only
		//  +1
		//////////////////////////////////
		// get my col
		col = getCharCol();
		// if row is not zero do move
		if(col != (*boardCol-1)){
			col = col+1;
			setCharCol(col);
			moveResult = true;
		}else {
			break;//get out leaving variable unchanged
		}
		break;
		//if character row = boardRow - 1
		// i cant move s
		// else row = row +1

	case 'a':
	case 'd':
	case 'i':
	case 'l':
	case 'p':
	case 'x':

	case 'A':
	case 'D':
	case 'I':
	case 'L':
	case 'P':
	case 'X':


		break;

	default:
		cout << "ERROR: cPlayer::move() - Invalid Direction!!!\n";
		moveResult = false;
		break;
	}
	// now check new square for an item or enemy . this should be the job for another function
	return moveResult;
}


//////////////////////////////// 
// addGold(int amount)
//  add an amount of gold to the cPlayers gold store
//////////////////////////////////////////////////
cPlayer::addGold(int amount){

	int newgold = gold + amount;

	gold = newgold;
}


/////////////////////////////////////////////////////////
//look()
// 
// prints ot whats on the square
///////////////////////////////////////////////////////////
void cPlayer::look(cSquareData *thisSquare){
// void cPlayer::look(cSquare mysquare){
	
	 cout<< "This Square has: \n";

// test
//	cout<< thisSquare->itemName <<"\n";
//	cout<< thisSquare->itemType <<"\n";
//	cout<< thisSquare->enemyName <<"\n";
//	cout<< thisSquare->enemyType <<"\n";
/////////////


	if(thisSquare->itemName == noitem && thisSquare->enemyName ==nochar ){
		cout<< "RESULT: Nothing Here!\n";
	}else if (thisSquare->itemName != noitem && thisSquare->enemyName == nochar){
	// only an item here
		

		cout<< "********\n";
		cout<< "**ITEM**\n";
		cout<< "********\n";
		if(thisSquare->itemName == Sword && thisSquare->itemType == Weapon){
			 cout << "Weapon Sword\n";
		 
		 }else if(thisSquare->itemName == Dagger && thisSquare->itemType == Weapon){
			 cout << "Weapon Dagger\n";
		 
		 }else if(thisSquare->itemName == Plate && thisSquare->itemType == Armour){
			 cout << "Plate Armour\n";
		 
		 }else if(thisSquare->itemName == Leather && thisSquare->itemType == Armour){
			 cout << "Leather Armour\n";
		 
		 }else if(thisSquare->itemName == Large && thisSquare->itemType == Shield){
			 cout << "Large Shield\n";

		 }else if(thisSquare->itemName == Small && thisSquare->itemType == Shield){
			 cout << "Small Shield\n";

		 }else if(thisSquare->itemName == Life && thisSquare->itemType == Ring){
			 cout << "Ring Of Life\n";

		 }else if(thisSquare->itemName == Strength && thisSquare->itemType == Ring){
			 cout << "Ring Of Strength\n";
		 }


	//	cout<< thisSquare->itemName <<"\n";
	//	cout<< thisSquare->itemType <<"\n";


	}else if (thisSquare->itemName == noitem && thisSquare->enemyName != nochar){
	// only and enemy here
		cout<< "*********\n";
		cout<< "**ENEMY**\n";
		cout<< "*********\n";
		if(thisSquare->enemyName == Orc && thisSquare->enemyType == Orc ){
		//	if(){
				cout << "Orc\n";
		//	}
		//
		 }else if(thisSquare->enemyName == Elf && thisSquare->enemyType == Elf){
			 cout << "Elf\n";
		 
		 }else if(thisSquare->enemyName == Dwarf && thisSquare->enemyType == Dwarf){
			 cout << "Dwarf\n";
		 
		 }else if(thisSquare->enemyName == Hobbit && thisSquare->enemyType == Hobbit){
			 cout << "Hobbit\n";
		 
		 }else if(thisSquare->enemyName == Human && thisSquare->enemyType == Human){
			 cout << "Human\n";
		 
		 }
	//	cout<< thisSquare->enemyName <<"\n";
	//	cout<< thisSquare->enemyType <<"\n";
	}else if (thisSquare->itemName != noitem && thisSquare->enemyName != nochar){
		 // there is an enemy and an item here
		cout<< "*********\n";
		cout<< "**ENEMY**\n";
		cout<< "*********\n";

		 //decode the ENUM
		 if(thisSquare->enemyName == Orc && thisSquare->enemyType == Orc){
			 cout << "Orc\n";
		 
		 }else if(thisSquare->enemyName == Elf && thisSquare->enemyType == Elf){
			 cout << "Elf\n";
		 
		 }else if(thisSquare->enemyName == Dwarf && thisSquare->enemyType == Dwarf){
			 cout << "Dwarf\n";
		 
		 }else if(thisSquare->enemyName == Hobbit && thisSquare->enemyType == Hobbit){
			 cout << "Hobbit\n";
		 
		 }else if(thisSquare->enemyName == Human && thisSquare->enemyType == Human){
			 cout << "Orc\n";
		 
		 }

		cout<< "********\n";
		cout<< "**ITEM**\n";
		cout<< "********\n";
		//decode the ENUM
		 if(thisSquare->itemName == Sword && thisSquare->itemType == Weapon){
			 cout << "Weapon Sword\n";
		 
		 }else if(thisSquare->itemName == Dagger && thisSquare->itemType == Weapon){
			 cout << "Weapon Dagger\n";
		 
		 }else if(thisSquare->itemName == Plate && thisSquare->itemType == Armour){
			 cout << "Plate Armour\n";
		 
		 }else if(thisSquare->itemName == Leather && thisSquare->itemType == Armour){
			 cout << "Leather Aromour\n";
		 
		 }else if(thisSquare->itemName == Large && thisSquare->itemType == Shield){
			 cout << "Large Shield\n";

		 }else if(thisSquare->itemName == Small && thisSquare->itemType == Shield){
			 cout << "Small Shield\n";

		 }else if(thisSquare->itemName == Life && thisSquare->itemType == Ring){
			 cout << "Ring Of Life\n";

		 }else if(thisSquare->itemName == Strength && thisSquare->itemType == Ring){
			 cout << "Ring Of Strength\n";
		 }

	}else cout <<"ALERT: look() cSquare is nothing!\n";
}


/////////////////////////////////////////////////////////
//look()  2 hides enemys if dead
// 
// prints ot whats on the square
///////////////////////////////////////////////////////////
void cPlayer::look(cSquareData *thisSquare,  cEnemy *orc,cEnemy *hobbit,cEnemy *human,cEnemy  *elf,cEnemy *dwarf){
// void cPlayer::look(cSquare mysquare){
	
	 cout<< "This Square has: \n";

// test
//	cout<< thisSquare->itemName <<"\n";
//	cout<< thisSquare->itemType <<"\n";
//	cout<< thisSquare->enemyName <<"\n";
//	cout<< thisSquare->enemyType <<"\n";
/////////////


	if(thisSquare->itemName == noitem && thisSquare->enemyName ==nochar ){
		cout<< "RESULT: Nothing Here!\n";
	}else if (thisSquare->itemName != noitem && thisSquare->enemyName == nochar){
	// only an item here
		

		cout<< "********\n";
		cout<< "**ITEM**\n";
		cout<< "********\n";
		if(thisSquare->itemName == Sword && thisSquare->itemType == Weapon){
			 cout << "Weapon Sword\n";
		 
		 }else if(thisSquare->itemName == Dagger && thisSquare->itemType == Weapon){
			 cout << "Weapon Dagger\n";
		 
		 }else if(thisSquare->itemName == Plate && thisSquare->itemType == Armour){
			 cout << "Plate Armour\n";
		 
		 }else if(thisSquare->itemName == Leather && thisSquare->itemType == Armour){
			 cout << "Leather Armour\n";
		 
		 }else if(thisSquare->itemName == Large && thisSquare->itemType == Shield){
			 cout << "Large Shield\n";

		 }else if(thisSquare->itemName == Small && thisSquare->itemType == Shield){
			 cout << "Small Shield\n";

		 }else if(thisSquare->itemName == Life && thisSquare->itemType == Ring){
			 cout << "Ring Of Life\n";

		 }else if(thisSquare->itemName == Strength && thisSquare->itemType == Ring){
			 cout << "Ring Of Strength\n";
		 }


	//	cout<< thisSquare->itemName <<"\n";
	//	cout<< thisSquare->itemType <<"\n";


	}else if (thisSquare->itemName == noitem && thisSquare->enemyName != nochar){
	// only and enemy here
	
		if(thisSquare->enemyName == Orc && thisSquare->enemyType == Orc ){
			if(orc->checkIfAlive()==true){
					cout<< "*********\n";
		cout<< "**ENEMY**\n";
		cout<< "*********\n";
				cout << "Orc\n";
			}
		//
		 }else if(thisSquare->enemyName == Elf && thisSquare->enemyType == Elf){
			
			 if(elf->checkIfAlive()==true){
				 	cout<< "*********\n";
		cout<< "**ENEMY**\n";
		cout<< "*********\n";
				cout << "Elf\n";
			}
		 
		 }else if(thisSquare->enemyName == Dwarf && thisSquare->enemyType == Dwarf){
			 
			 if(dwarf->checkIfAlive()==true){
		cout<< "*********\n";
		cout<< "**ENEMY**\n";
		cout<< "*********\n";
				cout << "Dwarf\n";
			}
		 
		 }else if(thisSquare->enemyName == Hobbit && thisSquare->enemyType == Hobbit){
			if(hobbit->checkIfAlive()==true){
					cout<< "*********\n";
		cout<< "**ENEMY**\n";
		cout<< "*********\n";
				cout << "Hobbit\n";
			}
			 
		 
		 }else if(thisSquare->enemyName == Human && thisSquare->enemyType == Human){
			 
			 if(human->checkIfAlive()==true){
				 	cout<< "*********\n";
		cout<< "**ENEMY**\n";
		cout<< "*********\n";
				cout << "Human\n";
			}
			
		 
		 }
	//	cout<< thisSquare->enemyName <<"\n";
	//	cout<< thisSquare->enemyType <<"\n";
	}else if (thisSquare->itemName != noitem && thisSquare->enemyName != nochar){
		 // there is an enemy and an item here
				if(thisSquare->enemyName == Orc && thisSquare->enemyType == Orc ){
			if(orc->checkIfAlive()==true){
					cout<< "*********\n";
		cout<< "**ENEMY**\n";
		cout<< "*********\n";
				cout << "Orc\n";
			}
		//
		 }else if(thisSquare->enemyName == Elf && thisSquare->enemyType == Elf){
			
			 if(elf->checkIfAlive()==true){
				 	cout<< "*********\n";
		cout<< "**ENEMY**\n";
		cout<< "*********\n";
				cout << "Elf\n";
			}
		 
		 }else if(thisSquare->enemyName == Dwarf && thisSquare->enemyType == Dwarf){
			 
			 if(dwarf->checkIfAlive()==true){
		cout<< "*********\n";
		cout<< "**ENEMY**\n";
		cout<< "*********\n";
				cout << "Dwarf\n";
			}
		 
		 }else if(thisSquare->enemyName == Hobbit && thisSquare->enemyType == Hobbit){
			if(hobbit->checkIfAlive()==true){
					cout<< "*********\n";
		cout<< "**ENEMY**\n";
		cout<< "*********\n";
				cout << "Hobbit\n";
			}
			 
		 
		 }else if(thisSquare->enemyName == Human && thisSquare->enemyType == Human){
			 
			 if(human->checkIfAlive()==true){
				 	cout<< "*********\n";
		cout<< "**ENEMY**\n";
		cout<< "*********\n";
				cout << "Human\n";
			}
			
		 
		 }

		cout<< "********\n";
		cout<< "**ITEM**\n";
		cout<< "********\n";
		//decode the ENUM
		 if(thisSquare->itemName == Sword && thisSquare->itemType == Weapon){
			 cout << "Weapon Sword\n";
		 
		 }else if(thisSquare->itemName == Dagger && thisSquare->itemType == Weapon){
			 cout << "Weapon Dagger\n";
		 
		 }else if(thisSquare->itemName == Plate && thisSquare->itemType == Armour){
			 cout << "Plate Armour\n";
		 
		 }else if(thisSquare->itemName == Leather && thisSquare->itemType == Armour){
			 cout << "Leather Aromour\n";
		 
		 }else if(thisSquare->itemName == Large && thisSquare->itemType == Shield){
			 cout << "Large Shield\n";

		 }else if(thisSquare->itemName == Small && thisSquare->itemType == Shield){
			 cout << "Small Shield\n";

		 }else if(thisSquare->itemName == Life && thisSquare->itemType == Ring){
			 cout << "Ring Of Life\n";

		 }else if(thisSquare->itemName == Strength && thisSquare->itemType == Ring){
			 cout << "Ring Of Strength\n";
		 }

	}else cout <<"ALERT: look() cSquare is nothing!\n";
}
/*************************************************************************************************************************
///////////////////////////////////////////////
// selectAttack()
//
/////////////////////////////////////////////////
char cPlayer::selectAttack(){
	if(checkForEnemy()) {
		//ATTATCK THE ENEMY
	}
	else {
		//NOTHING TO ATTACK
	}
}
*/


///////////////////////////////////////////////
//  attack()
//  sqeuence of events that take place when a
//  player attacks an enemy
//
// need to know what your attacking
///////////////////////////////////////////////
bool cPlayer::attack(cPlayer *player, cCharacter *enemy ,cRandomNumGen *fight){
 char attackResponse = 'y';

 while (attackResponse == 'y' && enemy->checkIfAlive()==true && player->checkIfAlive() == true){

		cout<<"MOVE: Attack!!!!\n";

		//display stats
		cout<<"\n-----------------------------------\n";
		cout<<"PLAYER A="<< player->getAttack() <<" D= "<<player->getDefence() <<" H= "<<player->getHealth()<<"\n";
		cout<<"ENEMY A="<< enemy->getAttack() <<" D= "<<enemy->getDefence() <<" H= "<<enemy->getHealth()<<"\n";
		cout<<"\n-----------------------------------\n";

			// first see is there an enemy present?

		//checkForEnemy()
			// check night or day
			// day_night = checkNightDay();
		//	bool day_night, strike, defend,answer = true;

		// show enemys stats.
			

			// get the characters stats ? not needed as players stats are available to the cPlayer class
		int	pAttack= player->getAttack();
		int	pDefend= player->getDefence();
		int	pAttackChance = player->getAttackChance();
		int	pDefenceChance = player->getDefenceChance();

		// get enemys stats
		int	eAttack= enemy->getAttack();
		int	eDefend= enemy->getDefence();
		int	eAttackChance = enemy->getAttackChance();
		int	eDefenceChance = enemy->getDefenceChance();

		int eHealth = enemy->getHealth();
			

		// try and attack
		//	strike = hitOrMiss(cPlayer.attackChance); // takes in attack chance of player and randomly returns if hit or miss

		// get random number
//		cRandomNumGen fight;
		int fightnum =fight->giveRandNum(100);
		bool strike = hitOrMiss(pAttackChance,fightnum);

		//try and defend
		fightnum =fight->giveRandNum(100);
		bool defend = hitOrMiss(eDefenceChance, fightnum); // takes in defence chance of enemy and randomly returns if he can defend it or not

		cout<<"[My Attack]\n";
		if(strike == true && defend == false){  // i hit he didnt defend = change his health
				cout<<"HE'S Hit!!!!\n";
				enemy->decreaseHealth(enemy,pAttack);
		}

		if(strike == true && defend == true){  // i hit he defend 
				cout<<"HE Defended\n";
			//	enemy->decreaseHealth(player ,pAttack);
		}

		if(strike == false){
			cout<<"YOU MISSED HIM\n";
		}


		///
		//set dead flag if character dies
			if(enemy->getHealth() <=0){
				enemy->die();
				cout<<"The Enemy Is Dead!!\n";

				// add gold to tally
				// enemys defence value in gold
				player->addGold(eDefend);
				cout<<"But i have won"<< eDefend <<" in GOLD\n";
				
				cout<<"I now have "<< player->getGold()<<" in Gold yipee!!!\n";


			}

			if(player->getHealth()<=0){
				player->die();
				cout<<"You Died!!";
			}


		if(enemy->checkIfAlive()!=false && player->getHealth() >=0){
			// after initial attack check if characters are still alive before attaking further



		///
		//// his turn to attck
		cout<<"[Enemy's Attack]\n";
		fightnum =fight->giveRandNum(100);
		strike = hitOrMiss(eAttackChance,fightnum);

		//try and defend
		fightnum =fight->giveRandNum(100);
		 defend = hitOrMiss(pDefenceChance, fightnum); // takes in defence chance of enemy and randomly returns if he can defend it or not

		if(strike == true && defend == false){  // i hit he didnt defend = change his health
				cout<<"OUCH IM HIT!!!!\n";
				player->decreaseHealth(player, eAttack);
		}

		if(strike == true && defend == true){  // he hit i defend 
				cout<<"YOU Defended\n";
			//	enemy->decreaseHealth(player, pAttack);
		}


		if(strike == false){
			cout<<"HE Missed YOU!!!!\n";
		}


		//set dead flag if character dies
			if(enemy->getHealth() <=0){
				enemy->die();
				cout<<"The Enemy Is Dead!!\n";

				// add gold to tally
				// enemys defence value in gold
				player->addGold(eDefend);
				cout<<"But i have won "<< eDefend <<" in GOLD\n";
				
				cout<<"I now have "<< player->getGold()<<" in Gold yipee!!!\n";


			}

			if(player->getHealth()<=0){
				player->die();
				cout<<"You Died!!";
			}


		//display stats
		cout<<"PLAYER A="<< player->getAttack() <<" D= "<<player->getDefence() <<" H= "<<player->getHealth()<<"\n";
		cout<<"ENEMY A="<< enemy->getAttack() <<" D= "<<enemy->getDefence() <<" H= "<<enemy->getHealth()<<"\n";


		if(player->checkIfAlive() != false){
		cout <<"Do you want to attack again??\n";
		cin >> attackResponse;
		}
		

		}
 }//while
 return true;
}

	//	hit();// decrement enemys health by amount (attackStrength - defence strength)
//		cEnemy.decreaseHealth(cCharacter , int cPlayer.getAttack());
//	}else if(strike == true && defend == true){
//		cout<<"HE DEFENDED YOUR ATTACK\n";
//	}
	//}

	//fightBack(); //enemys turn to attack

//	return answer;
//}


 /* */ //*******************************************************************************************************************



//////////////////////////////////////////////////////
// pickCharacter()
//
//////////////////////////////////////////////////////

game_char cPlayer::pickCharacter(){

	
	//***/ pickChar(&player)

	int selection;
	game_char gchar = nochar;

	while (gchar == nochar){
		cout<<"*************************\n";
		cout<<"**Choose your character**\n";
		cout<<"*************************\n";
		cout<<"1. Human\n";
		cout<<"2  Elf\n";
		cout<<"3. Dwarf\n";
		cout<<"4. Hobbit\n";
		cout<<"5. Orc\n";
		cin >> selection;

	switch (selection){
		
		case 1:
			gchar = Human;// give human its battle stats
			break;
		case 2:
			gchar = Elf;// give elf its battle stats
			break;
		case 3:
			gchar =  Dwarf;// give dwarf its battle stats
			break;
		case 4:
			gchar = Hobbit;// give hobbit its battle stats
			break;
		case 5:
			gchar = Orc;// give orc its battle stats
			break;
		default:
			cout<<"\nERROR: incorrect player selected\n";
			gchar = nochar;
			break;
	}//switch
	
	
	}//while
	return gchar;

}



//////////////////////////////////////////////////////
//gameMenu()
//
//
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
// exit()
//
/////////////////////////////////////////////////////
cPlayer::exit(){
	cout<<"OPERATION: Exiting the Game\n";
	cout<<"John Meehan 0327301\n";

	cout<<"CALL THE DESTRUCTORS!!!!\n";

// thanks for playing
//	call deconstructor


}