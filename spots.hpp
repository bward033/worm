//Bryan Ward 
//date: december 6, 2015
//lab4
//spots.hpp

#ifndef SPOTS_HPP
#define SPOTS_HPP
#include <iostream>
const int WORM = -1;
const int BOUNDARIES  = -1; 

class spots
{
public:
	spots();
	~spots(); 		
	int getRow ();
	int getColum();
	void setRow(int r);
	void setColum(int c );
	void print();
private:
	int row, colum;
};
#endif 
