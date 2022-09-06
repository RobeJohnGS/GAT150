#pragma once
#include "GameObject.h"

namespace JREngine {
	class Actor;

	class Component : public GameObject , public ISerializable {
	//Go through each component header and impliment the virtual funtions
	public:
		Component() = default;

		virtual void Initialize() override {}
		virtual void Update() = 0;

		friend class Actor;

	protected:
		Actor* m_owner = nullptr;
	};
}