#include "JRGame.h"
#include "Engine.h"
#include <iostream>

int main() {
	JREngine::InitializeMemory();
	JREngine::SetFilePath("../Assets");


	JREngine::renderer_g.Initialize();
	JREngine::inputSystem_g.Initialize();
	JREngine::audioSystem_g.Initialize();
	JREngine::resourceManager_g.Initialize();
	JREngine::physicsSystem_g.Initialize();
	JREngine::eventManager_g.Initialize();

	JREngine::Engine::Instance().Register();

	JREngine::renderer_g.CreateWindow("Game", 800, 600);
	JREngine::renderer_g.SetClearColor(JREngine::Color{ 10, 0, 0, 255 });

	std::unique_ptr<JRGame> game = std::make_unique<JRGame>();
	game->Initialize();

	bool quit = false;
	while (!quit) {
		JREngine::time_g.Tick();
		JREngine::inputSystem_g.Update();
		JREngine::audioSystem_g.Update();
		JREngine::physicsSystem_g.Update();
		JREngine::eventManager_g.Update();

		if (JREngine::inputSystem_g.GetKeyDown(JREngine::key_esc)) {
			quit = true;
		}

		game->Update();

		JREngine::renderer_g.BeginFrame();
		game->Draw(JREngine::renderer_g);

		JREngine::renderer_g.EndFrame();
	}

	game->Shutdown();
	game.reset();

	JREngine::Factory::Instance().Shutdown();

	JREngine::physicsSystem_g.Shutdown();
	JREngine::resourceManager_g.Shutdown();
	JREngine::inputSystem_g.Shutdown();
	JREngine::audioSystem_g.Shutdown();
	JREngine::renderer_g.Shutdown();
	JREngine::physicsSystem_g.Shutdown();
}