#include "ModelComponent.h"
#include "Renderer/Model.h"
#include "Framework/Actor.h"

namespace JREngine {
	void JREngine::ModelComponent::Update()
	{
		//
	}

	void JREngine::ModelComponent::Draw(Renderer& renderer)
	{
		m_model->Draw(renderer, m_owner->transform_);
	}

}
