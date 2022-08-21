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

		uint8_t operator [](size_t index) const { return (&r)[index]; }
		uint8_t& operator [] (size_t index) { return(&r)[index]; }

		static const Color white;
		static const Color black;
		static const Color red;
		static const Color green;
		static const Color blue;

		friend std::istream& operator >> (std::istream& stream, Color& color);
		friend std::ostream& operator << (std::ostream& stream, Color& c);
	};

	inline std::istream& operator >> (std::istream& stream, Color& color)
	{
		std::string line;
		std::getline(stream, line);

		std::string str;

		// red 
		str = line.substr(line.find("{") + 1, line.find(",") - (line.find("{") + 1));
		color.r = (uint8_t)(std::stof(str) * 255);

		// setting line to another sub section of the string to read green and blue 
		line = line.substr(line.find(",") + 1);
		// line: #g, #b } 

		// green 
		str = line.substr(line.find(" ") + 1, line.find(",") - (line.find(" ") + 1));
		color.g = (uint8_t)(std::stof(str) * 255);

		// blue 
		str = line.substr(line.find(" ") + 1, line.find("}") - (line.find(" ") + 1));
		color.b = (uint8_t)(std::stof(str) * 255);

		// default alpha to 255 
		color.a = 255;

		return stream;
	}

	std::ostream& operator<<(std::ostream& stream, Color& c)
	{
		stream << (int)c.r << " " << (int)c.g << " " << (int)c.b << " " << (int)c.a;

		return stream;
	}
}