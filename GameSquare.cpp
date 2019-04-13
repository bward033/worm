#include"GameSquare.hpp"
#include "freePool.hpp"

GameSquare::GameSquare(int row, int colum )
{
	numRows = row ;
	numColums = colum;
	index = (row -2) * (colum - 2);
	screen = new int* [numRows];
	for( int i = 0; i < numRows; i++)
	 {
		screen[i] = new int [numColums];
	}
	
	pool = new freePool;
	theWorm = new worm(index);
	_hRow = _hColum =Mrow = Mcolum = Mvalue = gFactor = 0;

	e = "0";
	inbounds  = true;
	wormS = 0;
}	

void GameSquare::theGrid()
{
	
	int i = 0;
	//cout << " this is the row = " << numRows << endl;
	//cout << "this is the colum = " << numColums << endl; 
	for(int r = 0; r < numRows; r++)
	{	
		for (int c  = 0; c < numColums; c++)
		{
			if ((c == 0 || r == 0 )  || c == (numColums - 1) || r ==  ( numRows - 1)) 
				screen[r][c]= -1;	
			else{
				//cout <<" this is r = " << r << endl;
				//cout <<" this is c = " << c << endl;
				screen[r][c] = pool -> getnextSpot();
				spots *spot = new spots;
				spot -> setRow(r);
				spot -> setColum(c);
			        pool ->	addToFreePool(spot);
				//screen[r][c] = i ;
				//i+=1;

			}
		}
	}
}

void GameSquare::print()
{
	int wormS = theWorm -> getWormSize();
	//spots * Warray[] = theWormSize() 	
	startup();
	for(int r = 0; r < numRows; r++)
	{	
		
		for (int c  = 0; c < numColums; c++)
		{
				
				move(r,c);
			if ((c == 0 || r == 0 )  || c == (numColums - 1) || r ==  ( numRows - 1)) 
				mvaddch(r,c,'$');	
		/*	if (r == Mrow && c == Mcolum)
			{
				cout << setw(5) <<'M';
			}
			else{
				cout << setw(5) << screen[r][c];
			}*/
		}
		//cout << endl;
	}
	//cout <<"this is the M = "<< Mvalue << endl;  
	move (Mrow, Mcolum);
	addch( '0' + Mvalue);
	move(_hRow,_hColum);
	addch('@');	
	refresh();
	if (!inbounds)
		terminate();
	//pool -> print();
	//theWorm->print();
/*
	pool -> print();
	cout << "\n \n \n ";	

	pool -> removeSpotInPool(screen [3][3]);	
	cout << "\n \n \n ";	
	for( int r = 0; r < numRows; r++)
	{	
		for(int c  = 0; c < numColums; c++)
		{
			cout << setw(5) << screen[r][c];
		}
		cout << endl;
	}
	cout << "\n \n \n ";	
*/
}

//int GameSqare::getColums(int numColums)
void GameSquare::insertWormPart(int row, int colum)
{
 	//spots last  = pool -> freePoolVector()->at(getNextSpot());		
	int row2 = pool -> getRowAtEnd();
	int colum2 = pool -> getColumAtEnd();
	//cout << " this is screen at freepool end  !!!!!!!!!!" << screen[row2][colum2]<< endl; 
	
	//cout <<" this is colum 2 !!!!!!!!!!!!!"<< colum2  << endl;
	screen[row2][colum2] = screen[row][colum];
	//cout << "this is screen at new row and c " <<screen[row][colum];
	pool -> removeSpotInPool(screen[row][colum]);
	spots spot;
	spot.setRow(row);
	spot.setColum(colum);
	theWorm->addToWorm(spot);
	//refresh();
	//spot.print();
	
}
bool GameSquare::moveWorm(int row, int colum)
{
	bool yum = 0;
	if (screen[row][colum] == -1)
	{
		inbounds =0;
		return 0;
	}
	if ( row == Mrow && colum == Mcolum)
	{
		gFactor += Mvalue;
		yum = true;
	} 
	spots *spot = new spots;
	spot->setRow(row);
	spot->setColum(colum);
	
	theWorm->addToWorm(*spot);
	if (gFactor == 0){
		theWorm -> removeFromWorm();
		spots wormTail = theWorm->getWormTailSpot();
		int tr = wormTail.getRow();
		int tc = wormTail.getColum();
	
		spots *st = new spots;
		st->setRow(tr);
		st->setColum(tc);
		pool->addToFreePool(st);
		screen[tr][tc] = screen[row][colum];
		
	}
	if(gFactor >0)
		gFactor--;
	/*	
	spots wormTail = theWorm->getWormTailSpot();
	int tr = wormTail.getRow();
	int tc = wormTail.getColum();
	
	spots *st = new spots;
	st->setRow(tr);
	st->setColum(tc);
	pool->addToFreePool(st);
	//spots wormHead =  theWorm->getWormHeadSpot();

	//cout << "this is screen" << screen[row][colum]<<endl; 
	int wtr = wormTail.getRow();
	int wtc = wormTail.getColum();
	int idx = screen[row][colum];
	screen[wtr][wtc] = idx; 
	*/
	//cout <<"idx =============================" << idx <<endl;
	//cout << " this is whr " << wtr <<" this is whc " << wtc << endl;
	pool -> removeSpotInPool(screen[row][colum]);
	if (yum)
	{
		newMunchie();
	}	
	//spot->print();
	return 1;
			
}				
void GameSquare::newMunchie()
{
	srand(time(NULL));
	Mvalue = rand() % 9+1;
//	cout << "this is the Mvalue ================== " << Mvalue << endl ;
		
	int where = rand()% pool->getnextSpot();
	
	Mrow = pool->getRowAt(where);
	Mcolum = pool->getColumAt(where);
//	cout << " this is the M Row " << Mrow << " and this is M Colum "  << Mcolum << endl;
	 e = to_string(Mvalue);
//	cout <<"this is e ====================================== " << e;
//	addch(e);	

}
		
void GameSquare::startup( void )
{
     initscr();	 /* activate the curses */
     curs_set(0);/* do not display the cursor */
     clear();	 /* clear the screen that curses provides */
     noecho();	 /* prevent the input chars to be echoed to the screen */
     cbreak();	 /* change the stty so that characters are delivered to the
		    program as they are typed--no need to hit the return key!*/
}

void GameSquare::terminate( void )
{
     mvcur( 0, COLS - 1, LINES - 1, 0 );
     clear();
     refresh();
     endwin();
}
void GameSquare::setHeadRow(int hrow)
{	
	_hRow = hrow;
}
void GameSquare::setHeadColum(int hcolum)
{
	_hColum = hcolum;
}


























