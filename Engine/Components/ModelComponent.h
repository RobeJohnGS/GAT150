#pragma once
#include "RendererComponent.h"

namespace JREngine {
	class Model;

	class ModelComponent : public RendererComponent {
	public:
		CLASS_DECLARATION(ModelComponent)

		virtual void Update() override;

		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson::Value& value) override;
		
		virtual void Draw(Renderer& renderer) override;
		
		std::shared_ptr<Model> m_model;
	};
}