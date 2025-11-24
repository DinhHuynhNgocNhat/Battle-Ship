/**
 * @file ConsoleView.h
 * @brief Defines the `ConsoleView` class for rendering the game board and shots
 * in a text-based console view.
 *
 * This header file declares the `ConsoleView` class, which is responsible for
 * displaying the game state on the console. It has a method to print the
 * player's and opponent's grids, as well as the status of the shots fired.
 * The class is closely tied to the `Board` class and uses it to retrieve the
 * necessary information to render the view.
 *
 * @author ngocn
 * @date Dec 16, 2024
 */

#ifndef CONSOLEVIEW_H_
#define CONSOLEVIEW_H_
#include "Board.h"

/**
 * @class ConsoleView
 * @brief Provides a console-based view of the game board.
 *
 * The `ConsoleView` class is responsible for rendering the player's and
 * opponent's grids and the results of shots fired during the game. It uses a
 * `Board` object to access the game state and outputs the information in a
 * text-based format to the console.
 */
class ConsoleView
{
private:
	Board* board;  /** A pointer to the game board. */
public:
    /**
     * @brief Constructs a `ConsoleView` object linked to a specific `Board`.
     * @param board A pointer to the `Board` object to be used for rendering
     * the view.
     */
	ConsoleView(Board* board);

    /**
     * @brief Renders the game state (player's and opponent's grids) to the
     *  console.
     *
     * This function prints the current status of the player's and opponent's
     * grids, including the ships' positions, shots fired, and any hits or
     * sunken ships.
     */
	void print();
};

#endif /* CONSOLEVIEW_H_ */
