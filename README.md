# **BATTLESHIP (OO MODEL)**
## 📌 **Overview**

This project implements an object-oriented model of the board game
Battleship.

The goal is not to implement a full multiplayer game, but to model the
game state from one player's perspective, replacing the traditional paper
sheet used in the analog version.

The implementation evolves in three parts:

- Part 1: Basic classes

- Part 2: Display and ship arrangement rules

- Part 3: Shots and game progress tracking

## 🧠** Design Goals**

- Clean object-oriented modeling

- Immutable value objects where appropriate

- Proper separation of responsibilities

- Use of STL containers and smart pointers

- No unnecessary console output

- Fully documented using Doxygen

- Systematic unit testing

## 🏗 **Architecture Overview**
Core Classes
### **1️. GridPosition (Immutable)**

**Represents a position on the grid** (e.g., B10).

Features:

- Constructible from (row, column) or string "B10"

- Validation via isValid()

- String conversion operator

- Comparison operators (==, <)

The < operator defines ordering from top-left to bottom-right (e.g., A1 … J10), enabling usage inside std::set and std::map.

### **2️. Ship (Immutable)**

Represents a ship defined by: bow and stern.

Features:

- Validity check (horizontal/vertical, length 2–5)

- length()

- occupiedArea()

- blockedArea() (used for arrangement rules)

### **3️. OwnGrid**

**Represents the player’s own ships.**

Responsibilities:

-Store ships

- Validate ship placement

- Enforce arrangement rules

- Handle incoming shots

- Track taken blows

### **4️. OpponentGrid**

**Represents the opponent’s grid from the player's perspective.**

Responsibilities:

- Track fired shots

- Store shot results

- Detect sunken opponent ships

### **5️. Board**

**Represents the complete game state from one player’s perspective.**

Contains:

- OwnGrid

- OpponentGrid

- Provides accessors to both grids.

### **6️. ConsoleView**

**Displays the board state on the console.**

Responsibilities:

- Render own grid

- Render opponent grid

- Display ships, hits, misses, and sunken ships

## ⚙️ Basic Classes

- Implement immutable GridPosition

- Implement immutable Ship

- Implement OwnGrid, OpponentGrid, Board

- Pass provided unit tests

- No extra output is allowed unless explicitly required.

## 🖥 Exercise 2.2 – Display & Arrangement Rules
- Display

- Render both grids side-by-side

- Own ships shown with #

- Empty water shown with ~

- Arrangement Rules (German version)

- Ships:

| Ship Class | Length | Quantity |
| ---------- | ------ | -------- |
| Carrier    | 5      | 1        |
| Battleship | 4      | 2        |
| Destroyer  | 3      | 3        |
| Submarine  | 2      | 4        |


Rules enforced in OwnGrid::placeShip:

- Ships must not touch

- Ships must be straight lines

- Ships must be horizontal or vertical

- Ships may be placed at edges

- Correct number of ships per length

Set theory is used to verify non-touching ships via:

- occupiedArea()

- blockedArea()

- Unit tests added in part2tests.cpp.

## 💥 Shots
Represents a shot at a specific GridPosition.

Enum Shot::Impact

- NONE

- HIT

- SUNKEN

OwnGrid::takeBlow

- Miss → NONE

- Hit → HIT

- Final hit (ship sunk) → SUNKEN

- Tracks all previous shots.

OpponentGrid::shotResult

- Shot positions

- Shot impact

- Sunken ships

Detects whether a ship has been sunk based on accumulated hits.

Updated Display

- ^ → Miss

- O → Hit

- # → Ship

- ~ → Water

## 🧪 **Testing**

- Provided base tests must pass

- part2tests.cpp → arrangement rule tests

- part3tests.cpp → shot logic tests

- Tests document expected behavior

## 📚 **Documentation**

- Complete Doxygen documentation

- HTML documentation generated via .doxyfile

- Includes explanation of:

- Class responsibilities

- Algorithms

- Design decisions

## 🎯 **Learning Objectives**

- Immutable objects

- STL containers (set, map, vector)

- Operator overloading

- Set operations

- Composition

- Defensive validation

- Test-driven understanding

- Clean separation of model and view

## 🚀 Optional Extension

- Interactive CLI game

- AI opponent

- GUI version (Qt)

- Save/Load functionality
