/**
 * @file OpponentGrid.h
 * @brief Declaration of the OpponentGrid class for managing an opponent's grid
 * in a battleship game.
 *
 * This file defines the OpponentGrid class, which represents the opponent's
 * grid. It tracks shots fired at the grid, records their impact, and maintains
 * information about sunken ships.
 *
 * @date Created on: Dec 12, 2024
 * @author ngocn
 */

#ifndef OPPONENTGRID_H_
#define OPPONENTGRID_H_
#include "Ship.h"
#include "Shot.h"
#include <vector>
#include <map>

/**
 * @class OpponentGrid
 * @brief Represents the opponent's grid in a battleship game.
 *
 * The OpponentGrid class manages the tracking of shots fired at the opponent's
 * grid, determines their impact,and keeps track of sunken ships. It provides
 * methods for retrieving grid dimensions, shot information, and sunken ship
 * statistics.
 */
class OpponentGrid
{
private:
	int rows; /**< Number of rows in the grid. */
	int columns; /**< Number of columns in the grid. */
	std::map<int,int> sunkenShips;  /**< Mapping of ship lengths to the number
											of sunken ships of that length. */
	std::map<GridPosition,Shot::Impact> shots; /**< Map of grid positions to
											their corresponding shot impacts. */
public:
    /**
     * @brief Constructs an OpponentGrid with specified dimensions.
     * @param rows The number of rows in the grid.
     * @param columns The number of columns in the grid.
     */
	OpponentGrid(int rows, int columns);

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
     * @brief Records the result of a shot fired at the opponent's grid.
     *
     * The method updates the opponent grid to store the impact of the shot and
     * marks any ships as sunken if applicable.
     *
     * @param shot The Shot object representing the position targeted.
     * @param impact The impact of the shot as a Shot::Impact enumeration value.
     */
	void shotResult(const Shot& shot, Shot::Impact impact);

    /**
     * @brief Retrieves all recorded shots fired at the opponent's grid.
     * @return A map of GridPosition objects to Shot::Impact values representing
     * shot impacts.
     */
	const std::map<GridPosition,Shot::Impact>& getShotAt() const;

    /**
     * @brief Retrieves information about sunken ships on the opponent's grid.
     *
     * This method returns a map indicating the count of sunken ships by their
     * lengths.
     *
     * @return A map where the keys are ship lengths and the values are the
     * number of sunken ships of that length.
     */
	const std::map<int,int> getSunkenShips() const;
};

#endif /* OPPONENTGRID_H_ */
