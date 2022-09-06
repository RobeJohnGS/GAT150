#pragma once
#include "Serialization/JSON.h"

#include "Core/Memory.h"
#include "Core/File.h"
#include "Core/Time.h"
#include "Core/Logger.h"

#include "Math/MathUtils.h"
#include "Math/Random.h"

#include "Framework/Scene.h"
#include "Framework/Game.h"
#include "Framework/Factory.h"
#include "Framework/Singleton.h"
#include "Framework/EventManager.h"

#include "Components/PlayerComponent.h"
#include "Components/AudioComponent.h"
#include "Components/ModelComponent.h"
#include "Components/PhysicsComponent.h"
#include "Components/RBPhysicsComponent.h"
#include "Components/CollisionComponent.h"
#include "Components/SpriteComponent.h"
#include "Components/SpriteAnimComponent.h"
#include "Components/TextComponent.h"
#include "Components/TilemapComponent.h"
#include "Components/CharacterComponent.h"
#include "Components/CameraComponent.h"

#include "Input/InputSystem.h"

#include "Audio/AudioSystem.h"

#include "Resource/ResourceManager.h"

#include "Physics/PhysicsSystem.h"

#include "Renderer/Renderer.h"
#include "Renderer/Text.h"
#include "Renderer/Font.h"
#include "Renderer/Texture.h"
#include "Renderer/Model.h"

#include <memory>
#include <vector>
#include <list>
#include <variant>

namespace JREngine
{
	extern Renderer renderer_g;
	extern InputSystem inputSystem_g;
	extern AudioSystem audioSystem_g;
	extern Time time_g;
	extern ResourceManager resourceManager_g;
	extern PhysicsSystem physicsSystem_g;
	extern EventManager eventManager_g;

	



	class Engine : public Singleton<Engine>{
	public:
		void Register();
	};
}
