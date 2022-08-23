#pragma once
#include "Vector2.h"
#include "Mat2_2.h"
#include "Mat3_3.h"
#include "MathUtils.h"
#include "Serialization/Serializable.h"

namespace JREngine
{
	struct Transform : public ISerializable{
		//create all virtual funtions then move read and write at the top above update;
		Vector2 position;
		float rotation{ 0 };
		Vector2 scale{ 1, 1 };

		Matrix3x3 matrix;

		// Inherited via ISerializable
		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson::Value& value) override;

		//Broken which makes it so I can't set in main
		/*Transform(const Vector2& position, float rotation, const Vector2& scale) :
			position{ position },
			rotation{ rotation },
			scale{ scale }
		{}*/

		void Update() {
			Matrix3x3 mxScale = Matrix3x3::CreateScale(scale);
			Matrix3x3 mxRotation = Matrix3x3::CreateRotation(Math::DegToRad(rotation));
			Matrix3x3 mxTranslation = Matrix3x3::CreateTranslation(position);

			//TRS
			matrix = { mxTranslation * mxRotation * mxScale };
		}

		void Update(const Matrix3x3& parent) {
			Matrix3x3 mxScale = Matrix3x3::CreateScale(scale);
			Matrix3x3 mxRotation = Matrix3x3::CreateRotation(Math::DegToRad(rotation));
			Matrix3x3 mxTranslation = Matrix3x3::CreateTranslation(position);

			//TRS
			matrix = { mxTranslation * mxRotation * mxScale };
			matrix = parent * matrix;
		}

		operator Matrix2x2 () const {
			Matrix2x2 mxScale = Matrix2x2::CreateScale(scale);
			Matrix2x2 mxRotation = Matrix2x2::CreateRotation(Math::DegToRad(rotation));

			return { mxScale * mxRotation };
		}

		operator Matrix3x3 () const {
			Matrix3x3 mxScale = Matrix3x3::CreateScale(scale);
			Matrix3x3 mxRotation = Matrix3x3::CreateRotation(Math::DegToRad(rotation));
			Matrix3x3 mxTranslation = Matrix3x3::CreateTranslation(position);

			return { mxTranslation * mxRotation * mxScale };
		}
	};
}