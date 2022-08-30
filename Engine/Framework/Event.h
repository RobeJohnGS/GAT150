#pragma once
#include <string>
#include <variant>
#include <functional>

namespace JREngine {
	class GameObject;

	class Event {
	public:
		using functionPtr = std::function<void(const Event&)>;

		//variables
		std::string name;
		GameObject* reciever = nullptr;
		std::variant<int, bool, float, std::string> data;
	};
}