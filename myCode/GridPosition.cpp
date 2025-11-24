/*
 * GridPosition.cpp
 *
 *  Created on: Dec 11, 2024
 *      Author: ngocn
 */
#include <iostream>
#include "GridPosition.h"
#include <string>

GridPosition::GridPosition(char row, int column)
{
	this->row=row;
	this->column=column;
}

GridPosition::GridPosition(std::string position)
{
	if (position.length()>=2){
		this->row=position[0];
		this->column=std::stoi(position.substr(1));
	}
}

bool GridPosition::isValid() const
{
	if (row >= 'A' && row <= 'Z' && column >= 1){
		return true;
	}
	return false;
}

char GridPosition::getRow() const
{
	return row;
}

int GridPosition::getColumn() const
{
	return column;
}

GridPosition::operator std::string() const
{
	//string(a,b): a is the number of repetitions, b is the repeated character
	return std::string(1,row) + std::to_string(column);
}

bool GridPosition::operator ==(const GridPosition& other) const
{
	if (this->row == other.row && this->column == other.column){

		return true;
	}
	return false;
}

bool GridPosition::operator <(const GridPosition& other) const
{
	if (this->row == other.row){
		if (this->column < other.column){
			return true;
		}
	}
	else if (this->row < other.row){
		return true;
	}
	return false;
}
