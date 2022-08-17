#include "Scene.h"
#include "Factory.h"
#include <algorithm>

namespace JREngine {
	void Scene::Update(){

		auto iter = m_actors.begin();
		while (iter != m_actors.end()) {
			(*iter)->Update();
			if ((*iter)->m_destroy) {
				//delete &iter;
				iter = m_actors.erase(iter);
			}
			else {
				iter++;
			}
		}
	}

	void Scene::Draw(Renderer& renderer){
		for (auto& actor : m_actors) {
			actor->Draw(renderer);
		}
	}
	
	void Scene::Add(std::unique_ptr<Actor> actor){
		actor->m_scene = this;
		m_actors.push_back(std::move(actor));
	}

	//void Scene::RemoveAll()

	//Move functions beneath draw?
	/*bool Scene::Write(const rapidjson::Value& value) {
	*
		return true;
	}*/

	/*bool Scene::Read(const rapidjson::Value& value) {
	* 
	* if (!value.HasMember("actors) && !value["actors"].isArray()){
	*	return false;
	* }
	* 
	* for (auto& actorValue : value["actors"].GetArray()){
	*	std::string type;
	*	READ_DATA(actorValue, type);
	*	
	*	auto actor = Factory::Instance().Create<Actor>(type);
	*	if (actor){
	*		//read actor
	*		actor-Read(actorValue);
	*		Add(std::move(actor));
	*	}
	* }
		return true;
	}*/
}