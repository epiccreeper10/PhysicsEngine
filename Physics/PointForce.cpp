#include "PointForce.h"

void PointForce::Apply(std::vector<class Body*> bodies)
{
	for (auto body : bodies)
	{
		if (!m_body->Intersects(body)) continue;
		glm::vec2 direction = body->position - m_body->position;
		glm::vec2 force = glm::normalize(direction);
		body->applyForce(force * m_forceMagnitude);
	}
}
