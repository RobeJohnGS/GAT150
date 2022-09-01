#include "CameraComponent.h"
#include "Framework/Actor.h"
#include "Engine.h"

namespace JREngine {

	void CameraComponent::Initialize(){
		SetViewport(viewport_size);
	}

	void CameraComponent::Update(){
		Matrix3x3 mxTranslation = Matrix3x3::CreateTranslation(-m_owner->m_transform.position);
		Matrix3x3 mxRotation = Matrix3x3::CreateRotation(-Math::DegToRad(m_owner->m_transform.rotation));

		m_view = mxTranslation * mxRotation;

		//titties
		//renderer_g.SetViewMatrix(m_view);
	}

	void CameraComponent::SetViewport(const Vector2& size){
		Matrix3x3 mxTranslation = Matrix3x3::CreateTranslation(size * 0.5f);

		m_viewport = mxTranslation;
		//titties
		//renderer_g.SetViewMatrix(m_viewport);
	}

	bool CameraComponent::Write(const rapidjson::Value& value) const
	{
		return true;
	}

	bool CameraComponent::Read(const rapidjson::Value& value)
	{
		READ_DATA(value, viewport_size);
		return true;
	}
}