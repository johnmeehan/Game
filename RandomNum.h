#ifndef INC_RANDOMNUM_H
#define INC_RANDOMNUM_H


/////////////////////////////////////
//	Random Number Generator Class
//  cRandomNumGen
//
//  A Class the Generates a Random 
//  Number when called.
//
//  KNOWN ISSUES: if called repeatedly in succession 
//  The same number is returned.
/////////////////////////////////////

class cRandomNumGen
{
public:
	//constructors
	cRandomNumGen();
	virtual ~cRandomNumGen(){	};

	//Accessors
	setRandMax();
	setRandMin();

	int giveRandNum();	//returns a random number between 1 and 10
	int giveRandNum(int);// max

	int giveRandNum(int ,int );//max and min 

	//methods


private:
	int max;
	int min;
//	int currentSeed;

};


#endif