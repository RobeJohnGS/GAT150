#include <iostream>
#include "Engine.h"

int main()
{


	JREngine::InitializeMemory();

	JREngine::SetFilePath("../Assets");

	JREngine::renderer_g.Initialize();
	JREngine::inputSystem_g.Initialize();
	JREngine::audioSystem_g.Initialize();

	JREngine::renderer_g.CreateWindow("Engine", 800, 600); // Creates the window with parameters
	JREngine::renderer_g.SetClearColor(JREngine::Color{ 0, 0, 0, 255 });

	std::shared_ptr<JREngine::Texture> texture = std::make_shared<JREngine::Texture>();
	texture->Create(JREngine::renderer_g, "jack-frost.bmp");
	float angle = 0;

	bool quit = false;
	while (!quit)
	{
		// Update
		JREngine::time_g.Tick();
		JREngine::inputSystem_g.Update();
		JREngine::audioSystem_g.Update();

		//cock
		if (JREngine::inputSystem_g.onKeyEsc(JREngine::InputSystem::KeyState::Pressed)) {
			quit = true;
		}

		//angle += 1;

		// Render
		JREngine::renderer_g.BeginFrame();

		JREngine::renderer_g.Draw(texture, { 400, 300 }, angle, { 0.5f, 0.5f }, { 0.5f, 0.5f });

		JREngine::renderer_g.EndFrame();
	}

	JREngine::audioSystem_g.Shutdown();
	JREngine::renderer_g.Shutdown();
}