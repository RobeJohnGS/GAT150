#include "ModelComponent.h"
#include "Renderer/Model.h"
#include "Framework/Actor.h"
#include "Engine.h"

namespace JREngine {
	void JREngine::ModelComponent::Update()
	{
		//
	}

	void JREngine::ModelComponent::Draw(Renderer& renderer)
	{
		m_model->Draw(renderer, m_owner->transform_);
	}

	/*
	* Under read
	std::string model_name;
	READ_DATA(value, model_name);

	m_model = resources_g.Get<Model>(model_name);
	*/

}
