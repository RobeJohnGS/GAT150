//#pragma once
//#include <cmath>
//#include <sstream>
//#include <string>
//namespace JREngine
//{
//	struct Vector3
//	{
//		float x, y, z;
//
//		//Constructors
//		Vector3() : x{ 0 }, y{ 0 } {}
//		Vector3(float x, float y) : x{ x }, y{ y } {}
//		Vector3(float v) : x{ v }, y{ v } {}
//		Vector3(int x, int y) : x{ (float)x }, y{ (float)y } {}
//
//		//Functions
//		void Set(float x, float y) { this->x = x, this->y = y; }
//		float operator [] (size_t index) const { return (&x)[index]; }
//		float& operator [] (size_t index) { return (&x)[index]; }
//
//		Vector3 Add(const Vector3& v) { return Vector3{ v.x + x, v.y + y }; }
//
//		float LengthSqr();
//		float Length();
//		float DstanceSqr(const Vector3& v);
//		float Distance(const Vector3& v);
//
//		Vector3 Normalized();
//		void Normalize();
//
//		static const Vector3 zero;
//		static const Vector3 one;
//
//		static const Vector3 up;
//		static const Vector3 down;
//		static const Vector3 left;
//		static const Vector3 right;
//
//		//Arithmetic Operators
//		//Vector3 = Vector3 + Vector3
//		Vector3 operator + (const Vector3& v) const { return Vector3{ this->x + v.x, this->y + v.y }; }
//		Vector3 operator - (const Vector3& v) const { return Vector3{ this->x - v.x, this->y - v.y }; }
//		Vector3 operator / (const Vector3& v) const { return Vector3{ this->x / v.x, this->y / v.y }; }
//		Vector3 operator * (const Vector3& v) const { return Vector3{ this->x * v.x, this->y * v.y }; }
//
//		//Vector3 = Vector3 + float
//		Vector3 operator += (const Vector3& v) { this->x += v.x, this->y += v.y; return *this; }
//		Vector3 operator -= (const Vector3& v) { this->x -= v.x, this->y -= v.y; return *this; }
//		Vector3 operator /= (const Vector3& v) { this->x /= v.x, this->y /= v.y; return *this; }
//		Vector3 operator *= (const Vector3& v) { this->x *= v.x, this->y *= v.y; return *this; }
//
//		//Assignment Operators
//		Vector3 operator + (float s) const { return Vector3{ this->x + s, this->y + s }; }
//		Vector3 operator - (float s) const { return Vector3{ this->x - s, this->y - s }; }
//		Vector3 operator / (float s) const { return Vector3{ this->x / s, this->y / s }; }
//		Vector3 operator * (float s) const { return Vector3{ this->x * s, this->y * s }; }
//
//		Vector3 operator += (float s) { return Vector3{ this->x += s, this->y += s }; }
//		Vector3 operator -= (float s) { return Vector3{ this->x -= s, this->y -= s }; }
//		Vector3 operator /= (float s) { return Vector3{ this->x /= s, this->y /= s }; }
//		Vector3 operator *= (float s) { return Vector3{ this->x *= s, this->y *= s }; }
//
//		//Unary
//		//Vector3 = -Vector3
//		Vector3 operator - () { return Vector3{ -x, -y }; }
//
//		//Comparison
//		//Vector3 == Vector3
//		bool operator == (const Vector3& v) const { return (this->x == v.x && this->y == v.y); }
//		bool operator != (const Vector3& v) const { return (this->x != v.x || this->y != v.y); }
//	};
//
//	inline float Vector3::LengthSqr() {
//		return (x * x) + (y * y);
//	}
//
//	inline float Vector3::Length() {
//		return std::sqrt((x * x) + (y * y));
//	}
//
//	inline float Vector3::DstanceSqr(const Vector3& v)
//	{
//		return ((*this) - v).LengthSqr();
//	}
//
//	inline float Vector3::Distance(const Vector3& v)
//	{
//		return ((*this) - v).Length();
//	}
//
//	inline Vector3 Vector3::Normalized()
//	{
//		float length = Length();
//
//		//if length = 0, return 0, 0; else, return the normal one.
//		return (length == 0) ? Vector3{ 0, 0 } : Vector3{ x / length, y / length };
//	}
//
//	inline void Vector3::Normalize()
//	{
//		(*this) /= Length();
//	}
//}