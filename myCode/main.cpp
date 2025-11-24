// Standard (system) header files
#include <iostream>
#include <cstdlib>
// Add more standard header files as required
#include <string>
#include "Board.h"
#include "ConsoleView.h"

void part1tests();
void part2tests();
void part3tests();
using namespace std;

// Main program
int main ()
{
    // TODO: Add your program code here
	cout << "Lab2_Battleship started." << endl << endl;

	Board board = Board(10,10);
	ConsoleView consoleView(&board);

	cout<<"Place ship in own grid"<<endl;

	//Place ship at B2-B3-B4
	board.getOwnGrid().placeShip(
			Ship(GridPosition("B4"),GridPosition("B2")));

	//Place ship at D4-E4-F4-G4
	board.getOwnGrid().placeShip(
			Ship(GridPosition("G4"),GridPosition("D4")));

	//Place ship at F6-F7-F8-F9
	board.getOwnGrid().placeShip(
			Ship(GridPosition("F6"),GridPosition("F9")));

	consoleView.print();

	cout<<"Shot at own grid"<<endl;

	//Shot own grid at B3-B4-B5
	board.getOwnGrid().takeBlow(Shot(GridPosition("B3")));
	board.getOwnGrid().takeBlow(Shot(GridPosition("B4")));
	board.getOwnGrid().takeBlow(Shot(GridPosition("B5")));

	consoleView.print();

	cout<<"Shot at opponent grid"<<endl;

	//Shot opponent grid at B2-B3-B4-B5
	board.getOpponentGrid().shotResult(GridPosition("B2"),Shot::Impact::NONE);
	board.getOpponentGrid().shotResult(GridPosition("B3"),Shot::Impact::HIT);
	board.getOpponentGrid().shotResult(GridPosition("B4"),Shot::Impact::HIT);
	board.getOpponentGrid().shotResult(GridPosition("B5"),Shot::Impact::SUNKEN);

	//Shot opponent grid at F5-G4-G5-G6-I5
	board.getOpponentGrid().shotResult(GridPosition("F5"),Shot::Impact::NONE);
	board.getOpponentGrid().shotResult(GridPosition("G4"),Shot::Impact::NONE);
	board.getOpponentGrid().shotResult(GridPosition("G5"),Shot::Impact::HIT);
	board.getOpponentGrid().shotResult(GridPosition("G6"),Shot::Impact::HIT);
	board.getOpponentGrid().shotResult(GridPosition("I5"),Shot::Impact::NONE);

	consoleView.print();

	//Testing
	part1tests();
	part2tests();
	part3tests();

	return 0;
}
