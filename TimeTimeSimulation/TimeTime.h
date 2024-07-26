#pragma once

#include "TimeState.h"
#include "WorldState.h"

//This is time time
//It manages the simulation
//	Only updating the time points that need to be updated
class TimeTime
{
private:
	TimeState previous;
	TimeState current;
	TimeState next;


	double deltaTime = 1.0 / 20;//The amount of time between worldStates in the TimeState

public:

	TimeTime(double deltaTime = 1.0 / 20, double maxTime = 1);

	void initialize(const WorldState& initial);

	void update();

	WorldState& at(const std::size_t& i);
};

