#include <iostream>
#include <SDL.h>
#include <glm/glm.hpp>
#include "Graphics.h"
#include "Random.h"
#include "Test.h"
#include "ParticleTest.h"
#include "ForceTest.h"
#include "JointTest.h"
#undef main


using namespace std;

int main() {
	
	Test* test = new ForceTest();

	test->Initialize();


	while (!test->IsQuit())test->Run();
	delete test;
	

	return 0;
}

