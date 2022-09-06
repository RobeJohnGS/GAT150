#include "PlayerComponent.h"
#include "Engine.h"
#include "Framework/Game.h"
#include <iostream>

namespace JREngine {
	void PlayerComponent::Initialize(){
		CharacterComponent::Initialize();
	}

	void PlayerComponent::Update() {
		Vector2 direction = Vector2::zero;
		if (JREngine::inputSystem_g.GetKeyState(key_A) == JREngine::InputSystem::Held && canMove) {
			direction = Vector2::left;
		}

		if (JREngine::inputSystem_g.GetKeyState(key_D) == JREngine::InputSystem::Held && canMove) {
			direction = Vector2::right;
		}

		Vector2 velocity;
		auto pComponent = m_owner->GetComponent<PhysicsComponent>();
		if (pComponent) {
			float multiplier = (m_groundCount > 0) ? 1 : 0.2f;

			pComponent->ApplyForce(direction * speed);
			velocity = pComponent->velocity;
		}

		auto animComponent = m_owner->GetComponent<SpriteAnimComponent>();
		if (animComponent) {
			if (velocity.x != 0) {
				animComponent->SetFlipH(velocity.x < 0);
			}
			
			if (std::fabs(velocity.x) > 0) {
				animComponent->SetSequence("run");
			} else {
				animComponent->SetSequence("idle");
			}
		}

		if (m_groundCount > 0 && inputSystem_g.GetKeyState(key_space) == InputSystem::KeyState::Pressed && canMove) {
			JREngine::audioSystem_g.PlayAudio("jump");
			auto component = m_owner->GetComponent<PhysicsComponent>();
			if (component) {
				component->ApplyForce(Vector2::up * jump);
			}
		}

		auto camera = m_owner->GetScene()->GetActorFromName("Camera");
		if (camera)
		{
			camera->m_transform.position = Math::Lerp(camera->m_transform.position, m_owner->m_transform.position, 2 * time_g.deltaTime);
		}
	}

	bool PlayerComponent::Write(const rapidjson::Value& value) const
	{
		return true;
	}

	bool PlayerComponent::Read(const rapidjson::Value& value){
		CharacterComponent::Read(value);
		READ_DATA(value, jump);

		return true;
	}

	void PlayerComponent::OnNotify(const Event& event){
		if (event.name == "EVENT_DAMAGE") {
			health -= std::get<float>(event.data);
			if (health <= 0) {
				m_owner->SetDestroy();

				Event event;
				event.name = "EVENT_PLAYER_DEAD";

				eventManager_g.Notify(event);
			}
		}
	}

	void PlayerComponent::OnCollisionEnter(Actor* other){
		if (other->GetName() == "Coin") {
			Event event;
			event.name = "EVENT_ADD_POINTS";
			event.data = 100;
			eventManager_g.Notify(event);

			other->SetDestroy();
		}

		if (other->GetTag() == "Enemy")
		{
			inBattle = true;
			canMove = false;
			Event event;
			event.name = "EVENT_DAMAGE";
			event.data = damage;
			event.reciever = other;

			eventManager_g.Notify(event);
			other->SetDestroy();
		}

		if (other->GetTag() == "Ground")
		{
			m_groundCount++;
		}

		if (other->GetTag() == "Bounce")
		{
			auto component = m_owner->GetComponent<PhysicsComponent>();
			if (component)
			{
				component->ApplyForce(Vector2::up * 80);
			}
			m_groundCount++;
		}
	}

	void PlayerComponent::OnCollisionExit(Actor* other){
		if (other->GetTag() == "Ground") {
			m_groundCount--;
		}

		if (other->GetTag() == "Bounce") {
			m_groundCount--;
		}

		if (other->GetTag() == "Enemy") {
			inBattle = false;
			canMove = true;
			other->SetActive(false);
			other->SetDestroy(); 
		}
	}
}
