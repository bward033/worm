//Auther::Bryan Ward
//Date:: december 6 2015
//lab4
//spots.cpp
#include "spots.hpp"
spots::spots()
{
	row = colum = 0;

}
spots::~spots()
{

}
int spots::getRow()
{
	return row;
}

int spots::getColum()
{
	return colum;
}
void spots::setRow(int r)
{
	row = r;
}
void spots::setColum(int c)
{
	colum =c ;
}
void spots::print()
{
	std::cout << "Row = " << getRow() << "  Colum = " << getColum() << std::endl;
}

