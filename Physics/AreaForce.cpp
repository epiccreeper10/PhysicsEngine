#include "AreaForce.h"


void AreaForce::Apply(std::vector<class Body*> bodies)
{
	for (auto body : bodies)
    {
        if (!m_body->Intersects(body)) continue; 

        glm::quat q = glm::angleAxis(glm::radians(m_angle), glm::vec3{ 0, 0, 1 });
        glm::vec2 force = glm::vec3{ m_forceMagnitude, 0, 0 } * q; 

        body->applyForce(force); 
    }

}
