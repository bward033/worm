//auther:Bryan Ward 
//date: December 6, 2015
//freePool.cpp
//
#include "freePool.hpp"
#include "spots.hpp"

freePool::freePool()
{
	 
	nextSpot = 0;
} 

std::vector <spots *> freePool::freePoolVector()
{
	return  _freePool;
}


void freePool::addToFreePool( spots *spot )
{

 	_freePool.push_back(spot);
	nextSpot++;

}

void freePool::removeSpotInPool(int &index )
{
	_freePool[index] = _freePool.back();
	_freePool.pop_back();
	nextSpot--;
	index = -1;
	

}

int freePool::getnextSpot()
{
	return nextSpot;
}	 

void freePool::print()
{
	int count = 0;
	for(auto i = _freePool.begin(); i != _freePool.end(); i++)
//		std::cout << *i << ' '<< count++ << ' ';
		//for(std::vector<spots*>::iterator spot = _freePool->begin() ; spot != _freePool->end(); spot++)
		{
			std::cout << count++; 
			 (*i)->print();
		}
			
}

int freePool::getRowAtEnd()
{
	spots * spot = new spots();
	spot = _freePool.back();
	int row = spot -> getRow();
	//std::cout << "this is row !!!!!!!!!!!!! = " << row << std::endl;
	return row; 
}
int freePool::getColumAtEnd()
{
	spots * spot = new spots();
	spot = _freePool.back();
	int colum = spot -> getRow();
	return colum;
}
	
int freePool::getRowAt(int idx )
{
	spots * spot = new spots();
	spot = _freePool.at(idx);
	int row = spot -> getRow();
	//std::cout << "this is row !!!!!!!!!!!!! = " << row << std::endl;
	return row; 
}
int freePool::getColumAt(int idx )
{
	spots * spot = new spots();
	spot = _freePool.at(idx );
	int colum = spot -> getRow();
	return colum;
}
