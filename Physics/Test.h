#pragma once
#include "Graphics.h"
#include "Input.h"
#include "Time.h"
#include "World.h"
#include "Random.h"

class Test
{
public:
	Test();
	~Test();

	virtual void Initialize();
	virtual void Run();
	virtual void Update();
	virtual void FixedUpdate() = 0;

	virtual void Prerender();
	virtual void Render() = 0;
	virtual void Postrender();

	bool IsQuit() { return m_quit; }

protected:
	void UpdateEvents();

protected:
	bool m_quit{ false };

	float m_fixedTime{ 0 };

	class Graphics* m_graphics{ nullptr };
	class Input* m_input{ nullptr };
	class Time* m_time{ nullptr };
	class World* m_world{ nullptr };
};
