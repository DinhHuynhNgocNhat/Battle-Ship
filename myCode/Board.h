/**
 * @file Board.h
 * @brief Defines the `Board` class representing the game board for managing the
 * grids of a player and opponent.
 *
 * This header file declares the `Board` class, which contains two grids: one
 * for the player's own ships (`OwnGrid`) and one for the opponent's ships
 * (`OpponentGrid`). The `Board` class allows access to these grids and provides
 * methods for retrieving the number of rows and columns in the grid.
 *
 * @author ngocn
 * @date Dec 16, 2024
 */

#ifndef BOARD_H_
#define BOARD_H_
#include "OwnGrid.h"
#include "OpponentGrid.h"

/**
 * @class Board
 * @brief Represents the game board with grids for the player and the opponent.
 *
 * The `Board` class is responsible for managing two grids: one for the player's
 * ships and one for the opponent's ships. It provides methods to access these
 * grids and retrieve the size of the board.
 */
class Board
{
private:
	OwnGrid ownGrid; /** The grid for the player's own ships. */
	OpponentGrid opponentGrid; /** The grid for the opponent's ships. */
public:
    /**
     * @brief Constructs a `Board` object with specified dimensions.
     * @param rows The number of rows in the grid.
     * @param columns The number of columns in the grid.
     */
	Board(int rows, int columns);

    /**
     * @brief Gets the number of rows in the board.
     * @return The number of rows.
     */
	int getRow() const;

    /**
     * @brief Gets the number of columns in the board.
     * @return The number of columns.
     */
	int getColumn() const;

    /**
     * @brief Gets the player's grid.
     * @return A reference to the player's `OwnGrid`.
     */
	OwnGrid& getOwnGrid();

    /**
     * @brief Gets the opponent's grid.
     * @return A reference to the opponent's `OpponentGrid`.
     */
	OpponentGrid& getOpponentGrid();
};

#endif /* BOARD_H_ */
