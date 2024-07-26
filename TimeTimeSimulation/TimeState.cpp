#include "TimeState.h"
#include <cmath>


TimeState::TimeState(double deltaTime, double maxTime)
{
	this->deltaTime = deltaTime;

	this->states.resize(std::ceil(maxTime / deltaTime));
}

void TimeState::initialize(const WorldState& state)
{
	std::size_t size = this->states.size();

	this->states.clear();

	this->states.resize(size, state);
}

WorldState& TimeState::at(const std::size_t& i)
{
	return this->states.at(i);
}
