#pragma once
#include <string>
#include <variant>
#include <functional>

namespace JREngine
{
	class GameObject;

	class Event
	{
	public:
		using functionPtr = std::function<void(const Event&)>;

	public:
		std::string name;
		GameObject* reciever = nullptr;
		std::variant<int, bool, float, std::string> data;
	};

	// this will be used later
	class INotify
	{
	public:
		virtual void OnNotify(const Event& event) = 0;
	};
}