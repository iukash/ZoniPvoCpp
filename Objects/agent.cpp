#include "agent.h"

Agent::Agent(Point pnt):Point()
{
    X = pnt.X;
    Y = pnt.Y;
    Z = pnt.Z;
}

Agent::Agent():Point()
{
    X = 0;
    Y = 0;
    Z = 0;
}

void Agent::SetPosition(Point pnt)
{
    X = pnt.X;
    Y = pnt.Y;
    Z = pnt.Z;
}
