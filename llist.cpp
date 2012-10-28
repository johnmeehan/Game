// llist.cpp: implementation of the llist class.
//
// simple implementation of single linked list
// 
//////////////////////////////////////////////////////////////////////
//#include "cCharacter.h"
//#include "cCounter.h"
//#include "cEnemy.h"
//#include "cPlayer.h"
#include "cSquareData.h"
#include "enum.h"
#include "llist.h"
//#include "RandomNum.h"


//#include"header.h"
#include <string>

using namespace std;
#include <iostream>


//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
//							class llist
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
// list()
// default constructor of linked list, creates an empty linked list
// consisting of head and tail, head points to tail
// 
// parameter:	none
//////////////////////////////////////////////////////////////////////
llist::llist()
{
	data dummy={-1,noitem,noitemtype,0,0,0,0,0};
//	data dummy={-1,"",""};
	head = new llnode(dummy,NULL);
	if (head == NULL) exit(-1);
	tail = new llnode(dummy,NULL);
	if (tail == NULL) exit(-1);
	// adjust links
	head->setSuccessor(tail);
	tail->setSuccessor(NULL);
	current = head;
}

//////////////////////////////////////////////////////////////////////
// llist(orig)
// copy constructor
// as class makes use of dynamic memory allocation, explicit copy 
// constructor is required. creates an exact copy of orig.
//
// parameter:	llist &orig - reference to original linked list
//////////////////////////////////////////////////////////////////////
llist::llist(llist &orig)
{
	data dummy={-1,noitem,noitemtype,0,0,0,0,0};
//	data dummy={-1,"",""};
	// safe old current node
	llnode *oldcurrent = orig.current;

	// allocate nodes for new list
	head = new llnode(dummy, NULL);
	if (head == NULL) exit(-1);
	tail = new llnode(dummy, NULL);
	if (tail == NULL) exit(-1);

	// adjust links
	head->setSuccessor(tail);
	tail->setSuccessor(NULL);
	current = head;

	// copy contents of linked list
	orig.gotoHead();
	while (orig.gotoSuccessor() == ok) {
		if (orig.current == orig.tail) break;
		insertAfter(orig.accessData());
		gotoSuccessor();
	}

	// find current node in original and copied list
	orig.gotoHead();
	gotoHead();
	while (orig.current != oldcurrent) {
		orig.gotoSuccessor();
		gotoSuccessor();
	}
}

//////////////////////////////////////////////////////////////////////
// ~llist()
// destructor
// as class uses dynamic memory, explicit destructor is required
//////////////////////////////////////////////////////////////////////
llist::~llist()
{
	gotoHead();
	while (deleteNext() == ok);
	delete head;
	delete tail;
}

//////////////////////////////////////////////////////////////////////
// member function definition
//////////////////////////////////////////////////////////////////////
// insertAfter(newdata)
// creates a new node, associates newdata with it and inserts the
// new node after the current node
//
// parameter:	data &newdata - reference to data for node
// return:		ok - node has been inserted
//				noMemory - no memory was available for construction of
//						   node
//				illegalNode - cannot insert node after tail
//////////////////////////////////////////////////////////////////////
//llError llist::insertAfter(data &newdata)
llError llist::insertAfter(data newdata)
{
	llnode *newnode;
	llError returnvalue=ok;
	if (current == tail) returnvalue = illegalNode;
	else {
		newnode = new llnode(newdata,current->getSuccessor());
		if (newnode == NULL) returnvalue = noMemory;
		else {
			newnode->setSuccessor(current->getSuccessor());
			current->setSuccessor(newnode);
		}
	}
	return returnvalue;		
}

//////////////////////////////////////////////////////////////////////
// gotoSuccessor()
// sets current node to successor of current node, thus traversing
// eventually the entire linked list
//
// parameter:	none
// return:		ok - goto successfull
//				illegalNode - tail has been already reached
//////////////////////////////////////////////////////////////////////
llError llist::gotoSuccessor()
{
	llError returnvalue=ok;
	if (current == tail) returnvalue = illegalNode;
	else current = current->getSuccessor();
	return returnvalue;
}

//////////////////////////////////////////////////////////////////////
// deleteNext()
// removes the successor of current from the list
//
// parameter: none
// return:	  ok - removal successful
//			  illegalNode - cannot remove tail from list
//////////////////////////////////////////////////////////////////////
llError llist::deleteNext()
{
	llnode *delnode;
	llError returnvalue=ok;
	if ( (current==tail) || (current->getSuccessor()== tail) ) returnvalue = illegalNode;
	else {
		delnode = current->getSuccessor();
		current->setSuccessor(delnode->getSuccessor());
		delete delnode;
	}
	return returnvalue;
}

//////////////////////////////////////////////////////////////////////
// accessData()
// accesses the data of the current node, allows both reading and
// writing access.
//
// parameter: none
// return:	  reference to data associated with current node
//////////////////////////////////////////////////////////////////////
data &llist::accessData()
{
	return current->getData();
}

