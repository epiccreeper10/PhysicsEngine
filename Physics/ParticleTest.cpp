#include "ParticleTest.h"
#include "CircleShape.h"
#include "Body.h"
#include <iostream>

void ParticleTest::Initialize()
{
	Test::Initialize();
}

void ParticleTest::Update()
{
	Test::Update();
	if (m_input->GetMouseButton(0))
	{
		//std::cout << "THE MOUSE IS WORKING\n";
		glm::vec2 velocity = randomUnitCircle() * randomf(10, 50);
		auto po = new Body(new CircleShape(randomf(3.0f, 10.0f), randomColor()), m_input->GetMousePosition(), velocity);
		po->damping = 0.5f;
		m_world->AddBody(po);
	}
}

void ParticleTest::FixedUpdate()
{
	m_world->Step(m_time->GetFixedDeltaTime());
}

void ParticleTest::Render()
{
	//m_graphics->DrawCircle(m_input->GetMousePosition(), 30, { randomf(), randomf(), randomf(), 1 });

	m_world->Draw(m_graphics);
}
