#pragma once
#include "Vector2.h"

namespace JREngine {
	struct Matrix2x2 {
		Vector2 rows[2];

		Matrix2x2() = default;
		Matrix2x2(const Vector2& row1, const Vector2& row2);

		Vector2 operator [] (size_t index) const { return rows[index]; }
		Vector2& operator [] (size_t index) { return rows[index]; }

		Vector2 operator * (const Vector2& v);
		Matrix2x2 operator * (const Matrix2x2& mx);

		static Matrix2x2 CreateScale(const Vector2& scale);
		static Matrix2x2 CreateScale(float scale);

		static Matrix2x2 CreateRotation(float rad);

		static const Matrix2x2 identity;
		static const Matrix2x2 zero;
		//bro, im so sleepy imma go "schmee-schmee-schmee-schmee-schmee-schmee-schmee" and i dont even care
	};

	inline Matrix2x2::Matrix2x2(const Vector2& row1, const Vector2& row2) {
		rows[0] = row1;
		rows[1] = row2;
	}

	inline Vector2 Matrix2x2::operator*(const Vector2& v){
		Vector2 result;
		result.x = v.x * rows[0][0] + v.y * rows[0][1];
		result.y = v.x * rows[1][0] + v.y * rows[1][1];

		return result;
	}

	inline Matrix2x2 Matrix2x2::operator*(const Matrix2x2& mx){
		Matrix2x2 result;
		result[0][0] = rows[0][0] * mx[0][0] + rows[0][1] * mx[1][0];
		result[0][1] = rows[0][1] * mx[1][0] + rows[1][1] * mx[1][1];
		result[1][0] = rows[0][0] * mx[0][0] + rows[0][1] * mx[1][0];
		result[1][1] = rows[0][0] * mx[0][0] + rows[0][1] * mx[1][0];

		return result;
	}

	inline Matrix2x2 Matrix2x2::CreateScale(const Vector2& scale){
		//non-uniform
		//sx 0
		//0 sy
		Matrix2x2 mx;
		mx[0] = { scale.x, 0.0f };
		mx[1] = { 0.0f, scale.y };

		return mx;
	}

	inline Matrix2x2 Matrix2x2::CreateScale(float scale){
		//uniform
		Matrix2x2 mx;
		mx[0] = { scale, 0.0f };
		mx[1] = { 0.0f, scale };

		return mx;
	}

	inline Matrix2x2 Matrix2x2::CreateRotation(float rad){
		Matrix2x2 mx;
		mx[0] = Vector2{ std::cos(rad), -std::sin(rad) };
		mx[1] = Vector2{ std::sin(rad), std::cos(rad) };

		return mx;
	}
}