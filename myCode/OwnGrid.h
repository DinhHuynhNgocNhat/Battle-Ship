/**
 * @file OwnGrid.h
 * @brief Declaration of the OwnGrid class for managing a player's grid in a
 * battleship game.
 *
 * This file defines the OwnGrid class, which represents the player's grid,
 * including the placement of ships and handling of shots fired at the grid.
 *
 * @date Created on: Dec 12, 2024
 * @author ngocn
 */

#ifndef OWNGRID_H_
#define OWNGRID_H_
#include "Ship.h"
#include "Shot.h"
#include <vector>
#include <map>
#include <set>

/**
 * @class OwnGrid
 * @brief Represents the player's grid in a battleship game.
 *
 * The OwnGrid class manages the player's grid, including ship placement,
 * tracking shots fired at the grid, and determining the impact of those shots.
 * It also provides methods for retrieving grid dimensions and the status of
 * ships.
 */
class OwnGrid
{
private:
	int rows; /**< Number of rows in the grid. */
	int columns; /**< Number of columns in the grid. */
	std::vector<Ship> ships;  /**< List of ships placed on the grid. */
	std::map<int,int> shipTypes;  /**< Mapping of ship lengths to their allowed
									counts. */
	std::set<GridPosition> shotAt;  /**< Set of positions that have been
										shot at. */
public:
    /**
     * @brief Constructs an OwnGrid with specified dimensions.
     * @param rows The number of rows in the grid.
     * @param columns The number of columns in the grid.
     */
	OwnGrid(int rows, int columns);

    /**
     * @brief Gets the number of rows in the grid.
     * @return The number of rows as an integer.
     */
	int getRows() const;

    /**
     * @brief Gets the number of columns in the grid.
     * @return The number of columns as an integer.
     */
	int getColumns() const;

    /**
     * @brief Attempts to place a ship on the grid.
     *
     * The method checks if the ship placement is valid and does not conflict
     * with existing ships and blocked areas or grid boundaries.
     *
     * @param ship The Ship object to place on the grid.
     * @return True if the ship is placed successfully, false otherwise.
     */
	bool placeShip(const Ship& ship);

    /**
     * @brief Retrieves the list of ships placed on the grid.
     * @return A vector of Ship objects currently placed on the grid.
     */
	std::vector<Ship> getShips() const;

    /**
     * @brief Handles a shot fired at the grid and determines its impact.
     *
     * The method checks if the shot hits a ship, misses, or sinks a ship.
     * It updates the internal state of the grid accordingly.
     *
     * @param shot The Shot object representing the position being targeted.
     * @return The impact of the shot as a Shot::Impact enumeration value.
     */
	Shot::Impact takeBlow(const Shot& shot);

    /**
     * @brief Gets the set of positions that have been shot at on the grid.
     * @return A set of GridPosition objects representing the positions shot at.
     */
	const std::set<GridPosition> getShotAt() const;

    /**
     * @brief Determines the impact of a shot at a specific position.
     *
     * This method checks if a position was hit, missed, or is part of a ship.
     *
     * @param position The GridPosition to check.
     * @return The impact of the shot as a Shot::Impact enumeration value.
     */
	const Shot::Impact getImpact(GridPosition& position) const;
};

#endif /* OWNGRID_H_ */
