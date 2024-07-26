#pragma once
#include <vector>

#include "WorldState.h"

class TimeTime;

//A ledger of every WorldState at every point in time at a single point in time time
class TimeState
{
private:
	friend class TimeTime;
	std::vector<WorldState> states;

	double deltaTime = 1.0 / 20;//The amount of time between updates.

public:
	TimeState(double deltaTime = 1.0 / 20, double maxTime = 1);


	void initialize(const WorldState& state);

	WorldState& at(const std::size_t& i);
};

