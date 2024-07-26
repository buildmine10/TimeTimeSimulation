#pragma once

//A ledger of everything in space
//This includes the state of the player, any physiscs object, etc.

//Make a class that inherits from this class
class WorldState
{
private:

public:
	virtual bool operator==(const WorldState& other) const;

	virtual WorldState update(double deltaTime) const;
};

