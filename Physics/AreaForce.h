#pragma once
#include "ForceGenerator.h"
#include "Body.h"
#include "glm/glm.hpp"
#include "glm/ext.hpp"



class AreaForce : public ForceGenerator
{
public:
    AreaForce(Body* body, float forceMagnitude, float angle) :
        m_body(body),
        m_forceMagnitude(forceMagnitude),
        m_angle(angle)
    {}
    void Apply(std::vector<class Body*> bodies) override;

private:
    Body* m_body{ nullptr };
    float m_forceMagnitude{ 1 };
    float m_angle{ 0 };
};