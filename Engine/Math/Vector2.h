#pragma once
//#include "../Math/Color.h"
#include <cmath>
#include <sstream>
#include <string>


namespace JREngine
{
	struct Vector2
	{
		float x, y;

		//Constructors
		Vector2() : x{ 0 }, y{ 0 } {}
		Vector2(float x, float y) : x{ x }, y{ y } {}
		Vector2(float v) : x{ v }, y{ v } {}
		Vector2(int x, int y) : x{ (float)x }, y{ (float)y } {}

		//Functions
		void Set(float x, float y) { this->x = x, this->y = y; }
		Vector2 Add(const Vector2& v) { return Vector2{ v.x + x, v.y + y }; }

		float LengthSqr();
		float Length();
		float DstanceSqr(const Vector2& v);
		float Distance(const Vector2& v);

		Vector2 Normalized();
		void Normalize();

		float GetAngle();

		static Vector2 Rotate(const Vector2& v, float angle);

		static const Vector2 zero;
		static const Vector2 one;

		static const Vector2 up;
		static const Vector2 down;
		static const Vector2 left;
		static const Vector2 right;

		//Arithmetic Operators
		//Vector2 = Vector2 + Vector2
		Vector2 operator + (const Vector2& v) const { return Vector2{ this->x + v.x, this->y + v.y }; }
		Vector2 operator - (const Vector2& v) const { return Vector2{ this->x - v.x, this->y - v.y }; }
		Vector2 operator / (const Vector2& v) const { return Vector2{ this->x / v.x, this->y / v.y }; }
		Vector2 operator * (const Vector2& v) const { return Vector2{ this->x * v.x, this->y * v.y }; }

		//Vector2 = Vector2 + float
		Vector2 operator += (const Vector2& v) { this->x += v.x, this->y += v.y; return *this; }
		Vector2 operator -= (const Vector2& v) { this->x -= v.x, this->y -= v.y; return *this; }
		Vector2 operator /= (const Vector2& v) { this->x /= v.x, this->y /= v.y; return *this; }
		Vector2 operator *= (const Vector2& v) { this->x *= v.x, this->y *= v.y; return *this; }

		//Assignment Operators
		Vector2 operator + (float s) const { return Vector2{ this->x + s, this->y + s }; }
		Vector2 operator - (float s) const { return Vector2{ this->x - s, this->y - s }; }
		Vector2 operator / (float s) const { return Vector2{ this->x / s, this->y / s }; }
		Vector2 operator * (float s) const { return Vector2{ this->x * s, this->y * s }; }

		Vector2 operator += (float s) { return Vector2{ this->x += s, this->y += s }; }
		Vector2 operator -= (float s) { return Vector2{ this->x -= s, this->y -= s }; }
		Vector2 operator /= (float s) { return Vector2{ this->x /= s, this->y /= s }; }
		Vector2 operator *= (float s) { return Vector2{ this->x *= s, this->y *= s }; }

		//Unary
		//Vector2 = -Vector2
		Vector2 operator - () { return Vector2{ -x, -y }; }

		//Comparison
		//Vector2 == Vector2
		bool operator == (const Vector2& v) const { return (this->x == v.x && this->y == v.y); }
		bool operator != (const Vector2& v) const { return (this->x != v.x || this->y != v.y); }

		static const Vector2 one;
		static const Vector2 zero;
		static const Vector2 up;
		static const Vector2 down;
		static const Vector2 left;
		static const Vector2 right;
	};

	//Defined in Vector2.cpp
	std::istream& operator >> (std::istream& stream, Vector2& v);

	inline float Vector2::LengthSqr() { 
		return (x * x) + (y * y); 
	}

	inline float Vector2::Length() { 
		return std::sqrt((x * x) + (y * y)); 
	}

	inline float Vector2::DstanceSqr(const Vector2& v)
	{
		return ((*this) - v).LengthSqr();
	}

	inline float Vector2::Distance(const Vector2& v)
	{
		return ((*this) - v).Length();
	}

	inline Vector2 Vector2::Normalized()
	{
		float length = Length();

		//if length = 0, return 0, 0; else, return the normal one.
		return (length == 0) ? Vector2::zero : Vector2{ x / length, y / length };
	}

	inline void Vector2::Normalize()
	{
		(*this) /= Length();
	}

	inline Vector2 Vector2::Rotate(const Vector2& v, float angle)
	{
		float x = v.x * std::cos(angle) - v.y * std::sin(angle);
		float y = v.x * std::sin(angle) + v.y * std::cos(angle);

		return Vector2{ x, y };
	}

	inline float Vector2::GetAngle()
	{
		return std::atan2(y, x);
	}
}