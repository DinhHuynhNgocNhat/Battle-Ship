/*
 * OpponentGrid.cpp
 *
 *  Created on: Dec 16, 2024
 *      Author: ngocn
 */
#include<iostream>
#include<vector>
#include<set>
#include <map>
#include "OpponentGrid.h"

using namespace std;

OpponentGrid::OpponentGrid(int rows, int columns):rows(rows), columns(columns)
{
	sunkenShips[2]=0;
	sunkenShips[3]=0;
	sunkenShips[4]=0;
	sunkenShips[5]=0;
}

int OpponentGrid::getRows() const
{
	return rows;
}

int OpponentGrid::getColumns() const
{
	return columns;
}

void OpponentGrid::shotResult(const Shot &shot, Shot::Impact impact)
{
	GridPosition target = shot.getTargetPosition();
	shots[target] = impact; // store a shot

	//check if shot is Sunken
	if (impact==Shot::Impact::SUNKEN){
		int dx[]={0,0,-1,1};
		int dy[]={-1,1,0,0};
		std::set<GridPosition> shipPositions;
		shipPositions.insert(target);

		//check 4 directions to identify all hits on a ship
		for (int dir=0;dir<4;dir++){
			GridPosition curPosition = target;
			while(true){
				curPosition = GridPosition(curPosition.getRow()+dx[dir],
						curPosition.getColumn()+dy[dir]);
				map<GridPosition, Shot::Impact>::iterator it =
													shots.find(curPosition);

				//if the next to grid not be HIT -> break
				if (it== shots.end()||it->second != Shot::Impact::HIT){
					break;
				}
				shipPositions.insert(curPosition);
				shots[curPosition]=Shot::Impact::SUNKEN;
			}
		}

		cout<<"Opponent ship ("<<(*shipPositions.begin()).getRow()<<
			(*shipPositions.begin()).getColumn()<<"-"<<
			(*shipPositions.rbegin()).getRow()<<
			(*shipPositions.rbegin()).getColumn()<<") is sunken"<<endl<<endl;

		int shipLength = shipPositions.size();

		//add 1 sunken ship
        if (sunkenShips.find(shipLength) != sunkenShips.end()) {
            sunkenShips[shipLength]++;
        } else {
            sunkenShips[shipLength] = 1;
        }
	}
}

const std::map<GridPosition, Shot::Impact>& OpponentGrid::getShotAt() const
{
	return shots;
}

const std::map<int,int> OpponentGrid::getSunkenShips() const
{
	return sunkenShips;
}
