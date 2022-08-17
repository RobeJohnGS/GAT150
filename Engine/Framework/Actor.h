#pragma once
#include "GameObject.h"
#include "Component.h"
#include "Math/Transform.h"
#include <vector>

namespace JREngine
{
	class Scene;
	class Renderer;

	class Actor : public GameObject/*, public ISeriablizable*/{
	//implement pure virtuals then move them below update
	public:
		Actor() = default;
		//Actor(const Model& model, const Transform& transform) : GameObject{ transform }, m_model{ model }  {}
		Actor(const Transform& transform) : transform_{ transform } {}

		virtual void Update() override;
		virtual void Draw(Renderer& renderer);

		//Add child broken
		//void AddChild(std::unique_ptr<Actor> child);
		void AddComponent(std::unique_ptr<Component> component);
		template<typename T>
		T* GetComponent();

		virtual void OnCollision(Actor* other){}
		
		float GetRadius() {
			//return m_model.GetRadius() * std::max(transform_.scale.x, transform_.scale.y);
			return 0;
		}
		
		const std::string& GetTag() {
			return tag;
		}
		void SetTag(const std::string& tag) {
			this->tag = tag;
		}

		/*const std::string& GetName() {
			return name;
		}
		void SetTag(const std::string& name) {
			this->name = name;
		}*/

		friend class Scene;
		friend class Component;

		bool m_destroy = false;

		Transform transform_;
	protected:
		//std::string name;
		std::string tag;

		Vector2 m_velocity;
		float m_damping = 1;

		Scene* m_scene = nullptr;

		Actor* m_parent = nullptr;

		std::vector<std::unique_ptr<Component>> m_components;
		std::vector<std::unique_ptr<Actor>> m_children;

	};

	template<typename T>
	inline T* Actor::GetComponent()
	{
		for (auto& components : m_components) {
			T* result = dynamic_cast<T*>(components.get());
			if (result) {
				return result;
			}
		}

		return nullptr;
	}
}