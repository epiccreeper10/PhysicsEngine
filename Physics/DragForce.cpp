#include "DragForce.h"


void DragForce::Apply(std::vector<class Body*> bodies)
{
    for (auto body : bodies)
    {
        if (!m_body->Intersects(body)) continue;
        float f = 0.5f * glm::length2(body->velocity) * m_drag;
        glm::vec2 force = glm::normalize(body->velocity);
        body->applyForce(force * -f);
    }
}
