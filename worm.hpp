// Bryan Ward 
// lab 4-5 
// worm.hpp
// december 7, 2015
//
#ifndef WORM_HPP
#define WORM_HPP
#include "spots.hpp"
#include <iostream>

class worm
{
	public:
		worm(int index);
		int getHead();
		int getTail();
		void addToWorm(spots spot);
		void removeFromWorm();
		int getWormSize();
		spots getWormHeadSpot();
		spots getWormTailSpot();
		void createWorm(spots spot);	
		void print();

	private:
		int  headOfWorm , tailOfWorm , wormSize, maxSize;
		spots* wormQ; 

};
#endif
