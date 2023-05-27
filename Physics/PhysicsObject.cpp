#include "PhysicsObject.h"
#include <glm/gtc/type_precision.hpp>

PhysicsObject::~PhysicsObject()
{
    delete m_body;
    delete m_shape;
}

void PhysicsObject::Step(float dt)
{
    m_body->Step(dt);
}

void PhysicsObject::Draw(Graphics* m_graphics)
{
    // Get the position and angle of the body
    glm::ivec2 position = m_body->position;

    // Draw the shape at the correct position and orientation
    m_shape->Draw(m_graphics, position);
}
