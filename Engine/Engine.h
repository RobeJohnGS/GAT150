#pragma once
#include "Serialization/JSON.h"

#include "Core/Memory.h"
#include "Core/File.h"
#include "Core/Time.h"

#include "Math/MathUtils.h"
#include "Math/Random.h"

#include "Framework/GameObject.h"
#include "Framework/Factory.h"

#include "Input/InputSystem.h"

#include "Renderer/Renderer.h"
#include "Renderer/Model.h"
#include "Renderer/Text.h"
#include "Renderer/Font.h"
#include "Renderer/Texture.h"

#include "Framework/Singleton.h"

#include "Resource/ResourceManager.h"

#include "Framework/Scene.h"
#include "Framework/Game.h"

#include "Physics/PhysicsSystem.h"

#include "Components/PlayerComponent.h"
#include "Components/SpriteComponent.h"
#include "Components/ModelComponent.h"
#include "Components/AudioComponent.h"
#include "Components/PhysicsComponent.h"

#include "Audio/AudioSystem.h"

#include <memory>
#include <vector>
#include <list>


namespace JREngine
{
	extern InputSystem inputSystem_g;
	extern Renderer renderer_g;

	extern Time time_g;
	
	extern AudioSystem audioSystem_g;

	extern ResourceManager resourceManager_g;

	extern PhysicsSystem physicsSystem_g;

	class Engine : public Singleton<Engine>{
	public:
		void Register();
	};
}
