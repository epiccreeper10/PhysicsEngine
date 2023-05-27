#pragma once
#include "ForceGenerator.h"
#include "Body.h"
#include "glm/gtx/norm.hpp"


class DragForce : public ForceGenerator
{
public:
    DragForce(class Body* body, float drag) :
        ForceGenerator{ body },
        m_drag{ drag }
    {}

    void Apply(std::vector<class Body*> bodies) override;

private:
    float m_drag{ 0 };
};