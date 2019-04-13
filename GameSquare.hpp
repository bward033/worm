//Bryan Ward 
//Desember 6, 2015
//Lab4
//gameSquare.hpp
#ifndef GAMESQUARE_HPP
#define GMAESQUARE_HPP

#include <iostream>
#include <iomanip>
#include "freePool.hpp"
#include "worm.hpp"
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include<curses.h>
#include<string>

using namespace std;
class GameSquare {
public:
	GameSquare (int row, int colum);
	~GameSquare ();
	void theGrid();
	void print();	 				
	int getRows(){ return numRows;}
	int getColums() { return numColums;}
	int** getScreen() {return screen;}
	void insertWormPart(int row, int colum);	
	bool  moveWorm(int row, int colum);
	void  newMunchie();
	void startup(void);
	void terminate(void);
	void setHeadRow(int hrow);
	void setHeadColum(int hcolum);
	

private:
	int index, numColums, numRows, Mrow, Mcolum, Mvalue, gFactor , _hRow , _hColum;
	int wormS, iwormS;
	int ** screen;
	freePool *pool;
	spots *spot;
	worm *theWorm;
	string e;
	bool inbounds;

};
#endif
