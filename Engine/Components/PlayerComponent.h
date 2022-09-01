//#pragma once
//#include "Framework/Component.h"
//#include "Physics/Collision.h"
//#include "CharacterComponent.h"
//
//namespace JREngine {
//	class PlayerComponent : CharacterComponent {
//	public:
//		PlayerComponent() = default;
//
//		CLASS_DECLARATION(PlayerComponent)
//
//		void Initialize() override;
//		void Update() override;
//
//		virtual void OnNotify(const Event& event) override;
//		virtual void OnCollisionEnter(Actor* other) override;
//		virtual void OnCollisionExit(Actor* other) override;
//
//		virtual bool Write(const rapidjson::Value& value) const override;
//		virtual bool Read(const rapidjson::Value& value) override;
//
//		//variables
//		float jump = 300;
//
//		int m_groundCount = 0;
//	};
//}
//titties

#pragma once
#include "Framework/Component.h"
#include "Physics/Collision.h"
#include "CharacterComponent.h"

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
		
		//variables
		float speed = 0.0f;

		float jump = 300;

		int m_groundCount = 0;
	};
}