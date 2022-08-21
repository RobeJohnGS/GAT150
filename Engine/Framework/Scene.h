#pragma once
#include "Actor.h"
#include <list>
#include <memory>

namespace JREngine {
	//Forward Declaration
	/*class Actor;
	class Renderer;*/

	class Scene : public ISerializable {
	//Implement all pure virtuals
	public:
		Scene() = default;
		~Scene() = default;

		void Update();
		void Draw(Renderer& renderer);
		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson::Value& value) override;

		void Add(std::unique_ptr<Actor> actor);

		template<typename T>
		T* GetActor();

	private:
		std::list<std::unique_ptr<Actor>> m_actors;
		
	};

	template<typename T>
	inline T* Scene::GetActor() {
		for (auto& actor : m_actors) {
			T* result = dynamic_cast<T*>(actor.get());
			if (result) {
				return result;
			}
		}

		return nullptr;
	}
}