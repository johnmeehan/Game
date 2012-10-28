
#ifndef INC_CCOUNTER_H
#define INC_CCOUNTER_H

///////////////////////
//The class counter
// John Meehan 
// 0327301
//////////////////////
class cCounter{
	public:
		void reset();		// reset the counter
		void increment();	// increment the count
		int getCount();	//return the count

		void setMax(int);
		bool reachedMax(int);

		bool changeDay(){
			if(count==5){return false;}else return true;
		};

		cCounter(){reset();};	//Default Constructor
		virtual ~cCounter(){};	//Deconstructor
	private:
		int fivedaycount;
		int count;	
		int max;

};



#endif