/////////////////////////////////////////////////
// nodeCount()
// counts the no of items on thelist
/////////////////////////////////////////////////
int llist::nodeCount(){
	int count = 0;
	gotoHead();
	current=current->getSuccessor();
	while(current != tail){
		count++;
		current = current->getSuccessor();
	}
	return count;
}


/////////////////////////////////////////////////
//	printList()
//	traverse thelinked list printing the nodes
//
/////////////////////////////////////////////////
llist::printList(){
	int i = nodeCount();  //get no of node on list for printing in right order
	//cout<<"Node Count = "<<i<<"\n";
	gotoHead();			// now back up to the top
	current= current->getSuccessor();
	cout<<"************\n";
	cout<<"*Items List*\n";
	cout<<"************\n";

	//while(current->getSuccessor() !=tail){
	while(current !=tail && i != 0){
		cout<<i<<" ";
		data temp = accessData();

		cout<<"\nID= " << temp.id ;

		//*** need to decode the ENUMS
		
		if(temp.name == Sword && temp.type == Weapon){
			 cout << " Weapon Sword\n";
		 
		 }else if(temp.name == Dagger && temp.type == Weapon){
			 cout << " Weapon Dagger\n";
		 
		 }else if(temp.name == Plate && temp.type == Armour){
			 cout << " Plate Armour\n";
		 
		 }else if(temp.name == Leather && temp.type == Armour){
			 cout << " Leather Armour\n";
		 
		 }else if(temp.name == Large && temp.type == Shield){
			 cout << " Large Shield\n";

		 }else if(temp.name == Small && temp.type == Shield){
			 cout << " Small Shield\n";

		 }else if(temp.name == Life && temp.type == Ring){
			 cout << " Ring Of Life\n";

		 }else if(temp.name == Strength && temp.type == Ring){
			 cout << " Ring Of Strength\n";
		 }
		
	//	cout<<"\nID= " << temp.id <<" NAME= "<<temp.name<<" TYPE= "<<temp.type;
		//	current->getData(data*);
		current= current->getSuccessor();
		i--;
	}
}





//////////////////////////////////////////
//  search()
//  search the linked list for a variable
//////////////////////////////////////////
bool llist::search(data newdata,  int searchType){
    // search code that does all the searches
    // in this program, the type is selected by
    // 'searchtype'
    // searchtype == 1 - >  by account no
    // searchtype == 2 - > by name
	// searchtype == 3 - > by ID
    // acc_no, newdata, searchtype
    
    bool returnResult = false;

//  op_result returnResult = ok;                        // everything is fine
    if ( searchType == 1){
        //SEARCHING BY NAME
        while( current->getSuccessor() != tail){
            
            //while this nodes next node is not the tail
            if(current->getSuccessor()->getData().name==newdata.name){
        //      if((strcmp(current->get_ptr_nextNode()->getAccInfo()->firstName, newdata.firstName)==0)&&(strcmp(current->get_ptr_nextNode()->getAccInfo()->lastName, newdata.lastName)==0)){
        
                returnResult = true;
                return returnResult;
            }
            current = current->getSuccessor();
        }
            
    
    }else if(searchType == 2){
        // SEARCHING BY TYPE
        while( current->getSuccessor() != tail){
            if(current->getSuccessor()->getData().type==newdata.type){
                returnResult = true;
                return returnResult;
            }   
            current = current->getSuccessor();      
        }
    
    }else if(searchType == 3){
        // SEARCHING BY ID
        while( current->getSuccessor() != tail){
            if(current->getSuccessor()->getData().id==newdata.id){
                returnResult = true;
                return returnResult;
            }   
            current = current->getSuccessor();      
        }
  //  return returnResult;

	}// search()  END
	return returnResult;
}


 
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
// class llnode
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
// llnode(newd, nextNode)
// default constructor
// constructs a new node, associates newd as data and sets its
// successor to nextNode
//
// parameter:	data newd - data for the new node
//				llnode *nextNode - pointer to successor of new node
//////////////////////////////////////////////////////////////////////
llist::llnode::llnode(data newd, llnode *nextNode) {
//	nextnode = NULL://added
	d = newd;
	successor = nextNode;
}

llist::llnode::llnode(data newd) {
	//nextnode = NULL://added
	d = newd;
	successor = NULL;
}

//////////////////////////////////////////////////////////////////////
// getData()
// returns the data associated with the node, allowing both reading
// and writing access.
//
// parameter:	none
// return:		reference to data of node
//////////////////////////////////////////////////////////////////////
data &llist::llnode::getData() {
	return d;
}

//////////////////////////////////////////////////////////////////////
// getSuccessor()
// returns the successor node of the node
//
// parameter:	none
// return:		pointer to successor of node
//////////////////////////////////////////////////////////////////////
llist::llnode *llist::llnode::getSuccessor() {
	return successor;
}

//////////////////////////////////////////////////////////////////////
// setSuccessor(nextNode)
// sets the successor of the node to nextNode
// 
// parameter:	llnode *nextNode - pointer to new successor of node
// return:		void
//////////////////////////////////////////////////////////////////////
void llist::llnode::setSuccessor(llnode *nextNode){
	successor = nextNode;
}


