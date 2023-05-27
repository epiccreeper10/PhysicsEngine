#include "Test.h"
#include "CircleShape.h"
#include "Graphics.h"


Test::Test()
{
	//
}

Test::~Test()
{
	if (m_time) delete m_time;
	if (m_input) delete m_input;
	if (m_graphics) delete m_graphics;
	if (m_world) delete m_world;
}

void Test::Initialize()
{
	m_graphics = new Graphics();
	m_graphics->CreateWindow("Physics", 800, 600);
	m_input = new Input();
	m_time = new Time();
	m_time->SetFixedDeltaTime(1.0f / 60.0f);
	m_world = new World();

}

void Test::Run()
{
	Update();
	m_fixedTime += m_time->TimeDelta();
	while (m_fixedTime > m_time->GetFixedDeltaTime())
	{
		FixedUpdate();
		m_fixedTime -= m_time->GetFixedDeltaTime();
	}

	Prerender();
	Render();
	Postrender();
	//m_graphics->DrawCircle(m_input->GetMousePosition(), 30, {randomf(), randomf(), randomf(), 1});
}

void Test::Update()
{
	UpdateEvents();

	m_input->Update();
	m_time->Update();
	//m_world->Step(m_time->TimeDelta());
}

void Test::Prerender()
{
	m_graphics->SetColor({ 0, 0, 0, 1 });
	m_graphics->Clear();
}

void Test::Postrender()
{
	m_graphics->Present();
}

void Test::UpdateEvents()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
		{
			m_quit = true;
		}
		if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)
		{
			m_quit = true;
		}
	}
}
