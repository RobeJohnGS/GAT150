#include "PlayerComponent.h"
#include "Engine.h"
#include <iostream>

namespace JREngine {
	void PlayerComponent::Update() {
		if (JREngine::inputSystem_g.GetKeyState(key_A) == JREngine::InputSystem::Held) {
			m_owner->transform_.position += {-10, 0};
		}
	}
}
