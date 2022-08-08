#pragma once
#include "GameObject.h"

namespace JREngine {
	class Actor;

	class Component : public GameObject {
	public:
		Component() = default;
		~Component() = default;

		friend class Actor;
	protected:
		Actor* m_owner = nullptr;
	};
}