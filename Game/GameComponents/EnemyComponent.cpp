#include "EnemyComponent.h"
#include "../Game/JRGame.h"
#include "Engine.h"
#include <iostream>

void EnemyComponent::Initialize(){
	CharacterComponent::Initialize();
}

void EnemyComponent::Update(){
	auto actor = m_owner->GetScene()->GetActorFromName("Player");
	if (actor) {
		JREngine::Vector2 direction = actor->m_transform.position - m_owner->m_transform.position;
		JREngine::Vector2 force = direction.Normalized() * speed;

		auto component = m_owner->GetComponent<JREngine::PhysicsComponent>();
		if (component) {
			component->ApplyForce(force);
		}
	}
}

void EnemyComponent::OnCollisionEnter(JREngine::Actor* other){
	if (other->GetTag() == "Player") {
		JREngine::Event event;
		event.name = "EVENT_DAMAGE";
		event.data = damage;
		event.reciever = other;

		JREngine::eventManager_g.Notify(event);
	}
}

void EnemyComponent::OnCollisionExit(JREngine::Actor* other){

}

void EnemyComponent::OnNotify(const JREngine::Event& event){
	if (event.name == "EVENT_DAMAGE") {
		health -= std::get<float>(event.data);
		if (health <= 0) {
			m_owner->SetDestroy();
		}
	}
}

bool EnemyComponent::Write(const rapidjson::Value& value) const
{
	return true;
}

bool EnemyComponent::Read(const rapidjson::Value& value)
{
	CharacterComponent::Read(value);
	return true;
}
