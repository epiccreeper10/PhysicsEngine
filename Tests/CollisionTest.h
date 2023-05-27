#pragma once
#include "Test.h"
#include "../Physics/Shape/CircleShape.h"
#include "../Physics/World.h"
#include "../Physics/Body.h"

class CollisionTest : public Test
{
public:
	void Initialize() override;

	void Update() override;
	virtual void FixedUpdate() override;
	virtual void Render() override;

protected:
	class Body* m_user{ nullptr };
	glm::vec4 color{ 0, 0, 1, 1, };
};