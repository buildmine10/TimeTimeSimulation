#pragma once

//A ledger of everything in space
//This includes the state of the player, any physiscs object, etc.
class WorldState
{
private:

public:
	bool operator==(const WorldState& other) const;

	WorldState update(double deltaTime) const;
};

