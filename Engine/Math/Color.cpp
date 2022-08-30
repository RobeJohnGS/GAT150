#include "Color.h"
#include <string>

namespace JREngine {
	std::istream& operator >> (std::istream& stream, Color& color)
	{
		std::string line;
		std::getline(stream, line);

		//red
		std::string strR = line.substr(line.find("{") + 1, line.find(",") - line.find(",") - 1);
		color.r = (uint8_t)(std::stof(strR) * 255);
		//green
		std::string strG = line.substr(line.find(",") + 1, line.find(",") - line.find(",") - 1);
		color.g = (uint8_t)(std::stof(strG) * 255);
		//blue
		std::string strB = line.substr(line.find(",") + 1, line.find(",") - line.find("{") - 1);
		color.b = (uint8_t)(std::stof(strB) * 255);
		//a
		color.a = 255;
		/*
		 red 
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
		*/

		return stream;
	}

	std::ostream& operator<<(std::ostream& stream, Color& color)
	{
		stream << (int)color.r << " " << (int)color.g << " " << (int)color.b << " " << (int)color.a;

		return stream;
	}
}