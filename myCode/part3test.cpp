/*
 * part3tests.cpp
 *
 *  Created on: 15.11.2019
 *      Author: mnl
 */

#include <iostream>
#include <vector>
#include <map>
#include "Board.h"
#include "ConsoleView.h"

using namespace std;

static int passedTests = 0;
static int totalTests = 0;

namespace Test3 {
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
using namespace Test3;
/**
 * Main test function for part 3.
 */
void part3tests (){
	cout << "*************** Start testing part 3 ****************"
			<< endl << endl;
    Board board = Board(10,10);

    //Place ships on the own grid
    board.getOwnGrid().placeShip(Ship{GridPosition{"B2"}, GridPosition{"B4"}});
    board.getOwnGrid().placeShip(Ship{GridPosition{"D4"}, GridPosition{"G4"}});
    board.getOwnGrid().placeShip(Ship{GridPosition{"F6"}, GridPosition{"F9"}});

    //1. Shot on own grid

    //1.1 Miss shot
    bool test = board.getOwnGrid().takeBlow(GridPosition{"B5"}) ==
    												Shot::Impact::NONE;
    assertTrue(test, "Assert failed 1: Shot must miss");

    //1.2 Shot hits
    test = (board.getOwnGrid().takeBlow(GridPosition{"B3"})==Shot::Impact::HIT);
    assertTrue(test, "Assert failed 2: Shot must hit");

    test = (board.getOwnGrid().takeBlow(GridPosition{"B4"})==Shot::Impact::HIT);
    assertTrue(test, "Assert failed 3: Shot must hit");

    //1.3 Sink the ship
    test = board.getOwnGrid().takeBlow(GridPosition{"B2"})
    										== Shot::Impact::SUNKEN;
    assertTrue(test, "Assert failed 4: Shot must sink ship");

    //1.4 Repeat the shot to the ship again
    test = board.getOwnGrid().takeBlow(GridPosition{"B2"})==Shot::Impact::NONE;
    assertTrue(test, "Assert failed 5: Shot must return NONE because "
    		"ship sank");

    //1.5 Shot out of the grid
    test = board.getOwnGrid().takeBlow(GridPosition{"B11"})==Shot::Impact::NONE;
    assertTrue(test, "Assert failed 6: Shot is out of the grid");

    //*****************************************************

    //2. Shot on opponent grid

    //2.1 Miss shot
    board.getOpponentGrid().shotResult(Shot(GridPosition{"B2"}),
    													Shot::Impact::NONE);
    test = board.getOpponentGrid().getShotAt().at(GridPosition{"B2"})
       	       											== Shot::Impact::NONE;
    assertTrue(test,"Assert failed 7: Shot must be NONE");

    //2.2 Hit shot
    board.getOpponentGrid().shotResult(Shot(GridPosition{"B5"}),
    													Shot::Impact::HIT);
    test = board.getOpponentGrid().getShotAt().at(GridPosition{"B5"})
       	       											== Shot::Impact::HIT;
    assertTrue(test,"Assert failed 8: Shot must be HIT");

    //2.3 Not hit all parts of a ship -> No Sunken ship
    board.getOpponentGrid().shotResult(Shot(GridPosition{"B4"}),
    													Shot::Impact::HIT);
    map<int,int> findSunkenShip = board.getOpponentGrid().getSunkenShips();
    assertTrue(!findSunkenShip.at(3),
    				"Assert failed 9: No ship (length 3) is sunken");

    //2.4 Sink a ship
    board.getOpponentGrid().shotResult(Shot(GridPosition{"B3"}),
        												Shot::Impact::SUNKEN);
    if (board.getOpponentGrid().getShotAt().at(GridPosition{"B5"})
					== Shot::Impact::SUNKEN){
    	if (board.getOpponentGrid().getShotAt().at(GridPosition{"B4"})
    						== Shot::Impact::SUNKEN){
    		if (board.getOpponentGrid().getShotAt().at(GridPosition{"B3"})
    		    						== Shot::Impact::SUNKEN){
    			test = true;
    		}
    	}
    }
    assertTrue(test,"Assert failed 10: All parts of this ship must be SUNKEN");

    //2.5 A ship with length 3 sank
    findSunkenShip = board.getOpponentGrid().getSunkenShips();
    test = findSunkenShip.find(3)->second==1;
    assertTrue(test,
    				"Assert failed 11: Ship (length 3) is sunken");

    printTestSummary();

    ConsoleView consoleView(&board);
    consoleView.print();
    cout<< endl << "*************** Finish testing part 3 ****************"
    		<< endl << endl;
}

