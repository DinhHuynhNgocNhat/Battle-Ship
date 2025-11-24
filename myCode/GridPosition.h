/**
 * @file GridPosition.h
 * @brief Declaration of the GridPosition class for representing positions.
 *
 * This file defines the GridPosition class, which encapsulates the row and
 * column of a position on a grid. The class provides utilities for creating,
 * validating, and comparing grid positions.
 *
 * @date Created on: Dec 11, 2024
 * @author ngocn
 */

#ifndef GRIDPOSITION_H_
#define GRIDPOSITION_H_
#include <string>

/**
 * @class GridPosition
 * @brief Represents a position on a grid using a row and a column.
 *
 * The GridPosition class encapsulates a grid position, represented by a row
 * (character) and a column (integer). It provides constructors for creating
 * positions, methods for validation, and operators for comparison and string
 * conversion.
 */
class GridPosition
{
private:
	char row; /**< The row of the grid, represented as a character. */
	int column;/**< The column of the grid, represented as an integer. */
public:
    /**
     * @brief Constructs a GridPosition using a row and a column.
     * @param row The row of the position (character, e.g., 'A').
     * @param column The column of the position (integer, e.g., 1).
     */
	GridPosition(char row, int column);

    /**
     * @brief Constructs a GridPosition from a string representation.
     *
     * The string should be in the format "<Row><Column>", e.g., "A1".
     *
     * @param position The string representation of the position.
     */
	GridPosition(std::string position);

    /**
     * @brief Checks if the grid position is valid.
     * @return True if the position is valid, false otherwise.
     */
	bool isValid() const;

    /**
     * @brief Gets the row of the grid position.
     * @return The row as a character.
     */
	char getRow() const;

    /**
     * @brief Gets the column of the grid position.
     * @return The column as an integer.
     */
	int getColumn() const;

    /**
     * @brief Converts the GridPosition to a string.
     *
     * The string representation will be in format "<Row><Column>", e.g., "A1".
     *
     * @return The string representation of the position.
     */
	operator std::string() const;

    /**
     * @brief Compares two GridPosition objects for equality.
     * @param other The other GridPosition to compare.
     * @return True if both positions are equal, false otherwise.
     */
	bool operator==(const GridPosition& other) const;

    /**
     * @brief Compares two GridPosition objects for ordering.
     *
     * Useful for storing GridPosition objects in sorted containers like
     * std::map or std::set.
     *
     * @param other The other GridPosition to compare.
     * @return True if this position is less than the other, false otherwise.
     */
	bool operator<(const GridPosition& other) const;
};

#endif /* GRIDPOSITION_H_ */
