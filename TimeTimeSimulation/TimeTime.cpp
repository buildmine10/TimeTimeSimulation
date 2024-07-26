#include "TimeTime.h"

TimeTime::TimeTime(double deltaTime, double maxTime)
{
	this->deltaTime = deltaTime;
	previous = TimeState(this->deltaTime, maxTime);
	current = TimeState(this->deltaTime, maxTime);
	next = TimeState(this->deltaTime, maxTime);


}

void TimeTime::initialize(const WorldState& initial)
{
	previous.initialize(initial);
	current.initialize(initial);
	next.initialize(initial);
}

void TimeTime::initialize(const TimeState& initial)
{
	previous = initial;
	current = initial;
	next = initial;
}

void TimeTime::update()
{
	//This can be safely multithreaded
	for (std::size_t i = 0; i < next.states.size(); i++) {
		//Check if an update needs to happen
		
		//If this is the first moment in time
		//Then it is not possible for the causally connection time point to change
		//If the causally connected time point has not changed
		if (i == 0 || current.states[i - 1] == previous.states[i - 1]) continue;


		//If the causally connected time point has changed
		//Then update that time point

		next.states[i] = current.states[i - 1].update(this->deltaTime);
	}


	previous = current;
	current = next;
}

WorldState& TimeTime::at(const std::size_t& i)
{
	return current.at(i);
}
