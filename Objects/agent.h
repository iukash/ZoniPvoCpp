#ifndef AGENT_H
#define AGENT_H

#include "point.h"

class Agent : public Point
{
public:
    Agent(Point pnt);
    Agent();
    void SetPosition(Point pnt);
};

#endif // AGENT_H
