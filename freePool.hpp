#ifndef FREEPOOL_HPP
#define FREEPOOL_HPP

#include<vector>
#include "spots.hpp"
#include <iostream>
#include <algorithm>

class freePool
{
public:
	freePool();
	~freePool();
	void addToFreePool(spots *spot );
	void removeSpotInPool(int &index );
	std::vector<spots*> freePoolVector();
	int getnextSpot();
	void print();
	int getRowAtEnd();
	int getColumAtEnd();
	int getRowAt(int idx );
	int getColumAt(int idx );
private:
	//std::vector<spots *> *_freePool;	
	std::vector< spots* > _freePool;
	int nextSpot;
};
#endif 
