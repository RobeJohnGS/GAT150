#pragma once
#include <cmath>
namespace Math {

	constexpr float pi = 3.14159265359f;
	constexpr float twoPi = 6.28318530718f;
	constexpr float halfPi = 1.57079632679f;

	constexpr float DegToRad(float degrees) {
		return degrees * (pi / 180);
	}

	constexpr float RadToDeg(float radians) {
		return radians * (180 / pi);
	}

	int sqr(int v);
	//Inline doesnt really call the funtion, it replaces the word for blocks of code.
	inline int half(int v) { return v / 2; }

	template <typename T>
	T Clamp(T value, T min, T max) {
		if (value < min) {
			return min;
		}

		if (value > max) {
			return max;
		}

		return value;
	}

	template<typename T>
	T Lerp(T min, T max, float t) {
		t = Clamp(t, 0.0f, 1.0f);

		return min + ((max - min) * t);
	}

	template<typename T>
	T Normalize(T value, T min, T max) {
		return (value - min) / (max - min);
	}

	template<typename T>
	T Remap(T value, T inMin, T inMax, T outMin, T outMax) {
		return Lerp(outMin, outMan, Normalize(value, inMin, inMax));
	}

	template<typename T>
	T mod(T numerator, T denominator) {
		return std::fmod(numerator, denominator);
	}

	template<>
	inline int mod(int numerator, int denominator) {
		return numerator % denominator;
	}

	template<typename T>
	T Wrap(T value, T min, T max) {
		if (value < min) {
			return max - mod((min - value), (min - max));
		}
		
		if (value > max) {
			return max + mod((value - min), (min - max));
		}

		return value;
	}
}