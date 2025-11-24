/**
 * @file Shot.h
 * @brief Defines the `Shot` class and the related `Impact` enumeration for
 * representing a shot in a grid-based game.
 *
 * This header file declares the `Shot` class, which is used to represent a shot
 * fired at a specific grid position. The `Shot` class also contains an
 * enumeration `Impact` to indicate the result of the shot, such as whether it
 * hit the target, missed, or sunk the ship.
 *
 * @author ngocn
 * @date Dec 19, 2024
 */
#include "GridPosition.h"
#ifndef SHOT_H_
#define SHOT_H_

/**
 * @class Shot
 * @brief Represents a shot fired at a specific position on a grid.
 *
 * A `Shot` object holds the target grid position where a shot is fired.
 * The impact of the shot (whether it is a miss, hit, or a sunken ship) is
 * represented using the `Impact` enumeration.
 */
class Shot
{
private:
	GridPosition targetPosition; /** The position on the grid where the shot
										was fired. */

public:
    /**
     * @brief Constructs a `Shot` object with a specified target position.
     * @param targetPosition The grid position where the shot is fired.
     */
	Shot(GridPosition targetPosition);

    /**
     * @brief Gets the target position of the shot.
     * @return The target grid position.
     */
	GridPosition getTargetPosition() const;

    /**
     * @enum Impact
     * @brief Represents the result of a shot.
     *
     * The `Impact` enum defines the possible outcomes of a shot.
     */
	enum Impact {NONE,HIT, SUNKEN};

};
#endif /* SHOT_H_ */
