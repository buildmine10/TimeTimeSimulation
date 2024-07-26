#include "WorldState.h"

bool WorldState::operator==(const WorldState& other) const
{
    return false;
}

WorldState WorldState::update(double deltaTime) const
{
    return *this;
}
