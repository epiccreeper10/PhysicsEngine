#include "../Physics/Tests/Test.h"
#include "../Physics/Tests/ForceTest.h"
#include "../Physics/Tests/ParticleTest.h"
#include "../Physics/Tests/CollisionTest.h"
#include "../Physics/Tests/JointTest.h"

int main(int argc, char* argv[])
{
	Test* test = new JointTest();
	test->Initialize();
	while (!test->IsQuit()) { test->Run(); }
	delete test;

	return 0;
}