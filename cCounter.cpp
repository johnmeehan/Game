//#include "cCharacter.h"
#include "cCounter.h"
//#include "cEnemy.h"
//#include "cPlayer.h"
//#include "cSquareData.h"
//#include "enum.h"
//#include "llist.h"
//#include "RandomNum.h"


#include <iostream>
using namespace std;
////////////////////////////
//implementation of Counter class
//
////////////////////////////



//////////////////////////////
//Reset Counter
//	bool reset()
//returns true when compleated
//////////////////////////////

void cCounter::reset()
{
	count = 0;
//	return true;
}

///////////////////////////////
//increment()
//increments the value of count by one
//returns true if ok.
///////////////////////////////
void cCounter::increment()
{
	count++;
//	return true;
}


////////////////////////////////
//getCount()
// returns int count of the counter
//
////////////////////////////////
int cCounter::getCount(){
	return count;
}

////////////////////////////////
//setMax(int)
//sets the maximum to user defined number
//takes in the users max number
////////////////////////////////
void cCounter::setMax(int newMax){

	max = newMax;
}

////////////////////////////////
//reachedMax()
//has the count reached it max?
//returns true if it has
////////////////////////////////
bool cCounter::reachedMax(int currentCount){
	bool returntype;

	if(currentCount >= cCounter::max){
		returntype = true;
	}else
		returntype = false;
	return returntype;
}
