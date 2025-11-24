/*
 * Shot.cpp
 *
 *  Created on: Dec 19, 2024
 *      Author: ngocn
 */

#include "Shot.h"

Shot::Shot(GridPosition targetPosition):targetPosition(targetPosition)
{

}

GridPosition Shot::getTargetPosition() const
{
	return targetPosition;
}
