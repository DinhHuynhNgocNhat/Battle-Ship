/**
 * @file Ship.h
 * @brief Declaration of the Ship class for representing ships on a grid.
 *
 * This file defines the Ship class, which encapsulates the properties and
 * behavior of a ship, including its bow and stern positions, length, and
 * occupied or blocked areas.
 *
 * @date Created on: Dec 11, 2024
 * @author ngocn
 */

#ifndef SHIP_H_
#define SHIP_H_
#include <string>
#include "GridPosition.h"
#include <set>

/**
 * @class Ship
 * @brief Represents a ship on a grid with a bow and stern position.
 *
 * The Ship class encapsulates a ship's properties, such as its bow and stern
 * positions, its length, and the areas it occupies or blocks on a grid. It also
 * includes methods for validating the ship's placement.
 */
class Ship
{
private:
	GridPosition bow; /**< The bow position of the ship on the grid. */
	GridPosition stern; /**< The stern position of the ship on the grid. */
public:
    /**
     * @brief Constructs a Ship with specified bow and stern positions.
     * @param bow The position of the ship's bow.
     * @param stern The position of the ship's stern.
     */
	Ship(const GridPosition& bow, const GridPosition& stern);

    /**
     * @brief Checks if the ship's placement is valid.
     *
     * A valid ship must have its bow and stern aligned either horizontally or
     * vertically, and the positions must be within the boundaries of the grid.
     *
     * @return True if the ship's placement is valid, false otherwise.
     */
	bool isValid() const;

    /**
     * @brief Gets the position of the ship's bow.
     * @return The GridPosition of the bow.
     */
	GridPosition getBow() const;

    /**
     * @brief Gets the position of the ship's stern.
     * @return The GridPosition of the stern.
     */
	GridPosition getStern() const;

    /**
     * @brief Calculates the length of the ship.
     *
     * The length is the number of grid cells the ship occupies, calculated as
     * the distance between the bow and stern.
     *
     * @return The length of the ship as an integer.
     */
	int length() const;

    /**
     * @brief Gets the area occupied by the ship.
     *
     * The occupied area includes all grid positions between the bow and stern.
     *
     * @return A set of GridPosition objects representing the occupied area.
     */
	std::set<GridPosition> occupiedArea() const;

    /**
     * @brief Gets the area blocked by the ship.
     *
     * The blocked area includes all grid positions adjacent to the occupied
     * area, preventing other ships from being placed too close.
     *
     * @return A set of GridPosition objects representing the blocked area.
     */
	std::set<GridPosition> blockArea() const;
};

#endif /* SHIP_H_ */
