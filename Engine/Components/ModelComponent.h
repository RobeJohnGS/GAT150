#pragma once
#include "RendererComponent.h"

namespace JREngine {
	class Model;

	class ModelComponent : public RendererComponent {
	public:
		virtual void Update() override;
		virtual void Draw(Renderer& renderer) override;

		std::shared_ptr<Model> m_model;
	};
}