#pragma once
#include <cstdint>
#include <iostream>
#include <string>

namespace JREngine {
	//typedef unsigned char u8_t;
	//using u8_t = unsigned char;

	struct Color {
		uint8_t r;
		uint8_t g;
		uint8_t b;
		uint8_t a;

		//friend std::istream& operator >> (std::istream& stream, Color& color);
		uint8_t operator [](size_t index) const { return (&r)[index]; }
		uint8_t& operator [] (size_t index) { return(&r)[index]; }

		//friend class Text;
	};

	std::istream& operator >> (std::istream& stream, Color& color);
	std::ostream& operator << (std::ostream& stream, const Color& color);
}