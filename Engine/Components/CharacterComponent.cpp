#include "CharacterComponent.h"
#include "Engine.h"

namespace JREngine {
	CharacterComponent::~CharacterComponent(){
		eventManager_g.Unsubscribe("EVENT_DAMAGE", m_owner);
	}

	void CharacterComponent::Initialize(){
		eventManager_g.Subscribe("EVENT_DAMAGE", std::bind(&CharacterComponent::OnNotify, this, std::placeholders::_1), m_owner);

		auto component = m_owner->GetComponent<CollisionComponent>();
		if (component) {
			component->SetCollisionEnter(std::bind(&CharacterComponent::OnCollisionEnter, this, std::placeholders::_1));
			component->SetCollisionExit(std::bind(&CharacterComponent::OnCollisionExit, this, std::placeholders::_1));
		}
	}

	bool CharacterComponent::Write(const rapidjson::Value& value) const{
		return true;
	}

	bool CharacterComponent::Read(const rapidjson::Value& value){
		READ_DATA(value, health);
		READ_DATA(value, damage);
		READ_DATA(value, speed);
		return true;
	}
}