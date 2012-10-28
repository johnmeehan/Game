//#include "cCharacter.h"
//#include "cCounter.h"
//#include "cEnemy.h"
//#include "cPlayer.h"
//#include "cSquareData.h"
//#include "enum.h"
//#include "llist.h"
#include "RandomNum.h"


//#include "header.h"
#include <time.h>
#include <iostream>

#include <cstdlib>

using namespace std;

///////////////////////////////
//
//
///////////////////////////////
cRandomNumGen::cRandomNumGen(){

	srand(time(NULL));
//currentSeed = srand(time(NULL));
}

/////////////////////////////////////////////////////////////////////
//  cRandonNumGen
//
//  KNOWN ISSUES: Returns same number if accesses in quick succession
////////////////////////////////////////////////////////////////////
int cRandomNumGen::giveRandNum(){
	

	int number = 0;

   // Seed the random-number generator with current time so that
   // the numbers will be different every time we run.
   srand(time(NULL));

   //srand( (int)time( NULL ) );
   //number = rand();
   //number = (int)(rand()*10.0/10)+1;
   //number = (int)(rand()*10.0/RAND_MAX)+1;
   //number = (rand()*10.0/RAND_MAX)+1;


   //Works  for a random number in a range
   //number = rand() % (max - min + 1) + min;

   number = (rand() % 10) + 1; 
	  
   return number;
};

cRandomNumGen::setRandMax(){
	int newmax;
	cout <<"RandNumGen\n";
	cout <<"Enter a New Max\n";
	cin >>newmax;
	
	max = newmax;
}


cRandomNumGen::setRandMin(){
	int newmin;
	cout <<"RandNumGen\n";
	cout <<"Enter a New Min\n";
	cin >>newmin;
	min = newmin;
}


int cRandomNumGen::giveRandNum(int max){
//	srand(currentSeed);
//	currentSeed = srand(currentSeed);
int min = 0;
	//int number = (min+(max-min) * (int)rand()/RAND_MAX); //create random domain between [min,max]
	//double number = (   (double)rand() / ((double)(max)+(double)(1)) );
	int number = (rand() % (max + 1));
	return number;

}

int cRandomNumGen::giveRandNum(int max, int min){
//	srand(currentSeed);
//	currentSeed = srand(currentSeed);

	//double number = (min + (max-min) * (double)rand()/RAND_MAX); //create random domain between [min,max]
	//double number = (   (double)rand() / ((double)(max)-(double)(min)+(double)(1))+(double)(min) );

	int number = rand() % (max - min + 1) + min;
	return number;

}



 