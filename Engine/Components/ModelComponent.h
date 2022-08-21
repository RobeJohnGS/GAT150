#pragma once
#include "RendererComponent.h"
#include "Renderer/Model.h"

namespace JREngine {
	class Model;

	class ModelComponent : public RendererComponent {
	public:
		virtual void Update() override;
		virtual void Draw(Renderer& renderer) override;

		std::shared_ptr<Model> m_model;

		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson::Value& value) override;
	};
}