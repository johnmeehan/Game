#ifndef INC_LLIST_H
#define INC_LLIST_H


//#ifndef INC_ENUM_H
//#define INC_ENUM_H

//#ifndef INC_CSQUAREDATA_H
//#define INC_CSQUAREDATA_H

//need to see
#include "enum.h"
#include "cSquareData.h"

//================================================llist.h
//////////////////////////////////////////////////////////////////////
// llist.h: interface for the llist class.
//
//////////////////////////////////////////////////////////////////////

// define error-conditions
typedef enum {ok,noMemory,illegalNode} llError;

////////////////////////////////////////////////////////////////////
// class data
// define type for required data - usually a fully defined class
// will be used. this example is a plain convenience dummy-class
////////////////////////////////////////////////////////////////////
class data{
public:
	int id;
	
	game_item name;
	game_item_type type;
//	char type[20];
//	char name[20];
	int weight;
	int attack;
	int defence;
	int health;
	int strength;

};

////////////////////////////////////////////////////
// class llist
// define linked list class
////////////////////////////////////////////////////
class llist{
public:
	data & accessData();
	inline void gotoHead() {current = head;}
	llError gotoSuccessor();
	llError deleteNext();

//	llError insertAfter(data &newdata);

	llError insertAfter(data newdata);
	llist(llist &orig);
	llist();
	virtual ~llist();
	printList();
	int nodeCount();
	bool search(data, int );

	bool pickUp(llist *,cSquareData *);			// add an item to the linked list from cSsquare
//	bool drop(llist *, cSquareData *);			// drop an item off of the list and on to the empty square
	void inventory(llist);						// Print out the list of items onboard


	bool checkForItem(cSquareData *);
	bool checkForEnemy(cSquareData *);

//	llnode getCurrent(){return current;}//

private:
	/////////////////////////////////////////////
	// class llnode
	// define single node of linked list
	/////////////////////////////////////////////
	class llnode{
	public:
	//	llnode(data newd, llnode *nextNode=NULL);
		llnode(data newd);//dummy

		llnode(data newd, llnode *nextNode);


		


		data &getData();
		llnode *getSuccessor();
		void setSuccessor(llnode *nextNode);
	private:
		data d;
		llnode *successor;
	};

	llnode *head;
	llnode *tail;
	llnode *current;
};




//#endif
#endif