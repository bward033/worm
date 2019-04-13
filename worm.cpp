//Auther:Bryan Ward 
//Date: decmber 8 2015
//worm.cpp
//lab4-5 
//


#include "worm.hpp"
//#include "freePool.hpp"
worm::worm(int index )
{
	wormQ = new spots[index];	
	maxSize = index;
	headOfWorm = 0;
	tailOfWorm = 0;
	wormSize = 0;	
	
}

int worm::getHead()
{
	return headOfWorm;
	
}
int worm::getTail()
{
	return tailOfWorm;
}
void worm::addToWorm(spots  spot )
{

	headOfWorm++;
	headOfWorm = headOfWorm % maxSize;
	wormQ[headOfWorm] = spot;
	
}
void worm::removeFromWorm()
{
	tailOfWorm++;
	tailOfWorm = tailOfWorm % maxSize;
	
}
int worm::getWormSize()
{
	return wormSize;

}
spots worm::getWormHeadSpot()
{
	return wormQ[headOfWorm];
}
spots worm::getWormTailSpot()
{
	return wormQ[tailOfWorm];
}
	
void worm::createWorm(spots  spot)
{
	
	wormQ[headOfWorm] = spot;
}
void worm::print()
{
	for (int i = 0 ; i < wormSize; i++)
	{
		wormQ[i].print();
	}
}
