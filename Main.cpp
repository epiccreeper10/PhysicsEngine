#include "../PhysicsMain/Tests/Test.h"
#include "../PhysicsMain/Tests/ForceTest.h"
#include "../PhysicsMain/Tests/ParticleTest.h"
#include "../PhysicsMain/Tests/CollisionTest.h"
#include "../PhysicsMain/Tests/JointTest.h"

int main(int argc, char* argv[])
{
	Test* test = new JointTest();
	test->Initialize();
	while (!test->IsQuit()) { test->Run(); }
	delete test;

	return 0;
}