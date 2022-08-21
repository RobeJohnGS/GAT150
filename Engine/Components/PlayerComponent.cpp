#include "PlayerComponent.h"
#include "Renderer/Text.h"
#include "Input/InputSystem.h"
#include "Engine.h"
#include "Framework/Actor.h"
#include "PhysicsComponent.h"
#include "AudioComponent.h"
#include <iostream>

namespace JREngine {
	void PlayerComponent::Update() {
		Vector2 direction = Vector2::zero;
		if (JREngine::inputSystem_g.GetKeyState(key_A) == JREngine::InputSystem::Held) {
			//m_owner->transform_.position += {-10, 0};
			//direction = Vector2::left;
			m_owner->m_transform.rotation -= 100 * time_g.deltaTime;
		}

		if (JREngine::inputSystem_g.GetKeyState(key_D) == JREngine::InputSystem::Held) {
			//m_owner->transform_.position += {10, 0};
			//direction = Vector2::right;
			m_owner->m_transform.rotation += 100 * time_g.deltaTime;
		}

		float thrust = 0;
		if (JREngine::inputSystem_g.GetKeyState(key_W) == JREngine::InputSystem::Held) {
			//m_owner->transform_.position += {0, -10};
			//thrust = speed;
			thrust = 100;
		}

		auto component = m_owner->GetComponent<PhysicsComponent>();
		if (component) {
			Vector2 force = Vector2::Rotate({ 1, 0 }, Math::DegToRad(m_owner->m_transform.rotation)) * thrust;
			component->ApplyForce(force);

			/*force = (Vector2{ 400, 300 } - m_owner->transform_.position).Normalized() * 60.0f;
			component->ApplyForce(force);*/
		}

		//m_owner->transform_.position += direction * 300 * time_g.deltaTime;

		if (inputSystem_g.GetKeyState(key_space) == InputSystem::Pressed) {
			auto component = m_owner->GetComponent<AudioComponent>();
			if (component) {
				component->Play();
			}
		}
	}

	bool PlayerComponent::Write(const rapidjson::Value& value) const
	{
		return true;
	}

	bool PlayerComponent::Read(const rapidjson::Value& value)
	{
		READ_DATA(value, speed);

		return true;
	}
}