//////////////////////////////////////////////////////////////////////
// getCurrent()
// returns the current node of the node
//
// parameter:	none
// return:		pointer to current of node
//////////////////////////////////////////////////////////////////////
//llnode *llist: getCurrent() {
//	return current;
//}
//***************************************************************************************************************player uses
//////////////////////////////////////////////////////
// pickUp()
// takes an item whos type is not allready on the list
// and puts it onto my items list
//
// Uses LINKED LIST [Head]-[Current]-[End]
///////////////////////////////////////////////////////
bool llist::pickUp(llist *itemlist, cSquareData *thisSquare){

	bool result = false;
	//takes in a reference to an llist
	//takes in a reference to data
	/////////////////////////////////////////////////
	//  player picks up an item from the board
	//  
	//  This should get the name & type of the item
	//  and put it in to the linked list (item list)
	/////////////////////////////////////////////////


	// sample data to fill into the list
	//					ID		TYPE	NAME		W	A	D	H	S		
	data sword         = {1, Sword , Weapon   ,10, 10, 0,  0,   0 };
	data dagger        = {2, Dagger, Weapon   ,5,  5,  0,  0,   0 };
	data plateArmour   = {3, Plate, Armour    ,40, -5, 10, 0,   0 };
	data leatherArmour = {4, Leather, Armour  ,20, 0,  5,  0,   0 };
	data largeShield   = {5, Large, Shield    ,30, -5, 10, 0,   0 };
	data smallShield   = {6, Small, Shield    ,10, 0,  5,  0,   0 };
	data ringLife      = {7,   Life , Ring   ,1,  0,  0,  10,  0 };
	data ringStrength  = {8,   Strength, Ring,1,  0,  0,  -10, 50 };


	data newdata;

	// check if square has an item if true
	bool exists = checkForItem(thisSquare);
	if(exists ==true){

	
		//get the item name and type
		newdata.type = thisSquare->itemType;
		newdata.name = thisSquare->itemName;

		bool exists = false;


		if(newdata.type!=Ring){
//			if(newdata.type==Ring){

	//	if(strcmp(newdata.type,"ring")!=0){
			//this will allow for multiple rings


				//search linked list with item type if matches to see if i allready have it
				exists = itemlist->search(newdata, 2);
		}
		if(exists == false){

					
					if(newdata.name==Dagger){itemlist->insertAfter(dagger);result = true;}
					if(newdata.name==Plate){itemlist->insertAfter(plateArmour);result = true;}
					if(newdata.name==Leather){itemlist->insertAfter(leatherArmour);result = true;}
					if(newdata.name==Large){itemlist->insertAfter(largeShield);result = true;}
					if(newdata.name==Small){itemlist->insertAfter(smallShield);result = true;}
					if(newdata.name==Life){itemlist->insertAfter(ringLife);result = true;}
					if(newdata.name==Strength){itemlist->insertAfter(ringStrength);result = true;}
					if(newdata.name==Sword){itemlist->insertAfter(sword);result = true;}
					
				//	if(strcmp(newdata.name,"sword")!=0){itemlist->insertAfter(sword);result = true;}
				//	if(strcmp(newdata.name,"dagger")!=0){itemlist->insertAfter(dagger);result = true;}
				//	if(strcmp(newdata.name,"plate")!=0){itemlist->insertAfter(plateArmour);result = true;}
				//	if(strcmp(newdata.name,"leather")!=0){itemlist->insertAfter(leatherArmour);result = true;}
				//	if(strcmp(newdata.name,"large")!=0){itemlist->insertAfter(largeShield);result = true;}
				//	if(strcmp(newdata.name,"small")!=0){itemlist->insertAfter(smallShield);result = true;}
				//	if(strcmp(newdata.name,"life")!=0){itemlist->insertAfter(ringLife);result = true;}
				//	if(strcmp(newdata.name,"strength")!=0){itemlist->insertAfter(ringStrength);result = true;}
					
		}else {
			// this type is allready on  the  list
			cout<<"RESULT: You have one of this type allready!!\n";
			result = false;
			
		}
	}else cout<<"ALERT: There is nothingto pick up!!!\n";



	return result;
}


////////////////////////////////////////////////////
// inventory()
//
// Uses LINKED LIST [Head]-[Current]-[End]
////////////////////////////////////////////////////
void llist::inventory(llist itemlist){
	cout<<"OPERATION: Print List\n";
// print out linked list printList()
	
	
	itemlist.printList();


	// printout my stats
}

///////////////////////////////////////////////
// checkForItem()
//
/////////////////////////////////////////////////
bool llist::checkForItem(cSquareData *thisSquare){

	bool squareResult = false;
	if (thisSquare->itemName != noitem){
		squareResult = true;
	
	}
	return squareResult;
}

///////////////////////////////////////////////
// checkForEnemy()
//
/////////////////////////////////////////////////
bool llist::checkForEnemy(cSquareData *thisSquare){

	bool squareResult = false;
	if (thisSquare->enemyName != nochar){
		squareResult = true;
	
	}
	return squareResult;
}



