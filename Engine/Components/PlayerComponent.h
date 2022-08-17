#pragma once
#include "Framework/Component.h"

namespace JREngine {
	class PlayerComponent : public Component {
	public:
		PlayerComponent() = default;
		~PlayerComponent() = default;

		void Update() override;

		float speed = 0.0f;
	};
}