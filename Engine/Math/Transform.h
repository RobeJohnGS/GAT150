#pragma once
#include "Vector2.h"
#include "Mat2_2.h"
#include "MathUtils.h"

namespace JREngine
{
	struct Transform
	{
		Vector2 position;
		float rotation{ 0 };
		Vector2 scale{ 1, 1 };

		operator Matrix2x2 () const {
			Matrix2x2 mxScale = Matrix2x2::CreateScale(scale);
			Matrix2x2 mxRotation = Matrix2x2::CreateRotation(Math::DegToRad(rotation));

			return { mxScale * mxRotation };
		}
	};
}