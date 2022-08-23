#include "Color.h"
#include <string>

namespace JREngine {
	const Color Color::white{ 255, 255, 255, 255 };

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