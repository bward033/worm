//auther: Bryan Ward
//date december 5, 2015
//lab 4-5
//
#include <iostream>
#include "GameSquare.hpp"
#include "getChar.hpp"
//#include<curses.h>


int main()//int argc, const char *argv[]) 
{
/*
	if( argc != 2 ) {
       		std::cout << "usage: " << argv[0] << "grid";
        	exit(1);
	}
*/
	char c = 0;	
	int row = 0;
	int colums = 0;
	//int breaker = 0;
	char temp;
	//cin >> tem
	std::cout << "Please enter the size of the grid\n";
	while ( row < 10 || row > 25)
	{
		std::cout << "rows can only be from 10 to 25 \n";
		std::cout << "Pleae enter row.";
		std::cin >> row;
		std::cout <<std::endl;
	}
	while (colums < 10 || colums > 80)
	{
		std::cout <<" colums can be 10 to 80 \n";
		std::cout <<"please enter colum ";
		std::cin >> colums;
		std::cout <<std::endl;
	}	
	
	
	GameSquare* grid = new GameSquare( row, colums);
	grid -> theGrid();
	//grid -> print();
	int headRow = (row -2)/2;
	int headColum = 1;
	grid-> setHeadRow(headRow);
	grid -> setHeadColum(headColum);
	//
	//for (headColum; headColum < 6; headColum++)
	bool game = true;
	while(headColum<6) 
	{	headColum++;
		grid -> insertWormPart(headRow, headColum);
		
	 }
	grid -> newMunchie(); 
	grid ->startup();	
//	grid -> print();

	refresh();
	
	while  (c !='q' && game )
	{	
	 	switch(c){
			case 'w':
				headRow--;
				grid-> setHeadRow(headRow);
				grid -> setHeadColum(headColum);
				game = grid -> moveWorm(headRow,headColum);	
				if (!game)
					exit(1);
			break;
			case 's':
				headRow++;
				grid-> setHeadRow(headRow);
				grid -> setHeadColum(headColum);
				game = grid -> moveWorm(headRow,headColum);	
				if (!game)
					exit(1);
			
			break;
			case 'd':
				headColum++;
				grid-> setHeadRow(headRow);
				grid -> setHeadColum(headColum);
				game = grid -> moveWorm(headRow,headColum);	
				if (!game)
					exit(1);
			
			break;
			case 'a':
				headColum--;
				grid-> setHeadRow(headRow);
				grid -> setHeadColum(headColum);
				game = grid -> moveWorm(headRow,headColum);	
				if (!game)
					exit(1);
			
			break;
			case 'q':
				//grid ->terminate();
				exit(1);
			default:
			
				headColum++;
				grid-> setHeadRow(headRow);
				grid -> setHeadColum(headColum);
				game = grid -> moveWorm(headRow,headColum);	
				if (!game)
					exit(1);
			
		}
		
		grid -> print();
		//std::cout << " enter w,a,s or d and q to quit ";
		c = get_char();
	}
	return 0;

}
