#pragma once
#include "Event.h"
#include <map>
#include <list>

namespace JREngine {
	class EventManager {
	public:
		//struct
		struct Observer {
			GameObject* reciever = nullptr;
			Event::functionPtr function;
		};

		//normal class
		void Initialize();
		void Shutdown();
		
		void Update();

		void Subscribe(const std::string& name, Event::functionPtr function, GameObject* reciever = nullptr);
		void Unsubscribe(const std::string& name, GameObject* reciever);

		void Notify(const Event& event);

	private:
		std::map<std::string, std::list<Observer>> m_events;
	};
}