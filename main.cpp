//#include"header.h"

//#include "cCharacter.h"
#include "cCounter.h"
#include "cEnemy.h"
#include "cPlayer.h"
#include "cSquareData.h"
#include "enum.h"
#include "llist.h"
#include "RandomNum.h"

#include <iostream>
using namespace std;
#include <string>

/////////////////////////////////////////////////////////////////////////////
//main()
// set up player, characters,items, board.
//		  place enemys and items.
//		  set up characters and items stats
//
//		  then play the game
/////////////////////////////////////////////////////////////////////////////
void main(){

	//////////////////////////////////
	//Declare Objects
	//
	//////////////////////////////////

	bool EXIT = false;
	game_char gchar; //ENUM
	game_item gitem;
	game_item_type gitemtype;
	cPlayer player; //PLAYER
	cEnemy orc, elf, hobbit, dwarf,human;		// creates the enemys
	cRandomNumGen randNum, xRand, yRand;
	
	cCounter daycount, fivedaycount;	// the day counter for deciding whenits night and day

	////////////////////////
	//itemList
	////////////////////////
//	data newdata;
	llist itemlist; // create an itemlist
	itemlist.gotoHead();

	///////////////////////////////////////////////
	// assin each of the cItem object their stats
	///////////////////////////////////////////////
	// sample data to fill into the list
	//					ID		TYPE	NAME		W	A	D	H	S		
//	data sword		   = {1, "weapon", "sword"	  ,10, 10, 0,  0,	0 };
//	data dagger 	   = {2, "weapon", "dagger"   ,5,  5,  0,  0,	0 };
//	data plateArmour   = {3, "armour", "plate"	  ,40, -5, 10, 0,	0 };
//	data leatherArmour = {4, "armour", "leather"  ,20, 0,  5,  0,	0 };
//	data largeShield   = {5, "shield", "large"	  ,30, -5, 10, 0,	0 };
//	data smallShield   = {6, "shield", "small"	  ,10, 0,  5,  0,	0 };
//	data ringLife	   = {7, "ring",   "life"	 ,1,  0,  0,  10,  0 };
//	data ringStrength  = {8, "ring",   "strength",1,  0,  0,  -10, 50 };


		// sample data to fill into the list
	//					ID		TYPE	NAME		W	A	D	H	S		
	data sword         = {1, Sword , Weapon   ,10, 10, 0,  0,   0 };
	data dagger        = {2, Dagger, Weapon   ,5,  5,  0,  0,   0 };
	data plateArmour   = {3, Plate, Armour    ,40, 5, 10, 0,   0 };
	data leatherArmour = {4, Leather, Armour  ,20, 0,  5,  0,   0 };
	data largeShield   = {5, Large, Shield    ,30, 5, 10, 0,   0 };
	data smallShield   = {6, Small, Shield    ,10, 0,  5,  0,   0 };
	data ringLife      = {7,   Life , Ring   ,1,  0,  0,  10,  0 };
	data ringStrength  = {8,   Strength, Ring,1,  0,  0,  10, 50 };



	system("cls");				//  Clear screen CLRSCR(); didn't work

	///////////////
	//welcome note
	///////////////
	cout<<"\n\n\n\t\t\t!!!!!!!!!!!!!"
			   "\n\t\t\t!JOHN MEEHAN!"
	       	   "\n\t\t\t!  0327301  !"
		       "\n\t\t\t! GRAD DIP  !\n";	// AUTHOR TAG
			   "\n\t\t\t!!!!!!!!!!!!!\n";

	cout<<"\n\t\tFantasy Game Using ADT's\n";
	cout<<"\n\n\t\tLast UpDated 25/12/04\n\n";
	//cout<<"\n\n\t\tVERSION: 2\n\n";
	//cout<<"\n\n\t\tVERSION: change pointers from . to ->\n\n";
	cout<<"\n\n\t\tVERSION: 5\n\n";

	system("pause");			// SAME AS -> cout<<"\n\nPress any key to continue: "); getche();

	////////////////////////
	//Board Set up
	// created at run time
	////////////////////////
	int i,j;
	int boardRow; 
	int boardCol;

	cout<<"****************\n";
	cout<<"**Board Set Up**\n";
	cout<<"****************\n";
	cout<<"To ensure all characters get a place on the board";
	cout<<"use \n";
	cout<< "Enter num ROWS:\n";
	cin >> boardRow; 

	cout <<"Enter Num COLS:\n";
	cin >> boardCol;
	
//	cSquareData gameBoard[5][5]; //create a board of[][] WORKS!!!!!

  // The 2D array is a pointer to a pointer to an int. 
  cSquareData ** gameBoard ;

  //int  i, j ; //perviously declared

  // Allocate an array of pointers to int and make gameBoard a
  //  pointer to the base element of the array. 

  gameBoard = new cSquareData * [boardCol] ; 

     // For each row i of gameBoard (gameBoard[i]), allocate an array of
     //  int's and make gameBoard[i] a pointer to the base element of
     //  the array.
  for (i=0; i<boardCol; i++){
    gameBoard[i] = new cSquareData[boardRow] ; 
  }



//-------------------------------------------------player------------------------------------------
	//////////////////////////
	//Which Character am i?
	// player setup
	//////////////////////////
  int initLoc = 0;
  // pick a character menu
  player.statsStore(player.pickCharacter());		// get that chars info
  player.setCharRow(initLoc);  // set its initial locatcion
  player.setCharCol(initLoc);
  player.bringToLife();

 //-----------------------------------------------------------------------------------


		//possible boardfunction
		//***/fillArray(boardRow,boardCol,&gameBoard[][])
	//////////////////////////
	// fill array
	// place item - can be multiple of same type on board
	//////////////////////////
	for(i=0;i<boardRow; i++) {
		for (j=0;j<boardCol; j++){

/// TEST
//cout << "[" << i << "," << j << "]\n";  // prints out the current location being looked as

			// fills the board randomly

			// enemys not placed yet so set all to NULL
			// will be changed when being place.
				gameBoard[i][j].enemyName = nochar;
				gameBoard[i][j].enemyType = nochar;
			//random item on this square
			//random number from 0-15
			int max =15;
			int rNum = randNum.giveRandNum(max);
//cout << "\n0-15\t" << rNum << "\n";
			//case 1,2,3,...,8 is that item
			switch(rNum){
			case 1:
				// set the squares item contents to sword
				gitem =Sword;
				gitemtype =Weapon;
				gameBoard[i][j].itemName = gitem;
				gameBoard[i][j].itemType = gitemtype;
				break;
			case 2:
				// set the squares item contents to blank
				gitem =Dagger;
				gitemtype =Weapon;
				gameBoard[i][j].itemName = gitem;
				gameBoard[i][j].itemType = gitemtype;
				break;
			case 3:
				// set the squares item contents to blank
				gitem =Plate;
				gitemtype =Armour;

				gameBoard[i][j].itemName = gitem;
				gameBoard[i][j].itemType = gitemtype;
				break;
			case 4:
				// set the squares item contents to blank
				gitem =Leather;
				gitemtype =Armour;
				
				gameBoard[i][j].itemName = gitem;
				gameBoard[i][j].itemType = gitemtype;
				break;
			case 5:
				// set the squares item contents to blank
				gitem= Large;
				gitemtype = Shield;
				gameBoard[i][j].itemName = gitem;
				gameBoard[i][j].itemType = gitemtype;
				break;
			case 6:
				// set the squares item contents to blank
				gitem=Small;
				gitemtype = Shield;
				gameBoard[i][j].itemName = gitem;
				gameBoard[i][j].itemType = gitemtype;
				break;
			case 7:
				// set the squares item contents to blank
				gitem= Life;
				gitemtype= Ring;
				gameBoard[i][j].itemName = gitem;
				gameBoard[i][j].itemType = gitemtype;
				break;
			case 8:
				// set the squares item contents to blank
				gitem= Strength;
				gitemtype = Ring;
				gameBoard[i][j].itemName = gitem;
				gameBoard[i][j].itemType = gitemtype;
				break;

  
			default:
				// set the squares item contents to blank
				gameBoard[i][j].itemName = noitem;
				gameBoard[i][j].itemType = noitemtype;
				break;
			}//switch
			// if greater than 8 set gameBoard[][].itemName = noitem;  // ie a blank square
	
		}//for
	}//for

	//possible boardfunction
//	 orc.assignEnemys(&orc,&elf,&dwarf,&hobbit,&human,&gameBoard[boardRow][boardCol]);
	//////////////////////////////
	// assign enemys
	// one of each on the board
	// and set there locations
	//////////////////////////////
	// assign each of the cEnemy cCharacters their stats

	int itsRow;
	int itsCol;
	//////////////
	//Orc
	//////////////
	orc.statsStore(gchar = Orc);// give orc its battle stats
	//random x and y
	itsRow = xRand.giveRandNum(boardRow-1);
	itsCol = yRand.giveRandNum(boardCol-1);
	cout << "Row:\t" << itsRow << "\tCol:\t" << itsCol<< "\n";	//**************test
	//set its location
	orc.setCharRow(itsRow);
	orc.setCharCol(itsCol);
	orc.bringToLife();

	// tellits location it has one
	//which goes to the gameBoard[x][y] and sets the character atributes of gameBoard[][].enemyName etc......
	gameBoard[itsRow][itsCol].enemyName = Orc;
	gameBoard[itsRow][itsCol].enemyType = Orc;


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

	//-------------------------------------------------------END SETUP OF CHARACTERS AND ITEMS-------------------------------------------

	////////////////////////
	////////////////////////
	/// play the game	///
	////////////////////////
	////////////////////////
system("cls");
	//***//Possible playerfuction// char hud(&daycount, &player ,&itemlist)
	cout<<"OPERATION: Play the Game\n";
	// character selection allready made
int nowRow;
int nowCol;
data newdata;
bool returnResult,dayNight;
//data tempdata;
bool hitMiss;
cRandomNumGen fight;

dayNight = true;// its day time to start

	//gameBoard[boardRow][boardCol].enemyName
char input;  //players menu selection

//while(input != 'x' || player.getGold()<100 || player.getHealth()!=0 ){ 
while(EXIT !=true && player.checkIfAlive() != false){ 
	//play while while input not == x;
	//OR Gold not greater than 100
	//OR while players health not equal to 0


	////////////////////////////////
	// day and night change
	//
	/////////////////////////////////
	daycount.increment();
	fivedaycount.increment();
	if(fivedaycount.getCount()>=5){
		// change 
		if(dayNight == false){
		dayNight=true; //day
		}else if (dayNight == true){
			dayNight= false;
		}

		fivedaycount.reset();

	}else{
	//	dayNight= false;

		// goes over 5 reset
	//	fivedaycount.reset();
	}


	///////////////////////////////////////
	//look at board
	////////////////////////////////////////
	player.look(&gameBoard[player.getCharRow()][player.getCharCol()],&orc, &hobbit, &human, &elf, &dwarf); //look at the board square
	cout<<"DAY: "<< daycount.getCount() <<"\n";
	if(dayNight==true){
		cout<<"Daytime\n";
	}else cout<<"Nighttime\n";


	///////////////////////////////////
	//print location
	///////////////////////////////////
	cout<< "My Location is: ["<<player.getCharRow() <<"]["<< player.getCharCol() << "]\n";

		
	// Move Menu
	char mdir;

	/// player stats
	cout<<"------------------MY-STATS----------------------\n";
	cout<<" A= "<< player.getAttack() <<" D= "<<player.getDefence() <<" H= "<<player.getHealth() <<" S= "<<player.getStrength() <<" Gold= "<<player.getGold() <<"/100\n";


	cout<<"--------------------MOVE------------------------\n";
	cout<<"[N]north ";
	cout<<"[S]south ";
	cout<<"[E]east ";
	cout<<"[W]west\n";
	cout<<"------------------------------------------------\n";
	cout<<"[A]ttack ";
	cout<<"[P]ick ";
	cout<<"[D]rop ";
	cout<<"[L]ook ";
	cout<<"[I]nventry ";
	cout<<"e[X]it ";
	cin >> input;

	system("cls");

	switch (input){
		
	case 'n':
	case 'N':
		mdir = 'n'; 
		break;
	case 's':
	case 'S':
		mdir = 's'; 
		break;
	case 'e':
	case 'E':
		mdir = 'e'; 
		break;
	case 'w':
	case 'W':
		mdir = 'w'; 
		break;
 
	case 'a':
	case 'A':
		mdir = NULL; 

		

			///cEnemy orc, elf, hobbit, dwarf,human;		// creates the enemys
		//getEnemy(this square)
		if(gameBoard[player.getCharRow()][player.getCharCol()].enemyName == Orc){
			if(orc.checkIfAlive()){
				hitMiss = player.attack(&player,&orc,&fight);
			}
			}else if(gameBoard[player.getCharRow()][player.getCharCol()].enemyName == Elf){	
			hitMiss = player.attack(&player,&elf,&fight);
			if(elf.checkIfAlive()){
				hitMiss = player.attack(&player,&orc,&fight);
			}
		
			}else if(gameBoard[player.getCharRow()][player.getCharCol()].enemyName == Dwarf){
				hitMiss = player.attack(&player,&dwarf,&fight);
				if(dwarf.checkIfAlive()){
				hitMiss = player.attack(&player,&orc,&fight);
			}
			
			}else if(gameBoard[player.getCharRow()][player.getCharCol()].enemyName == Hobbit){
				hitMiss = player.attack(&player,&hobbit,&fight);
				if(hobbit.checkIfAlive()){
				hitMiss = player.attack(&player,&orc,&fight);
			}
					
			}else if(gameBoard[player.getCharRow()][player.getCharCol()].enemyName == Human){
				hitMiss = player.attack(&player,&human,&fight);
				if(human.checkIfAlive()){
				hitMiss = player.attack(&player,&orc,&fight);
			}
				
		}else break;

		
		//	see am i still alive
		if (player.checkIfAlive()==false){ 
			cout<<"*******************\n";
			cout<<"*YOU DIED IN SHAME*\n";
			cout<<"*******************\n";
			
			cout<<"With only "<< player.getGold() <<" in GOLD\n";

		}else {
			cout<<"I love a good fight\n";

		}

		break;
	case 'p':
	case 'P':
		mdir = NULL; 


		////////////////////////////
		// insert data to the list
		////////////////////////////
		nowRow = player.getCharRow();
		nowCol = player.getCharCol();

		itemlist.gotoHead();

		if(itemlist.pickUp(&itemlist,&gameBoard[nowRow][nowCol])){

				// increase players stats as we are adding 
				//////////////////////////////////////////////
				if(gameBoard[player.getCharRow()][player.getCharCol()].itemName == Sword){				 
					player.increaseAttack(&player, sword.attack);
				}else if(gameBoard[player.getCharRow()][player.getCharCol()].itemName == Dagger){					 
					player.increaseAttack(&player, dagger.attack);
					
				}else if(gameBoard[player.getCharRow()][player.getCharCol()].itemName == Plate){				 
					player.increaseAttack(&player,plateArmour.attack);
					player.increaseDefence(&player,plateArmour.defence);		
				}else if(gameBoard[player.getCharRow()][player.getCharCol()].itemName == Leather){
					player.increaseDefence(&player,leatherArmour.defence);	
				}else if(gameBoard[player.getCharRow()][player.getCharCol()].itemName == Large){	 
					player.decreaseAttack(&player,largeShield.attack);
					player.increaseDefence(&player,largeShield.defence);
				}else if(gameBoard[player.getCharRow()][player.getCharCol()].itemName == Small){
					player.increaseDefence(&player,smallShield.defence);
				}else if(gameBoard[player.getCharRow()][player.getCharCol()].itemName == Life){
					player.increaseHealth(&player,ringLife.health);			
				}else if(gameBoard[player.getCharRow()][player.getCharCol()].itemName == Strength){
					player.decreaseHealth(&player,ringStrength.health);
					player.increaseStrength(&player,ringStrength.strength);
				}

			//remove the item from the board
		gameBoard[nowRow][nowCol].itemName = noitem;
		gameBoard[nowRow][nowCol].itemType = noitemtype;
		}


		//bool pickResult = player.pickUp(&itemlist);
		// call pickUp()
		// *player->pickUp(&itemlist, )

		break;
	case 'd':
	case 'D':
		mdir = NULL; 

		/////////////////////////////////////
		//drop an item off of the list
		//and change stats accordingly
		/////////////////////////////////////

		
	////////////
	// delete
	///////////
		nowRow = player.getCharRow();
		nowCol = player.getCharCol();
		itemlist.gotoHead(); // this is the bastard

	//	itemlist.drop(&itemlist,&gameBoard[nowRow][nowCol]);

		itemlist.printList();

		itemlist.gotoHead(); // this is the bastard


	
	cout<<"\n\nOPERATION:  Delete Item By ID\n";
			cout<<"Item ID: ";
			cin>>newdata.id;

			//bool returnResult;
			//returnResult=itemlist.search(newdata,3);
			if(itemlist.search(newdata,3)){

				//copy back to square
				itemlist.gotoSuccessor();
				gameBoard[player.getCharRow()][player.getCharCol()].itemName = itemlist.accessData().name;
				gameBoard[player.getCharRow()][player.getCharCol()].itemType = itemlist.accessData().type;

				cout<<gameBoard[player.getCharRow()][player.getCharCol()].itemName;
				cout<<gameBoard[player.getCharRow()][player.getCharCol()].itemType ;


				///////////////////////
				// change player stats
				////////////////////////
				/*
		// sample data to fill into the list
	//				ID		TYPE	NAME		W	A	D	H	S		
	data sword         = {1, Sword , Weapon   ,10, 10, 0,  0,   0 };
	data dagger        = {2, Dagger, Weapon   ,5,  5,  0,  0,   0 };
	data plateArmour   = {3, Plate, Armour    ,40, -5, 10, 0,   0 };
	data leatherArmour = {4, Leather, Armour  ,20, 0,  5,  0,   0 };
	data largeShield   = {5, Large, Shield    ,30, -5, 10, 0,   0 };
	data smallShield   = {6, Small, Shield    ,10, 0,  5,  0,   0 };
	data ringLife      = {7,   Life , Ring   ,1,  0,  0,  10,  0 };
	data ringStrength  = {8,   Strength, Ring,1,  0,  0,  -10, 50 };

  */
				// decrease players stats as we are removing
				//////////////////////////////////////////////
				if(gameBoard[player.getCharRow()][player.getCharCol()].itemName == Sword){				 
					player.decreaseAttack(&player, sword.attack);
					player.decreaseDefence(&player,sword.defence);
				}else if(gameBoard[player.getCharRow()][player.getCharCol()].itemName == Dagger){					 
					player.decreaseAttack(&player, dagger.attack);
					
				}else if(gameBoard[player.getCharRow()][player.getCharCol()].itemName == Plate){				 
				//	player.increaseAttack(plateArmour.attack);
					player.decreaseDefence(&player,plateArmour.defence);		
				}else if(gameBoard[player.getCharRow()][player.getCharCol()].itemName == Leather){
					player.decreaseDefence(&player,leatherArmour.defence);	
				}else if(gameBoard[player.getCharRow()][player.getCharCol()].itemName == Large){	 
				//	player.increaseAttack(largeShield.attack);
					player.decreaseDefence(&player,largeShield.defence);
				}else if(gameBoard[player.getCharRow()][player.getCharCol()].itemName == Small){
					player.decreaseDefence(&player,smallShield.defence);
				}else if(gameBoard[player.getCharRow()][player.getCharCol()].itemName == Life){
					player.decreaseHealth(&player,ringLife.health);			
				}else if(gameBoard[player.getCharRow()][player.getCharCol()].itemName == Strength){
					player.decreaseHealth(&player,ringStrength.health);
					player.decreaseStrength(&player,ringStrength.strength);
				}


		//		player.decreaseAttack(tempdata.attack);
		//		player.decreaseDefence(tempdata.defence);
		//		player.decreaseHealth(tempdata.health);
		//		player.decreaseStrength(tempdata.strength);
			


			}else cout<<"\n\nERROR:  Not Found\n";

			returnResult = false;
			itemlist.gotoHead(); // this is the bastard
			returnResult=itemlist.search(newdata,3);
			if(returnResult == true){
				itemlist.deleteNext();
				cout<<"\n\nREPORT:  ITEM REMOVED\n";
			}else cout<<"\n\nERROR:  Not Found\n";

			system("pause");		//Wait for key press
			itemlist.gotoHead();
	
			itemlist.printList();
			

		// copy the item name and type from the list node 
//		gameBoard[player.getCharRow()][player.getCharCol()].itemName = noitem;
//		gameBoard[player.getCharRow()][player.getCharCol()].itemType = noitemtype;

		// then delete the node from the list

		//call drop()
		 //*player->drop()
		break;
	case 'l':
	case 'L':
		mdir = NULL; 
		//will ahve to change to *player in going into a function
		player.look(&gameBoard[player.getCharRow()][player.getCharCol()]);

		break;
	case 'i':
	case 'I':
		mdir = NULL; 
		itemlist.printList();
		// print out the linked list
		//player.inventory(&itemlist)
		// *player.inventory(&itemlist)
		break;


	case 'x':
	case 'X':
		mdir = NULL; 
		// exit the game
	//	player.addGold(100); // to allow to quir
	//	player.decreaseHealth(&player,200);

		//player.
		EXIT = true;

		player.exit();

		orc.~cEnemy();
		cout<<"Deconstruction cEnemy\n";
		elf.~cEnemy();
		cout<<"Deconstruction cEnemy\n";
		dwarf.~cEnemy();
		cout<<"Deconstruction cEnemy\n";
		hobbit.~cEnemy();
		cout<<"Deconstruction cEnemy\n";
		human.~cEnemy();
		cout<<"Deconstruction cEnemy\n";
		cout<<"Deconstruction llist\n";
		player.~cPlayer();
		cout<<"Deconstruction cPlayer\n";

		// Deallocate the array memory
		for (i=0; i<boardCol; i++) delete [ ] gameBoard[i] ;
		cout<<"Deconstruction Dyanamic Array Board\n";
		
		break;

	default:
		mdir = NULL; 
		cout<<"\nERROR: invalid key press\n";
		break;
	}//SWITCH
//	player.look(&gameBoard[player.getCharRow()][player.getCharCol()]);

if(mdir != NULL){ // if direction is a valid one
	player.move(mdir,&boardRow,&boardCol,&orc,&hobbit,&human,&elf,&dwarf);

	} //IF
}// WHILE






// Deallocate the array memory
//  for (i=0; i<boardCol; i++) delete [ ] gameBoard[i] ;
}//main end