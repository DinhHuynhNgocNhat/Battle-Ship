/*
 * Board.cpp
 *
 *  Created on: Dec 16, 2024
 *      Author: ngocn
 */

#include "Board.h"

Board::Board(int rows, int columns):ownGrid(rows,columns),
opponentGrid(rows,columns)
{
}

int Board::getRow() const
{
	return ownGrid.getRows();
}

int Board::getColumn() const
{
	return ownGrid.getColumns();
}

OwnGrid& Board::getOwnGrid()
{
	return ownGrid;
}

OpponentGrid& Board::getOpponentGrid()
{
	return opponentGrid;
}
