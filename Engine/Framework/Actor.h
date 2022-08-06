#pragma once
#include "GameObject.h"
#include "Component.h"
#include <vector>

namespace JREngine
{
	class Scene;
	class Renderer;

	class Actor : public GameObject
	{
	public:
		Actor() = default;
		//Actor(const Model& model, const Transform& transform) : GameObject{ transform }, m_model{ model }  {}
		Actor(const Transform& transform) : transform_{ transform } {}

		virtual void Update() override {}
		virtual void Draw(Renderer& renderer);

		void AddComponent(std::unique_ptr<Component> component);

		virtual void OnCollision(Actor* other){}
		
		float GetRadius() {
			//return m_model.GetRadius() * std::max(transform_.scale.x, transform_.scale.y);
			return 0;
		}
		
		std::string& GetTag() {
			return m_tag;
		}

		friend class Scene;

		bool m_destroy = false;

		Transform transform_;
	protected:
		std::string m_tag;

		Vector2 m_velocity;
		float m_damping = 1;

		Scene* m_scene = nullptr;

		std::vector<std::unique_ptr<Component>> m_components;

	};
}