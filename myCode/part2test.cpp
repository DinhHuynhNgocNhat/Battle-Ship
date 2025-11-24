/*
 * part2tests.cpp
 *
 *  Created on: 15.11.2019
 *      Author: mnl
 */

#include <iostream>

using namespace std;

#include "Board.h"
#include "ConsoleView.h"

static int passedTests = 0;
static int totalTests = 0;
namespace Test2 {
/**
 * Outputs the failedMessage on the console if condition is false.
 *
 * @param condition the condition
 * @param failedMessage the message
 */
	void assertTrue(bool condition, string failedMessage) {
		totalTests++;
		if (!condition) {
			cout << failedMessage << endl;
		}
		else {
		    passedTests++;
		}
	}
	void printTestSummary() {
	    cout << passedTests << "/" << totalTests << " tests passed." << endl;
	}
}

/**
 */
using namespace Test2;
void part2tests () {
	cout << "*************** Start testing part 2 ****************" << endl
			<< endl;
	Board board = Board(10,10);

	//Place ships on the own grid
	board.getOwnGrid().placeShip(Ship{GridPosition{"B2"}, GridPosition{"B4"}});
	board.getOwnGrid().placeShip(Ship{GridPosition{"D4"}, GridPosition{"G4"}});
	board.getOwnGrid().placeShip(Ship{GridPosition{"F6"}, GridPosition{"F9"}});

	//1. Ships must not touch each other
	assertTrue(!board.getOwnGrid().placeShip(Ship{GridPosition{"A2"},
		GridPosition{"E2"}}),"Assert failed 1: "
				"						ships are touching at a right angle");
	assertTrue(!board.getOwnGrid().placeShip(Ship{GridPosition{"B4"},
		GridPosition{"B5"}}),"Assert failed 2: "
				"							Ships are touching horizontally");
	assertTrue(!board.getOwnGrid().placeShip(Ship{GridPosition{"G4"},
		GridPosition{"H4"}}),"Assert failed 3: Ships are touching vertically");

	//2. Ships must be positioned horizontally or vertically
    assertTrue(!board.getOwnGrid().placeShip(Ship{GridPosition{"A8"},
    	GridPosition{"C10"}}),"Assert failed 4: Ship is placed diagonally");

	//3. Ships may be positioned at the edges of the grid
	assertTrue(board.getOwnGrid().placeShip(Ship{GridPosition{"F1"},
		GridPosition{"H1"}}), "Assert failed 5: Cannot place ship at the edge");

	//4. Ship must not be partly outside the grid
	assertTrue(!board.getOwnGrid().placeShip(Ship{GridPosition{"D8"},
		GridPosition{"D12"}}),
						"Assert failed 6: Ship is out of the grid");

	assertTrue(!board.getOwnGrid().placeShip(Ship{GridPosition{"H10"},
		GridPosition{"K10"}}),
						"Assert failed 7: Ship is out of the grid");

	//5. Placing ships of valid lengths and respecting the count
	assertTrue(!board.getOwnGrid().placeShip(Ship{GridPosition{"I1"},
		GridPosition{"I6"}}), "Assert failed 8: There is no ship length 6");

	assertTrue(board.getOwnGrid().placeShip(Ship{GridPosition{"A6"},
			GridPosition{"A10"}}),
				"Assert failed 9: Can't place the first ship with length 5");

	assertTrue(!board.getOwnGrid().placeShip(Ship{GridPosition{"J1"},
		GridPosition{"J5"}}),
		"Assert failed 10: There is only one ship with length 5");

	assertTrue(!board.getOwnGrid().placeShip(Ship{GridPosition{"J1"},
		GridPosition{"J4"}}),
		"Assert failed 11: There is only two ship with length 4");

	printTestSummary();

	ConsoleView consoleView(&board);
	consoleView.print();
    cout << endl << "*************** Finish testing part 2 ***************"
    		<< endl << endl;
}
