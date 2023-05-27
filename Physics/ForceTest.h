#pragma once
#include "Test.h"
#include "AreaForce.h"
#include "PointForce.h"
#include "DragForce.h"
#include "GravityField.h"

class ForceTest : public Test {
public:
	void Initialize() override;

	// Inherited via Test
	void Update() override;
	void FixedUpdate() override;
	void Render() override;
};