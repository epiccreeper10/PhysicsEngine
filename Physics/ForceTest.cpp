#include "ForceTest.h"
#include "CircleShape.h"
#include <iostream>

//#define POINT_FORCE
//#define AREA_FORCE
//#define DRAG_FORCE

void ForceTest::Initialize()
{
	Test::Initialize();

	/*auto forceGenerator = new GravityField(400);
	m_world->AddForceGen(forceGenerator);*/

#if defined(POINT_FORCE)
	auto body = new Body(new CircleShape(200, { 1, 1, 1, 0.2f }), { 400, 300 }, { 0, 0 }, 0, Body::Static);
	ForceGenerator* forceGenerator = new PointForce(body, 2000);
	m_world->AddForceGen(forceGenerator);
#elif defined(AREA_FORCE)
	auto body = new Body(new CircleShape(200, { 1, 1, 1, 0.2f }), { 400, 300 }, { 0, 0 }, 0, Body::Static);
	ForceGenerator* forceGenerator = new AreaForce(body, 2000, -90);
	m_world->AddForceGen(forceGenerator);
#elif defined(DRAG_FORCE)
	auto body = new Body(new CircleShape(200, { 1, 1, 1, 0.2f }), { 400, 300 }, { 0, 0 }, 0, Body::Static);
	ForceGenerator* forceGenerator = new DragForce(body, 0.5f);
	m_world->AddForceGen(forceGenerator);
#endif

}

void ForceTest::Update()
{
	Test::Update();
	if (m_input->GetMouseButton(0))
	{
		float size = randomf(3.0f, 10.0f);
		glm::vec2 velocity = randomUnitCircle() * randomf(10, 50);
		auto po = new Body(new CircleShape(size, randomColor()), m_input->GetMousePosition(), velocity, size * 2);
		po->damping = 0.5f;
		po->gravityScale = 1;
		m_world->AddBody(po);
	}
}

void ForceTest::FixedUpdate()
{
	m_world->Step(m_time->GetFixedDeltaTime());
}

void ForceTest::Render()
{
	m_graphics->DrawCircle(m_input->GetMousePosition(), 30, randomColor());

	m_world->Draw(m_graphics);
}
