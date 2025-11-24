/*
 * OwnGrid.cpp
 *
 *  Created on: Dec 12, 2024
 *      Author: ngocn
 */
#include <iostream>
#include <string>
#include "OwnGrid.h"
#include <set>
#include <vector>

using namespace std;

OwnGrid::OwnGrid(int rows, int columns) : rows(rows), columns(columns)
{
	shipTypes = {{2,4},{3,3},{4,2},{5,1}};//length - number
}


int OwnGrid::getRows() const
{
	return rows;
}

int OwnGrid::getColumns() const
{
	return columns;
}

bool OwnGrid::placeShip(const Ship &ship)
{
	//if ship valid
	if (ship.isValid()){
		for (const Ship placedShips : ships){
			std::set<GridPosition> placedArea = placedShips.occupiedArea();
			std::set<GridPosition> blockedArea = placedShips.blockArea();

			//if new ship is on occupiedArea and blockedArea
			for (const GridPosition position : ship.occupiedArea()){
				if (placedArea.count(position) > 0 ||
						blockedArea.count(position) > 0){
					return false;
				}

				//if new ship out of the grid
				if(position.getRow()<'A' || position.getRow() >='A'+getRows()){
					return false;
				}
				if(position.getColumn()<1||position.getColumn()>getColumns()){
					return false;
				}
			}
		}

		//if new ship has invalid length
		if (shipTypes[ship.length()]<=0){
			return false;
		}
		ships.push_back(ship);
		shipTypes[ship.length()]--;
		return true;
	}
	return false;
}

std::vector<Ship> OwnGrid::getShips() const
{
	return ships;
}

Shot::Impact OwnGrid::takeBlow(const Shot &shot)
{
	//target position not repeat
	GridPosition target = shot.getTargetPosition();
	if(shotAt.count(target)){
		return Shot::Impact::NONE;
	}
	shotAt.insert(target);

	for (Ship ownShips : ships){
		set<GridPosition> occupiedArea = ownShips.occupiedArea();
		//check all position are hit -> sunken ; only a part of ship -> hit
		if (occupiedArea.count(target)){
			set<GridPosition> intersection;
			for(GridPosition shotPos : shotAt){
				if (occupiedArea.count(shotPos)){
						intersection.insert(shotPos);
				}
			}

			if (intersection.size()==occupiedArea.size()){
				cout<<"Own ship ("<<ownShips.getBow().getRow()<<
					ownShips.getBow().getColumn()<<"-"<<
					ownShips.getStern().getRow()<<
					ownShips.getStern().getColumn()<<") is sunken"<<endl<<endl;
				return Shot::Impact::SUNKEN;
			}
			return Shot::Impact::HIT;
		}
	}
	return Shot::Impact::NONE;
}

const std::set<GridPosition> OwnGrid::getShotAt() const
{
	return shotAt;
}

const Shot::Impact OwnGrid::getImpact(GridPosition &position) const
{
	//if this position not include in container shotAt
    if (shotAt.count(position) == 0) {
        return Shot::Impact::NONE;
    }

	for (Ship ownShip : ships){
		std::set<GridPosition> occupiedArea = ownShip.occupiedArea();
		if(occupiedArea.count(position)){
			return Shot::Impact::HIT;
		}

	}
	return Shot::Impact::NONE;
}
