/*
 * ConsoleView.cpp
 *
 *  Created on: Dec 16, 2024
 *      Author: ngocn
 */
#include <iostream>
#include "ConsoleView.h"
#include <vector>
#include <set>
#include <string>

using namespace std;

ConsoleView::ConsoleView(Board *board)
{
	this->board=board;
}

void ConsoleView::print()
{
	const int row = board->getRow();
	const int col = board->getColumn();
	vector<Ship> ownShips = board->getOwnGrid().getShips();
	set<GridPosition> shotAt = board->getOwnGrid().getShotAt();

	map<GridPosition,Shot::Impact> opponentShots =
			board->getOpponentGrid().getShotAt();

	cout<<" ";
	for (int idxCol=1;idxCol<=col;idxCol++){
		cout<<" "<<idxCol;
	}
	cout<<"   ";
	for (int idxCol=1;idxCol<=col;idxCol++){
		cout<<" "<<idxCol;
	}
	cout<<endl;

	//set array for print grid
	char grid[row*col];
	char oppGrid[row*col];
	for (int idx=0;idx<row*col;idx++){
		grid[idx]='.';
		oppGrid[idx]='.';
	}

	//set own ship on own array
	for (const Ship& ship : ownShips){
		for (const GridPosition& pos : ship.occupiedArea()){
			int idx = (pos.getRow()-'A')*col+(pos.getColumn()-1);
			grid[idx]='#';
		}
	}

	//print shots on own array
	for (GridPosition shot : shotAt){
		int rowIdx = shot.getRow() - 'A' + 1;
		int colIdx = shot.getColumn();
		if (rowIdx>row || colIdx>col || rowIdx<1 || colIdx<1){
			break;
		}
        int idx = (shot.getRow()-'A')*col+(shot.getColumn()-1);
        Shot::Impact impact = board->getOwnGrid().getImpact(shot);
        if (impact == Shot::Impact::NONE) {
        	grid[idx] = '^';
        }
        else if (impact == Shot::Impact::HIT)
        {
        	grid[idx] = '0';
        }
	}

	//print shots on opponent array
	for (pair<GridPosition,Shot::Impact> oppShot : opponentShots){
		int idx = (oppShot.first.getRow()-'A')*col+oppShot.first.getColumn()-1;
	    switch (oppShot.second){
    		case Shot::Impact::HIT:
    			oppGrid[idx]='0';
    			break;
    		case Shot::Impact::NONE:
    			oppGrid[idx]='^';
    			break;
    		case Shot::Impact::SUNKEN:
    			oppGrid[idx]='#';
    			break;
	    }
	}

	//print array
	for (int idxRow=0;idxRow<row;idxRow++){
		//Own Grid
		cout<<static_cast<char>('A'+idxRow);
		for(int idxCol=0;idxCol<col;idxCol++){
			int index = idxRow*col+idxCol;
			cout<<" "<<grid[index];
		}
		cout <<"   ";
		//Opponent Grid
		cout<<static_cast<char>('A'+idxRow);
		for(int idxCol=0;idxCol<col;idxCol++){
			int index = idxRow*col+idxCol;
			cout<<" "<<oppGrid[index];
		}
		cout<<endl;
	}
	cout<<endl;
}
