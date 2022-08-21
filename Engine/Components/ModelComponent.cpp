#include "ModelComponent.h"
#include "Renderer/Renderer.h"
#include "Engine.h"
#include "Resource/ResourceManager.h"
#include "Framework/Actor.h"

namespace JREngine {
	void JREngine::ModelComponent::Update()
	{
		//
	}

	void JREngine::ModelComponent::Draw(Renderer& renderer)
	{
		m_model->Draw(renderer, m_owner->m_transform);
	}

	bool ModelComponent::Write(const rapidjson::Value& value) const
	{
		return false;
	}

	bool ModelComponent::Read(const rapidjson::Value& value)
	{
		std::string model_name;
		READ_DATA(value, model_name);

		m_model = resourceManager_g.Get<Model>(model_name);
		return true;
	}
}
