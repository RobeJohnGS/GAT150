#pragma once
#include "Framework/Component.h"
#include "Physics/Collision.h"

namespace JREngine {
	class Actor;

	class PlayerComponent : public Component, public ICollision {
	public:
		PlayerComponent() = default;
		~PlayerComponent() = default;

		CLASS_DECLARATION(PlayerComponent)

		void Initialize() override;
		void Update() override;

		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson::Value& value) override;

		// Inherited via ICollision
		virtual void OnCollisionEnter(Actor* other) override;
		virtual void OnCollisionExit(Actor* other) override;
		
		float speed = 0.0f;
	};
}