#pragma once
#include "Framework/Component.h"
#include "Math/Mat3_3.h"

namespace JREngine {
	class CameraComponent : public Component {
	public:
		CLASS_DECLARATION(CameraComponent)

		virtual void Initialize() override;
		virtual void Update() override;

		const Matrix3x3& GetView() {
			return m_view;
		}

		void SetViewPort(const Vector2& size);
		const Matrix3x3& GetViewport() {
			return m_viewport;
		}

		// Inherited via Component
		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson::Value& value) override;

		//variables
		Vector2 viewport_size;

		Matrix3x3 m_view;
		Matrix3x3 m_viewport;
	};
}