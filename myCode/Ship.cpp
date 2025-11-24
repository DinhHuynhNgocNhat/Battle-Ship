/*
 * Ship.cpp
 *
 *  Created on: Dec 11, 2024
 *      Author: ngocn
 */
#include <iostream>
#include <cmath>
#include "Ship.h"
#include <set>

Ship::Ship(const GridPosition &bow, const GridPosition &stern) :
	bow(bow), stern(stern)
{

}

bool Ship::isValid() const
{
	// the bow and stern in the grid
	if (bow.isValid() && stern.isValid()){
		if (bow.getRow()==stern.getRow() || bow.getColumn()==stern.getColumn()){
			if (length()>=2 && length()<=5){
				return true;
			}
		}
	}
	return false;
}

GridPosition Ship::getBow() const
{
	return bow;
}

GridPosition Ship::getStern() const
{
	return stern;
}

int Ship::length() const
{
	if (bow.getRow()==stern.getRow()){
		return abs(bow.getColumn()-stern.getColumn())+1;
	}
	return abs(bow.getRow()-stern.getRow())+1;
}

std::set<GridPosition> Ship::occupiedArea() const
{
	std::set<GridPosition> occupiedArea;
	if (isValid()){
		char bowRow= bow.getRow();
		char sternRow = stern.getRow();
		int bowCol = bow.getColumn();
		int sternCol = stern.getColumn();

		//check if bow and stern in the same column
		if (bowRow==sternRow){
			for (int idx=std::min(bowCol,sternCol);
					idx<std::max(bowCol,sternCol)+1;idx++){
				occupiedArea.insert(GridPosition(bowRow,idx));
			}
		}

		//check if bow and stern in the same row
		else if (bowCol==sternCol){
			for (char idx=std::min(bowRow,sternRow);
					idx<std::max(bowRow,sternRow)+1;idx++){
				occupiedArea.insert(GridPosition(idx,bowCol));
			}
		}
	}
	return occupiedArea;
}

std::set<GridPosition> Ship::blockArea() const
{
	std::set<GridPosition> blockArea;

	int dx[]={-1,-1,-1,0,0,1,1,1};
	int dy[]={-1,0,1,-1,1,-1,0,1};

	char startRow = std::min(bow.getRow(),stern.getRow());
	char endRow = std::max(bow.getRow(),stern.getRow());
	int startCol = std::min(bow.getColumn(),stern.getColumn());
	int endCol = std::max(bow.getColumn(),stern.getColumn());

	if (startRow==endRow){
		for (int col=startCol;col<=endCol;col++){
			for (int direct=0;direct<8;direct++){
				char x = startRow + dx[direct];
				int y = col + dy[direct];
				if (x >= 'A' && x <= 'J' && y >= 1 && y <= 10){
					blockArea.insert(GridPosition(x,y));
				}
			}
		}
	}

	else if (startCol==endCol){
		for (int row=startRow;row<=endRow;row++){
			for (int direct=0;direct<8;direct++){
				char x = row + dx[direct];
				int y = startCol + dy[direct];
				if (x >= 'A' && x <= 'J' && y >= 1 && y <= 10){
					blockArea.insert(GridPosition(x,y));
				}
			}
		}
	}
	return blockArea;
}
