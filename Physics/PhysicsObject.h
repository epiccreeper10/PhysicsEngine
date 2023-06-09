#pragma once
#include "Body.h"
#include "Shape.h"

class PhysicsObject
{
public:
	Body* GetBody() { return m_body; }
	Shape* GetShape() { return m_shape; }
	PhysicsObject(Body* body, Shape* shape) : m_body{ body }, m_shape{ shape } {}
	~PhysicsObject();

	void Step(float dt);
	void Draw(class Graphics* m_graphics);


protected:
	Body* m_body{ nullptr };
	Shape* m_shape{ nullptr };
};

